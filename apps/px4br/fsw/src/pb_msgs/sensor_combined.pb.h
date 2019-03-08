/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.6 at Wed Oct 26 00:46:16 2016. */

#ifndef PB_SENSOR_COMBINED_PB_H_INCLUDED
#define PB_SENSOR_COMBINED_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _px4_sensor_combined_pb_RELATIVE_TIMESTAMP {
    px4_sensor_combined_pb_RELATIVE_TIMESTAMP_RELATIVE_TIMESTAMP_INVALID = 2147483647
} px4_sensor_combined_pb_RELATIVE_TIMESTAMP;
#define _px4_sensor_combined_pb_RELATIVE_TIMESTAMP_MIN px4_sensor_combined_pb_RELATIVE_TIMESTAMP_RELATIVE_TIMESTAMP_INVALID
#define _px4_sensor_combined_pb_RELATIVE_TIMESTAMP_MAX px4_sensor_combined_pb_RELATIVE_TIMESTAMP_RELATIVE_TIMESTAMP_INVALID
#define _px4_sensor_combined_pb_RELATIVE_TIMESTAMP_ARRAYSIZE ((px4_sensor_combined_pb_RELATIVE_TIMESTAMP)(px4_sensor_combined_pb_RELATIVE_TIMESTAMP_RELATIVE_TIMESTAMP_INVALID+1))

/* Struct definitions */
typedef struct _px4_sensor_combined_pb {
    uint64_t timestamp;
    pb_size_t gyro_rad_count;
    float gyro_rad[3];
    float gyro_integral_dt;
    int32_t accelerometer_timestamp_relative;
    pb_size_t accelerometer_m_s2_count;
    float accelerometer_m_s2[3];
    float accelerometer_integral_dt;
    int32_t magnetometer_timestamp_relative;
    pb_size_t magnetometer_ga_count;
    float magnetometer_ga[3];
    int32_t baro_timestamp_relative;
    float baro_alt_meter;
    float baro_temp_celcius;
/* @@protoc_insertion_point(struct:px4_sensor_combined_pb) */
} px4_sensor_combined_pb;

/* Default values for struct fields */

/* Initializer values for message structs */
#define px4_sensor_combined_pb_init_default      {0, 0, {0, 0, 0}, 0, 0, 0, {0, 0, 0}, 0, 0, 0, {0, 0, 0}, 0, 0, 0}
#define px4_sensor_combined_pb_init_zero         {0, 0, {0, 0, 0}, 0, 0, 0, {0, 0, 0}, 0, 0, 0, {0, 0, 0}, 0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define px4_sensor_combined_pb_timestamp_tag     1
#define px4_sensor_combined_pb_gyro_rad_tag      2
#define px4_sensor_combined_pb_gyro_integral_dt_tag 3
#define px4_sensor_combined_pb_accelerometer_timestamp_relative_tag 4
#define px4_sensor_combined_pb_accelerometer_m_s2_tag 5
#define px4_sensor_combined_pb_accelerometer_integral_dt_tag 6
#define px4_sensor_combined_pb_magnetometer_timestamp_relative_tag 7
#define px4_sensor_combined_pb_magnetometer_ga_tag 8
#define px4_sensor_combined_pb_baro_timestamp_relative_tag 9
#define px4_sensor_combined_pb_baro_alt_meter_tag 10
#define px4_sensor_combined_pb_baro_temp_celcius_tag 11

/* Struct field encoding specification for nanopb */
extern const pb_field_t px4_sensor_combined_pb_fields[12];

/* Maximum encoded size of messages (where known) */
#define px4_sensor_combined_pb_size              109

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define SENSOR_COMBINED_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif