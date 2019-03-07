/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.6 at Wed Oct 26 00:46:16 2016. */

#include "tecs_status.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t px4_tecs_status_pb_fields[18] = {
    PB_FIELD(  1, UINT64  , REQUIRED, STATIC  , FIRST, px4_tecs_status_pb, timestamp, timestamp, 0),
    PB_FIELD(  2, FLOAT   , REQUIRED, STATIC  , OTHER, px4_tecs_status_pb, altitudeSp, timestamp, 0),
    PB_FIELD(  3, FLOAT   , REQUIRED, STATIC  , OTHER, px4_tecs_status_pb, altitude_filtered, altitudeSp, 0),
    PB_FIELD(  4, FLOAT   , REQUIRED, STATIC  , OTHER, px4_tecs_status_pb, flightPathAngleSp, altitude_filtered, 0),
    PB_FIELD(  5, FLOAT   , REQUIRED, STATIC  , OTHER, px4_tecs_status_pb, flightPathAngle, flightPathAngleSp, 0),
    PB_FIELD(  6, FLOAT   , REQUIRED, STATIC  , OTHER, px4_tecs_status_pb, flightPathAngleFiltered, flightPathAngle, 0),
    PB_FIELD(  7, FLOAT   , REQUIRED, STATIC  , OTHER, px4_tecs_status_pb, airspeedSp, flightPathAngleFiltered, 0),
    PB_FIELD(  8, FLOAT   , REQUIRED, STATIC  , OTHER, px4_tecs_status_pb, airspeed_filtered, airspeedSp, 0),
    PB_FIELD(  9, FLOAT   , REQUIRED, STATIC  , OTHER, px4_tecs_status_pb, airspeedDerivativeSp, airspeed_filtered, 0),
    PB_FIELD( 10, FLOAT   , REQUIRED, STATIC  , OTHER, px4_tecs_status_pb, airspeedDerivative, airspeedDerivativeSp, 0),
    PB_FIELD( 11, FLOAT   , REQUIRED, STATIC  , OTHER, px4_tecs_status_pb, totalEnergyError, airspeedDerivative, 0),
    PB_FIELD( 12, FLOAT   , REQUIRED, STATIC  , OTHER, px4_tecs_status_pb, energyDistributionError, totalEnergyError, 0),
    PB_FIELD( 13, FLOAT   , REQUIRED, STATIC  , OTHER, px4_tecs_status_pb, totalEnergyRateError, energyDistributionError, 0),
    PB_FIELD( 14, FLOAT   , REQUIRED, STATIC  , OTHER, px4_tecs_status_pb, energyDistributionRateError, totalEnergyRateError, 0),
    PB_FIELD( 15, FLOAT   , REQUIRED, STATIC  , OTHER, px4_tecs_status_pb, throttle_integ, energyDistributionRateError, 0),
    PB_FIELD( 16, FLOAT   , REQUIRED, STATIC  , OTHER, px4_tecs_status_pb, pitch_integ, throttle_integ, 0),
    PB_FIELD( 17, UENUM   , REQUIRED, STATIC  , OTHER, px4_tecs_status_pb, mode, pitch_integ, 0),
    PB_LAST_FIELD
};


/* @@protoc_insertion_point(eof) */
