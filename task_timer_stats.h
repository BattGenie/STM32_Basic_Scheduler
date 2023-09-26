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
* @file    task_timer_stats.h
* @author  Nick Mazzilli, P.E.
* @date    09.09.2023
* @ingroup OS
* @brief   Task Timing Statistics
*
*******************************************************************************/

/*
 ****************************************************************************
 * Change Log History
 *****************************************************************************
 * Version   :  DD.MM.YYYY : Author		: Description
 * V00.00.01 :  09.09.2023 : nmazzilli  : Initial Version
 ******************************************************************************
*/

#ifndef TASK_TIMER_STATS_H
#define TASK_TIMER_STATS_H

/*******************************************************************************
* Include Files
*******************************************************************************/

#include <basic_types.h>

/*******************************************************************************
* Public Constants
*******************************************************************************/

#define TASK_TIMER_STATS_ENABLE             	1U


/*******************************************************************************
* Public Type Definitions
*******************************************************************************/

typedef enum
{
    TASK_NAME__CAN_MainRx100ms      = 0U	,
    TASK_NAME__CAN_MainTx100ms          	,
	TASK_NAME__CAN_MainTx1000ms           	,
    TASK_NAME__Sensor_Processing_Main    	,
    TASK_NAME__Model_Proc_MHE_Main    		,
    TASK_NAME__SOP_NMPC_Main          		,
    TASK_NAME__IVT_I2C       				,
    TASK_NAME__LAST
} Task_Names_t;

typedef struct
{
    uint32_t    start_time_msec_u32;
    uint32_t    task_time_msec_u32;
    uint32_t    min_task_time_msec_u32;
    uint32_t    avg_task_time_msec_u32;
    uint32_t    max_task_time_msec_u32;
    uint16_t    task_cntr;
} Task_Stats_t;


/*******************************************************************************
* Public Data Declarations
*******************************************************************************/
/* None */

/*******************************************************************************
* Public Function Declarations
*******************************************************************************/

extern void TASK_TIMER_STATS_Init(void);
extern void TASK_TIMER_STATS_Task_Start( Task_Names_t task );
extern void TASK_TIMER_STATS_Task_End( Task_Names_t task );
extern void TASK_TIMER_STATS_Task_Stats( Task_Stats_t *stats, Task_Names_t task );

/*******************************************************************************
* Unit Test Local Functions and Types
*******************************************************************************/

#ifdef TEST

TESTABLE_STATIC void taskTimerStatsUpdateStats( Task_Names_t task );

#else

#endif


#endif  /* TASK_TIMER_STATS_H */
/* EOF */
