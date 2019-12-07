#ifndef UT_CAMIO_H
#define UT_CAMIO_H

#include "cfe.h"

#define CAMIO_IMAGE_SIZE   (4665654)


typedef struct
{
	char          Payload[CAMIO_IMAGE_SIZE];
} CAMIO_Image_t;



typedef struct
{
	uint32        Count;
	CAMIO_Image_t Image;
} CAMIO_ImageMsg_t;


#endif
