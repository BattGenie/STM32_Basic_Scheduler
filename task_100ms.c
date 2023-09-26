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
* @file    task_100ms.c
* @author  BattGenie Software Team
* @date    05.09.2023
* @ingroup OS
* @brief   100 ms Task Function
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

#include <task_100ms.h>
#include <can.h>
#include <meas.h>
#include <csp.h>
#include <vsp.h>
#include <tsp.h>
#include <soc.h>
#include <rte_types.h>
#include <rte.h>
#include <ivt_cnvt.h>
#include <chg_detection.h>
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

/* None */


/*******************************************************************************
* Private Function Declarations (static)
*******************************************************************************/

#ifdef TEST

#else

#endif

/*******************************************************************************
* Public Function Definitions
*******************************************************************************/

void TASK_100MS_Main(void)
{
	TASK_TIMER_STATS_Task_Start( TASK_NAME__IVT_I2C );
	measRun();
	TASK_TIMER_STATS_Task_End( TASK_NAME__IVT_I2C );

	TASK_TIMER_STATS_Task_Start( TASK_NAME__CAN_MainRx100ms );
	canReceive();
	TASK_TIMER_STATS_Task_End( TASK_NAME__CAN_MainRx100ms );

	TASK_TIMER_STATS_Task_Start( TASK_NAME__Sensor_Processing_Main );
	CSP_Main();
	VSP_Main();
	TSP_Main();
	IVT_CNVT_Main();
	CHG_DETECTION_Main();

	TASK_TIMER_STATS_Task_End( TASK_NAME__Sensor_Processing_Main );

	TASK_TIMER_STATS_Task_Start( TASK_NAME__CAN_MainTx100ms );
	canTransmit100Ms();
	TASK_TIMER_STATS_Task_End( TASK_NAME__CAN_MainTx100ms );
}

/*******************************************************************************
* Private Function Definitions (static)
*******************************************************************************/

/* None */

/* EOF */
