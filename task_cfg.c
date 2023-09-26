/*******************************************************************************
*
* Copyright @ 2023 BattGenie Inc. All Rights Reserved.
* Embedded C Code Header Template
* Author: BattGenie Software Team
*
* BattGenie Inc. asserts copyright ownership of this template and all derivative
* works, including any modifications from this base template.
* Redistribution and use in source and binary forms, with or without modification
* are not permitted without BattGenie Inc. written approval.
* This copyright statement should not be removed or edited.
* Removing it will be considered an copyright violation.
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Please respect the intellectual ownership of this source code
* and do not distribute them to anyone.
*
* @file    template.c
* @author  BattGenie Software Team
* @date    05.09.2023
* @ingroup OS
* @brief   Util functions for embedded c
*
*******************************************************************************/

/*
 ****************************************************************************
 * Change Log History
 *****************************************************************************
 * Version   :  DD.MM.YYYY : Author		: Description
 * V00.00.01 :  05.09.2023 : nmazzilli  : Initial Version
 ******************************************************************************
*/

/*******************************************************************************
* Include Files
*******************************************************************************/

#include <task_cfg.h>
#include <scheduler.h>				// For task interval definitions
#include <task_100ms.h>             // For 100 ms tasks
#include <task_1s.h>             	// For 1000 ms tasks
#include <task_background.h>        // For continuous tasks

/*******************************************************************************
* Private Constants
*******************************************************************************/

/* None */

/*******************************************************************************
* Private Type Definitions
*******************************************************************************/

#ifdef TEST

#else

#endif

/*******************************************************************************
* Private Data Definitions (static)
*******************************************************************************/

static Task_t Tasks[] =
{
	{ INTERVAL_100MS ,      0, TASK_100MS_Main       },
  	{ INTERVAL_1000MS,      0, TASK_1S_Main      },
  	{ INTERVAL_BACKGROUND,  0, TASK_BACKGROUND_Main },
};

static uint8_t const TaskTotalNumber = sizeof(Tasks) / sizeof(*Tasks);


/*******************************************************************************
* Private Function Declarations (static)
*******************************************************************************/

#ifdef TEST

#else

#endif

/*******************************************************************************
* Public Function Definitions
*******************************************************************************/

Task_t * const TASK_CFG_Get( void )
{
	return Tasks;
}

uint8_t const TASK_CFG_NumTasksGet( void )
{
	return TaskTotalNumber;
}

/*******************************************************************************
* Private Function Definitions (static)
*******************************************************************************/

/* None */

/* EOF */
