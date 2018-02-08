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

#ifndef PE_APP_H
#define PE_APP_H

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************
 ** Pragmas
 *************************************************************************/

/************************************************************************
 ** Includes
 *************************************************************************/

#include "cfe.h"

#include "pe_platform_cfg.h"
#include "pe_mission_cfg.h"
#include "pe_perfids.h"
#include "pe_msgids.h"
#include "pe_msg.h"
#include "pe_events.h"
#include "pe_tbldefs.h"
#include "px4_msgs.h"
#include "lib/px4lib.h"

#include "Vector10F.hpp"
#include "Vector3F.hpp"
#include "Matrix10F10.hpp"
#include "Matrix10F3.hpp"
#include "Matrix3F3.hpp"

#include <poll.h>

/************************************************************************
 ** Local Defines
 *************************************************************************/

#define PE_BETA_TABLE_SIZE	(7)

/************************************************************************
 ** Local Structure Definitions
 *************************************************************************/

enum {
	X_x = 0,
	X_y,
	X_z,
	X_vx,
	X_vy,
	X_vz,
	X_bx,
	X_by,
	X_bz,
	X_tz,
	n_x
};

enum {
	U_ax = 0,
	U_ay,
	U_az,
	n_u
};

enum {
	Y_baro_z = 0,
	n_y_baro
};

enum {
	Y_gps_x = 0,
	Y_gps_y,
	Y_gps_z,
	Y_gps_vx,
	Y_gps_vy,
	Y_gps_vz,
	n_y_gps
};

enum {
	Y_land_vx = 0,
	Y_land_vy,
	Y_land_agl,
	n_y_land
};

/* Enums for other sensors would go here */


/**
 **  \brief PE Application Class
 */
class PE
{
public:
    PE();
    ~PE();

    /** \brief Constants */
    float 	DELAY_MAX;
    float 	HIST_STEP;
    float 	BIAS_MAX;
    size_t 	HIST_LEN;
    size_t 	N_DIST_SUBS;
    float  	BETA_TABLE[PE_BETA_TABLE_SIZE];
    uint32 	EST_STDDEV_XY_VALID; // 2.0 m
    uint32 	EST_STDDEV_Z_VALID; // 2.0 m
    uint32 	EST_STDDEV_TZ_VALID; // 2.0 m
    float 	P_MAX; // max allowed value in state covariance
    float 	LAND_RATE; // rate of land detector correction

    /**\brief Scheduling Pipe ID */
    CFE_SB_PipeId_t SchPipeId;

    /** \brief Command Pipe ID */
    CFE_SB_PipeId_t CmdPipeId;

    /* Task-related */

    /** \brief Task Run Status */
    uint32 uiRunStatus;

    /* Config table-related */

    /** \brief Config Table Handle */
    CFE_TBL_Handle_t ConfigTblHdl;

    /** \brief Config Table Pointer */
    PE_ConfigTbl_t* ConfigTblPtr;

    /** \brief Ingest Data */
    PX4_VehicleGpsPositionMsg_t mVehicleGpsPositionMsg;
    PX4_VehicleStatusMsg_t mVehicleStatusMsg;
    PX4_VehicleLandDetectedMsg_t mVehicleLandDetectedMsg;
    PX4_ActuatorArmedMsg_t mActuatorArmedMsg;
    PX4_VehicleAttitudeMsg_t mVehicleAttitudeMsg;
    PX4_VehicleControlModeMsg_t mVehicleControlModeMsg;
    PX4_SensorCombinedMsg_t mSensorCombinedMsg;
    PX4_VehicleAttitudeSetpointMsg_t mVehicleAttitudeSetpointMsg;
    PX4_ManualControlSetpointMsg_t mManualControlSetpointMsg;
    PX4_DistanceSensorMsg_t mDistanceSensorMsg;

    /** \brief Output Data published at the end of cycle */
    PX4_VehicleLocalPositionMsg_t mVehicleLocalPositionMsg;
    PX4_EstimatorStatusMsg_t mEstimatorStatusMsg;
    PX4_VehicleGlobalPositionMsg_t mVehicleGlobalPositionMsg;
    PX4_Ekf2InnovationsMsg_t mEkf2InnovationsMsg;

    // TODO: implement
    //BlockStats n_y_baro mBaroStats;
    //BlockStats n_y_gps mGpsStats;
    uint16 mLandCount;

	// low pass
	//BlockLowPassVector<float, n_x> mXLowPass;
	//BlockLowPass mAglLowPass;

	// delay blocks
	//BlockDelay<float, n_x, 1, HIST_LEN> mXDelay;
	//BlockDelay<uint64_t, 1, 1, HIST_LEN> mTDelay;

	// misc
    pollfd mPolls[3];
	uint64 mTimeStamp;
	uint64 mTimeStampLastBaro;
	uint64 mTimeLastBaro;
	uint64 mTimeLastGps;
	uint64 mTimeLastLand;

	// reference altitudes
	float mAltOrigin;
	bool  mAltOriginInitialized;
	float mBaroAltOrigin;
	float mGpsAltOrigin;

	// status
	bool mReceivedGps;
	bool mLastArmedState;

	// masks
	uint8 mSensorTimeout;
	uint8 mSensorFault;
	uint8 mEstimatorInitialized;

	// state space
	math::Vector10F  mStateVec; // state vector
	math::Vector3F  mInputVec; // input vector
	math::Matrix10F10  mStateCov; // state covariance matrix

	//matrix::Dcm<float> _R_att;
	math::Vector3F mEuler;

	math::Matrix10F10 mDynamicsMat; // dynamics matrix
	math::Matrix10F3 mInputMat; // input matrix
	//math::Matrix3F3 mInputCov; // input covariance
	math::Matrix10F10 mNoiseCov; // process noise covariance

    /** \brief Housekeeping Telemetry for downlink */
    PE_HkTlm_t HkTlm;

    /************************************************************************/
    /** \brief Position Estimator (PE) application entry point
     **
     **  \par Description
     **       Position Estimator Task application entry point.  This function
     **       performs app initialization, then waits for the cFE ES Startup
     **       Sync, then executes the main processing loop.
     **
     **  \par Assumptions, External Events, and Notes:
     **       If there is an unrecoverable failure during initialization the
     **       main loop is never executed and the application will exit.
     **
     *************************************************************************/
    void AppMain(void);

    /************************************************************************/
    /** \brief Initialize the Position Estimator (PE) application
     **
     **  \par Description
     **       Position Estimator application initialization routine. This
     **       function performs all the required startup steps to
     **       initialize (or restore from CDS) PE data structures and get
     **       the application registered with the cFE services so it can
     **       begin to receive command messages and send events.
     **
     **  \par Assumptions, External Events, and Notes:
     **       None
     **
     **  \returns
     **  \retcode #CFE_SUCCESS  \retdesc \copydoc CFE_SUCCESS    \endcode
     **  \retstmt Return codes from #CFE_ES_RegisterApp          \endcode
     **  \retstmt Return codes from #PE_InitEvent               \endcode
     **  \retstmt Return codes from #PE_InitPipe                \endcode
     **  \retstmt Return codes from #PE_InitData                \endcode
     **  \retstmt Return codes from #PE_InitConfigTbl           \endcode
     **  \retstmt Return codes from #OS_TaskInstallDeleteHandler \endcode
     **  \endreturns
     **
     *************************************************************************/
    int32 InitApp(void);

    /************************************************************************/
    /** \brief Initialize Event Services and Event tables
     **
     **  \par Description
     **       This function performs the steps required to setup
     **       cFE Event Services for use by the PE application.
     **
     **  \par Assumptions, External Events, and Notes:
     **       None
     **
     **  \returns
     **  \retcode #CFE_SUCCESS  \retdesc \copydoc CFE_SUCCESS \endcode
     **  \retstmt Return codes from #CFE_EVS_Register  \endcode
     **  \endreturns
     **
     *************************************************************************/
    int32 InitEvent(void);

    /************************************************************************/
    /** \brief Initialize global variables used by PE application
     **
     **  \par Description
     **       This function performs the steps required to initialize
     **       the PE application data.
     **
     **  \par Assumptions, External Events, and Notes:
     **       None
     **
     *************************************************************************/
    void InitData(void);

    /************************************************************************/
    /** \brief Initialize message pipes
     **
     **  \par Description
     **       This function performs the steps required to setup
     **       initialize the cFE Software Bus message pipes and subscribe to
     **       messages for the PE application.
     **
     **  \par Assumptions, External Events, and Notes:
     **       None
     **
     **  \returns
     **  \retcode #CFE_SUCCESS  \retdesc \copydoc CFE_SUCCESS \endcode
     **  \retstmt Return codes from #CFE_SB_CreatePipe        \endcode
     **  \retstmt Return codes from #CFE_SB_SubscribeEx       \endcode
     **  \retstmt Return codes from #CFE_SB_Subscribe         \endcode
     **  \endreturns
     **
     *************************************************************************/
    int32 InitPipe(void);

    /************************************************************************/
    /** \brief Receive and process messages from the scheduler pipe.
     **
     **  \par Description
     **       This function receives and processes messages
     **       for the PE application from the SCH pipe.  This function
     **       will pend for the type defined by iBlocking, allowing
     **       it to wait for messages, i.e. wakeup messages from scheduler.
     **
     **  \par Assumptions, External Events, and Notes:
     **       None
     **
     **  \param [in]   iBlocking    A #CFE_SB_PEND_FOREVER, #CFE_SB_POLL or
     **                             millisecond timeout
     **
     **  \returns
     **  \retcode #CFE_SUCCESS  \retdesc \copydoc CFE_SUCCESS \endcode
     **  \retstmt Return codes from #CFE_SB_RcvMsg            \endcode
     **  \endreturns
     **
     *************************************************************************/
    int32 RcvSchPipeMsg(int32 iBlocking);

    /************************************************************************/
    /** \brief Position Estimator Task incoming command processing
     **
     **  \par Description
     **       This function processes incoming commands subscribed
     **       by PE application
     **
     **  \par Assumptions, External Events, and Notes:
     **       None
     **
     *************************************************************************/
    void ProcessCmdPipe(void);

    /************************************************************************/
    /** \brief Position Estimator Task application commands
     **
     **  \par Description
     **       This function processes command messages
     **       specific to the PE application
     **
     **  \par Assumptions, External Events, and Notes:
     **       None
     **
     **  \param [in]   MsgPtr       A #CFE_SB_Msg_t pointer that
     **                             references the software bus message
     **
     *************************************************************************/
    void ProcessAppCmds(CFE_SB_Msg_t* MsgPtr);

    /************************************************************************/
    /** \brief Sends PE housekeeping message
     **
     **  \par Description
     **       This function sends the housekeeping message
     **
     **  \par Assumptions, External Events, and Notes:
     **       None
     **
     *************************************************************************/
    void ReportHousekeeping(void);
    /************************************************************************/
    /** \brief Sends the VehicleLocalPositionMsg message.
     **
     **  \par Description
     **       This function publishes the VehicleLocalPositionMsg message containing
     **       <TODO>
     **
     **  \par Assumptions, External Events, and Notes:
     **       None
     **
     *************************************************************************/
    void SendVehicleLocalPositionMsg(void);
    /************************************************************************/
    /** \brief Sends the EstimatorStatusMsg message.
     **
     **  \par Description
     **       This function publishes the EstimatorStatusMsg message containing
     **       <TODO>
     **
     **  \par Assumptions, External Events, and Notes:
     **       None
     **
     *************************************************************************/
    void SendEstimatorStatusMsg(void);
    /************************************************************************/
    /** \brief Sends the VehicleGlobalPositionMsg message.
     **
     **  \par Description
     **       This function publishes the VehicleGlobalPositionMsg message containing
     **       <TODO>
     **
     **  \par Assumptions, External Events, and Notes:
     **       None
     **
     *************************************************************************/
    void SendVehicleGlobalPositionMsg(void);
    /************************************************************************/
    /** \brief Sends the Ekf2InnovationsMsg message.
     **
     **  \par Description
     **       This function publishes the Ekf2InnovationsMsg message containing
     **       <TODO>
     **
     **  \par Assumptions, External Events, and Notes:
     **       None
     **
     *************************************************************************/
    void SendEkf2InnovationsMsg(void);
    /************************************************************************/
    /** \brief Verify Command Length
     **
     **  \par Description
     **       This function verifies the command message length.
     **
     **  \par Assumptions, External Events, and Notes:
     **       None
     **
     **  \param [in]   MsgPtr        A #CFE_SB_Msg_t pointer that
     **                              references the software bus message
     **  \param [in]   usExpectedLen The expected length of the message
     **
     **  \returns
     **  TRUE if the message length matches expectations, FALSE if it does not.
     **  \endreturns
     **
     *************************************************************************/
    boolean VerifyCmdLength(CFE_SB_Msg_t* MsgPtr, uint16 usExpectedLen);

    /************************************************************************/
    /** \brief Validate PE configuration table
    **
    **  \par Description
    **       This function validates PE's configuration table
    **
    **  \par Assumptions, External Events, and Notes:
    **       None
    **
    **  \param [in]   ConfigTblPtr    A pointer to the table to validate.
    **
    **  \returns
    **  \retcode #CFE_SUCCESS  \retdesc \copydoc CFE_SUCCESS  \endcode
    **  \endreturns
    **
    *************************************************************************/
    static int32  ValidateConfigTbl(void*);

private:
    /************************************************************************/
    /** \brief Initialize the PE configuration tables.
    **
    **  \par Description
    **       This function initializes PE's configuration tables.  This
    **       includes <TODO>.
    **
    **  \par Assumptions, External Events, and Notes:
    **       None
    **
    **  \returns
    **  \retcode #CFE_SUCCESS  \retdesc \copydoc CFE_SUCCESS  \endcode
    **  \retstmt Return codes from #CFE_TBL_Register          \endcode
    **  \retstmt Return codes from #CFE_TBL_Load              \endcode
    **  \retstmt Return codes from #PE_AcquireConfigPointers \endcode
    **  \endreturns
    **
    *************************************************************************/
    int32  InitConfigTbl(void);

    /************************************************************************/
    /** \brief Obtain PE configuration tables data pointers.
    **
    **  \par Description
    **       This function manages the configuration tables
    **       and obtains a pointer to their data.
    **
    **  \par Assumptions, External Events, and Notes:
    **       None
    **
    **  \returns
    **  \retcode #CFE_SUCCESS  \retdesc \copydoc CFE_SUCCESS  \endcode
    **  \endreturns
    **
    *************************************************************************/
    int32  AcquireConfigPointers(void);




private:
    //Vector<n_x> dynamics(const Vector<float, n_x> &x,const Vector<float, n_u> &u);
	void initStateCov();
	void InitStateSpace();
	void updateStateSpace();
	void updateStateSpaceParams();

	// predict the next state
	void predict();

	// baro
	//int  baroMeasure(Vector<float, n_y_baro> &y);
	void baroCorrect();
	void baroInit();
	void baroCheckTimeout();

	// gps
	//int  gpsMeasure(Vector<double, n_y_gps> &y);
	void gpsCorrect();
	void gpsInit();
	void gpsCheckTimeout();

	// land
	//int  landMeasure(Vector<float, n_y_land> &y);
	void landCorrect();
	void landInit();
	void landCheckTimeout();

	// timeouts
	void checkTimeouts();

	// misc
	//inline float agl() { return _x(X_tz) - _x(X_z); }
	bool landed();
	int getDelayPeriods(float delay, uint8 *periods);





};

#ifdef __cplusplus
}
#endif 

#endif /* PE_APP_H */

/************************/
/*  End of File Comment */
/************************/
