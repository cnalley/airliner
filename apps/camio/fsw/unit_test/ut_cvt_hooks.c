
#include "cfe.h"
#include "utlist.h"
#include "uttools.h"
#include "ut_cvt_hooks.h"
#include <string.h>


typedef struct
{
	uint16 ID;
	uint32 Size;
	uint32 Offset;
	uint32 UpdateCount;
	uint32 MutexID;
} CVT_Registration_t;


typedef struct
{
	CVT_Registration_t Registration[CVT_MAX_REGISTRATIONS];
	uint32             Cursor;
} CVT_Registry_t;


typedef struct
{
	CVT_Registry_t     Registry;
	uint32             DataStore[CVT_DATA_STORE_SIZE];
} CVT_DataStoreTable_t;


CVT_DataStoreTable_t CVT_DataStoreTable;


void Ut_CVT_ClearDataStore(void)
{
	memset(&CVT_DataStoreTable, 0, sizeof(CVT_DataStoreTable));
}



int32 Ut_CVT_GetContainer(uint16 ContentID, uint32 Size, CVT_ContainerID_t *ContainerID)
{
	int32  status = CVT_SUCCESS;
	uint32 i = 0;

	if(ContentID == 0)
	{
		status = CVT_INVALID_ID;
		goto end_of_function;
	}

	/* Try to find the name already registered. */
	for(i = 0; i < CVT_MAX_REGISTRATIONS; ++i)
	{
		/* Is this entry the same name? */
		if(ContentID == CVT_DataStoreTable.Registry.Registration[i].ID)
		{
			/* It is the same name.  Is the registered size the same size? */
			if(Size != CVT_DataStoreTable.Registry.Registration[i].Size)
			{
				/* This is not the correct size. */
				status = CVT_INCORRECT_SIZE;
				goto end_of_function;
			}
			else
			{
				/* It is the same size.  Return this container ID. */
				status = CVT_SUCCESS;
				*ContainerID = i;
				goto end_of_function;
			}
		}
	}

	/* If we got this far, we didn't find an entry with the same name.  Find an empty one. */
	for(i = 0; i < CVT_MAX_REGISTRATIONS; ++i)
	{
		/* Is this name empty? */
		if(0 == CVT_DataStoreTable.Registry.Registration[i].Size)
		{
			/* This is empty.  Do we have enough room to allocate from the data store? */
			if(CVT_DataStoreTable.Registry.Cursor + Size <= CVT_DATA_STORE_SIZE)
			{
				char semName[15];

				/* Yes.  Now allocate space by setting the offset and moving the cursor. */
				CVT_DataStoreTable.Registry.Registration[i].Offset = CVT_DataStoreTable.Registry.Cursor;
				CVT_DataStoreTable.Registry.Cursor += Size;
			}
			else
			{
				/* There isn't enough room in the data store. */
				status = CVT_DATASTORE_FULL;
				goto end_of_function;
			}

			break;
		}
	}

	/* Check to see if we found any empty value. */
	if(i == CVT_MAX_REGISTRATIONS)
	{
		/* No.  The registry is full. */
		status = CVT_REGISTRY_FULL;
		goto end_of_function;
	}

	/* Now store the name and size. */
	CVT_DataStoreTable.Registry.Registration[i].ID = ContentID;
	CVT_DataStoreTable.Registry.Registration[i].Size = Size;
	*ContainerID = i;
	status = CVT_SUCCESS;

end_of_function:

	return status;
}


int32 Ut_CVT_GetContent(const CVT_ContainerID_t ContainerID, uint32 *UpdateCount, void* Buffer, uint32 *Size)
{
	int32  status = CVT_SUCCESS;
	uint32 i = 0;

	if(ContainerID >= CVT_MAX_REGISTRATIONS)
	{
		status = CVT_INVALID_ID;
		goto end_of_function;
	}

	if(CVT_DataStoreTable.Registry.Registration[ContainerID].Size == 0)
	{
		status = CVT_INVALID_ID;
		goto end_of_function;

	}

	if(CVT_DataStoreTable.Registry.Registration[ContainerID].Size != *Size)
	{
		status = CVT_INVALID_SIZE;
		goto end_of_function;
	}

	*UpdateCount = CVT_DataStoreTable.Registry.Registration[ContainerID].UpdateCount;
	*Size = CVT_DataStoreTable.Registry.Registration[i].Size;
	memcpy(Buffer, &CVT_DataStoreTable.DataStore[CVT_DataStoreTable.Registry.Registration[i].Offset], *Size);

	status = CVT_SUCCESS;

end_of_function:

    return status;
}


int32 Ut_CVT_SetContent(const CVT_ContainerID_t ContainerID, void* Buffer, uint32 Size)
{
	int32  status = CVT_SUCCESS;
	uint32 i = 0;

	if(ContainerID >= CVT_MAX_REGISTRATIONS)
	{
		status = CVT_INVALID_ID;
		goto end_of_function;
	}

	if(CVT_DataStoreTable.Registry.Registration[ContainerID].Size == 0)
	{
		status = CVT_INVALID_ID;
		goto end_of_function;

	}

	if(CVT_DataStoreTable.Registry.Registration[ContainerID].Size != Size)
	{
		status = CVT_INVALID_SIZE;
		goto end_of_function;
	}

	CVT_DataStoreTable.Registry.Registration[ContainerID].UpdateCount++;
	memcpy(&CVT_DataStoreTable.DataStore[CVT_DataStoreTable.Registry.Registration[i].Offset], Buffer, Size);

	status = CVT_SUCCESS;

end_of_function:

    return status;
}
