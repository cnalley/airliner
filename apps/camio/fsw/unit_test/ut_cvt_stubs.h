#ifndef UT_CVT_STUBS_H_
#define UT_CVT_STUBS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cvt_lib.h"

typedef enum 
{
	UT_CVT_GETCONTAINER_INDEX,
	UT_CVT_GETCONTENT_INDEX,
	UT_CVT_SETCONTENT_INDEX,
    UT_CVT_MAX_INDEX
} Ut_CVT_INDEX_t;

typedef struct
{
    int32 (*CVT_GetContainer)(uint16 ContentID, uint32 Size, CVT_ContainerID_t *ContainerID);
    int32 (*CVT_GetContent)(const CVT_ContainerID_t ContainerID, uint32 *UpdateCount, void* Buffer, uint32 *Size);
    int32 (*CVT_SetContent)(const CVT_ContainerID_t ContainerID, void* Buffer, uint32 Size);
} Ut_CVT_HookTable_t;

typedef struct
{
    int32   Value;
    uint32  Count;
    boolean ContinueReturnCodeAfterCountZero;
} Ut_CVT_ReturnCodeTable_t;

void Ut_CVT_Reset(void);
void Ut_CVT_SetFunctionHook(uint32 Index, void *FunPtr);
void Ut_CVT_SetReturnCode(uint32 Index, int32 RtnVal, uint32 CallCnt);
void Ut_CVT_ContinueReturnCodeAfterCountZero(uint32 Index);

#ifdef __cplusplus
}
#endif

#endif
