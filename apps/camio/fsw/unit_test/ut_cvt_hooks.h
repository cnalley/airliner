#ifndef UT_CVT_HOOKS_H_
#define UT_CVT_HOOKS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cfe.h"
#include "utlist.h"
#include "cvt_lib.h"

UtListNode_t* UtList_GetNode(UtListHead_t *List, uint32 Index);
void          UtList_GetData(UtListHead_t *List, uint32 Index, void **Data, uint32 *DataSize);

int32         Ut_CVT_GetContainer(uint16 ContentID, uint32 Size, CVT_ContainerID_t *ContainerID);
int32         Ut_CVT_GetContent(const CVT_ContainerID_t ContainerID, uint32 *UpdateCount, void* Buffer, uint32 *Size);
int32         Ut_CVT_SetContent(const CVT_ContainerID_t ContainerID, void* Buffer, uint32 Size);

#ifdef __cplusplus
}
#endif

#endif
