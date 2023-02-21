/**
 ****************************************************************************************
 *
 * @file user_ble_gap.h
 *
 * @brief Header for ble tools for scanning and formatting ble data
 *
 * Copyright (C) 2012-2020 Dialog Semiconductor.
 * This computer program includes Confidential, Proprietary Information
 * of Dialog Semiconductor. All Rights Reserved.
 *
 ****************************************************************************************
 */
 
#ifndef _USER_BLE_GAP_H_
#define _USER_BLE_GAP_H_

#include "app_easy_timer.h"

/*
 * TYPE DEFINITIONS
 ****************************************************************************************
 */

typedef enum{
		BLE_GAP_ERROR_NO_ERROR,
		BLE_GAP_ERROR_INVALID_PARAMS,	
}ble_gap_error_t;

/*
 * DEFINES
 ****************************************************************************************
 */

/*Min and Max are not limitations of the stack but these windows provide better functionality*/
#define BLE_MIN_SCAN_INTVL_MS		(uint16_t)(10)
#if defined (__DA14531__)
//531 has an LDO refresh period where we need to give it time to refresh
#define BLE_MAX_SCAN_INTVL_MS		(uint16_t)(50)
#else
#define BLE_MAX_SCAN_INTVL_MS		(uint16_t)(250)
#endif

#define MAX_ADV_PAYLOAD_LEN			(uint16_t)(40)
#define NO_NAME_FOUND						"N/A"
#define NO_NAME_FOUND_LEN				(size_t)sizeof(NO_NAME_FOUND)

/*
 * FUNCTION DECLARATIONS
 ****************************************************************************************
 */
const char *format_local_name(const uint8_t *, const uint8_t);
const char *format_bd_address(const struct bd_addr *);
timer_hnd set_routine_timer(void);
ble_gap_error_t user_ble_gap_start_scan(bool, uint16_t, uint16_t, bool);

#endif // _USER_BLE_GAP_H_
