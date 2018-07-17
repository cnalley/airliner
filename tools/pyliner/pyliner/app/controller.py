"""
The controller module exposes a Controller App for performing high-level vehicle
state management.

Enums:
    FlightMode  Use to send the flight software a mode.

Apps:
    Controller  Sends high-level one-off vehicle management commands.

"""
import time

from flufl.enum import Enum

from pyliner.app import App
from pyliner.action import ACTION_RTL, ACTION_SEND_COMMAND
from pyliner.intent import Intent
from pyliner.pyliner_exceptions import UnauthorizedAtpError
from pyliner.telemetry import ManualSetpoint
from pyliner.util import query_yes_no

_WAIT_TIME = 0.1


class FlightMode(Enum):
    """Use to select a mode for the flight software."""
    Manual = 1
    AltCtl = 2
    PosCtl = 3
    RTL = 4


class Controller(App):
    """Sends high-level one-off commands to the vehicle."""

    def __init__(self):
        super(Controller, self).__init__()
        self.atp_override = None

    def attach(self, vehicle_wrapper):
        super(Controller, self).attach(vehicle_wrapper)
        self.vehicle.callback = self.receive

    def detach(self):
        self.vehicle.callback = None
        super(Controller, self).detach()

    def arm(self):
        """Arm vehicle."""
        print("Arming vehicle")
        self.vehicle.info("Arming vehicle")
        self.vehicle.broadcast(Intent(
            action=ACTION_SEND_COMMAND,
            data=ManualSetpoint(ArmSwitch=3))).first()
        self.vehicle.broadcast(Intent(
            action=ACTION_SEND_COMMAND,
            data=ManualSetpoint(ArmSwitch=1))).first()

    def receive(self, intent):
        actions = {
            ACTION_RTL: self.rtl
        }
        try:
            actions[intent.action]()
        except KeyError:
            if intent.component == self.vehicle._name:
                self.info('Controller cannot process intent: {}'.format(intent))

    def atp(self, text, error=True):
        """Collect authorization to proceed (ATP) from the user."""
        atp_auth = None
        while atp_auth is None:
            if callable(self.atp_override):
                atp_auth = self.atp_override()
            elif self.atp_override is not None:
                atp_auth = self.atp_override
            else:
                atp_auth = query_yes_no(
                    "Requires authorization for: {}".format(text))
            self.vehicle.info("ATP: {} Auth: {}".format(text, atp_auth))
            if error and atp_auth is False:
                raise UnauthorizedAtpError
            return atp_auth

    def disarm(self):
        print("Disarming vehicle")
        self.vehicle.info("Disarming vehicle")
        self.vehicle.broadcast(Intent(
            action=ACTION_SEND_COMMAND,
            data=ManualSetpoint(ArmSwitch=3))).first()

    def flight_mode(self, mode):
        if not mode:
            raise ValueError('Mode transition requires a passed mode.')
        if mode == FlightMode.Manual:
            raise NotImplemented()
        elif mode == FlightMode.AltCtl:
            raise NotImplemented()
        elif mode == FlightMode.PosCtl:
            self._mode_posctl()

    def _mode_posctl(self):
        print("Position control")
        self.vehicle.info("Position control")
        self.vehicle.broadcast(Intent(
            action=ACTION_SEND_COMMAND,
            data=ManualSetpoint(Z=0.5, PosctlSwitch=1, GearSwitch=1))
        ).first()

    @classmethod
    def required_telemetry_paths(cls):
        return None

    def rtl(self):
        """Return to launch."""
        print("RTL")
        self.vehicle.info("RTL")
        self.vehicle.broadcast(Intent(
            action=ACTION_SEND_COMMAND,
            data=ManualSetpoint(ReturnSwitch=1, GearSwitch=3, ArmSwitch=1))
        ).first()

    def takeoff(self):
        """Takeoff"""
        print("Auto takeoff")
        self.vehicle.info("Auto takeoff")
        self.vehicle.broadcast(Intent(
            action=ACTION_SEND_COMMAND,
            data=ManualSetpoint(TransitionSwitch=1, ArmSwitch=1))
        ).first()
        time.sleep(5)
