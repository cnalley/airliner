/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.6 at Wed Oct 26 00:46:16 2016. */

#ifndef PB_SENSOR_BARO_PB_H_INCLUDED
#define PB_SENSOR_BARO_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _px4_sensor_baro_pb {
    uint64_t timestamp;
    uint64_t error_count;
    float pressure;
    float altitude;
    float temperature;
/* @@protoc_insertion_point(struct:px4_sensor_baro_pb) */
} px4_sensor_baro_pb;

/* Default values for struct fields */

/* Initializer values for message structs */
#define px4_sensor_baro_pb_init_default          {0, 0, 0, 0, 0}
#define px4_sensor_baro_pb_init_zero             {0, 0, 0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define px4_sensor_baro_pb_timestamp_tag         1
#define px4_sensor_baro_pb_error_count_tag       2
#define px4_sensor_baro_pb_pressure_tag          3
#define px4_sensor_baro_pb_altitude_tag          4
#define px4_sensor_baro_pb_temperature_tag       5

/* Struct field encoding specification for nanopb */
extern const pb_field_t px4_sensor_baro_pb_fields[6];

/* Maximum encoded size of messages (where known) */
#define px4_sensor_baro_pb_size                  37

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define SENSOR_BARO_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
