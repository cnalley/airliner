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

#ifdef __cplusplus
extern "C" {
#endif

#include "mac_app.hpp"

/************************************************************************
** Function Definitions
*************************************************************************/


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Initialize Config Table                                         */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int32 MAC::InitConfigTbl()
{
    int32  iStatus = 0;

    /* Register Param table */
    iStatus = CFE_TBL_Register(&ParamTblHdl,
                               MAC_PARAM_TABLENAME,
                               (sizeof(MAC_ParamTbl_t)),
                               CFE_TBL_OPT_DEFAULT,
                               MAC::ValidateParamTbl);
    if (iStatus != CFE_SUCCESS)
    {
        /* Note, a critical table could return another nominal code.  If this table is
         * made critical this logic would have to change. */
        (void) CFE_EVS_SendEvent(MAC_INIT_ERR_EID, CFE_EVS_ERROR,
                                 "Failed to register param table (0x%08X)",
                                 (unsigned int)iStatus);
        goto MAC_InitConfigTbl_Exit_Tag;
    }

    /* Load Config table file */
    iStatus = CFE_TBL_Load(ParamTblHdl,
                           CFE_TBL_SRC_FILE,
                           MAC_PARAM_TABLE_FILENAME);
    if (iStatus != CFE_SUCCESS)
    {
        /* Note, CFE_SUCCESS is for a successful full table load.  If a partial table
           load is desired then this logic would have to change. */
        (void) CFE_EVS_SendEvent(MAC_INIT_ERR_EID, CFE_EVS_ERROR,
                                 "Failed to load Config Table (0x%08X)",
                                 (unsigned int)iStatus);
        goto MAC_InitConfigTbl_Exit_Tag;
    }

    iStatus = AcquireConfigPointers();

MAC_InitConfigTbl_Exit_Tag:
    return (iStatus);
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Validate PWM Configuration Table                                */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int32 MAC::ValidateParamTbl(void* ConfigTblPtr)
{
    int32  iStatus = CFE_SUCCESS;
    char Param[MAC_PARAM_NAME_MAX_LEN];
    MAC_ParamTbl_t* MAC_ParamTblPtr = (MAC_ParamTbl_t*)(ConfigTblPtr);

    if (MAC_ParamTblPtr-> < _MIN ||
        MAC_ParamTblPtr-> > _MAX)
    {
        snprintf(Param, MAC_PARAM_NAME_MAX_LEN, "");
        iStatus = -1;
        goto MAC_ValidateConfigTbl_Exit_Tag;
    }
    
    if (MAC_ParamTblPtr-> < _MIN ||
        MAC_ParamTblPtr-> > _MAX)
    {
        snprintf(Param, MAC_PARAM_NAME_MAX_LEN, "");
        iStatus = -1;
        goto MAC_ValidateConfigTbl_Exit_Tag;
    }
    
    if (MAC_ParamTblPtr-> < _MIN ||
        MAC_ParamTblPtr-> > _MAX)
    {
        snprintf(Param, MAC_PARAM_NAME_MAX_LEN, "");
        iStatus = -1;
        goto MAC_ValidateConfigTbl_Exit_Tag;
    }
    
    if (MAC_ParamTblPtr-> < _MIN ||
        MAC_ParamTblPtr-> > _MAX)
    {
        snprintf(Param, MAC_PARAM_NAME_MAX_LEN, "");
        iStatus = -1;
        goto MAC_ValidateConfigTbl_Exit_Tag;
    }
    
    if (MAC_ParamTblPtr-> < _MIN ||
        MAC_ParamTblPtr-> > _MAX)
    {
        snprintf(Param, MAC_PARAM_NAME_MAX_LEN, "");
        iStatus = -1;
        goto MAC_ValidateConfigTbl_Exit_Tag;
    }
    
    if (MAC_ParamTblPtr-> < _MIN ||
        MAC_ParamTblPtr-> > _MAX)
    {
        snprintf(Param, MAC_PARAM_NAME_MAX_LEN, "");
        iStatus = -1;
        goto MAC_ValidateConfigTbl_Exit_Tag;
    }
    
    if (MAC_ParamTblPtr-> < _MIN ||
        MAC_ParamTblPtr-> > _MAX)
    {
        snprintf(Param, MAC_PARAM_NAME_MAX_LEN, "");
        iStatus = -1;
        goto MAC_ValidateConfigTbl_Exit_Tag;
    }
    
    if (MAC_ParamTblPtr-> < _MIN ||
        MAC_ParamTblPtr-> > _MAX)
    {
        snprintf(Param, MAC_PARAM_NAME_MAX_LEN, "");
        iStatus = -1;
        goto MAC_ValidateConfigTbl_Exit_Tag;
    }
    
    if (MAC_ParamTblPtr-> < _MIN ||
        MAC_ParamTblPtr-> > _MAX)
    {
        snprintf(Param, MAC_PARAM_NAME_MAX_LEN, "");
        iStatus = -1;
        goto MAC_ValidateConfigTbl_Exit_Tag;
    }
    
    if (MAC_ParamTblPtr-> < _MIN ||
        MAC_ParamTblPtr-> > _MAX)
    {
        snprintf(Param, MAC_PARAM_NAME_MAX_LEN, "");
        iStatus = -1;
        goto MAC_ValidateConfigTbl_Exit_Tag;
    }
    
    if (MAC_ParamTblPtr-> < _MIN ||
        MAC_ParamTblPtr-> > _MAX)
    {
        snprintf(Param, MAC_PARAM_NAME_MAX_LEN, "");
        iStatus = -1;
        goto MAC_ValidateConfigTbl_Exit_Tag;
    }
    
    if (MAC_ParamTblPtr-> < _MIN ||
        MAC_ParamTblPtr-> > _MAX)
    {
        snprintf(Param, MAC_PARAM_NAME_MAX_LEN, "");
        iStatus = -1;
        goto MAC_ValidateConfigTbl_Exit_Tag;
    }
    
    if (MAC_ParamTblPtr-> < _MIN ||
        MAC_ParamTblPtr-> > _MAX)
    {
        snprintf(Param, MAC_PARAM_NAME_MAX_LEN, "");
        iStatus = -1;
        goto MAC_ValidateConfigTbl_Exit_Tag;
    }
    
    if (MAC_ParamTblPtr-> < _MIN ||
        MAC_ParamTblPtr-> > _MAX)
    {
        snprintf(Param, MAC_PARAM_NAME_MAX_LEN, "");
        iStatus = -1;
        goto MAC_ValidateConfigTbl_Exit_Tag;
    }
    
    if (MAC_ParamTblPtr-> < _MIN ||
        MAC_ParamTblPtr-> > _MAX)
    {
        snprintf(Param, MAC_PARAM_NAME_MAX_LEN, "");
        iStatus = -1;
        goto MAC_ValidateConfigTbl_Exit_Tag;
    }
    
    if (MAC_ParamTblPtr-> < _MIN ||
        MAC_ParamTblPtr-> > _MAX)
    {
        snprintf(Param, MAC_PARAM_NAME_MAX_LEN, "");
        iStatus = -1;
        goto MAC_ValidateConfigTbl_Exit_Tag;
    }

MAC_ValidateConfigTbl_Exit_Tag:

    if (iStatus != CFE_SUCCESS)
    {
        (void) CFE_EVS_SendEvent(MAC_TBL_VALIDATE_ERR_EID, CFE_EVS_ERROR,
                                 "Table validation failed for parameter (%s)",
                                 Param);
    }
    
    return iStatus;  
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Acquire Config Pointers                                         */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int32 MAC::AcquireConfigPointers(void)
{
    int32 iStatus = CFE_SUCCESS;

    /*
    ** Release the table
    */
    (void) CFE_TBL_ReleaseAddress(ParamTblHdl);

    /*
    ** Manage the table
    */
    iStatus = CFE_TBL_Manage(ParamTblHdl);
    if ((iStatus != CFE_SUCCESS) && (iStatus != CFE_TBL_INFO_UPDATED))
    {
        (void) CFE_EVS_SendEvent(MAC_CONFIG_TABLE_ERR_EID, CFE_EVS_ERROR,
                                 "Failed to manage PWM Config table (0x%08X)",
                                 (unsigned int)iStatus);
        goto MAC_AcquireConfigPointers_Exit_Tag;
    }

    /*
    ** Get a pointer to the table
    */
    iStatus = CFE_TBL_GetAddress((void**)&ParamTblPtr,
                                 ParamTblHdl);
    if (iStatus == CFE_TBL_INFO_UPDATED)
    {
        UpdateParams();
        iStatus = CFE_SUCCESS;
    }
    else if(iStatus != CFE_SUCCESS)
    {
        ParamTblPtr = 0;
        (void) CFE_EVS_SendEvent(MAC_CONFIG_TABLE_ERR_EID, CFE_EVS_ERROR,
                                 "Failed to get Param table's address (0x%08X)",
                                 (unsigned int)iStatus);
    }

MAC_AcquireConfigPointers_Exit_Tag:
    return (iStatus);

}


#ifdef __cplusplus
}
#endif

/************************/
/*  End of File Comment */
/************************/
    
