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

#ifndef NAV_TBLDEFS_H
#define NAV_TBLDEFS_H

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
#include "nav_platform_cfg.h"

/************************************************************************
 ** Local Defines
 *************************************************************************/

/**
 * \brief Defines the table identification name used for the
 * configuration table registration.
 */
#define NAV_CONFIG_TABLENAME ("CONFIG_TBL")

/** \brief Definition for a single config table entry */
typedef struct
{
    /** \navcfg NAV_ACC_RAD
     *
     *  \brief Default Accepted Radius.
     *
     *  \par Limits:
     *       Min > Max (incr.) 0.05 > 200.0 , default 2.0.
     */
    float NAV_ACC_RAD;

    /** \navcfg NAV_ALT_RAD
     *
     *  \brief Altitude Acceptance Radius.
     *
     *  \par Limits:
     *       Min > Max (incr.) 0.05 > 200 , default 0.8.
     */
    float NAV_ALT_RAD;

    /** \navcfg NAV_LOITER_RAD
     *
     *  \brief The Loiter Radius.
     *
     *  \par Limits:
     *       Min > Max (incr.) 25 > 1000 , default 50.0.
     */
    float NAV_LOITER_RAD;

    /** \navcfg NAV_MIS_TAKEOFF_ALT
     *
     *  \brief Take-off Altitude.
     *
     *  \par Limits:
     *       Min > Max (incr.) 0 > 80 , default 2.5.
     */
    float NAV_MIS_TAKEOFF_ALT;

    /** \navcfg NAV_MIS_YAW_ERR
     *
     *  \brief Max yaw error in degrees needed for waypoint heading acceptance.
     *
     *  \par Limits:
     *       Min > Max (incr.) 0 > 90 , default 12.0.
     */
    float NAV_MIS_YAW_ERR;

    /** \navcfg NAV_MIS_YAW_TMT
     *
     *  \brief Time in seconds we wait on reaching target heading at a waypoint if it is forced.
     *
     *  \par Limits:
     *       Min > Max (incr.) -1 > 20 , default -1.0.
     */
    float NAV_MIS_YAW_TMT;

    /** \navcfg NAV_MIS_LTRMIN_ALT
     *
     *  \brief Minimum Loiter Altitude.
     *
     *  \par Limits:
     *       Min > Max (incr.) -1 > 80 , default 1.20.
     */
    float NAV_MIS_LTRMIN_ALT;

    /** \navcfg NAV_RTL_RETURN_ALT
     *
     *  \brief RTL Altitude.
     *
     *  \par Limits:
     *       Min > Max (incr.) 0 > 150 , default 30.0.
     */
    float NAV_RTL_RETURN_ALT;

    /** \navcfg NAV_RTL_DESCEND_ALT
     *
     *  \brief RTL Loiter Altitude.
     *
     *  \par Limits:
     *       Min > Max (incr.) 2 > 100 , default 10.0.
     */
    float NAV_RTL_DESCEND_ALT;

    /** \navcfg NAV_RTL_LAND_DELAY
     *
     *  \brief RTL Delay.
     *
     *  \par Limits:
     *       Min > Max (incr.) -1 > 300 , default 0.0.
     */
    float NAV_RTL_LAND_DELAY;

    /** \navcfg NAV_RTL_MIN_DIST
     *
     *  \brief Minimum distance to trigger rising to a safe altitude.
     *
     *  \par Limits:
     *       Min > Max (incr.) 0.5 > 20 , default 5.0.
     */
    float NAV_RTL_MIN_DIST;

}NAV_ConfigTbl_t;

#ifdef __cplusplus
}
#endif

#endif /* NAV_TBLDEFS_H */

/************************/
/*  End of File Comment */
/************************/