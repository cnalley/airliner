#ifndef UT_CUSTOM_HOOKS_H_
#define UT_CUSTOM_HOOKS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cfe.h"
#include "camio.h"

int32    Ut_CAMIO_CustomInit(void);
int32    Ut_CAMIO_CustomGetImage(CAMIO_Image_t *Image);
int32    Ut_CAMIO_CustomClose(void);

#ifdef __cplusplus
}
#endif

#endif
