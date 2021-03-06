/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.6 at Wed Oct 26 00:46:09 2016. */

#ifndef PB_DIFFERENTIAL_PRESSURE_PB_H_INCLUDED
#define PB_DIFFERENTIAL_PRESSURE_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _px4_differential_pressure_pb {
    uint64_t timestamp;
    uint64_t error_count;
    float differential_pressure_raw_pa;
    float differential_pressure_filtered_pa;
    float max_differential_pressure_pa;
    float temperature;
/* @@protoc_insertion_point(struct:px4_differential_pressure_pb) */
} px4_differential_pressure_pb;

/* Default values for struct fields */

/* Initializer values for message structs */
#define px4_differential_pressure_pb_init_default {0, 0, 0, 0, 0, 0}
#define px4_differential_pressure_pb_init_zero   {0, 0, 0, 0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define px4_differential_pressure_pb_timestamp_tag 1
#define px4_differential_pressure_pb_error_count_tag 2
#define px4_differential_pressure_pb_differential_pressure_raw_pa_tag 3
#define px4_differential_pressure_pb_differential_pressure_filtered_pa_tag 4
#define px4_differential_pressure_pb_max_differential_pressure_pa_tag 5
#define px4_differential_pressure_pb_temperature_tag 6

/* Struct field encoding specification for nanopb */
extern const pb_field_t px4_differential_pressure_pb_fields[7];

/* Maximum encoded size of messages (where known) */
#define px4_differential_pressure_pb_size        42

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define DIFFERENTIAL_PRESSURE_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
