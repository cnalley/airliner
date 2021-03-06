/****************************************************************************
*
*   Copyright (c) 2017 Windhover Labs, L.L.C. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
* 1. Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in
*    the documentation and/or other materials provided with the
*    distribution.
* 3. Neither the name Windhover Labs nor the names of its
*    contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
* COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
* OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
* AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
* ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
*****************************************************************************/

#ifndef MPC_TBLDEFS_H
#define MPC_TBLDEFS_H

/************************************************************************
** Pragmas
*************************************************************************/

/************************************************************************
** Includes
*************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

#include "cfe.h"
#include "mpc_platform_cfg.h"

/************************************************************************
** Local Defines
*************************************************************************/

#define THR_MIN_MIN          (0.05)
#define THR_MIN_MAX          (1.0)
#define THR_HOVER_MIN        (0.2)
#define THR_HOVER_MAX        (0.8)
#define THR_MAX_MIN          (0.0)
#define THR_MAX_MAX          (0.95)
#define MANTHR_MIN_MIN       (0.0)
#define MANTHR_MIN_MAX       (1.0)
#define MANTHR_MAX_MIN       (0.0)
#define MANTHR_MAX_MAX       (1.0)
#define Z_P_MIN              (0.0)
#define Z_P_MAX              (1.5)
#define Z_VEL_P_MIN          (0.1)
#define Z_VEL_P_MAX          (0.4)
#define Z_VEL_I_MIN          (0.01)
#define Z_VEL_I_MAX          (0.1)
#define Z_VEL_D_MIN          (0.0)
#define Z_VEL_D_MAX          (0.1)
#define Z_VEL_MAX_UP_MIN     (0.5)
#define Z_VEL_MAX_UP_MAX     (8.0)
#define Z_VEL_MAX_DN_MIN     (0.5)
#define Z_VEL_MAX_DN_MAX     (4.0)
#define Z_FF_MIN             (0.0)
#define Z_FF_MAX             (1.0)
#define XY_P_MIN             (0.0)
#define XY_P_MAX             (2.0)
#define XY_VEL_P_MIN         (0.06)
#define XY_VEL_P_MAX         (0.15)
#define XY_VEL_I_MIN         (0.0)
#define XY_VEL_I_MAX         (0.1)
#define XY_VEL_D_MIN         (0.005)
#define XY_VEL_D_MAX         (0.1)
#define XY_CRUISE_MIN        (3.0)
#define XY_CRUISE_MAX        (20.0)
#define TARGET_THRE_MIN      (1.0)
#define TARGET_THRE_MAX      (50.0)
#define XY_VEL_MAX_MIN       (0.0)
#define XY_VEL_MAX_MAX       (20.0)
#define XY_FF_MIN            (0.0)
#define XY_FF_MAX            (1.0)
#define TILTMAX_AIR_MIN      (0.0)
#define TILTMAX_AIR_MAX      (3.1415926 / 2.0)
#define TILTMAX_LND_MIN      (0.0)
#define TILTMAX_LND_MAX      (3.1415926 / 2.0)
#define LAND_SPEED_MIN       (0.2)
#define LAND_SPEED_MAX       (122.0)
#define TKO_SPEED_MIN        (1.0)
#define TKO_SPEED_MAX        (5.0)
#define MAN_TILT_MAX_MIN     (0.0)
#define MAN_TILT_MAX_MAX     (90.0)
#define MAN_Y_MAX_MIN        (0.0)
#define MAN_Y_MAX_MAX        (400.0)
#define HOLD_DZ_MIN          (0.0)
#define HOLD_DZ_MAX          (1.0)
#define HOLD_MAX_XY_MIN      (0.0)
#define HOLD_MAX_XY_MAX      (3.0)
#define HOLD_MAX_Z_MIN       (0.0)
#define HOLD_MAX_Z_MAX       (3.0)
#define VELD_LP_MIN          (0.0)
#define VELD_LP_MAX          (10.0)
#define ACC_HOR_MAX_MIN      (2.0)
#define ACC_HOR_MAX_MAX      (15.0)
#define ACC_UP_MAX_MIN       (2.0)
#define ACC_UP_MAX_MAX       (15.0)
#define ACC_DOWN_MAX_MIN     (2.0)
#define ACC_DOWN_MAX_MAX     (15.0)
#define ALT_MODE_MIN         (0)
#define ALT_MODE_MAX         (1)
#define XY_MAN_EXPO_MIN      (0.0)
#define XY_MAN_EXPO_MAX      (1.0)
#define Z_MAN_EXPO_MIN       (0.0)
#define Z_MAN_EXPO_MAX       (1.0)
#define LAND_ALT1_MIN        (0)
#define LAND_ALT1_MAX        (122)
#define LAND_ALT2_MIN        (0)
#define LAND_ALT2_MAX        (122)
#define TKO_RAMP_T_MIN       (0.1)
#define TKO_RAMP_T_MAX       (1.0)
#define MC_YAWRATE_MAX_MIN   (0.0)
#define MC_YAWRATE_MAX_MAX   (1800.0)
#define MC_YAW_P_MIN         (0.0)
#define MC_YAW_P_MAX         (5.0)
#define MPC_CRUISE_90_MIN    (1.0)
#define MPC_CRUISE_90_MAX    (20.0)
#define MPC_JERK_MAX_MIN     (0.0)
#define MPC_JERK_MAX_MAX     (15.0)
#define MPC_JERK_MIN_MIN     (0.5)
#define MPC_JERK_MIN_MAX     (10.0)
#define MPC_DEC_HOR_SLOW_MIN (0.5)
#define MPC_DEC_HOR_SLOW_MAX (10.0)
#define MPC_VEL_MANUAL_MIN   (3.0)
#define MPC_VEL_MANUAL_MAX   (20.0)
#define NAV_ACC_RAD_MIN      (0.05)
#define NAV_ACC_RAD_MAX      (200.0)
#define NAV_MIS_YAW_ERR_MIN  (0.0)
#define NAV_MIS_YAW_ERR_MAX  (90.0)


/**
 * \brief Defines the table identification name used for the
 * configuration table registration.
 */
#define MPC_CONFIG_TABLENAME ("CONFIG_TBL")


/** \brief Definition for a single config table entry */
typedef struct
{
    /** \brief Minimum thrust in auto thrust control.
     *
     *  \par It's recommended to set it > 0 to avoid free fall with zero thrust.
     *
     *  \par Limits:
     *       Min > Max (incr.) #THR_MIN_MIN > #THR_MIN_MAX, default 0.2.
     */
    float THR_MIN;

    /** \brief Hover thrust.
     *
     *  \par Vertical thrust required to hover.  This value is mapped to center
     *       stick for manual throttle control.  With this value set to the
     *       thrust required to hover, transition from manual to ALTCTL mode
     *       while hovering will occur with the throttle stick near center,
     *       which is then interpreted as (near) zero demand for vertical
     *       speed.
     *
     *  \par Limits:
     *       Min > Max (incr.) #THR_HOVER_MIN > #THR_HOVER_MAX, default 0.2.
     */
    float THR_HOVER;

    /** \brief Maximum thrust in auto thrust control.
     *
     *  \par Limit max allowed thrust. Setting a value of one can put
     *       the system into actuator saturation as no spread between
     *       the motors is possible any more. A value of 0.8 - 0.9
     *       is recommended.
     *
     *  \par Limits:
     *       Min > Max (incr.) #THR_MAX_MIN > #THR_MAX_MAX.
     */
    float THR_MAX;

    /** \brief Minimum manual thrust.
     *
     *  \par Minimum vertical thrust. It's recommended to set it > 0 to avoid
     *       free fall with zero thrust.
     *
     *  \par Limits:
     *       Min > Max (incr.) #MANTHR_MIN_MIN > #MANTHR_MIN_MAX.
     */
    float MANTHR_MIN;

    /** \brief Maximum manual thrust.
     *
     *  \par Limit max allowed thrust. Setting a value of one can put
     *       the system into actuator saturation as no spread between
     *       the motors is possible any more. A value of 0.8 - 0.9
     *       is recommended.
     *
     *  \par Limits:
     *       Min > Max (incr.) #MANTHR_MAX_MIN > #MANTHR_MAX_MAX.
     */
    float MANTHR_MAX;

    /** \brief Proportional gain for vertical position error
     *
     *  \par Limits:
     *       Min > Max (incr.) #Z_P_MIN > #Z_P_MAX.
     */
    float Z_P;

    /** \brief Proportional gain for vertical velocity error
     *
     *  \par Limits:
     *       Min > Max (incr.) #Z_VEL_P_MIN > #Z_VEL_P_MAX.
     */
    float Z_VEL_P;

    /** \brief Integral gain for vertical velocity error
     *
     *  \par Non zero value allows hovering thrust estimation on stabilized or
     *       autonomous takeoff.
     *
     *  \par Limits:
     *       Min > Max (incr.) #Z_VEL_I_MIN > #Z_VEL_I_MAX.
     */
    float Z_VEL_I;

    /** \brief Differential gain for vertical velocity error.
     *
     *  \par Limits:
     *       Min > Max (incr.) #Z_VEL_D_MIN > #Z_VEL_D_MAX.
     */
    float Z_VEL_D;

    /** \brief Maximum vertical ascent velocity
     *
     *  \par Maximum vertical velocity in AUTO mode and endpoint for
     *       stabilized modes (ALTCTRL, POSCTRL).
     *
     *  \par Limits:
     *       Min > Max (incr.) #Z_VEL_D_MIN > #Z_VEL_D_MAX.
     *
     *  \par Units: m/s
     */
    float Z_VEL_MAX_UP;

    /** \brief Maximum vertical descent velocity
     *
     *  \par Maximum vertical velocity in AUTO mode and endpoint for
     *       stabilized modes (ALTCTRL, POSCTRL).
     *
     *  \par Limits:
     *       Min > Max (incr.) #Z_VEL_MAX_DN_MIN > #Z_VEL_MAX_DN_MAX.
     *
     *  \par Units: m/s
     */
    float Z_VEL_MAX_DN;

    /** \brief Vertical velocity feed forward
     *
     *  \par Feed forward weight for altitude control in stabilized modes
     *       (ALTCTRL, POSCTRL). 0 will give slow response and no overshot,
     *       1 - fast response and big overshot.
     *
     *  \par Limits:
     *       Min > Max (incr.) #Z_FF_MIN > #Z_FF_MAX.
     */
    float Z_FF;

    /** \brief Proportional gain for horizontal position error.
     *
     *  \par Limits:
     *       Min > Max (incr.) #XY_P_MIN > #XY_P_MAX.
     */
    float XY_P;

    /** \brief Proportional gain for horizontal velocity error.
     *
     *  \par Limits:
     *       Min > Max (incr.) #XY_VEL_P_MIN > #XY_VEL_P_MAX.
     */
    float XY_VEL_P;

    /** \brief Non-zero value allows to resist wind.
     *
     *  \par Limits:
     *       Min > Max (incr.) #XY_VEL_I_MIN > #XY_VEL_I_MAX.
     */
    float XY_VEL_I;

    /** \brief Differential gain for horizontal velocity error. Small values
     *         help reduce fast oscillations. If value is too big
     *         oscillations will appear again.
     *
     *  \par Limits:
     *       Min > Max (incr.) #XY_VEL_D_MIN > #XY_VEL_D_MAX.
     */
    float XY_VEL_D;

    /** \brief Nominal horizontal velocity in mission.
     *
     *  \par Limits:
     *       Min > Max (incr.) #XY_CRUISE_MIN > #XY_CRUISE_MAX.
     *
     *  \par Units:  m/s
     */
    float XY_CRUISE;

    /** \brief Distance Threshold Horizontal Auto
     *
     *  \par The distance defines at which point the vehicle
     *       has to slow down to reach target if no direct
     *       passing to the next target is desired.
     *
     *  \par Limits:
     *       Min > Max (incr.) #TARGET_THRE_MIN > #TARGET_THRE_MAX.
     *
     *  \par Units:  m
     */
    float TARGET_THRE;

    /** \brief Maximum horizontal velocity
     *
     *  \par Maximum horizontal velocity in AUTO mode. If higher speeds
     *       are commanded in a mission they will be capped to this velocity.
     *
     *  \par Limits:
     *       Min > Max (incr.) #XY_VEL_MIN > #XY_VEL_MAX.
     *
     *  \par Units:  m/s
     */
    float XY_VEL_MAX;

    /** \brief Horizontal velocity feed forward
     *
     *  \par Feed forward weight for position control in position control mode (POSCTRL).
     *       0 will give slow response and no overshot, 1 - fast response and big overshot.
     *
     *  \par Limits:
     *       Min > Max (incr.) #XY_FF_MIN > #XY_FF_MAX.
     */
    float XY_FF;

    /** \brief Maximum tilt angle in air.
     *
     *  \par Limits maximum tilt in AUTO and POSCTRL modes during flight.
     *
     *  \par Limits:
     *       Min > Max (incr.) #TILTMAX_AIR_MIN > #TILTMAX_AIR_MAX.
     *
     *  \par Units: radians
     */
    float TILTMAX_AIR;

    /** \brief Maximum tilt angle during landing.
     *
     *  \par Limits maximum tilt angle on landing.
     *
     *  \par Limits:
     *       Min > Max (incr.) #TILTMAX_LND_MIN > #TILTMAX_LND_MAX.
     *
     *  \par Units: radians
     */
    float TILTMAX_LND;

    /** \brief Landing descend rate
     *
     *  \par Limits:
     *       Min > Max (incr.) #LAND_SPEED_MIN > #LAND_SPEED_MAX.
     *
     *  \par Units: m
     */
    float LAND_SPEED;

    /** \brief Takeoff climb rate
     *
     *  \par Limits:
     *       Min > Max (incr.) #TKO_SPEED_MIN > #TKO_SPEED_MAX.
     *
     *  \par Units: m/s
     */
    float TKO_SPEED;

    /** \brief Maximal tilt angle in manual or altitude mode
     *
     *  \par Limits:
     *       Min > Max (incr.) #MAN_TILT_MAX_MIN > #MAN_TILT_MAX_MAX.
     *
     *  \par Units: deg
     */
    float MAN_TILT_MAX;

    /** \brief Max manual yaw rate
     *
     *  \par Limits:
     *       Min > Max (incr.) #MAN_Y_MAX_MIN > #MAN_Y_MAX_MAX.
     *
     *  \par Units: deg/s
     */
    float MAN_Y_MAX;

    /** \brief Deadzone of sticks where position hold is enabled
     *
     *  \par Limits:
     *       Min > Max (incr.) #MAN_Y_MAX_MIN > #MAN_Y_MAX_MAX.
     *
     *  \par Units: deg/s
     */
    float HOLD_DZ;

    /** \brief Maximum horizontal velocity for which position hold
     *         is enabled (use 0 to disable check).
     *
     *  \par Limits:
     *       Min > Max (incr.) #MAN_XY_MAX_MIN > #MAN_XY_MAX_MAX.
     *
     *  \par Units: m/s
     */
    float HOLD_MAX_XY;

    /** \brief Maximum vertical velocity for which position hold is enabled
     *         (use 0 to disable check)
     *
     *  \par Limits:
     *       Min > Max (incr.) #HOLD_MAX_Z_MIN > #HOLD_MAX_Z_MAX.
     *
     *  \par Units: m/s
     */
    float HOLD_MAX_Z;

    /** \brief Low pass filter cut freq. for numerical velocity derivative
     *
     *  \par Limits:
     *       Min > Max (incr.) #VELD_LP_MIN > #VELD_LP_MAX.
     *
     *  \par Units: Hz
     */
    float VELD_LP;

    /** \brief Maximum horizonal acceleration in velocity controlled modes
     *
     *  \par Limits:
     *       Min > Max (incr.) #ACC_HOR_MAX_MIN > #ACC_HOR_MAX_MAX.
     *
     *  \par Units: m/s/s
     */
    float ACC_HOR_MAX;

    /** \brief Maximum vertical acceleration in velocity controlled modes upward
     *
     *  \par Limits:
     *       Min > Max (incr.) #ACC_UP_MAX_MIN > #ACC_UP_MAX_MAX.
     *
     *  \par Units: m/s/s
     */
    float ACC_UP_MAX;

    /** \brief Maximum vertical acceleration in velocity controlled modes down
     *
     *  \par Limits:
     *       Min > Max (incr.) #ACC_DOWN_MAX_MIN > #ACC_DOWN_MAX_MAX.
     *
     *  \par Units: m/s/s
     */
    float ACC_DOWN_MAX;

    /** \brief Altitude control mode, note mode 1 only tested with LPE
     *
     *  \par Limits:
     *       Min > Max (incr.) #ALT_MODE_MIN > #ALT_MODE_MAX.
     *
     *  \par 0: Altitude following, 1: Terrain following
     */
    uint32 ALT_MODE;

    /** \brief Manual control stick exponential curve sensitivity attenuation
     *         with small velocity setpoints.
     *
     *  \par Limits:
     *       Min > Max (incr.) #XY_MAN_EXPO_MIN > #XY_MAN_EXPO_MAX.
     *
     *  \par 0: Purely linear input curve, 1: Purely cubic input curve
     */
    float XY_MAN_EXPO;

    /** \brief Manual control stick vertical exponential curve
     *
     *  \par The higher the value the less sensitivity the stick has
     *       around zero while still reaching the maximum value with full
     *       stick deflection.
     *
     *  \par Limits:
     *       Min > Max (incr.) #Z_MAN_EXPO_MIN > #Z_MAN_EXPO_MAX.
     *
     *  \par 0: Purely linear input curve, 1: Purely cubic input curve
     */
    float Z_MAN_EXPO;

    /** \brief Altitude for step 1 of slow landing (descend)
     *
     *  \par Below this altitude descending velocity gets limited
     *       to a value between #Z_VEL_MAX and #LAND_SPEED
     *       to enable a smooth descent experience.
     *       Value needs to be higher than #LAND_ALT2
     *
     *  \par Limits:
     *       Min > Max (incr.) #LAND_ALT1_MIN > #LAND_ALT1_MAX.
     *
     *  \par Units: m
     */
    uint32 LAND_ALT1;

    /** \brief Altitude for step 2 of slow landing (landing)
     *
     *  \par Below this altitude descending velocity gets limited to
     *  #LAND_SPEED.  Value needs to be lower than #LAND_ALT1.
     *
     *  \par Limits:
     *       Min > Max (incr.) #LAND_ALT2_MIN > #LAND_ALT2_MAX.
     *
     *  \par Units: m
     */
    uint32 LAND_ALT2;

    /** \brief Position control smooth takeoff ramp time constant
     *
     *  \par Increasing this value will make automatic and manual takeoff
     *       slower.  If it's too slow the drone might scratch the ground
     *       and tip over.
     *
     *  \par Limits:
     *       Min > Max (incr.) #TKO_RAMP_T_MIN > #TKO_RAMP_T_MAX.
     */
    float TKO_RAMP_T;

    /** \brief Max yaw rate
     *
     *  \par Limits:
     *       Min > Max (incr.) #MC_YAWRATE_MAX_MIN > #MC_YAWRATE_MAX_MAX.
     *
     *  \par Units: deg/s
     */
    float MC_YAWRATE_MAX;

    /** \brief Yaw P gain
     *
     *  \par Yaw proportional gain, i.e. desired angular speed in rad/s for error 1 rad.
     *
     *  \par Limits:
     *       Min > Max (incr.) #MC_YAW_P_MIN > #MC_YAW_P_MAX.
     *
     *  \par Units: 1/s
     */
    float MC_YAW_P;

    int32 VT_OPT_RECOV_EN;

    /** \brief Cruising speed at 90
     *
     *  \par Cruise speed when angle prev-current/current-next setpoint
     *       is 90 degrees. It should be lower than #XY_CRUISE.
     *
     *  \par Applies only in AUTO modes (includes also RTL / hold / etc.)
     *
     *  \par Limits:
     *       Min > Max (incr.) #MPC_CRUISE_90_MIN > #MPC_CRUISE_90_MAX.
     *
     *  \par Units: m/s
     */
    float MPC_CRUISE_90;

    /** \brief Maximum jerk in manual controlled mode for BRAKING to zero.
     *
     *  \par If this value is below MPC_JERK_MIN, the acceleration limit in xy
     *   and z is MPC_ACC_HOR_MAX and MPC_ACC_UP_MAX respectively
     *   instantaneously when the user demands brake (=zero stick input).
     *   Otherwise the acceleration limit increases from current acceleration
     *   limit towards MPC_ACC_HOR_MAX/MPC_ACC_UP_MAX with jerk limit
     *
     *  \par Limits:
     *       Min > Max (incr.) #MPC_JERK_MAX_MIN > #MPC_JERK_MAX_MAX.
     *
     *  \par Units: m/s/s/s
     */
    float MPC_JERK_MAX;

    /** \brief Minimum jerk in manual controlled mode for BRAKING to zero
     *
     *  \par Limits:
     *       Min > Max (incr.) #MPC_JERK_MIN_MIN > #MPC_JERK_MIN_MAX.
     *
     *  \par Units: m/s/s/s
     */
    float MPC_JERK_MIN;

    /** \brief Slow horizontal manual deceleration for manual mode
     *
     *  \par Limits:
     *       Min > Max (incr.) #MPC_DEC_HOR_SLOW_MIN > #MPC_DEC_HOR_SLOW_MAX.
     *
     *  \par Units: m/s/s
     */
    float MPC_DEC_HOR_SLOW;

    /** \brief Maximum horizontal velocity setpoint for manual controlled mode
     *
     *  \par If velocity setpoint larger than MPC_XY_VEL_MAX is set, then
     *       the setpoint will be capped to MPC_XY_VEL_MAX
     *
     *  \par Limits:
     *       Min > Max (incr.) #MPC_VEL_MANUAL_MIN > #MPC_VEL_MANUAL_MAX.
     *
     *  \par Units: m/s
     */
    float MPC_VEL_MANUAL;

    /** \brief Acceptance Radius
     *
     *  \par Default acceptance radius, overridden by acceptance radius of
     *       waypoint if set. For fixed wing the L1 turning distance is used
     *       for horizontal acceptance.
     *
     *  \par Limits:
     *       Min > Max (incr.) #NAV_ACC_RAD_MIN > #NAV_ACC_RAD_MAX.
     *
     *  \par Units: m
     */
    float NAV_ACC_RAD;

    /** NAV_MIS_YAW_ERR
     *
     *  \brief Max yaw error in degrees needed for waypoint heading acceptance.
     *
     *  \par Limits:
     *       Min > Max (incr.) NAV_MIS_YAW_ERR_MIN > NAV_MIS_YAW_ERR_MAX , default 12.0.
     *
     *  \par Units: deg
     */
    float NAV_MIS_YAW_ERR;


} MPC_ConfigTbl_t;


#ifdef __cplusplus
}
#endif

#endif /* MPC_TBLDEFS_H */

/************************/
/*  End of File Comment */
/************************/
