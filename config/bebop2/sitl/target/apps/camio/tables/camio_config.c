/*
** Pragmas
*/

/*
** Include Files
*/
#include "cfe_tbl_filedef.h"
#include "camio_tbldefs.h"

/*
** Local Defines
*/

/*
** Local Structure Declarations
*/
static OS_USED CFE_TBL_FileDef_t CFE_TBL_FileDef =
{
    /* Content format: ObjName[64], TblName[38], Desc[32], TgtFileName[20], ObjSize
    **    ObjName - variable name of config table, e.g., CAMIO_ConfigDefTbl[]
    **    TblName - app's table name, e.g., CAMIO.CONFIG_TBL, where CAMIO is the same app name
    **              used in cfe_es_startup.scr, and CAMIO_defConfigTbl is the same table
    **              name passed in to CFE_TBL_Register()
    **    Desc - description of table in string format
    **    TgtFileName[20] - table file name, compiled as .tbl file extension
    **    ObjSize - size of the entire table
    */

    "CAMIO_ConfigTbl", "CAMIO.CONFIG_TBL", "CAMIO default config table",
    "camio_config.tbl", sizeof(CAMIO_ConfigTbl_t)
};

/*
** External Global Variables
*/

/*
** Global Variables
*/

/* Default CAMIO config table data */
CAMIO_ConfigTbl_t CAMIO_ConfigTbl =
{
	/* Table ID */
	1
};

/*
** Local Variables
*/

/*
** Function Prototypes
*/

/*
** Function Definitions
*/

/*=======================================================================================
** End of file camio_config.c
**=====================================================================================*/
    
