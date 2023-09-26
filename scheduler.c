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
* @file    scheduler.c
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

#include <scheduler.h>
#include <task_cfg.h>
#include <assert.h>
#include <can.h>
#include <meas.h>
#include <charger.h>
#include <csp.h>
#include <vsp.h>
#include <tsp.h>
#include <soc.h>
#include <rte_types.h>
#include <rte.h>
#include <ivt_cnvt.h>
#include <chg_detection.h>
#include <model_proc.h>
#include <sop.h>
#include <task_timer_stats.h>


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

static Task_t *task_ptr = NULL;         			// Task pointer
static uint8_t task_index_u8 = 0;					// Task index


/*******************************************************************************
* Private Function Declarations (static)
*******************************************************************************/

#ifdef TEST

#else

#endif

/*******************************************************************************
* Public Function Definitions
*******************************************************************************/

/******************************************************************************/
void OS_Init(void)
{
	task_ptr = TASK_CFG_Get();    // Get a pointer to the task configuration

	canInit();
	measInit();
	chargerInit();

	RTE_Init();
	CSP_Init();
	VSP_Init();
	TSP_Init();
	IVT_CNVT_Init();
	CHG_DETECTION_Init();

	TASK_TIMER_STATS_Init();
}

/******************************************************************************/
void OS_Run( const uint32_t tick_u32 )
{
	const uint8_t num_tasks_u8 = TASK_CFG_NumTasksGet();		// Number of tasks

	assert( task_ptr != NULL );
	assert( num_tasks_u8 != 0 );

	/* Loop through the task configuration block and calculate whether there is
	 * a task that is ready to execute. If there is, execute that task. Otherwise
	 * continue looping.
	 */
	for ( task_index_u8 = 0; task_index_u8 < num_tasks_u8; task_index_u8++)
	{
		assert( task_index_u8 < num_tasks_u8 );

		if( ( tick_u32 - task_ptr[ task_index_u8 ].last_tick_u32 ) >= task_ptr[ task_index_u8 ].interval_u16 )
		{
			assert( task_ptr[ task_index_u8 ].Func != NULL );

			(*task_ptr[ task_index_u8 ].Func)();        // Execute Task
			task_ptr[ task_index_u8 ].last_tick_u32 = tick_u32;  // Save last tick the task was ran.
		}
	}
}


/*******************************************************************************
* Private Function Definitions (static)
*******************************************************************************/

/* None */

/* EOF */
