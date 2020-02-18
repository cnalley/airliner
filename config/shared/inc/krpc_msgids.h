    
#ifndef KRPC_MSGIDS_H
#define KRPC_MSGIDS_H

#ifdef __cplusplus
extern "C" {
#endif

/***** TODO:  These Message ID values are default and may need to be changed
******        by the developer or mission integrator!
******/

#include "msg_ids.h"

/**
** \brief KRPC application-specific command MID
*/
#define KRPC_CMD_MID                 (0x18C0)

/**
** \brief Command for the application to send HK data
*/
#define KRPC_SEND_HK_MID             (0x18C1)

/**
** \brief Wakeup command for the application to perform processing
*/
#define KRPC_WAKEUP_MID              (0x18D0)

/**
** \brief Application-specific data output
*/
#define KRPC_OUT_DATA_MID            (0x18D1)

/**
** \brief Application housekeeping telemetry data
*/
#define KRPC_HK_TLM_MID              (0x08BB)


#ifdef __cplusplus
}
#endif

#endif /* KRPC_MSGIDS_H */

/************************/
/*  End of File Comment */
/************************/
