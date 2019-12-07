#ifndef UT_CUSTOM_STUBS_H_
#define UT_CUSTOM_STUBS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "camio.h"

typedef enum 
{
	UT_CAMIO_CUSTOMINIT_INDEX,
	UT_CAMIO_CUSTOMGETIMAGE_INDEX,
	UT_CAMIO_CUSTOMCLOSE_INDEX,
    UT_CAMIO_CUSTOM_MAX_INDEX
} Ut_Custom_INDEX_t;

typedef struct
{
    int32 (*CAMIO_CustomInit)(void);
    int32 (*CAMIO_CustomGetImage)(CAMIO_Image_t *Image);
    int32 (*CAMIO_CustomClose)(void);
} Ut_Custom_HookTable_t;

typedef struct
{
    int32   Value;
    uint32  Count;
    boolean ContinueReturnCodeAfterCountZero;
} Ut_Custom_ReturnCodeTable_t;

void Ut_Custom_Reset(void);
void Ut_Custom_SetFunctionHook(uint32 Index, void *FunPtr);
void Ut_Custom_SetReturnCode(uint32 Index, int32 RtnVal, uint32 CallCnt);
void Ut_Custom_ContinueReturnCodeAfterCountZero(uint32 Index);
void Ut_Custom_SetImage(CAMIO_Image_t *ImageMsg);

#ifdef __cplusplus
}
#endif

#endif
