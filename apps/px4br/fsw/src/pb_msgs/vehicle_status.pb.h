/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.6 at Wed Oct 26 00:46:18 2016. */

#ifndef PB_VEHICLE_STATUS_PB_H_INCLUDED
#define PB_VEHICLE_STATUS_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _px4_vehicle_status_pb_ARMING_STATE {
    px4_vehicle_status_pb_ARMING_STATE_ARMING_STATE_INIT = 0,
    px4_vehicle_status_pb_ARMING_STATE_ARMING_STATE_STANDBY = 1,
    px4_vehicle_status_pb_ARMING_STATE_ARMING_STATE_ARMED = 2,
    px4_vehicle_status_pb_ARMING_STATE_ARMING_STATE_ARMED_ERROR = 3,
    px4_vehicle_status_pb_ARMING_STATE_ARMING_STATE_STANDBY_ERROR = 4,
    px4_vehicle_status_pb_ARMING_STATE_ARMING_STATE_REBOOT = 5,
    px4_vehicle_status_pb_ARMING_STATE_ARMING_STATE_IN_AIR_RESTORE = 6,
    px4_vehicle_status_pb_ARMING_STATE_ARMING_STATE_MAX = 7
} px4_vehicle_status_pb_ARMING_STATE;
#define _px4_vehicle_status_pb_ARMING_STATE_MIN px4_vehicle_status_pb_ARMING_STATE_ARMING_STATE_INIT
#define _px4_vehicle_status_pb_ARMING_STATE_MAX px4_vehicle_status_pb_ARMING_STATE_ARMING_STATE_MAX
#define _px4_vehicle_status_pb_ARMING_STATE_ARRAYSIZE ((px4_vehicle_status_pb_ARMING_STATE)(px4_vehicle_status_pb_ARMING_STATE_ARMING_STATE_MAX+1))

typedef enum _px4_vehicle_status_pb_HIL_STATE {
    px4_vehicle_status_pb_HIL_STATE_HIL_STATE_OFF = 0,
    px4_vehicle_status_pb_HIL_STATE_HIL_STATE_ON = 1
} px4_vehicle_status_pb_HIL_STATE;
#define _px4_vehicle_status_pb_HIL_STATE_MIN px4_vehicle_status_pb_HIL_STATE_HIL_STATE_OFF
#define _px4_vehicle_status_pb_HIL_STATE_MAX px4_vehicle_status_pb_HIL_STATE_HIL_STATE_ON
#define _px4_vehicle_status_pb_HIL_STATE_ARRAYSIZE ((px4_vehicle_status_pb_HIL_STATE)(px4_vehicle_status_pb_HIL_STATE_HIL_STATE_ON+1))

typedef enum _px4_vehicle_status_pb_NAVIGATION_STATE {
    px4_vehicle_status_pb_NAVIGATION_STATE_NAVIGATION_STATE_MANUAL = 0,
    px4_vehicle_status_pb_NAVIGATION_STATE_NAVIGATION_STATE_ALTCTL = 1,
    px4_vehicle_status_pb_NAVIGATION_STATE_NAVIGATION_STATE_POSCTL = 2,
    px4_vehicle_status_pb_NAVIGATION_STATE_NAVIGATION_STATE_AUTO_MISSION = 3,
    px4_vehicle_status_pb_NAVIGATION_STATE_NAVIGATION_STATE_AUTO_LOITER = 4,
    px4_vehicle_status_pb_NAVIGATION_STATE_NAVIGATION_STATE_AUTO_RTL = 5,
    px4_vehicle_status_pb_NAVIGATION_STATE_NAVIGATION_STATE_AUTO_RCRECOVER = 6,
    px4_vehicle_status_pb_NAVIGATION_STATE_NAVIGATION_STATE_AUTO_RTGS = 7,
    px4_vehicle_status_pb_NAVIGATION_STATE_NAVIGATION_STATE_AUTO_LANDENGFAIL = 8,
    px4_vehicle_status_pb_NAVIGATION_STATE_NAVIGATION_STATE_AUTO_LANDGPSFAIL = 9,
    px4_vehicle_status_pb_NAVIGATION_STATE_NAVIGATION_STATE_ACRO = 10,
    px4_vehicle_status_pb_NAVIGATION_STATE_NAVIGATION_STATE_UNUSED = 11,
    px4_vehicle_status_pb_NAVIGATION_STATE_NAVIGATION_STATE_DESCEND = 12,
    px4_vehicle_status_pb_NAVIGATION_STATE_NAVIGATION_STATE_TERMINATION = 13,
    px4_vehicle_status_pb_NAVIGATION_STATE_NAVIGATION_STATE_OFFBOARD = 14,
    px4_vehicle_status_pb_NAVIGATION_STATE_NAVIGATION_STATE_STAB = 15,
    px4_vehicle_status_pb_NAVIGATION_STATE_NAVIGATION_STATE_RATTITUDE = 16,
    px4_vehicle_status_pb_NAVIGATION_STATE_NAVIGATION_STATE_AUTO_TAKEOFF = 17,
    px4_vehicle_status_pb_NAVIGATION_STATE_NAVIGATION_STATE_AUTO_LAND = 18,
    px4_vehicle_status_pb_NAVIGATION_STATE_NAVIGATION_STATE_AUTO_FOLLOW_TARGET = 19,
    px4_vehicle_status_pb_NAVIGATION_STATE_NAVIGATION_STATE_MAX = 20
} px4_vehicle_status_pb_NAVIGATION_STATE;
#define _px4_vehicle_status_pb_NAVIGATION_STATE_MIN px4_vehicle_status_pb_NAVIGATION_STATE_NAVIGATION_STATE_MANUAL
#define _px4_vehicle_status_pb_NAVIGATION_STATE_MAX px4_vehicle_status_pb_NAVIGATION_STATE_NAVIGATION_STATE_MAX
#define _px4_vehicle_status_pb_NAVIGATION_STATE_ARRAYSIZE ((px4_vehicle_status_pb_NAVIGATION_STATE)(px4_vehicle_status_pb_NAVIGATION_STATE_NAVIGATION_STATE_MAX+1))

typedef enum _px4_vehicle_status_pb_RC_IN_MODE {
    px4_vehicle_status_pb_RC_IN_MODE_RC_IN_MODE_DEFAULT = 0,
    px4_vehicle_status_pb_RC_IN_MODE_RC_IN_MODE_OFF = 1,
    px4_vehicle_status_pb_RC_IN_MODE_RC_IN_MODE_GENERATED = 2
} px4_vehicle_status_pb_RC_IN_MODE;
#define _px4_vehicle_status_pb_RC_IN_MODE_MIN px4_vehicle_status_pb_RC_IN_MODE_RC_IN_MODE_DEFAULT
#define _px4_vehicle_status_pb_RC_IN_MODE_MAX px4_vehicle_status_pb_RC_IN_MODE_RC_IN_MODE_GENERATED
#define _px4_vehicle_status_pb_RC_IN_MODE_ARRAYSIZE ((px4_vehicle_status_pb_RC_IN_MODE)(px4_vehicle_status_pb_RC_IN_MODE_RC_IN_MODE_GENERATED+1))

/* Struct definitions */
typedef struct _px4_vehicle_status_pb {
    uint64_t timestamp;
    uint32_t system_id;
    uint32_t component_id;
    uint32_t onboard_control_sensors_present;
    uint32_t onboard_control_sensors_enabled;
    uint32_t onboard_control_sensors_health;
    uint32_t nav_state;
    uint32_t arming_state;
    uint32_t hil_state;
    bool failsafe;
    uint32_t system_type;
    bool is_rotary_wing;
    bool is_vtol;
    bool vtol_fw_permanent_stab;
    bool in_transition_mode;
    bool rc_signal_lost;
    uint32_t rc_input_mode;
    bool data_link_lost;
    uint32_t data_link_lost_counter;
    bool engine_failure;
    bool engine_failure_cmd;
    bool mission_failure;
/* @@protoc_insertion_point(struct:px4_vehicle_status_pb) */
} px4_vehicle_status_pb;

/* Default values for struct fields */

/* Initializer values for message structs */
#define px4_vehicle_status_pb_init_default       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define px4_vehicle_status_pb_init_zero          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define px4_vehicle_status_pb_timestamp_tag      1
#define px4_vehicle_status_pb_system_id_tag      2
#define px4_vehicle_status_pb_component_id_tag   3
#define px4_vehicle_status_pb_onboard_control_sensors_present_tag 4
#define px4_vehicle_status_pb_onboard_control_sensors_enabled_tag 5
#define px4_vehicle_status_pb_onboard_control_sensors_health_tag 6
#define px4_vehicle_status_pb_nav_state_tag      7
#define px4_vehicle_status_pb_arming_state_tag   8
#define px4_vehicle_status_pb_hil_state_tag      9
#define px4_vehicle_status_pb_failsafe_tag       10
#define px4_vehicle_status_pb_system_type_tag    11
#define px4_vehicle_status_pb_is_rotary_wing_tag 12
#define px4_vehicle_status_pb_is_vtol_tag        13
#define px4_vehicle_status_pb_vtol_fw_permanent_stab_tag 14
#define px4_vehicle_status_pb_in_transition_mode_tag 15
#define px4_vehicle_status_pb_rc_signal_lost_tag 16
#define px4_vehicle_status_pb_rc_input_mode_tag  17
#define px4_vehicle_status_pb_data_link_lost_tag 18
#define px4_vehicle_status_pb_data_link_lost_counter_tag 19
#define px4_vehicle_status_pb_engine_failure_tag 20
#define px4_vehicle_status_pb_engine_failure_cmd_tag 21
#define px4_vehicle_status_pb_mission_failure_tag 22

/* Struct field encoding specification for nanopb */
extern const pb_field_t px4_vehicle_status_pb_fields[23];

/* Maximum encoded size of messages (where known) */
#define px4_vehicle_status_pb_size               104

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define VEHICLE_STATUS_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
