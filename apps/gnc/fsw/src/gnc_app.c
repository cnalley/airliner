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

/************************************************************************
** Pragmas
*************************************************************************/

/************************************************************************
** Includes
*************************************************************************/
#include <string.h>
#include <math.h>

#include "cfe.h"

#include "gnc_app.h"
#include "gnc_msg.h"
#include "gnc_version.h"

/************************************************************************
** Local Defines
*************************************************************************/

/************************************************************************
** Local Structure Declarations
*************************************************************************/

/************************************************************************
** External Global Variables
*************************************************************************/

/************************************************************************
** Global Variables
*************************************************************************/
GNC_AppData_t  GNC_AppData;

/************************************************************************
** Local Variables
*************************************************************************/

/************************************************************************
** Local Function Definitions
*************************************************************************/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Initialize event tables                                         */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int32 GNC_InitEvent()
{
    int32  iStatus=CFE_SUCCESS;
    int32  ind = 0;

    /* Initialize the event filter table.
     * Note: 0 is the CFE_EVS_NO_FILTER mask and event 0 is reserved (not used) */
    memset((void*)GNC_AppData.EventTbl, 0x00, sizeof(GNC_AppData.EventTbl));

    /* TODO: Choose the events you want to filter.  CFE_EVS_MAX_EVENT_FILTERS
     * limits the number of filters per app.  An explicit CFE_EVS_NO_FILTER 
     * (the default) has been provided as an example. */
    GNC_AppData.EventTbl[  ind].EventID = GNC_RESERVED_EID;
    GNC_AppData.EventTbl[ind++].Mask    = CFE_EVS_NO_FILTER;

    GNC_AppData.EventTbl[  ind].EventID = GNC_INF_EID;
    GNC_AppData.EventTbl[ind++].Mask    = CFE_EVS_NO_FILTER;

    GNC_AppData.EventTbl[  ind].EventID = GNC_CONFIG_TABLE_ERR_EID;
    GNC_AppData.EventTbl[ind++].Mask    = CFE_EVS_NO_FILTER;

    GNC_AppData.EventTbl[  ind].EventID = GNC_CDS_ERR_EID;
    GNC_AppData.EventTbl[ind++].Mask    = CFE_EVS_NO_FILTER;

    GNC_AppData.EventTbl[  ind].EventID = GNC_PIPE_ERR_EID;
    GNC_AppData.EventTbl[ind++].Mask    = CFE_EVS_NO_FILTER;

    GNC_AppData.EventTbl[  ind].EventID = GNC_MSGID_ERR_EID;
    GNC_AppData.EventTbl[ind++].Mask    = CFE_EVS_NO_FILTER;

    GNC_AppData.EventTbl[  ind].EventID = GNC_MSGLEN_ERR_EID;
    GNC_AppData.EventTbl[ind++].Mask    = CFE_EVS_NO_FILTER;

    /* Register the table with CFE */
    iStatus = CFE_EVS_Register(GNC_AppData.EventTbl,
                               GNC_EVT_CNT, CFE_EVS_BINARY_FILTER);
    if (iStatus != CFE_SUCCESS)
    {
        (void) CFE_ES_WriteToSysLog("GNC - Failed to register with EVS (0x%08X)\n", (unsigned int)iStatus);
    }

    return (iStatus);
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Initialize Message Pipes                                        */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int32 GNC_InitPipe()
{
    int32  iStatus=CFE_SUCCESS;

    /* Init schedule pipe and subscribe to wakeup messages */
    iStatus = CFE_SB_CreatePipe(&GNC_AppData.SchPipeId,
                                 GNC_SCH_PIPE_DEPTH,
                                 GNC_SCH_PIPE_NAME);
    if (iStatus == CFE_SUCCESS)
    {
        iStatus = CFE_SB_SubscribeEx(GNC_WAKEUP_MID, GNC_AppData.SchPipeId, CFE_SB_Default_Qos, GNC_SCH_PIPE_WAKEUP_RESERVED);

        if (iStatus != CFE_SUCCESS)
        {
            (void) CFE_EVS_SendEvent(GNC_INIT_ERR_EID, CFE_EVS_ERROR,
                                     "Sch Pipe failed to subscribe to GNC_WAKEUP_MID. (0x%08X)",
                                     (unsigned int)iStatus);
            goto GNC_InitPipe_Exit_Tag;
        }

        iStatus = CFE_SB_SubscribeEx(GNC_SEND_HK_MID, GNC_AppData.SchPipeId, CFE_SB_Default_Qos, GNC_SCH_PIPE_SEND_HK_RESERVED);

        if (iStatus != CFE_SUCCESS)
        {
            (void) CFE_EVS_SendEvent(GNC_INIT_ERR_EID, CFE_EVS_ERROR,
                                     "CMD Pipe failed to subscribe to GNC_SEND_HK_MID. (0x%08X)",
                                     (unsigned int)iStatus);
            goto GNC_InitPipe_Exit_Tag;
        }

        iStatus = CFE_SB_SubscribeEx(KRPC_ALTITUDE_TLM_MID, GNC_AppData.SchPipeId, CFE_SB_Default_Qos, GNC_SCH_PIPE_ALTITUDE_TLM_RESERVED);
        if (iStatus != CFE_SUCCESS)
        {
            (void) CFE_EVS_SendEvent(GNC_INIT_ERR_EID, CFE_EVS_ERROR,
                                     "CMD Pipe failed to subscribe to KRPC_ALTITUDE_TLM_MID. (0x%08X)",
                                     (unsigned int)iStatus);
            goto GNC_InitPipe_Exit_Tag;
        }
        iStatus = CFE_SB_SubscribeEx(KRPC_APOAPSIS_TLM_MID, GNC_AppData.SchPipeId, CFE_SB_Default_Qos, GNC_SCH_PIPE_APOAPSIS_TLM_RESERVED);
        if (iStatus != CFE_SUCCESS)
        {
            (void) CFE_EVS_SendEvent(GNC_INIT_ERR_EID, CFE_EVS_ERROR,
                                     "CMD Pipe failed to subscribe to KRPC_APOAPSIS_TLM_MID. (0x%08X)",
                                     (unsigned int)iStatus);
            goto GNC_InitPipe_Exit_Tag;
        }
        iStatus = CFE_SB_SubscribeEx(KRPC_SOLID_FUEL_TLM_MID, GNC_AppData.SchPipeId, CFE_SB_Default_Qos, GNC_SCH_PIPE_SOLID_FUEL_TLM_RESERVED);
        if (iStatus != CFE_SUCCESS)
        {
            (void) CFE_EVS_SendEvent(GNC_INIT_ERR_EID, CFE_EVS_ERROR,
                                     "CMD Pipe failed to subscribe to KRPC_SOLID_FUEL_TLM_MID. (0x%08X)",
                                     (unsigned int)iStatus);
            goto GNC_InitPipe_Exit_Tag;
        }
    }
    else
    {
        (void) CFE_EVS_SendEvent(GNC_INIT_ERR_EID, CFE_EVS_ERROR,
                                 "Failed to create SCH pipe (0x%08X)",
                                 (unsigned int)iStatus);
        goto GNC_InitPipe_Exit_Tag;
    }

    /* Init command pipe and subscribe to command messages */
    iStatus = CFE_SB_CreatePipe(&GNC_AppData.CmdPipeId,
                                 GNC_CMD_PIPE_DEPTH,
                                 GNC_CMD_PIPE_NAME);
    if (iStatus == CFE_SUCCESS)
    {
        /* Subscribe to command messages */
        iStatus = CFE_SB_Subscribe(GNC_CMD_MID, GNC_AppData.CmdPipeId);

        if (iStatus != CFE_SUCCESS)
        {
            (void) CFE_EVS_SendEvent(GNC_INIT_ERR_EID, CFE_EVS_ERROR,
                                     "CMD Pipe failed to subscribe to GNC_CMD_MID. (0x%08X)",
                                     (unsigned int)iStatus);
            goto GNC_InitPipe_Exit_Tag;
        }
    }
    else
    {
        (void) CFE_EVS_SendEvent(GNC_INIT_ERR_EID, CFE_EVS_ERROR,
                                 "Failed to create CMD pipe (0x%08X)",
                                 (unsigned int)iStatus);
        goto GNC_InitPipe_Exit_Tag;
    }

    /* Init data pipe and subscribe to messages on the data pipe */
    iStatus = CFE_SB_CreatePipe(&GNC_AppData.DataPipeId,
                                 GNC_DATA_PIPE_DEPTH,
                                 GNC_DATA_PIPE_NAME);
    if (iStatus == CFE_SUCCESS)
    {
        /* TODO:  Add CFE_SB_Subscribe() calls for other apps' output data here.
        **
        ** Examples:
        **     CFE_SB_Subscribe(GNCEXEC_OUT_DATA_MID, GNC_AppData.DataPipeId);
        */
    }
    else
    {
        (void) CFE_EVS_SendEvent(GNC_INIT_ERR_EID, CFE_EVS_ERROR,
                                 "Failed to create Data pipe (0x%08X)",
                                 (unsigned int)iStatus);
        goto GNC_InitPipe_Exit_Tag;
    }

GNC_InitPipe_Exit_Tag:
    return (iStatus);
}
    

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Initialize Global Variables                                     */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int32 GNC_InitData()
{
    int32  iStatus=CFE_SUCCESS;

    /* Init current value table */
    CFE_PSP_MemSet((void*)&GNC_AppData, 0x00, sizeof(&GNC_AppData.CVT));

    /* Init input data */
    memset((void*)&GNC_AppData.InData, 0x00, sizeof(GNC_AppData.InData));

    /* Init output data */
    memset((void*)&GNC_AppData.OutData, 0x00, sizeof(GNC_AppData.OutData));
    CFE_SB_InitMsg(&GNC_AppData.OutData,
                   GNC_OUT_DATA_MID, sizeof(GNC_AppData.OutData), TRUE);

    /* Init housekeeping packet */
    memset((void*)&GNC_AppData.HkTlm, 0x00, sizeof(GNC_AppData.HkTlm));
    CFE_SB_InitMsg(&GNC_AppData.HkTlm,
                   GNC_HK_TLM_MID, sizeof(GNC_AppData.HkTlm), TRUE);

    /* Init no arg cmd */
    CFE_SB_InitMsg(&GNC_AppData.NoArgCmd,
                   KRPC_CMD_MID, sizeof(GNC_AppData.NoArgCmd), TRUE);

    /* Init target pitch and heading command */
    CFE_SB_InitMsg(&GNC_AppData.KRPC_TargetPitchAndHeadingCmd,
                   KRPC_TARGET_PITCH_HEADING_MID, sizeof(GNC_AppData.KRPC_TargetPitchAndHeadingCmd), TRUE);

    /* Init throttle command */
    CFE_SB_InitMsg(&GNC_AppData.KRPC_SetThrottleCmd,
                   KRPC_SET_THROTTLE_MID, sizeof(GNC_AppData.KRPC_SetThrottleCmd), TRUE);


    return (iStatus);
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* GNC initialization                                              */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int32 GNC_InitApp()
{
    int32  iStatus   = CFE_SUCCESS;
    int8   hasEvents = 0;

    iStatus = GNC_InitEvent();
    if (iStatus != CFE_SUCCESS)
    {
        (void) CFE_ES_WriteToSysLog("GNC - Failed to init events (0x%08X)\n", (unsigned int)iStatus);
        goto GNC_InitApp_Exit_Tag;
    }
    else
    {
        hasEvents = 1;
    }

    iStatus = GNC_InitPipe();
    if (iStatus != CFE_SUCCESS)
    {
        (void) CFE_EVS_SendEvent(GNC_INIT_ERR_EID, CFE_EVS_ERROR,
                                 "Failed to init pipes (0x%08X)",
                                 (unsigned int)iStatus);
        goto GNC_InitApp_Exit_Tag;
    }

    iStatus = GNC_InitData();
    if (iStatus != CFE_SUCCESS)
    {
        (void) CFE_EVS_SendEvent(GNC_INIT_ERR_EID, CFE_EVS_ERROR,
                                 "Failed to init data (0x%08X)",
                                 (unsigned int)iStatus);
        goto GNC_InitApp_Exit_Tag;
    }

    iStatus = GNC_InitConfigTbl();
    if (iStatus != CFE_SUCCESS)
    {
        (void) CFE_EVS_SendEvent(GNC_INIT_ERR_EID, CFE_EVS_ERROR,
                                 "Failed to init config tables (0x%08X)",
                                 (unsigned int)iStatus);
        goto GNC_InitApp_Exit_Tag;
    }

    iStatus = GNC_InitCdsTbl();
    if (iStatus != CFE_SUCCESS)
    {
        (void) CFE_EVS_SendEvent(GNC_INIT_ERR_EID, CFE_EVS_ERROR,
                                 "Failed to init CDS table (0x%08X)",
                                 (unsigned int)iStatus);
        goto GNC_InitApp_Exit_Tag;
    }

    /* Send initial commands to KRPC */
    GNC_InitState();

GNC_InitApp_Exit_Tag:
    if (iStatus == CFE_SUCCESS)
    {
        (void) CFE_EVS_SendEvent(GNC_INIT_INF_EID, CFE_EVS_INFORMATION,
                                 "Initialized.  Version %d.%d.%d.%d",
                                 GNC_MAJOR_VERSION,
                                 GNC_MINOR_VERSION,
                                 GNC_REVISION,
                                 GNC_MISSION_REV);
    }
    else
    {
        if (hasEvents == 1)
        {
            (void) CFE_EVS_SendEvent(GNC_INIT_ERR_EID, CFE_EVS_ERROR, "Application failed to initialize");
        }
        else
        {
            (void) CFE_ES_WriteToSysLog("GNC - Application failed to initialize\n");
        }
    }

    return (iStatus);
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Receive and Process Messages                                    */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int32 GNC_RcvMsg(int32 iBlocking)
{
    int32           iStatus=CFE_SUCCESS;
    CFE_SB_Msg_t*   MsgPtr=NULL;
    CFE_SB_MsgId_t  MsgId;

    /* Stop Performance Log entry */
    CFE_ES_PerfLogExit(GNC_MAIN_TASK_PERF_ID);

    /* Wait for WakeUp messages from scheduler */
    iStatus = CFE_SB_RcvMsg(&MsgPtr, GNC_AppData.SchPipeId, iBlocking);

    /* Start Performance Log entry */
    CFE_ES_PerfLogEntry(GNC_MAIN_TASK_PERF_ID);

    if (iStatus == CFE_SUCCESS)
    {
        MsgId = CFE_SB_GetMsgId(MsgPtr);
        switch (MsgId)
    {
            case GNC_WAKEUP_MID:
                GNC_ProcessNewCmds();
                GNC_ProcessNewData();
                GNC_ControlLoop();
                /* TODO:  Add more code here to handle other things when app wakes up */

                /* The last thing to do at the end of this Wakeup cycle should be to
                 * automatically publish new output. */
                GNC_SendOutData();
                break;

            case GNC_SEND_HK_MID:
                GNC_ReportHousekeeping();
                break;
                
            case KRPC_ALTITUDE_TLM_MID:
                CFE_PSP_MemCpy(&GNC_AppData.CVT.KRPC_MeanAltitudeTlm, 
                            MsgPtr, 
                            sizeof(GNC_AppData.CVT.KRPC_MeanAltitudeTlm));
                GNC_ControlLoop();
                break;

            case KRPC_APOAPSIS_TLM_MID:
            {
                CFE_PSP_MemCpy(&GNC_AppData.CVT.KRPC_ApoapsisAltitudeTlm, 
                            MsgPtr, 
                            sizeof(GNC_AppData.CVT.KRPC_ApoapsisAltitudeTlm));
                break;
            }
            case KRPC_SOLID_FUEL_TLM_MID:
            {
                CFE_PSP_MemCpy(&GNC_AppData.CVT.KRPC_SolidFuelTlm, 
                            MsgPtr, 
                            sizeof(GNC_AppData.CVT.KRPC_SolidFuelTlm));
                break;
            }
            default:
                (void) CFE_EVS_SendEvent(GNC_MSGID_ERR_EID, CFE_EVS_ERROR,
                                  "Recvd invalid SCH msgId (0x%04X)", (unsigned short)MsgId);
        }
    }
    else if (iStatus == CFE_SB_NO_MESSAGE)
    {
        /* TODO: If there's no incoming message, you can do something here, or 
         * nothing.  Note, this section is dead code only if the iBlocking arg
         * is CFE_SB_PEND_FOREVER. */
        iStatus = CFE_SUCCESS;
    }
    else if (iStatus == CFE_SB_TIME_OUT)
    {
        /* TODO: If there's no incoming message within a specified time (via the
         * iBlocking arg, you can do something here, or nothing.  
         * Note, this section is dead code only if the iBlocking arg
         * is CFE_SB_PEND_FOREVER. */
        iStatus = CFE_SUCCESS;
        GNC_SendOutData();
        GNC_ControlLoop();
    }
    else
    {
        /* TODO: This is an example of exiting on an error (either CFE_SB_BAD_ARGUMENT, or
         * CFE_SB_PIPE_RD_ERROR).
         */
        (void) CFE_EVS_SendEvent(GNC_PIPE_ERR_EID, CFE_EVS_ERROR,
                "SB pipe read error (0x%08X), app will exit", (unsigned int)iStatus);
        GNC_AppData.uiRunStatus= CFE_ES_APP_ERROR;
    }

    return (iStatus);
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Process Incoming Data                                           */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void GNC_ProcessNewData()
{
    int iStatus = CFE_SUCCESS;
    CFE_SB_Msg_t*   DataMsgPtr=NULL;
    CFE_SB_MsgId_t  DataMsgId;

    /* Process telemetry messages till the pipe is empty */
    while (1)
    {
        iStatus = CFE_SB_RcvMsg(&DataMsgPtr, GNC_AppData.DataPipeId, CFE_SB_POLL);
        if (iStatus == CFE_SUCCESS)
        {
            DataMsgId = CFE_SB_GetMsgId(DataMsgPtr);
            switch (DataMsgId)
            {
                /* TODO:  Add code to process all subscribed data here
                **
                ** Example:
                **     case NAV_OUT_DATA_MID:
                **         GNC_ProcessNavData(DataMsgPtr);
                **         break;
                */

                default:
                    (void) CFE_EVS_SendEvent(GNC_MSGID_ERR_EID, CFE_EVS_ERROR,
                                      "Recvd invalid data msgId (0x%04X)", (unsigned short)DataMsgId);
                    break;
            }
        }
        else if (iStatus == CFE_SB_NO_MESSAGE)
        {
            break;
        }
        else
        {
            (void) CFE_EVS_SendEvent(GNC_PIPE_ERR_EID, CFE_EVS_ERROR,
                  "Data pipe read error (0x%08X)", (unsigned int)iStatus);
            GNC_AppData.uiRunStatus = CFE_ES_APP_ERROR;
            break;
        }
    }
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Process Incoming Commands                                       */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void GNC_ProcessNewCmds()
{
    int iStatus = CFE_SUCCESS;
    CFE_SB_Msg_t*   CmdMsgPtr=NULL;
    CFE_SB_MsgId_t  CmdMsgId;

    /* Process command messages till the pipe is empty */
    while (1)
    {
        iStatus = CFE_SB_RcvMsg(&CmdMsgPtr, GNC_AppData.CmdPipeId, CFE_SB_POLL);
        if(iStatus == CFE_SUCCESS)
        {
            CmdMsgId = CFE_SB_GetMsgId(CmdMsgPtr);
            switch (CmdMsgId)
            {
                case GNC_CMD_MID:
                    GNC_ProcessNewAppCmds(CmdMsgPtr);
                    break;

                /* TODO:  Add code to process other subscribed commands here
                **
                ** Example:
                **     case CFE_TIME_DATA_CMD_MID:
                **         GNC_ProcessTimeDataCmd(CmdMsgPtr);
                **         break;
                */

                default:
                    /* Bump the command error counter for an unknown command.
                     * (This should only occur if it was subscribed to with this
                     *  pipe, but not handled in this switch-case.) */
                    GNC_AppData.HkTlm.usCmdErrCnt++;
                    (void) CFE_EVS_SendEvent(GNC_MSGID_ERR_EID, CFE_EVS_ERROR,
                                      "Recvd invalid CMD msgId (0x%04X)", (unsigned short)CmdMsgId);
                    break;
            }
        }
        else if (iStatus == CFE_SB_NO_MESSAGE)
        {
            break;
        }
        else
        {
            (void) CFE_EVS_SendEvent(GNC_PIPE_ERR_EID, CFE_EVS_ERROR,
                  "CMD pipe read error (0x%08X)", (unsigned int)iStatus);
            GNC_AppData.uiRunStatus = CFE_ES_APP_ERROR;
            break;
        }
    }
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Process GNC Commands                                            */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void GNC_ProcessNewAppCmds(CFE_SB_Msg_t* MsgPtr)
{
    uint32  uiCmdCode=0;

    if (MsgPtr != NULL)
    {
        uiCmdCode = CFE_SB_GetCmdCode(MsgPtr);
        switch (uiCmdCode)
        {
            case GNC_NOOP_CC:
                GNC_AppData.HkTlm.usCmdCnt++;
                (void) CFE_EVS_SendEvent(GNC_CMD_INF_EID, CFE_EVS_INFORMATION,
                                  "Recvd NOOP cmd (%u), Version %d.%d.%d.%d",
                                  (unsigned int)uiCmdCode,
                                  GNC_MAJOR_VERSION,
                                  GNC_MINOR_VERSION,
                                  GNC_REVISION,
                                  GNC_MISSION_REV);
                break;

            case GNC_RESET_CC:
                GNC_AppData.HkTlm.usCmdCnt = 0;
                GNC_AppData.HkTlm.usCmdErrCnt = 0;
                (void) CFE_EVS_SendEvent(GNC_CMD_INF_EID, CFE_EVS_INFORMATION,
                                  "Recvd RESET cmd (%u)", (unsigned int)uiCmdCode);
                break;

            /* TODO:  Add code to process the rest of the GNC commands here */

            default:
                GNC_AppData.HkTlm.usCmdErrCnt++;
                (void) CFE_EVS_SendEvent(GNC_MSGID_ERR_EID, CFE_EVS_ERROR,
                                  "Recvd invalid cmdId (%u)", (unsigned int)uiCmdCode);
                break;
        }
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Send GNC Housekeeping                                           */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void GNC_ReportHousekeeping()
{
    /* TODO:  Add code to update housekeeping data, if needed, here.  */

    CFE_SB_TimeStampMsg((CFE_SB_Msg_t*)&GNC_AppData.HkTlm);
    int32 iStatus = CFE_SB_SendMsg((CFE_SB_Msg_t*)&GNC_AppData.HkTlm);
    if (iStatus != CFE_SUCCESS)
    {
        /* TODO: Decide what to do if the send message fails. */
    }
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Publish Output Data                                             */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void GNC_SendOutData()
{
    int32 iStatus = 0;
    /* TODO:  Add code to update output data, if needed, here.  */

    CFE_SB_TimeStampMsg((CFE_SB_Msg_t*)&GNC_AppData.OutData);
    iStatus = CFE_SB_SendMsg((CFE_SB_Msg_t*)&GNC_AppData.OutData);
    if (iStatus != CFE_SUCCESS)
    {
        /* TODO: Decide what to do if the send message fails. */
    }
}

void GNC_InitState()
{
    int32 iStatus = 0;
    CFE_SB_CmdHdr_t *CmdHdrPtr = (CFE_SB_CmdHdr_t *)&GNC_AppData.NoArgCmd;

    /* Start solid fuel with non-zero value */
    GNC_AppData.CVT.KRPC_SolidFuelTlm.Fuel = 1.0f;

    /* Set autopilot target pitch and heading. */
    GNC_AppData.KRPC_TargetPitchAndHeadingCmd.TargetPitch = 90.0f;
    GNC_AppData.KRPC_TargetPitchAndHeadingCmd.TargetHeading = 90.0f;
    CFE_SB_TimeStampMsg((CFE_SB_Msg_t*)&GNC_AppData.KRPC_TargetPitchAndHeadingCmd);
    iStatus = CFE_SB_SendMsg((CFE_SB_Msg_t*)&GNC_AppData.KRPC_TargetPitchAndHeadingCmd);
    if (iStatus != CFE_SUCCESS)
    {
        /* TODO: Decide what to do if the send message fails. */
    }

    /* Engage autopilot */
    CCSDS_WR_FC(CmdHdrPtr->Sec, KRPC_ENGAGE_AUTOPILOT_CC);
    CFE_SB_TimeStampMsg((CFE_SB_Msg_t*)&GNC_AppData.NoArgCmd);
    iStatus = CFE_SB_SendMsg((CFE_SB_Msg_t*)&GNC_AppData.NoArgCmd);
    if (iStatus != CFE_SUCCESS)
    {
        /* TODO: Decide what to do if the send message fails. */
    }

    /* Set throttle 100% */
    GNC_AppData.KRPC_SetThrottleCmd.Throttle = 1.0f;
    CFE_SB_TimeStampMsg((CFE_SB_Msg_t*)&GNC_AppData.KRPC_SetThrottleCmd);
    iStatus = CFE_SB_SendMsg((CFE_SB_Msg_t*)&GNC_AppData.KRPC_SetThrottleCmd);
    if (iStatus != CFE_SUCCESS)
    {
        /* TODO: Decide what to do if the send message fails. */
    }
}

void GNC_ControlLoop()
{
    const float turn_start_altitude = 250.0f;
    const float turn_end_altitude   = 45000.0f;
    const float target_altitude     = 150000.0f;
    const float targeting_altitude  = 50000.0f;
    static double turn_angle = 0.0f;
    static double burn_time = 0.0f;
    static double burn_ut = 0.0f;
    static double remaining_burn_time = 0.0f;
    static boolean once = FALSE;
    static boolean srbs_separated = FALSE;
    static int countDown = 100;

    /* Current altitude */
    float altitude = GNC_AppData.CVT.KRPC_MeanAltitudeTlm.Altitude;
    float apoapsis = GNC_AppData.CVT.KRPC_ApoapsisAltitudeTlm.ApoapsisAltitude;

    /* Countdown to launch */
    countDown--;

    /* Launch */
    if(FALSE == once && 0 == countDown)
    {
        int32 iStatus = 0;
        CFE_SB_CmdHdr_t *CmdHdrPtr = (CFE_SB_CmdHdr_t *)&GNC_AppData.NoArgCmd;
        /* Activate next stage */
        CCSDS_WR_FC(CmdHdrPtr->Sec, KRPC_ACTIVATE_NEXT_STAGE_CC);
        CFE_SB_TimeStampMsg((CFE_SB_Msg_t*)&GNC_AppData.NoArgCmd);
        iStatus = CFE_SB_SendMsg((CFE_SB_Msg_t*)&GNC_AppData.NoArgCmd);
        if (iStatus != CFE_SUCCESS)
        {
            /* TODO: Decide what to do if the send message fails. */
        }
        once = TRUE;
    }

    /* Gravity turn */
    if (altitude > turn_start_altitude && altitude < turn_end_altitude)
    {
        double frac = (altitude - turn_start_altitude)
                    / (turn_end_altitude - turn_start_altitude);
        double new_turn_angle = frac * 90.0;
        if (fabs(new_turn_angle - turn_angle) > 0.5)
        {
            turn_angle = new_turn_angle;
            GNC_AppData.KRPC_TargetPitchAndHeadingCmd.TargetPitch = 90.0f - turn_angle;
            GNC_AppData.KRPC_TargetPitchAndHeadingCmd.TargetHeading = 90.0f;
            CFE_SB_TimeStampMsg((CFE_SB_Msg_t*)&GNC_AppData.KRPC_TargetPitchAndHeadingCmd);
            (void) CFE_SB_SendMsg((CFE_SB_Msg_t*)&GNC_AppData.KRPC_TargetPitchAndHeadingCmd);
        }
    }

    /* Separate SRBs when finished */
    if (!srbs_separated)
    {
        if (GNC_AppData.CVT.KRPC_SolidFuelTlm.Fuel < 0.1)
        {
            int32 iStatus = 0;
            CFE_SB_CmdHdr_t *CmdHdrPtr = (CFE_SB_CmdHdr_t *)&GNC_AppData.NoArgCmd;
            /* Activate next stage */
            CCSDS_WR_FC(CmdHdrPtr->Sec, KRPC_ACTIVATE_NEXT_STAGE_CC);
            CFE_SB_TimeStampMsg((CFE_SB_Msg_t*)&GNC_AppData.NoArgCmd);
            iStatus = CFE_SB_SendMsg((CFE_SB_Msg_t*)&GNC_AppData.NoArgCmd);
            if (iStatus != CFE_SUCCESS)
            {
                /* TODO: Decide what to do if the send message fails. */
            }
            srbs_separated = TRUE;
        }
    }
    
    /* Decrease throttle when approaching target apoapsis */
    if (apoapsis > target_altitude * 0.9)
    {
        int32 iStatus = 0;
        /* Set throttle 25% */
        GNC_AppData.KRPC_SetThrottleCmd.Throttle = 0.25f;
        CFE_SB_TimeStampMsg((CFE_SB_Msg_t*)&GNC_AppData.KRPC_SetThrottleCmd);
        iStatus = CFE_SB_SendMsg((CFE_SB_Msg_t*)&GNC_AppData.KRPC_SetThrottleCmd);
        if (iStatus != CFE_SUCCESS)
        {
            /* TODO: Decide what to do if the send message fails. */
        }
    }
    
    /* Disable engines when target apoapsis is reached */
    if (apoapsis >= target_altitude)
    {
        int32 iStatus = 0;
        /* Set throttle 0% */
        GNC_AppData.KRPC_SetThrottleCmd.Throttle = 0.0f;
        CFE_SB_TimeStampMsg((CFE_SB_Msg_t*)&GNC_AppData.KRPC_SetThrottleCmd);
        iStatus = CFE_SB_SendMsg((CFE_SB_Msg_t*)&GNC_AppData.KRPC_SetThrottleCmd);
        if (iStatus != CFE_SUCCESS)
        {
            /* TODO: Decide what to do if the send message fails. */
        }
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Verify Command Length                                           */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

boolean GNC_VerifyCmdLength(CFE_SB_Msg_t* MsgPtr,
                           uint16 usExpectedLen)
{
    boolean bResult  = TRUE;
    uint16  usMsgLen = 0;

    if (MsgPtr != NULL)
    {
        usMsgLen = CFE_SB_GetTotalMsgLength(MsgPtr);

        if (usExpectedLen != usMsgLen)
        {
            bResult = FALSE;
            CFE_SB_MsgId_t MsgId = CFE_SB_GetMsgId(MsgPtr);
            uint16 usCmdCode = CFE_SB_GetCmdCode(MsgPtr);

            (void) CFE_EVS_SendEvent(GNC_MSGLEN_ERR_EID, CFE_EVS_ERROR,
                              "Rcvd invalid msgLen: msgId=0x%08X, cmdCode=%d, "
                              "msgLen=%d, expectedLen=%d",
                              MsgId, usCmdCode, usMsgLen, usExpectedLen);
            GNC_AppData.HkTlm.usCmdErrCnt++;
        }
    }

    return (bResult);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* GNC application entry point and main process loop               */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void GNC_AppMain()
{
    /* Register the application with Executive Services */
    GNC_AppData.uiRunStatus = CFE_ES_APP_RUN;

    int32 iStatus = CFE_ES_RegisterApp();
    if (iStatus != CFE_SUCCESS)
    {
        (void) CFE_ES_WriteToSysLog("GNC - Failed to register the app (0x%08X)\n", (unsigned int)iStatus);
    }

    /* Start Performance Log entry */
    CFE_ES_PerfLogEntry(GNC_MAIN_TASK_PERF_ID);

    /* Perform application initializations */
    if (iStatus == CFE_SUCCESS)
    {
        iStatus = GNC_InitApp();
    }

    if (iStatus == CFE_SUCCESS)
    {
        /* Do not perform performance monitoring on startup sync */
        CFE_ES_PerfLogExit(GNC_MAIN_TASK_PERF_ID);
        CFE_ES_WaitForStartupSync(GNC_STARTUP_TIMEOUT_MSEC);
        CFE_ES_PerfLogEntry(GNC_MAIN_TASK_PERF_ID);
    }
    else
    {
        GNC_AppData.uiRunStatus = CFE_ES_APP_ERROR;
    }

    /* Application main loop */
    while (CFE_ES_RunLoop(&GNC_AppData.uiRunStatus) == TRUE)
    {
        int32 iStatus = GNC_RcvMsg(GNC_SCH_PIPE_PEND_TIME);
        if (iStatus != CFE_SUCCESS)
        {
            /* TODO: Decide what to do for other return values in GNC_RcvMsg(). */
        }
        /* TODO: This is only a suggestion for when to update and save CDS table.
        ** Depends on the nature of the application, the frequency of update
        ** and save can be more or less independently.
        */
        GNC_UpdateCdsTbl();
        GNC_SaveCdsTbl();

        iStatus = GNC_AcquireConfigPointers();
        if(iStatus != CFE_SUCCESS)
        {
            /* We apparently tried to load a new table but failed.  Terminate the application. */
            GNC_AppData.uiRunStatus = CFE_ES_APP_ERROR;
        }
    }

    /* Stop Performance Log entry */
    CFE_ES_PerfLogExit(GNC_MAIN_TASK_PERF_ID);

    /* Exit the application */
    CFE_ES_ExitApp(GNC_AppData.uiRunStatus);
}

/************************/
/*  End of File Comment */
/************************/
