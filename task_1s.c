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
* @file    task_1s.c
* @author  BattGenie Software Team
* @date    05.09.2023
* @ingroup OS
* @brief   1000 ms Task Function
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

#include <task_1s.h>
#include <model_proc.h>
#include <sop.h>
#include <can.h>
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

static bool_t first_run_b = true;


/*******************************************************************************
* Private Function Declarations (static)
*******************************************************************************/

#ifdef TEST

#else

#endif

/*******************************************************************************
* Public Function Definitions
*******************************************************************************/

void TASK_1S_Main(void)
{
	if ( first_run_b == true )
	{
		first_run_b = false;
		MODEL_PROC_Init();
		SOP_Init();
	}

	TASK_TIMER_STATS_Task_Start( TASK_NAME__CAN_MainTx1000ms );
	canTransmit1000Ms();
	TASK_TIMER_STATS_Task_End( TASK_NAME__CAN_MainTx1000ms );

	//TASK_NAME__Model_Proc_MHE_Main
	TASK_TIMER_STATS_Task_Start( TASK_NAME__Model_Proc_MHE_Main );
	MODEL_PROC_Main();
	TASK_TIMER_STATS_Task_End( TASK_NAME__Model_Proc_MHE_Main );

	TASK_TIMER_STATS_Task_Start( TASK_NAME__SOP_NMPC_Main );
	SOP_Main();
	TASK_TIMER_STATS_Task_End( TASK_NAME__SOP_NMPC_Main );
}

/*******************************************************************************
* Private Function Definitions (static)
*******************************************************************************/

/* None */

/* EOF */
