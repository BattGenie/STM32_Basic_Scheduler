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
* @file    task_cfg.h
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
 * V00.00.01 :  05.01.2023 : nmazzilli  : Initial Version
 ******************************************************************************
*/

#ifndef TASK_CFG
#define TASK_CFG

/*******************************************************************************
* Include Files
*******************************************************************************/

#include <basic_types.h>
#include <scheduler.h>

/*******************************************************************************
* Public Constants
*******************************************************************************/
/* None */


/*******************************************************************************
* Public Type Definitions
*******************************************************************************/
/* None */

/*******************************************************************************
* Public Data Declarations
*******************************************************************************/
/* None */

/*******************************************************************************
* Public Function Declarations
*******************************************************************************/

Task_t * const TASK_CFG_Get( void );
uint8_t const TASK_CFG_NumTasksGet( void );


/*******************************************************************************
* Unit Test Local Functions and Types
*******************************************************************************/

#ifdef TEST

#else

#endif


#endif  /* TASK_CFG */
/* EOF */
