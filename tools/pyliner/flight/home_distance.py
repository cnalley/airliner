from time import sleep

from pyliner.app.communication import Communication
from pyliner.util import read_json
from pyliner.util.scripting_wrapper import ScriptingWrapper
from pyliner.vehicle import Vehicle

rky = Vehicle(
    vehicle_id='rocky',
    communications=Communication(
        airliner_map=read_json("airliner.json"),
        ci_port=5009,
        to_port=5012)
)

with ScriptingWrapper(rky) as rocky:
    while rocky.nav.altitude == "NULL":
        sleep(1)
        print "Waiting for telemetry downlink..."

    home = rocky.nav.position

    while True:
        # raw_input('Press Enter To Log: ')
        position = rocky.nav.position
        print('Position: {}\tDistance: {}'.format(
            position, rocky.geographic.distance(home, position)))
