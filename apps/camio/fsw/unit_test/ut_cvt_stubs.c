/*
** Include section
*/

#include "cfe.h"
#include "utassert.h"
#include "ut_cvt_stubs.h"
#include "ut_cvt_hooks.h"
#include <string.h>

Ut_CVT_HookTable_t           Ut_CVT_HookTable;
Ut_CVT_ReturnCodeTable_t     Ut_CVT_ReturnCodeTable[UT_CVT_MAX_INDEX];

extern void Ut_CVT_ClearDataStore(void);


void Ut_CVT_Reset(void)
{
    memset(&Ut_CVT_HookTable, 0, sizeof(Ut_CVT_HookTable));
    memset(&Ut_CVT_ReturnCodeTable, 0, sizeof(Ut_CVT_ReturnCodeTable));

    Ut_CVT_ClearDataStore();
}

void Ut_CVT_SetFunctionHook(uint32 Index, void *FunPtr)
{
    if      (Index == UT_CVT_GETCONTAINER_INDEX)            { Ut_CVT_HookTable.CVT_GetContainer = FunPtr; }
    else if (Index == UT_CVT_GETCONTENT_INDEX)              { Ut_CVT_HookTable.CVT_GetContent = FunPtr; }
    else if (Index == UT_CVT_SETCONTENT_INDEX)              { Ut_CVT_HookTable.CVT_SetContent = FunPtr; }
    else
    {
        printf("Unsupported CVT Index In SetFunctionHook Call %lu\n", Index);
        UtAssert_True(FALSE, "Unsupported CVT Index In SetFunctionHook Call");
    }
}

void Ut_CVT_SetReturnCode(uint32 Index, int32 RtnVal, uint32 CallCnt)
{
    if (Index < UT_CVT_MAX_INDEX)
    {
        Ut_CVT_ReturnCodeTable[Index].Value = RtnVal;
        Ut_CVT_ReturnCodeTable[Index].Count = CallCnt;
    }
    else
    {
        printf("Unsupported CVT Index In SetReturnCode Call %lu\n", Index);
        UtAssert_True(FALSE, "Unsupported CVT Index In SetReturnCode Call");
    }
}

boolean Ut_CVT_UseReturnCode(uint32 Index)
{
    if (Ut_CVT_ReturnCodeTable[Index].Count > 0)
    {
        Ut_CVT_ReturnCodeTable[Index].Count--;
        if (Ut_CVT_ReturnCodeTable[Index].Count == 0)
            return(TRUE);
    }
    else if (Ut_CVT_ReturnCodeTable[Index].ContinueReturnCodeAfterCountZero == TRUE)
    {
        return(TRUE);
    }
    
    return(FALSE);
}

void Ut_CVT_ContinueReturnCodeAfterCountZero(uint32 Index)
{
    Ut_CVT_ReturnCodeTable[Index].ContinueReturnCodeAfterCountZero = TRUE;
}


int32 CVT_GetContainer(uint16 ContentID, uint32 Size, CVT_ContainerID_t *ContainerID)
{
    /* Check for specified return */
    if (Ut_CVT_UseReturnCode(UT_CVT_GETCONTAINER_INDEX))
        return Ut_CVT_ReturnCodeTable[UT_CVT_GETCONTAINER_INDEX].Value;

    /* Check for Function Hook */
    if (Ut_CVT_HookTable.CVT_GetContainer)
        return Ut_CVT_HookTable.CVT_GetContainer(ContentID, Size, ContainerID);

    return Ut_CVT_GetContainer(ContentID, Size, ContainerID);
}


int32 CVT_GetContent(const CVT_ContainerID_t ContainerID, uint32 *UpdateCount, void* Buffer, uint32 *Size)
{
    /* Check for specified return */
    if (Ut_CVT_UseReturnCode(UT_CVT_GETCONTENT_INDEX))
        return Ut_CVT_ReturnCodeTable[UT_CVT_GETCONTENT_INDEX].Value;

    /* Check for Function Hook */
    if (Ut_CVT_HookTable.CVT_GetContent)
        return Ut_CVT_HookTable.CVT_GetContent(ContainerID, UpdateCount, Buffer, Size);

    return Ut_CVT_GetContent(ContainerID, UpdateCount, Buffer, Size);
}


int32 CVT_SetContent(const CVT_ContainerID_t ContainerID, void* Buffer, uint32 Size)
{
    /* Check for specified return */
    if (Ut_CVT_UseReturnCode(UT_CVT_SETCONTENT_INDEX))
        return Ut_CVT_ReturnCodeTable[UT_CVT_SETCONTENT_INDEX].Value;

    /* Check for Function Hook */
    if (Ut_CVT_HookTable.CVT_SetContent)
        return Ut_CVT_HookTable.CVT_SetContent(ContainerID, Buffer, Size);

    return Ut_CVT_SetContent(ContainerID, Buffer, Size);
}
