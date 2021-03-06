
#ifndef VC_MISSION_CFG_H
#define VC_MISSION_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/*
** VC Mission Configuration Parameter Definitions
*/

/** \brief This defines how long the application waits for a SCH message.  This
 *         should normally be #CFE_SB_PEND_FOREVER, but can be a value in milliseconds. */
#define VC_SB_TIMEOUT         CFE_SB_PEND_FOREVER

#ifdef __cplusplus
}
#endif

#endif /* VC_MISSION_CFG_H */

/************************/
/*  End of File Comment */
/************************/
