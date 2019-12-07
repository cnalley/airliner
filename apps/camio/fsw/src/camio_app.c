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

#include "cfe.h"

#include "camio_app.h"
#include "camio_msg.h"
#include "camio_version.h"
#include "camio_custom.h"

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
CAMIO_AppData_t  CAMIO_AppData;

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

int32 CAMIO_InitEvent()
{
    int32  iStatus=CFE_SUCCESS;
    int32  ind = 0;

    /* Initialize the event filter table.
     * Note: 0 is the CFE_EVS_NO_FILTER mask and event 0 is reserved (not used) */
    CFE_PSP_MemSet((void*)CAMIO_AppData.EventTbl, 0x00, sizeof(CAMIO_AppData.EventTbl));

    /* TODO: Choose the events you want to filter.  CFE_EVS_MAX_EVENT_FILTERS
     * limits the number of filters per app.  An explicit CFE_EVS_NO_FILTER 
     * (the default) has been provided as an example. */
    CAMIO_AppData.EventTbl[  ind].EventID = CAMIO_RESERVED_EID;
    CAMIO_AppData.EventTbl[ind++].Mask    = CFE_EVS_NO_FILTER;

    CAMIO_AppData.EventTbl[  ind].EventID = CAMIO_INF_EID;
    CAMIO_AppData.EventTbl[ind++].Mask    = CFE_EVS_NO_FILTER;

    CAMIO_AppData.EventTbl[  ind].EventID = CAMIO_CONFIG_TABLE_ERR_EID;
    CAMIO_AppData.EventTbl[ind++].Mask    = CFE_EVS_NO_FILTER;

    CAMIO_AppData.EventTbl[  ind].EventID = CAMIO_CDS_ERR_EID;
    CAMIO_AppData.EventTbl[ind++].Mask    = CFE_EVS_NO_FILTER;

    CAMIO_AppData.EventTbl[  ind].EventID = CAMIO_PIPE_ERR_EID;
    CAMIO_AppData.EventTbl[ind++].Mask    = CFE_EVS_NO_FILTER;

    CAMIO_AppData.EventTbl[  ind].EventID = CAMIO_MSGID_ERR_EID;
    CAMIO_AppData.EventTbl[ind++].Mask    = CFE_EVS_NO_FILTER;

    CAMIO_AppData.EventTbl[  ind].EventID = CAMIO_MSGLEN_ERR_EID;
    CAMIO_AppData.EventTbl[ind++].Mask    = CFE_EVS_NO_FILTER;

    /* Register the table with CFE */
    iStatus = CFE_EVS_Register(CAMIO_AppData.EventTbl,
                               CAMIO_EVT_CNT, CFE_EVS_BINARY_FILTER);
    if (iStatus != CFE_SUCCESS)
    {
        (void) CFE_ES_WriteToSysLog("CAMIO - Failed to register with EVS (0x%08X)\n", (unsigned int)iStatus);
    }

    return (iStatus);
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Initialize Message Pipes                                        */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int32 CAMIO_InitPipe()
{
    int32  iStatus=CFE_SUCCESS;

    /* Init schedule pipe and subscribe to wakeup messages */
    iStatus = CFE_SB_CreatePipe(&CAMIO_AppData.SchPipeId,
                                 CAMIO_SCH_PIPE_DEPTH,
                                 CAMIO_SCH_PIPE_NAME);
    if (iStatus == CFE_SUCCESS)
    {
        iStatus = CFE_SB_SubscribeEx(CAMIO_ACQUIRE_IMAGE_MID, CAMIO_AppData.SchPipeId, CFE_SB_Default_Qos, CAMIO_SCH_PIPE_WAKEUP_RESERVED);

        if (iStatus != CFE_SUCCESS)
        {
            (void) CFE_EVS_SendEvent(CAMIO_INIT_ERR_EID, CFE_EVS_ERROR,
                                     "Sch Pipe failed to subscribe to CAMIO_ACQUIRE_IMAGE_MID. (0x%08X)",
                                     (unsigned int)iStatus);
            goto CAMIO_InitPipe_Exit_Tag;
        }

        iStatus = CFE_SB_SubscribeEx(CAMIO_SEND_HK_MID, CAMIO_AppData.SchPipeId, CFE_SB_Default_Qos, CAMIO_SCH_PIPE_SEND_HK_RESERVED);

        if (iStatus != CFE_SUCCESS)
        {
            (void) CFE_EVS_SendEvent(CAMIO_INIT_ERR_EID, CFE_EVS_ERROR,
                                     "CMD Pipe failed to subscribe to CAMIO_SEND_HK_MID. (0x%08X)",
                                     (unsigned int)iStatus);
            goto CAMIO_InitPipe_Exit_Tag;
        }

    }
    else
    {
        (void) CFE_EVS_SendEvent(CAMIO_INIT_ERR_EID, CFE_EVS_ERROR,
                                 "Failed to create SCH pipe (0x%08X)",
                                 (unsigned int)iStatus);
        goto CAMIO_InitPipe_Exit_Tag;
    }

    /* Init command pipe and subscribe to command messages */
    iStatus = CFE_SB_CreatePipe(&CAMIO_AppData.CmdPipeId,
                                 CAMIO_CMD_PIPE_DEPTH,
                                 CAMIO_CMD_PIPE_NAME);
    if (iStatus == CFE_SUCCESS)
    {
        /* Subscribe to command messages */
        iStatus = CFE_SB_Subscribe(CAMIO_CMD_MID, CAMIO_AppData.CmdPipeId);

        if (iStatus != CFE_SUCCESS)
        {
            (void) CFE_EVS_SendEvent(CAMIO_INIT_ERR_EID, CFE_EVS_ERROR,
                                     "CMD Pipe failed to subscribe to CAMIO_CMD_MID. (0x%08X)",
                                     (unsigned int)iStatus);
            goto CAMIO_InitPipe_Exit_Tag;
        }
    }
    else
    {
        (void) CFE_EVS_SendEvent(CAMIO_INIT_ERR_EID, CFE_EVS_ERROR,
                                 "Failed to create CMD pipe (0x%08X)",
                                 (unsigned int)iStatus);
        goto CAMIO_InitPipe_Exit_Tag;
    }

    /* Init data pipe and subscribe to messages on the data pipe */
    iStatus = CFE_SB_CreatePipe(&CAMIO_AppData.DataPipeId,
                                 CAMIO_DATA_PIPE_DEPTH,
                                 CAMIO_DATA_PIPE_NAME);
    if (iStatus == CFE_SUCCESS)
    {
        /* TODO:  Add CFE_SB_Subscribe() calls for other apps' output data here.
        **
        ** Examples:
        **     CFE_SB_Subscribe(GNCEXEC_OUT_DATA_MID, CAMIO_AppData.DataPipeId);
        */
    }
    else
    {
        (void) CFE_EVS_SendEvent(CAMIO_INIT_ERR_EID, CFE_EVS_ERROR,
                                 "Failed to create Data pipe (0x%08X)",
                                 (unsigned int)iStatus);
        goto CAMIO_InitPipe_Exit_Tag;
    }

CAMIO_InitPipe_Exit_Tag:
    return (iStatus);
}
    

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Initialize Global Variables                                     */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int32 CAMIO_InitData()
{
    int32  iStatus=CFE_SUCCESS;

    /* Init input data */
    memset((void*)&CAMIO_AppData.InData, 0x00, sizeof(CAMIO_AppData.InData));

    /* Init output data */
    memset((void*)&CAMIO_AppData.OutData, 0x00, sizeof(CAMIO_AppData.OutData));
    CFE_SB_InitMsg(&CAMIO_AppData.OutData,
                   CAMIO_OUT_DATA_MID, sizeof(CAMIO_AppData.OutData), TRUE);

    /* Init housekeeping packet */
    memset((void*)&CAMIO_AppData.HkTlm, 0x00, sizeof(CAMIO_AppData.HkTlm));
    CFE_SB_InitMsg(&CAMIO_AppData.HkTlm,
                   CAMIO_HK_TLM_MID, sizeof(CAMIO_AppData.HkTlm), TRUE);

    return (iStatus);
}



/* TODO:  Add Doxy. */
int32    CAMIO_InitCVT(void)
{
    int32  iStatus;

    iStatus = CVT_GetContainer(CAMIO_IMAGE_MID, sizeof(CAMIO_AppData.ImageMsg), &CAMIO_AppData.ImageContainerID);

    return (iStatus);
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* CAMIO initialization                                              */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int32 CAMIO_InitApp()
{
    int32  iStatus   = CFE_SUCCESS;
    int8   hasEvents = 0;

    iStatus = CAMIO_InitEvent();
    if (iStatus != CFE_SUCCESS)
    {
        (void) CFE_ES_WriteToSysLog("CAMIO - Failed to init events (0x%08X)\n", (unsigned int)iStatus);
        goto CAMIO_InitApp_Exit_Tag;
    }
    else
    {
        hasEvents = 1;
    }

    iStatus = CAMIO_InitPipe();
    if (iStatus != CFE_SUCCESS)
    {
        (void) CFE_EVS_SendEvent(CAMIO_INIT_ERR_EID, CFE_EVS_ERROR,
                                 "Failed to init pipes (0x%08X)",
                                 (unsigned int)iStatus);
        goto CAMIO_InitApp_Exit_Tag;
    }

    iStatus = CAMIO_InitData();
    if (iStatus != CFE_SUCCESS)
    {
        (void) CFE_EVS_SendEvent(CAMIO_INIT_ERR_EID, CFE_EVS_ERROR,
                                 "Failed to init data (0x%08X)",
                                 (unsigned int)iStatus);
        goto CAMIO_InitApp_Exit_Tag;
    }

    iStatus = CAMIO_InitConfigTbl();
    if (iStatus != CFE_SUCCESS)
    {
        (void) CFE_EVS_SendEvent(CAMIO_INIT_ERR_EID, CFE_EVS_ERROR,
                                 "Failed to init config tables (0x%08X)",
                                 (unsigned int)iStatus);
        goto CAMIO_InitApp_Exit_Tag;
    }

    iStatus = CAMIO_InitCdsTbl();
    if (iStatus != CFE_SUCCESS)
    {
        (void) CFE_EVS_SendEvent(CAMIO_INIT_ERR_EID, CFE_EVS_ERROR,
                                 "Failed to init CDS table (0x%08X)",
                                 (unsigned int)iStatus);
        goto CAMIO_InitApp_Exit_Tag;
    }

    iStatus = CAMIO_InitCVT();
    if (iStatus != CFE_SUCCESS)
    {
        (void) CFE_EVS_SendEvent(CAMIO_INIT_ERR_EID, CFE_EVS_ERROR,
                                 "Failed to init CVT (0x%08X)",
                                 (unsigned int)iStatus);
        goto CAMIO_InitApp_Exit_Tag;
    }

    iStatus = CAMIO_CustomInit();
    if (iStatus != CFE_SUCCESS)
    {
        (void) CFE_EVS_SendEvent(CAMIO_INIT_ERR_EID, CFE_EVS_ERROR,
                                 "Failed to init custom layer (0x%08X)",
                                 (unsigned int)iStatus);
        goto CAMIO_InitApp_Exit_Tag;
    }

CAMIO_InitApp_Exit_Tag:
    if (iStatus == CFE_SUCCESS)
    {
        (void) CFE_EVS_SendEvent(CAMIO_INIT_INF_EID, CFE_EVS_INFORMATION,
                                 "Initialized.  Version %d.%d.%d.%d",
                                 CAMIO_MAJOR_VERSION,
                                 CAMIO_MINOR_VERSION,
                                 CAMIO_REVISION,
                                 CAMIO_MISSION_REV);
    }
    else
    {
        if (hasEvents == 1)
        {
            (void) CFE_EVS_SendEvent(CAMIO_INIT_ERR_EID, CFE_EVS_ERROR, "Application failed to initialize");
        }
        else
        {
            (void) CFE_ES_WriteToSysLog("CAMIO - Application failed to initialize\n");
        }
    }

    return (iStatus);
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Receive and Process Messages                                    */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int32 CAMIO_RcvMsg(int32 iBlocking)
{
    int32           iStatus=CFE_SUCCESS;
    CFE_SB_Msg_t*   MsgPtr=NULL;
    CFE_SB_MsgId_t  MsgId;

    /* Stop Performance Log entry */
    CFE_ES_PerfLogExit(CAMIO_MAIN_TASK_PERF_ID);

    /* Wait for WakeUp messages from scheduler */
    iStatus = CFE_SB_RcvMsg(&MsgPtr, CAMIO_AppData.SchPipeId, iBlocking);

    /* Start Performance Log entry */
    CFE_ES_PerfLogEntry(CAMIO_MAIN_TASK_PERF_ID);

    if (iStatus == CFE_SUCCESS)
    {
        MsgId = CFE_SB_GetMsgId(MsgPtr);
        switch (MsgId)
	    {
            case CAMIO_ACQUIRE_IMAGE_MID:
            	CAMIO_AcquireImage();
                CAMIO_PublishImage();
                break;

            case CAMIO_SEND_HK_MID:
                CAMIO_ProcessNewCmds();
                CAMIO_ReportHousekeeping();
                break;

            default:
                (void) CFE_EVS_SendEvent(CAMIO_MSGID_ERR_EID, CFE_EVS_ERROR,
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
    }
    else
    {
        /* TODO: This is an example of exiting on an error (either CFE_SB_BAD_ARGUMENT, or
         * CFE_SB_PIPE_RD_ERROR).
         */
        (void) CFE_EVS_SendEvent(CAMIO_PIPE_ERR_EID, CFE_EVS_ERROR,
			  "SB pipe read error (0x%08X), app will exit", (unsigned int)iStatus);
        CAMIO_AppData.uiRunStatus= CFE_ES_APP_ERROR;
    }

    return (iStatus);
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Process Incoming Commands                                       */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void CAMIO_ProcessNewCmds()
{
    int iStatus = CFE_SUCCESS;
    CFE_SB_Msg_t*   CmdMsgPtr=NULL;
    CFE_SB_MsgId_t  CmdMsgId;

    /* Process command messages till the pipe is empty */
    while (1)
    {
        iStatus = CFE_SB_RcvMsg(&CmdMsgPtr, CAMIO_AppData.CmdPipeId, CFE_SB_POLL);
        if(iStatus == CFE_SUCCESS)
        {
            CmdMsgId = CFE_SB_GetMsgId(CmdMsgPtr);
            switch (CmdMsgId)
            {
                case CAMIO_CMD_MID:
                    CAMIO_ProcessNewAppCmds(CmdMsgPtr);
                    break;

                /* TODO:  Add code to process other subscribed commands here
                **
                ** Example:
                **     case CFE_TIME_DATA_CMD_MID:
                **         CAMIO_ProcessTimeDataCmd(CmdMsgPtr);
                **         break;
                */

                default:
                    /* Bump the command error counter for an unknown command.
                     * (This should only occur if it was subscribed to with this
                     *  pipe, but not handled in this switch-case.) */
                    CAMIO_AppData.HkTlm.usCmdErrCnt++;
                    (void) CFE_EVS_SendEvent(CAMIO_MSGID_ERR_EID, CFE_EVS_ERROR,
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
            (void) CFE_EVS_SendEvent(CAMIO_PIPE_ERR_EID, CFE_EVS_ERROR,
                  "CMD pipe read error (0x%08X)", (unsigned int)iStatus);
            CAMIO_AppData.uiRunStatus = CFE_ES_APP_ERROR;
            break;
        }
    }
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Process CAMIO Commands                                            */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void CAMIO_ProcessNewAppCmds(CFE_SB_Msg_t* MsgPtr)
{
    uint32  uiCmdCode=0;

    if (MsgPtr != NULL)
    {
        uiCmdCode = CFE_SB_GetCmdCode(MsgPtr);
        switch (uiCmdCode)
        {
            case CAMIO_NOOP_CC:
                CAMIO_AppData.HkTlm.usCmdCnt++;
                (void) CFE_EVS_SendEvent(CAMIO_CMD_INF_EID, CFE_EVS_INFORMATION,
                                  "Recvd NOOP cmd (%u), Version %d.%d.%d.%d",
                                  (unsigned int)uiCmdCode,
                                  CAMIO_MAJOR_VERSION,
                                  CAMIO_MINOR_VERSION,
                                  CAMIO_REVISION,
                                  CAMIO_MISSION_REV);
                break;

            case CAMIO_RESET_CC:
                CAMIO_AppData.HkTlm.usCmdCnt = 0;
                CAMIO_AppData.HkTlm.usCmdErrCnt = 0;
                (void) CFE_EVS_SendEvent(CAMIO_CMD_INF_EID, CFE_EVS_INFORMATION,
                                  "Recvd RESET cmd (%u)", (unsigned int)uiCmdCode);
                break;

            /* TODO:  Add code to process the rest of the CAMIO commands here */

            default:
                CAMIO_AppData.HkTlm.usCmdErrCnt++;
                (void) CFE_EVS_SendEvent(CAMIO_MSGID_ERR_EID, CFE_EVS_ERROR,
                                  "Recvd invalid cmdId (%u)", (unsigned int)uiCmdCode);
                break;
        }
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Send CAMIO Housekeeping                                           */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void CAMIO_ReportHousekeeping()
{
    /* TODO:  Add code to update housekeeping data, if needed, here.  */

    CFE_SB_TimeStampMsg((CFE_SB_Msg_t*)&CAMIO_AppData.HkTlm);
    int32 iStatus = CFE_SB_SendMsg((CFE_SB_Msg_t*)&CAMIO_AppData.HkTlm);
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

int32 CAMIO_PublishImage(void)
{
	int32 returnCode = 0;

	memcpy(&CAMIO_AppData.ImageMsg.Image, &CAMIO_AppData.Image, sizeof(CAMIO_AppData.Image));

	returnCode = CVT_SetContent(
        CAMIO_AppData.ImageContainerID,
        (void*)&CAMIO_AppData.ImageMsg,
        sizeof(CAMIO_AppData.ImageMsg)
    );

	return returnCode;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Verify Command Length                                           */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

boolean CAMIO_VerifyCmdLength(CFE_SB_Msg_t* MsgPtr,
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

            (void) CFE_EVS_SendEvent(CAMIO_MSGLEN_ERR_EID, CFE_EVS_ERROR,
                              "Rcvd invalid msgLen: msgId=0x%08X, cmdCode=%d, "
                              "msgLen=%d, expectedLen=%d",
                              MsgId, usCmdCode, usMsgLen, usExpectedLen);
            CAMIO_AppData.HkTlm.usCmdErrCnt++;
        }
    }

    return (bResult);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* CAMIO application entry point and main process loop               */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void CAMIO_AppMain()
{
    /* Register the application with Executive Services */
    CAMIO_AppData.uiRunStatus = CFE_ES_APP_RUN;

    int32 iStatus = CFE_ES_RegisterApp();
    if (iStatus != CFE_SUCCESS)
    {
        (void) CFE_ES_WriteToSysLog("CAMIO - Failed to register the app (0x%08X)\n", (unsigned int)iStatus);
    }

    /* Start Performance Log entry */
    CFE_ES_PerfLogEntry(CAMIO_MAIN_TASK_PERF_ID);

    /* Perform application initializations */
    if (iStatus == CFE_SUCCESS)
    {
        iStatus = CAMIO_InitApp();
    }

    if (iStatus == CFE_SUCCESS)
    {
        /* Do not perform performance monitoring on startup sync */
        CFE_ES_PerfLogExit(CAMIO_MAIN_TASK_PERF_ID);
        CFE_ES_WaitForStartupSync(CAMIO_STARTUP_TIMEOUT_MSEC);
        CFE_ES_PerfLogEntry(CAMIO_MAIN_TASK_PERF_ID);
    }
    else
    {
        CAMIO_AppData.uiRunStatus = CFE_ES_APP_ERROR;
    }

    /* Application main loop */
    while (CFE_ES_RunLoop(&CAMIO_AppData.uiRunStatus) == TRUE)
    {
        int32 iStatus = CAMIO_RcvMsg(CAMIO_SCH_PIPE_PEND_TIME);
        if (iStatus != CFE_SUCCESS)
        {
            /* TODO: Decide what to do for other return values in CAMIO_RcvMsg(). */
        }
        /* TODO: This is only a suggestion for when to update and save CDS table.
        ** Depends on the nature of the application, the frequency of update
        ** and save can be more or less independently.
        */
        CAMIO_UpdateCdsTbl();
        CAMIO_SaveCdsTbl();

        iStatus = CAMIO_AcquireConfigPointers();
        if(iStatus != CFE_SUCCESS)
        {
            /* We apparently tried to load a new table but failed.  Terminate the application. */
            CAMIO_AppData.uiRunStatus = CFE_ES_APP_ERROR;
        }
    }

    /* Stop Performance Log entry */
    CFE_ES_PerfLogExit(CAMIO_MAIN_TASK_PERF_ID);

    /* Exit the application */
    CFE_ES_ExitApp(CAMIO_AppData.uiRunStatus);
}



void  CAMIO_AcquireImage(void)
{
	CAMIO_CustomGetImage(&CAMIO_AppData.Image);
}


/************************/
/*  End of File Comment */
/************************/
