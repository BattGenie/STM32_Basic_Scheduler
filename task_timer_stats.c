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
* @file    task_timer_stats.c
* @author  BattGenie Software Team
* @date    09.09.2023
* @ingroup OS
* @brief   Task Timing Statistics Main Function
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

/*******************************************************************************
* Include Files
*******************************************************************************/

#include <task_timer_stats.h>
#include <stm32f0xx_hal.h>
#include <util.h>

/*******************************************************************************
* Private Constants
*******************************************************************************/


#define TASK_TIMER_STATS_BUF_COUNT          	( (uint8_t) 10U )
#define TASK_TIMER_STATS_RESET_STATS_CNT    	( (uint16_t) 500U )

/*******************************************************************************
* Private Type Definitions
*******************************************************************************/

#ifdef TEST

#else

#endif

/*******************************************************************************
* Private Data Definitions (static)
*******************************************************************************/

TESTABLE_STATIC Task_Stats_t 			        task_timer_stats_array[ TASK_NAME__LAST ];
TESTABLE_STATIC uint32_t                        task_timer_stats_buffer[ TASK_NAME__LAST ][ TASK_TIMER_STATS_BUF_COUNT ];
TESTABLE_STATIC Util_Circ_Buff_U32_t            task_timer_stats_cir_buffer_array[ TASK_NAME__LAST ];


/*******************************************************************************
* Private Function Declarations (static)
*******************************************************************************/

#ifdef TEST

#else

TESTABLE_STATIC void taskTimerStatsUpdateStats( Task_Names_t task );

#endif

/*******************************************************************************
* Public Function Definitions
*******************************************************************************/

/******************************************************************************/
extern void TASK_TIMER_STATS_Init(void)
{
#if TASK_TIMER_STATS_ENABLE
    uint8_t idx_u8 = 0U;
    for( idx_u8 = 0U; idx_u8 < TASK_NAME__LAST; idx_u8++ )
    {
    	task_timer_stats_array[ idx_u8 ].start_time_msec_u32 = 0U;
    	task_timer_stats_array[ idx_u8 ].task_time_msec_u32 = 0U;
    	task_timer_stats_array[ idx_u8 ].avg_task_time_msec_u32 = 0U;
    	task_timer_stats_array[ idx_u8 ].max_task_time_msec_u32 = U32_MIN;
    	task_timer_stats_array[ idx_u8 ].min_task_time_msec_u32 = U32_MAX;
    	task_timer_stats_array[ idx_u8 ].task_cntr = 0U;
    	UTIL_CircularBuffInitU32( &task_timer_stats_cir_buffer_array[ idx_u8 ], task_timer_stats_buffer[ idx_u8 ], 0U, TASK_TIMER_STATS_BUF_COUNT  );
    }
#else

#endif
}

/******************************************************************************/
extern void TASK_TIMER_STATS_Task_Start( Task_Names_t task )
{
#if TASK_TIMER_STATS_ENABLE
    if ( task < TASK_NAME__LAST )
    {
    	task_timer_stats_array[ task ].start_time_msec_u32 = HAL_GetTick();
    }
#else

#endif
}

/******************************************************************************/
extern void TASK_TIMER_STATS_Task_End( Task_Names_t task )
{
#if TASK_TIMER_STATS_ENABLE
    if( task < TASK_NAME__LAST )
    {
        uint32_t end_time = HAL_GetTick();

        task_timer_stats_array[ task ].task_time_msec_u32 =
                end_time - task_timer_stats_array[ task ].start_time_msec_u32;

        taskTimerStatsUpdateStats( task );
    }
#else

#endif
}

/******************************************************************************/
extern void TASK_TIMER_STATS_Task_Stats( Task_Stats_t *stats, Task_Names_t task )
{
#if TASK_TIMER_STATS_ENABLE
    if( task < TASK_NAME__LAST )
    {
        *stats = task_timer_stats_array[ task ];
    }
#else

#endif
}


/*******************************************************************************
* Private Function Definitions (static)
*******************************************************************************/

TESTABLE_STATIC void taskTimerStatsUpdateStats( Task_Names_t task )
{
#if TASK_TIMER_STATS_ENABLE
    if( task < TASK_NAME__LAST )
    {
    	UTIL_CircularBuffInsertU32( &task_timer_stats_cir_buffer_array[ task ], task_timer_stats_array[ task ].task_time_msec_u32 );

        uint32_t curr_task_tm_u32 = task_timer_stats_array[ task ].task_time_msec_u32;

        if( task_timer_stats_array[ task ].task_cntr > TASK_TIMER_STATS_RESET_STATS_CNT )
        {
            /* Stats are reset */
        	task_timer_stats_array[ task ].task_cntr = 0U;
        	task_timer_stats_array[ task ].max_task_time_msec_u32 = curr_task_tm_u32;
        	task_timer_stats_array[ task ].min_task_time_msec_u32 = curr_task_tm_u32;
        }
        else
        {
        	task_timer_stats_array[ task ].task_cntr++;
            if( curr_task_tm_u32 > task_timer_stats_array[ task ].max_task_time_msec_u32 )
            {
            	task_timer_stats_array[ task ].max_task_time_msec_u32 = curr_task_tm_u32;
            }
            else
            {
                /* No Need to reset Max */
            }

            if( curr_task_tm_u32 < task_timer_stats_array[ task ].min_task_time_msec_u32 )
            {
            	task_timer_stats_array[ task ].min_task_time_msec_u32 = curr_task_tm_u32;
            }
            else
            {
                /* No Need to reset Min */
            }

            /* Update Average */
            task_timer_stats_array[ task ].avg_task_time_msec_u32 =
            		UTIL_CircularBuffRollingAvgU32_u32( &task_timer_stats_cir_buffer_array[ task ] );
        }
    }
#else

#endif
}

/* EOF */
