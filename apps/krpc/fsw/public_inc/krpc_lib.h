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

#ifndef KRPC_LIB_H
#define KRPC_LIB_H

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


/************************************************************************
** Local Defines
*************************************************************************/

/************************************************************************
** KRPC Command Codes
*************************************************************************/

#define KRPC_ENGAGE_RCS_CC           (2)

#define KRPC_DISENGAGE_RCS_CC        (3)

#define KRPC_ENGAGE_SAS_CC           (4)

#define KRPC_DISENGAGE_SAS_CC        (5)

#define KRPC_ACTIVATE_NEXT_STAGE_CC  (6)

#define KRPC_ENGAGE_AUTOPILOT_CC     (7)

/************************************************************************
** Local Structure Declarations
*************************************************************************/

/** 
**  \brief KRPC autopilot target pitch and heading.
*/
typedef struct
{
    uint8  ucCmdHeader[CFE_SB_CMD_HDR_SIZE];
    float  TargetPitch;
    float  TargetHeading;
} KRPC_TargetPitchAndHeadingCmd_t;

typedef struct
{
    uint8  ucCmdHeader[CFE_SB_CMD_HDR_SIZE];
    uint8  Mode;
} KRPC_SasModeCmd_t;

/** 
**  \brief KRPC set throttle command (percent).
*/
typedef struct
{
    /** \brief cFE SB Cmd Msg Hdr */
    uint8  ucCmdHeader[CFE_SB_CMD_HDR_SIZE];
    /** \brief Throttle. */
    float  Throttle;
} KRPC_SetThrottleCmd_t;


/** 
**  \brief KRPC mean altitude ASL from center of mass.
*/
typedef struct
{
    /** \brief cFE SB Tlm Msg Hdr */
    uint8              TlmHeader[CFE_SB_TLM_HDR_SIZE];
    /** \brief Altitude. */
    double              Altitude;   
} KRPC_MeanAltitudeTlm_t;


/** 
**  \brief KRPC rotation quaternion.
*/
typedef struct
{
    /** \brief cFE SB Tlm Msg Hdr */
    uint8              TlmHeader[CFE_SB_TLM_HDR_SIZE];
    struct
    {
        /** \brief X. */
        double             X;   
        /** \brief Y. */
        double             Y;
        /** \brief Z. */
        double             Z;
        /** \brief W. */
        double             W;
    } Rotation;
} KRPC_RotationTlm_t;


/** 
**  \brief KRPC velocity in the given reference frame.
*/
typedef struct
{
    /** \brief cFE SB Tlm Msg Hdr */
    uint8              TlmHeader[CFE_SB_TLM_HDR_SIZE];
    struct
    {
        /** \brief X. */
        double             X;   
        /** \brief Y. */
        double             Y;
        /** \brief Z. */
        double             Z;
    } Velocity;
} KRPC_VelocityTlm_t;


/** 
**  \brief KRPC mission elapsed time.
*/
typedef struct
{
    /** \brief cFE SB Tlm Msg Hdr */
    uint8              TlmHeader[CFE_SB_TLM_HDR_SIZE];
    /** \brief elapsed time in seconds. */
    double             Met;   
} KRPC_MetTlm_t;


/** 
**  \brief KRPC universal time.
*/
typedef struct
{
    /** \brief cFE SB Tlm Msg Hdr */
    uint8              TlmHeader[CFE_SB_TLM_HDR_SIZE];
    /** \brief elapsed time in seconds. */
    double             Ut;   
} KRPC_UtTlm_t;


/** 
**  \brief KRPC G force acting on the vessel.
*/
typedef struct
{
    /** \brief cFE SB Tlm Msg Hdr */
    uint8              TlmHeader[CFE_SB_TLM_HDR_SIZE];
    /** \brief G force. */
    float             GForce;   
} KRPC_GForceTlm_t;


/** 
**  \brief KRPC apoapsis altitude.
*/
typedef struct
{
    /** \brief cFE SB Tlm Msg Hdr */
    uint8              TlmHeader[CFE_SB_TLM_HDR_SIZE];
    /** \brief Apoapsis altitude. */
    double             ApoapsisAltitude;   
} KRPC_ApoapsisAltitudeTlm_t;


/** 
**  \brief KRPC periapsis altitude.
*/
typedef struct
{
    /** \brief cFE SB Tlm Msg Hdr */
    uint8              TlmHeader[CFE_SB_TLM_HDR_SIZE];
    /** \brief Periapsis altitude. */
    double             PeriapsisAltitude;   
} KRPC_PeriapsisAltitudeTlm_t;

/** 
**  \brief KRPC solid fuel.
*/
typedef struct
{
    /** \brief cFE SB Tlm Msg Hdr */
    uint8              TlmHeader[CFE_SB_TLM_HDR_SIZE];
    /** \brief Fuel. */
    double             Fuel;   
} KRPC_SolidFuelTlm_t;


#ifdef __cplusplus
}
#endif

#endif /* KRPC_LIB_H */

/************************/
/*  End of File Comment */
/************************/
