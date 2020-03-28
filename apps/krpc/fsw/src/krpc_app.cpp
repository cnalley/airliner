/************************************************************************
** Includes
*************************************************************************/
#include <string.h>

#include "cfe.h"

#include "krpc_app.h"
#include "krpc_msg.h"
#include "krpc_version.h"
#include <string>
#include <unistd.h>
/* RPC includes */
#include <krpc.hpp>
#include <krpc/services/krpc.hpp>
#include <krpc/services/space_center.hpp>

/** \brief Current Value Table */
KRPC_CurrentValueTable_t CVT;

/** \brief Shared data mutex */
uint32 MutexCVT;


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Instantiate the application object.                             */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
KRPC oKRPC;



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Default constructor.                                            */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
KRPC::KRPC()
{

}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Destructor constructor.                                         */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
KRPC::~KRPC()
{

}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Initialize event tables.                                        */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int32 KRPC::InitEvent()
{
    int32  iStatus=CFE_SUCCESS;

    /* Register the table with CFE */
    iStatus = CFE_EVS_Register(0, 0, CFE_EVS_BINARY_FILTER);
    if (iStatus != CFE_SUCCESS)
    {
        (void) CFE_ES_WriteToSysLog("KRPC - Failed to register with EVS (0x%08lX)\n", iStatus);
    }

    return iStatus;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Initialize Message Pipes                                        */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int32 KRPC::InitPipe()
{
    int32  iStatus=CFE_SUCCESS;

    /* Init schedule pipe and subscribe to wakeup messages */
    iStatus = CFE_SB_CreatePipe(&SchPipeId,
            KRPC_SCH_PIPE_DEPTH,
            KRPC_SCH_PIPE_NAME);
    if (iStatus == CFE_SUCCESS)
    {
        iStatus = CFE_SB_SubscribeEx(KRPC_WAKEUP_MID, SchPipeId, CFE_SB_Default_Qos, KRPC_WAKEUP_MID_MAX_MSG_COUNT);
        if (iStatus != CFE_SUCCESS)
        {
            (void) CFE_EVS_SendEvent(KRPC_SUBSCRIBE_ERR_EID, CFE_EVS_ERROR,
                    "Sch Pipe failed to subscribe to KRPC_WAKEUP_MID. (0x%08lX)",
                    iStatus);
            goto KRPC_InitPipe_Exit_Tag;
        }

        iStatus = CFE_SB_SubscribeEx(KRPC_SEND_HK_MID, SchPipeId, CFE_SB_Default_Qos, KRPC_SEND_HK_MID_MAX_MSG_COUNT);
        if (iStatus != CFE_SUCCESS)
        {
            (void) CFE_EVS_SendEvent(KRPC_SUBSCRIBE_ERR_EID, CFE_EVS_ERROR,
                    "CMD Pipe failed to subscribe to KRPC_SEND_HK_MID. (0x%08X)",
                    (unsigned int)iStatus);
            goto KRPC_InitPipe_Exit_Tag;
        }
    }
    else
    {
        (void) CFE_EVS_SendEvent(KRPC_PIPE_INIT_ERR_EID, CFE_EVS_ERROR,
            "Failed to create SCH pipe (0x%08lX)",
            iStatus);
        goto KRPC_InitPipe_Exit_Tag;
    }

    /* Init command pipe and subscribe to command messages */
    iStatus = CFE_SB_CreatePipe(&CmdPipeId,
            KRPC_CMD_PIPE_DEPTH,
            KRPC_CMD_PIPE_NAME);
    if (iStatus == CFE_SUCCESS)
    {
        /* Subscribe to command messages */
        iStatus = CFE_SB_Subscribe(KRPC_CMD_MID, CmdPipeId);
        if (iStatus != CFE_SUCCESS)
        {
            (void) CFE_EVS_SendEvent(KRPC_SUBSCRIBE_ERR_EID, CFE_EVS_ERROR,
                "CMD Pipe failed to subscribe to KRPC_CMD_MID. (0x%08lX)",
                iStatus);
            goto KRPC_InitPipe_Exit_Tag;
        }
        iStatus = CFE_SB_Subscribe(KRPC_TARGET_PITCH_HEADING_MID, CmdPipeId);
        if (iStatus != CFE_SUCCESS)
        {
            (void) CFE_EVS_SendEvent(KRPC_SUBSCRIBE_ERR_EID, CFE_EVS_ERROR,
                "CMD Pipe failed to subscribe to KRPC_TARGET_PITCH_HEADING_MID. (0x%08lX)",
                iStatus);
            goto KRPC_InitPipe_Exit_Tag;
        }
        iStatus = CFE_SB_Subscribe(KRPC_SET_THROTTLE_MID, CmdPipeId);
        if (iStatus != CFE_SUCCESS)
        {
            (void) CFE_EVS_SendEvent(KRPC_SUBSCRIBE_ERR_EID, CFE_EVS_ERROR,
                "CMD Pipe failed to subscribe to KRPC_SET_THROTTLE_MID. (0x%08lX)",
                iStatus);
            goto KRPC_InitPipe_Exit_Tag;
        }
        iStatus = CFE_SB_Subscribe(KRPC_SAS_MODE_MID, CmdPipeId);
        if (iStatus != CFE_SUCCESS)
        {
            (void) CFE_EVS_SendEvent(KRPC_SUBSCRIBE_ERR_EID, CFE_EVS_ERROR,
                "CMD Pipe failed to subscribe to KRPC_SAS_MODE_MID. (0x%08lX)",
                iStatus);
            goto KRPC_InitPipe_Exit_Tag;
        }
    }
    else
    {
        (void) CFE_EVS_SendEvent(KRPC_PIPE_INIT_ERR_EID, CFE_EVS_ERROR,
            "Failed to create CMD pipe (0x%08lX)",
            iStatus);
        goto KRPC_InitPipe_Exit_Tag;
    }

KRPC_InitPipe_Exit_Tag:
    return iStatus;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Initialize Global Variables                                     */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void KRPC::InitData()
{
    /* Init current value table */
    CFE_PSP_MemSet((void*)&CVT, 0x00, sizeof(CVT));
    /* Init housekeeping message */
    CFE_SB_InitMsg(&HkTlm, KRPC_HK_TLM_MID, sizeof(HkTlm), TRUE);
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* KRPC initialization                                              */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int32 KRPC::InitApp()
{
    int32  iStatus   = CFE_SUCCESS;
    int8   hasEvents = 0;

    iStatus = InitEvent();
    if (iStatus != CFE_SUCCESS)
    {
        (void) CFE_ES_WriteToSysLog("KRPC - Failed to init events (0x%08lX)\n", iStatus);
        goto KRPC_InitApp_Exit_Tag;
    }
    else
    {
        hasEvents = 1;
    }

    iStatus = InitPipe();
    if (iStatus != CFE_SUCCESS)
    {
        goto KRPC_InitApp_Exit_Tag;
    }

    InitData();

    iStatus = InitConfigTbl();
    if (iStatus != CFE_SUCCESS)
    {
        goto KRPC_InitApp_Exit_Tag;
    }

    /* Create mutex for current value table */
    iStatus = OS_MutSemCreate(&MutexCVT, "KRPC CVT Mutex", 0);
    if (iStatus != CFE_SUCCESS)
    {
        goto KRPC_InitApp_Exit_Tag;
    }

    ChildTaskPtr = DataStreamTask;

    iStatus = CFE_ES_CreateChildTask(
            &ChildTaskID,
            KRPC_CHILD_TASK_NAME,
            ChildTaskPtr,
            0,
            KRPC_CHILD_TASK_STACK_SIZE,
            KRPC_CHILD_TASK_PRIORITY,
            KRPC_CHILD_TASK_FLAGS);


KRPC_InitApp_Exit_Tag:
    if (iStatus == CFE_SUCCESS)
    {
        (void) CFE_EVS_SendEvent(KRPC_INIT_INF_EID, CFE_EVS_INFORMATION,
                                 "Initialized.  Version %d.%d.%d.%d",
                                 KRPC_MAJOR_VERSION,
                                 KRPC_MINOR_VERSION,
                                 KRPC_REVISION,
                                 KRPC_MISSION_REV);
    }
    else
    {
        if (hasEvents == 1)
        {
            (void) CFE_ES_WriteToSysLog("KRPC - Application failed to initialize\n");
        }
    }

    return iStatus;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Receive and Process Messages                                    */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int32 KRPC::RcvSchPipeMsg(int32 iBlocking)
{
    int32           iStatus=CFE_SUCCESS;
    CFE_SB_Msg_t*   MsgPtr=NULL;
    CFE_SB_MsgId_t  MsgId;

    /* Stop Performance Log entry */
    CFE_ES_PerfLogExit(KRPC_MAIN_TASK_PERF_ID);

    /* Wait for WakeUp messages from scheduler */
    iStatus = CFE_SB_RcvMsg(&MsgPtr, SchPipeId, iBlocking);

    /* Start Performance Log entry */
    CFE_ES_PerfLogEntry(KRPC_MAIN_TASK_PERF_ID);

    if (iStatus == CFE_SUCCESS)
    {
        MsgId = CFE_SB_GetMsgId(MsgPtr);
        switch (MsgId)
        {
            case KRPC_WAKEUP_MID:
                ProcessCmdPipe();
                break;

            case KRPC_SEND_HK_MID:
                ReportHousekeeping();
                break;

            default:
                (void) CFE_EVS_SendEvent(KRPC_MSGID_ERR_EID, CFE_EVS_ERROR,
                     "Recvd invalid SCH msgId (0x%04X)", MsgId);
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
        ProcessCmdPipe();
        ReportHousekeeping();
        iStatus = CFE_SUCCESS;
    }
    else
    {
        (void) CFE_EVS_SendEvent(KRPC_RCVMSG_ERR_EID, CFE_EVS_ERROR,
                "SCH pipe read error (0x%08lX).", iStatus);
    }

    return iStatus;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Process Incoming Commands                                       */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void KRPC::ProcessCmdPipe()
{
    int32 iStatus = CFE_SUCCESS;
    CFE_SB_Msg_t*   CmdMsgPtr=NULL;
    CFE_SB_MsgId_t  CmdMsgId;

    /* Process command messages until the pipe is empty */
    while (1)
    {
        iStatus = CFE_SB_RcvMsg(&CmdMsgPtr, CmdPipeId, CFE_SB_POLL);
        if(iStatus == CFE_SUCCESS)
        {
            CmdMsgId = CFE_SB_GetMsgId(CmdMsgPtr);
            switch (CmdMsgId)
            {
                case KRPC_CMD_MID:
                {
                    ProcessAppCmds(CmdMsgPtr);
                    break;
                }
                case KRPC_TARGET_PITCH_HEADING_MID:
                {
                    OS_MutSemTake(MutexCVT);
                    CFE_PSP_MemCpy(&CVT.TargetPitchAndHeadingCmd, 
                            CmdMsgPtr, 
                            sizeof(CVT.TargetPitchAndHeadingCmd));
                    OS_MutSemGive(MutexCVT);
                    break;
                }
                case KRPC_SET_THROTTLE_MID:
                {
                    OS_MutSemTake(MutexCVT);
                    CFE_PSP_MemCpy(&CVT.SetThrottleCmd, 
                            CmdMsgPtr, 
                            sizeof(CVT.SetThrottleCmd));
                    OS_MutSemGive(MutexCVT);
                    break;
                }
                case KRPC_SAS_MODE_MID:
                {
                    OS_MutSemTake(MutexCVT);
                    CFE_PSP_MemCpy(&CVT.SasModeCmd, 
                            CmdMsgPtr, 
                            sizeof(CVT.SasModeCmd));
                    OS_MutSemGive(MutexCVT);
                    break;
                }
                default:
                {
                    /* Bump the command error counter for an unknown command.
                     * (This should only occur if it was subscribed to with this
                     *  pipe, but not handled in this switch-case.) */
                    HkTlm.usCmdErrCnt++;
                    (void) CFE_EVS_SendEvent(KRPC_MSGID_ERR_EID, CFE_EVS_ERROR,
                                      "Recvd invalid CMD msgId (0x%04X)", (unsigned short)CmdMsgId);
                    break;
                }
            }
        }
        else if (iStatus == CFE_SB_NO_MESSAGE)
        {
            break;
        }
        else
        {
            (void) CFE_EVS_SendEvent(KRPC_RCVMSG_ERR_EID, CFE_EVS_ERROR,
                  "CMD pipe read error (0x%08lX)", iStatus);
            break;
        }
    }
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Process KRPC Commands                                            */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void KRPC::ProcessAppCmds(CFE_SB_Msg_t* MsgPtr)
{
    uint32  uiCmdCode=0;

    if (MsgPtr != NULL)
    {
        uiCmdCode = CFE_SB_GetCmdCode(MsgPtr);
        switch (uiCmdCode)
        {
            case KRPC_NOOP_CC:
            {
                HkTlm.usCmdCnt++;
                (void) CFE_EVS_SendEvent(KRPC_CMD_NOOP_EID, CFE_EVS_INFORMATION,
                    "Recvd NOOP. Version %d.%d.%d.%d",
                    KRPC_MAJOR_VERSION,
                    KRPC_MINOR_VERSION,
                    KRPC_REVISION,
                    KRPC_MISSION_REV);
                break;
            }
            case KRPC_RESET_CC:
            {
                HkTlm.usCmdCnt = 0;
                HkTlm.usCmdErrCnt = 0;
                break;
            }
            case KRPC_ENGAGE_RCS_CC:
            {
                OS_MutSemTake(MutexCVT);
                CVT.EngageRCS = true;
                OS_MutSemGive(MutexCVT);
                HkTlm.usCmdCnt++;
                break;
            }
            case KRPC_DISENGAGE_RCS_CC:
            {
                OS_MutSemTake(MutexCVT);
                CVT.EngageRCS = false;
                OS_MutSemGive(MutexCVT);
                (void) CFE_EVS_SendEvent(KRPC_CMD_INF_EID, CFE_EVS_INFORMATION,
                                  "RCS deactivated.");
                HkTlm.usCmdCnt++;
                break;
            }
            case KRPC_ENGAGE_SAS_CC:
            {
                OS_MutSemTake(MutexCVT);
                CVT.EngageSAS = true;
                OS_MutSemGive(MutexCVT);
                HkTlm.usCmdCnt++;
                break;
            }
            case KRPC_DISENGAGE_SAS_CC:
            {
                OS_MutSemTake(MutexCVT);
                CVT.EngageSAS = false;
                OS_MutSemGive(MutexCVT);
                (void) CFE_EVS_SendEvent(KRPC_CMD_INF_EID, CFE_EVS_INFORMATION,
                                  "SAS deactivated.");
                HkTlm.usCmdCnt++;
                break;
            }
            case KRPC_ACTIVATE_NEXT_STAGE_CC:
            {
                OS_MutSemTake(MutexCVT);
                CVT.ActivateNextStage = true;
                OS_MutSemGive(MutexCVT);
                HkTlm.usCmdCnt++;
                break;
            }
            case KRPC_ENGAGE_AUTOPILOT_CC:
            {
                OS_MutSemTake(MutexCVT);
                CVT.EngageAutopilot = true;
                OS_MutSemGive(MutexCVT);
                HkTlm.usCmdCnt++;
                break;
            }
            default:
            {
                HkTlm.usCmdErrCnt++;
                (void) CFE_EVS_SendEvent(KRPC_CC_ERR_EID, CFE_EVS_ERROR,
                                  "Recvd invalid command code (%u)", (unsigned int)uiCmdCode);
                break;
            }
        }
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Send KRPC Housekeeping                                           */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void KRPC::ReportHousekeeping()
{
    CFE_SB_TimeStampMsg((CFE_SB_Msg_t*)&HkTlm);
    CFE_SB_SendMsg((CFE_SB_Msg_t*)&HkTlm);
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Publish Output Data                                             */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Verify Command Length                                           */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
boolean KRPC::VerifyCmdLength(CFE_SB_Msg_t* MsgPtr,
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

            (void) CFE_EVS_SendEvent(KRPC_MSGLEN_ERR_EID, CFE_EVS_ERROR,
                              "Rcvd invalid msgLen: msgId=0x%08X, cmdCode=%d, "
                              "msgLen=%d, expectedLen=%d",
                              MsgId, usCmdCode, usMsgLen, usExpectedLen);
            HkTlm.usCmdErrCnt++;
        }
    }

    return bResult;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* KRPC Application C style main entry point.                       */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
extern "C" void KRPC_AppMain()
{
    oKRPC.AppMain();
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* KRPC Application C++ style main entry point.                     */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void KRPC::AppMain()
{
    /* Register the application with Executive Services */
    uiRunStatus = CFE_ES_APP_RUN;

    int32 iStatus = CFE_ES_RegisterApp();
    if (iStatus != CFE_SUCCESS)
    {
        (void) CFE_ES_WriteToSysLog("KRPC - Failed to register the app (0x%08lX)\n", iStatus);
    }

    /* Start Performance Log entry */
    CFE_ES_PerfLogEntry(KRPC_MAIN_TASK_PERF_ID);

    /* Perform application initializations */
    if (iStatus == CFE_SUCCESS)
    {
        iStatus = InitApp();
    }

    if (iStatus == CFE_SUCCESS)
    {
        /* Do not perform performance monitoring on startup sync */
        CFE_ES_PerfLogExit(KRPC_MAIN_TASK_PERF_ID);
        CFE_ES_WaitForStartupSync(KRPC_STARTUP_TIMEOUT_MSEC);
        CFE_ES_PerfLogEntry(KRPC_MAIN_TASK_PERF_ID);
    }
    else
    {
        uiRunStatus = CFE_ES_APP_ERROR;
    }

    /* Application main loop */
    while (CFE_ES_RunLoop(&uiRunStatus) == TRUE)
    {
        RcvSchPipeMsg(KRPC_SCH_PIPE_PEND_TIME);

        iStatus = AcquireConfigPointers();
        if(iStatus != CFE_SUCCESS)
        {
            /* We apparently tried to load a new table but failed.  Terminate the application. */
            uiRunStatus = CFE_ES_APP_ERROR;
        }
    }

    /* Stop Performance Log entry */
    CFE_ES_PerfLogExit(KRPC_MAIN_TASK_PERF_ID);

    /* Exit the application */
    CFE_ES_ExitApp(uiRunStatus);
}


void KRPC::DataStreamTask(void)
{
    /* Telemetry */
    KRPC_MeanAltitudeTlm_t AltitudeTlm;
    KRPC_RotationTlm_t RotationTlm;
    KRPC_VelocityTlm_t VelocityTlm;
    KRPC_MetTlm_t MetTlm;
    KRPC_UtTlm_t UtTlm;
    KRPC_GForceTlm_t GForceTlm;
    KRPC_ApoapsisAltitudeTlm_t ApoapsisAltitudeTlm;
    KRPC_PeriapsisAltitudeTlm_t PeriapsisAltitudeTlm;
    KRPC_SolidFuelTlm_t SolidFuelTlm;

    /* Commands */
    KRPC_CurrentValueTable_t CmdState = {0};

    /* Register this child task */
    CFE_ES_RegisterChildTask();

    /* Init altitude packet */
    CFE_SB_InitMsg(&AltitudeTlm,
                   KRPC_ALTITUDE_TLM_MID, sizeof(AltitudeTlm), TRUE);
    /* Init rotation packet */
    CFE_SB_InitMsg(&RotationTlm,
                   KRPC_ROTATION_TLM_MID, sizeof(RotationTlm), TRUE);            
    /* Init velocity packet */
    CFE_SB_InitMsg(&VelocityTlm,
                   KRPC_VELOCITY_TLM_MID, sizeof(VelocityTlm), TRUE);
    /* Init MET packet */
    CFE_SB_InitMsg(&MetTlm,
                   KRPC_MET_TLM_MID, sizeof(MetTlm), TRUE);
    /* Init UT packet */
    CFE_SB_InitMsg(&UtTlm,
                   KRPC_UT_TLM_MID, sizeof(UtTlm), TRUE);
    /* Init G force packet */
    CFE_SB_InitMsg(&GForceTlm,
                   KRPC_G_FORCE_TLM_MID, sizeof(GForceTlm), TRUE);
    /* Init apoapsis altitude packet */
    CFE_SB_InitMsg(&ApoapsisAltitudeTlm,
                   KRPC_APOAPSIS_TLM_MID, sizeof(ApoapsisAltitudeTlm), TRUE);
    /* Init periapsis altitude packet */
    CFE_SB_InitMsg(&PeriapsisAltitudeTlm,
                   KRPC_PERIAPSIS_TLM_MID, sizeof(PeriapsisAltitudeTlm), TRUE);
    /* Init solid fuel packet */
    CFE_SB_InitMsg(&SolidFuelTlm,
                   KRPC_SOLID_FUEL_TLM_MID, sizeof(SolidFuelTlm), TRUE);

    /* Connect to the RPC server */
    krpc::Client conn = krpc::connect("CFS", "192.168.0.155", 50000, 50001);
    krpc::services::KRPC krpc(&conn);
    krpc::services::SpaceCenter sc(&conn);
    /* Get the version of the RPC server */
    std::string krpcVersion = krpc.get_status().version();
    (void) CFE_EVS_SendEvent(KRPC_INIT_INF_EID, CFE_EVS_INFORMATION,
            "Connected to KRPC server. Version %s",
            krpcVersion.c_str());
    /* Get the active vessal */
    auto vessel = sc.active_vessel();
    /* Get the reference frame */
    auto ref_frame = vessel.orbit().body().reference_frame();
    /* Setup streams */
    /* Universal time in seconds */
    auto ut = sc.ut_stream();
    /* Vessel mission elapsed time in seconds */
    auto met = vessel.met_stream();
    /* Mean altitude */
    auto altitude = vessel.flight().mean_altitude_stream();
    /* Apoapsis altitude */
    auto apoapsis = vessel.orbit().apoapsis_altitude_stream();
    /* Fuel */
    auto stage_2_resources = vessel.resources_in_decouple_stage(2, false);
    auto srb_fuel = stage_2_resources.amount_stream("SolidFuel");

    /* Loop */
    while(1)
    {
        /* Retrieve current values */
        /* Universal time */
        UtTlm.Ut = ut();
        /* Publish to the software bus */
        CFE_SB_TimeStampMsg((CFE_SB_Msg_t*)&UtTlm);
        (void) CFE_SB_SendMsg((CFE_SB_Msg_t*)&UtTlm);
        /* Mission elapsed time */
        MetTlm.Met = met();
        /* Publish to the software bus */
        CFE_SB_TimeStampMsg((CFE_SB_Msg_t*)&MetTlm);
        (void) CFE_SB_SendMsg((CFE_SB_Msg_t*)&MetTlm);
        /* Mean altitude */
        AltitudeTlm.Altitude = altitude();
        /* Publish to the software bus */
        CFE_SB_TimeStampMsg((CFE_SB_Msg_t*)&AltitudeTlm);
        (void) CFE_SB_SendMsg((CFE_SB_Msg_t*)&AltitudeTlm);
        /* Apoapsis altitude */
        ApoapsisAltitudeTlm.ApoapsisAltitude = apoapsis();
        /* Publish to the software bus */
        CFE_SB_TimeStampMsg((CFE_SB_Msg_t*)&ApoapsisAltitudeTlm);
        (void) CFE_SB_SendMsg((CFE_SB_Msg_t*)&ApoapsisAltitudeTlm);
        /* Solid fuel */
        SolidFuelTlm.Fuel = srb_fuel();
        /* Publish to the software bus */
        CFE_SB_TimeStampMsg((CFE_SB_Msg_t*)&SolidFuelTlm);
        (void) CFE_SB_SendMsg((CFE_SB_Msg_t*)&SolidFuelTlm);

        /* Outgoing commands */
        OS_MutSemTake(MutexCVT);
        /* RCS state */
        if(CVT.EngageRCS != CmdState.EngageRCS)
        {
            vessel.control().set_rcs(CVT.EngageRCS);
            CmdState.EngageRCS = CVT.EngageRCS;
            (void) CFE_EVS_SendEvent(KRPC_CMD_INF_EID, CFE_EVS_INFORMATION,
                    "RCS activated.");
        }
        /* SAS state */
        if(CVT.EngageSAS != CmdState.EngageSAS)
        {
            vessel.control().set_sas(CVT.EngageSAS);
            CmdState.EngageSAS = CVT.EngageSAS;
            (void) CFE_EVS_SendEvent(KRPC_CMD_INF_EID, CFE_EVS_INFORMATION,
                    "SAS activated.");
        }
        /* Next stage */
        if(true == CVT.ActivateNextStage)
        {
            vessel.control().activate_next_stage();
            CVT.ActivateNextStage = false;
            (void) CFE_EVS_SendEvent(KRPC_CMD_INF_EID, CFE_EVS_INFORMATION,
                    "Next stage activated.");
        }
        /* Autopilot */
        if(CVT.EngageAutopilot != CmdState.EngageAutopilot)
        {
            if(true == CVT.EngageAutopilot)
            {
                vessel.auto_pilot().engage();
                (void) CFE_EVS_SendEvent(KRPC_CMD_INF_EID, CFE_EVS_INFORMATION,
                        "Autopilot activated.");
            }
            else
            {
                vessel.auto_pilot().disengage();
            }
            CmdState.EngageAutopilot = CVT.EngageAutopilot;
        }
        /* Autopilot target pitch and heading */
        if(CVT.TargetPitchAndHeadingCmd.TargetPitch !=
           CmdState.TargetPitchAndHeadingCmd.TargetPitch ||
           CVT.TargetPitchAndHeadingCmd.TargetHeading !=
           CmdState.TargetPitchAndHeadingCmd.TargetHeading)
        {
            vessel.auto_pilot().target_pitch_and_heading(
            CVT.TargetPitchAndHeadingCmd.TargetPitch,
            CVT.TargetPitchAndHeadingCmd.TargetHeading);

            CmdState.TargetPitchAndHeadingCmd.TargetPitch =
            CVT.TargetPitchAndHeadingCmd.TargetPitch;
            CmdState.TargetPitchAndHeadingCmd.TargetHeading =
            CVT.TargetPitchAndHeadingCmd.TargetHeading;
            (void) CFE_EVS_SendEvent(KRPC_CMD_INF_EID, CFE_EVS_INFORMATION,
                        "Autopilot target pitch and header %0.1f:%0.1f.",
                        CmdState.TargetPitchAndHeadingCmd.TargetPitch,
                        CmdState.TargetPitchAndHeadingCmd.TargetHeading);
        }
        /* Throttle */
        if(CVT.SetThrottleCmd.Throttle != CmdState.SetThrottleCmd.Throttle)
        {
            vessel.control().set_throttle(CVT.SetThrottleCmd.Throttle);
            CmdState.SetThrottleCmd.Throttle = CVT.SetThrottleCmd.Throttle;
            (void) CFE_EVS_SendEvent(KRPC_CMD_INF_EID, CFE_EVS_INFORMATION,
                        "Throttle set to %0.1f.",
                        CmdState.SetThrottleCmd.Throttle);
        }
        /* SAS mode */
        if(CVT.SasModeCmd.Mode != CmdState.SasModeCmd.Mode)
        {
            krpc::services::SpaceCenter::SASMode mode = 
            (krpc::services::SpaceCenter::SASMode)CVT.SasModeCmd.Mode;
            vessel.auto_pilot().set_sas_mode(mode);
            CmdState.SasModeCmd = CVT.SasModeCmd;
        }
        OS_MutSemGive(MutexCVT);

        /* 50 Hz */
        usleep(KRPC_DATA_STREAM_TASK_RATE_US);
    }

    CFE_ES_ExitChildTask();
}

/************************/
/*  End of File Comment */
/************************/