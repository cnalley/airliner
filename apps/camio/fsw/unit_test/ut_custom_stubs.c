/*
** Include section
*/

#include "cfe.h"
#include "utassert.h"
#include "ut_custom_stubs.h"
#include "ut_custom_hooks.h"
#include <string.h>

Ut_Custom_HookTable_t           Ut_Custom_HookTable;
Ut_Custom_ReturnCodeTable_t     Ut_Custom_ReturnCodeTable[UT_CAMIO_CUSTOM_MAX_INDEX];
CAMIO_Image_t                   Ut_Image;

void Ut_Custom_Reset(void)
{
    memset(&Ut_Custom_HookTable, 0, sizeof(Ut_Custom_HookTable));
    memset(&Ut_Custom_ReturnCodeTable, 0, sizeof(Ut_Custom_ReturnCodeTable));

    memset(&Ut_Image, 0, sizeof(Ut_Image));
}

void Ut_Custom_SetFunctionHook(uint32 Index, void *FunPtr)
{
    if      (Index == UT_CAMIO_CUSTOMINIT_INDEX)       { Ut_Custom_HookTable.CAMIO_CustomInit = FunPtr; }
    else if (Index == UT_CAMIO_CUSTOMGETIMAGE_INDEX)   { Ut_Custom_HookTable.CAMIO_CustomGetImage = FunPtr; }
    else if (Index == UT_CAMIO_CUSTOMCLOSE_INDEX)      { Ut_Custom_HookTable.CAMIO_CustomClose = FunPtr; }
    else
    {
        printf("Unsupported CAMIO Custom Index In SetFunctionHook Call %lu\n", Index);
        UtAssert_True(FALSE, "Unsupported CAMIO Custom Index In SetFunctionHook Call");
    }
}

void Ut_Custom_SetReturnCode(uint32 Index, int32 RtnVal, uint32 CallCnt)
{
    if (Index < UT_CAMIO_CUSTOM_MAX_INDEX)
    {
        Ut_Custom_ReturnCodeTable[Index].Value = RtnVal;
        Ut_Custom_ReturnCodeTable[Index].Count = CallCnt;
    }
    else
    {
        printf("Unsupported CAMIO Custom Index In SetReturnCode Call %lu\n", Index);
        UtAssert_True(FALSE, "Unsupported CAMIO Custom Index In SetReturnCode Call");
    }
}

boolean Ut_Custom_UseReturnCode(uint32 Index)
{
    if (Ut_Custom_ReturnCodeTable[Index].Count > 0)
    {
        Ut_Custom_ReturnCodeTable[Index].Count--;
        if (Ut_Custom_ReturnCodeTable[Index].Count == 0)
            return(TRUE);
    }
    else if (Ut_Custom_ReturnCodeTable[Index].ContinueReturnCodeAfterCountZero == TRUE)
    {
        return(TRUE);
    }
    
    return(FALSE);
}

void Ut_Custom_ContinueReturnCodeAfterCountZero(uint32 Index)
{
    Ut_Custom_ReturnCodeTable[Index].ContinueReturnCodeAfterCountZero = TRUE;
}


int32 CAMIO_CustomInit(void)
{
    /* Check for specified return */
    if (Ut_Custom_UseReturnCode(UT_CAMIO_CUSTOMINIT_INDEX))
        return Ut_Custom_ReturnCodeTable[UT_CAMIO_CUSTOMINIT_INDEX].Value;

    /* Check for Function Hook */
    if (Ut_Custom_HookTable.CAMIO_CustomInit)
        return Ut_Custom_HookTable.CAMIO_CustomInit();

    return CFE_SUCCESS;
}


int32 CAMIO_CustomGetImage(CAMIO_Image_t *Image)
{
    /* Check for specified return */
    if (Ut_Custom_UseReturnCode(UT_CAMIO_CUSTOMGETIMAGE_INDEX))
        return Ut_Custom_ReturnCodeTable[UT_CAMIO_CUSTOMGETIMAGE_INDEX].Value;

    /* Check for Function Hook */
    if (Ut_Custom_HookTable.CAMIO_CustomGetImage)
        return Ut_Custom_HookTable.CAMIO_CustomGetImage(Image);

    memcpy(Image, &Ut_Image, sizeof(Ut_Image));

    return CFE_SUCCESS;
}


int32 CAMIO_CustomClose(void)
{
    /* Check for specified return */
    if (Ut_Custom_UseReturnCode(UT_CAMIO_CUSTOMCLOSE_INDEX))
        return Ut_Custom_ReturnCodeTable[UT_CAMIO_CUSTOMCLOSE_INDEX].Value;

    /* Check for Function Hook */
    if (Ut_Custom_HookTable.CAMIO_CustomClose)
        return Ut_Custom_HookTable.CAMIO_CustomClose();

    return CFE_SUCCESS;
}


void Ut_Custom_SetImage(CAMIO_Image_t *Image)
{
    memcpy(&Ut_Image, Image, sizeof(Ut_Image));
}
