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
* @file    scheduler.h
* @author  Nick Mazzilli, P.E.
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

#ifndef SCHEDULER_H
#define SCHEDULER_H

/*******************************************************************************
* Include Files
*******************************************************************************/

#include <basic_types.h>

/*******************************************************************************
* Public Constants
*******************************************************************************/

/**
 * Define the system tick interval in microseconds
 */
#define SYS_TICK_INTERVAL	 1000UL

/**
 * Background task interval
 */
#define INTERVAL_BACKGROUND  (0UL / SYS_TICK_INTERVAL)

/**
 * The interval to call the 10 ms tasks
 */
#define INTERVAL_10MS        (10000UL / SYS_TICK_INTERVAL)

/**
 * The interval to call the 50 ms tasks
 */
#define INTERVAL_50MS        (50000UL / SYS_TICK_INTERVAL)

/**
 * The interval to call the 100 ms tasks
 */
#define INTERVAL_100MS       (100000UL / SYS_TICK_INTERVAL)

/**
 * The interval to call the 500 ms tasks
 */
#define INTERVAL_500MS       (500000UL / SYS_TICK_INTERVAL)

/**
 * The interval to call the 1000 ms tasks
 */
#define INTERVAL_1000MS       (1000000UL / SYS_TICK_INTERVAL)


/*******************************************************************************
* Public Type Definitions
*******************************************************************************/

typedef struct
{
  	uint16_t interval_u16;				/**< Defines how often a task will run  */
  	uint32_t last_tick_u32;				/**< Stores the last tick task was ran  */
  	void (* const Func)(void);			/**< Function pointer to the task  */
} Task_t;


/*******************************************************************************
* Public Data Declarations
*******************************************************************************/
/* None */

/*******************************************************************************
* Public Function Declarations
*******************************************************************************/

void OS_Init( void );
void OS_Run( const uint32_t tick_u32 );

/*******************************************************************************
* Unit Test Local Functions and Types
*******************************************************************************/

#ifdef TEST

#else

#endif


#endif  /* SCHEDULER_H */
/* EOF */
