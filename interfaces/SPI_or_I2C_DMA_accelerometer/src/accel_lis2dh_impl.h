/**
 ****************************************************************************************
 *
 * @file user_accel_ble_impl.h
 *
 * @brief User Accel BLE project header file.
 *
 * Copyright (C) 2012 Dialog Semiconductor.
 * This computer program includes Confidential, Proprietary Information
 * of Dialog Semiconductor. All Rights Reserved.
 *
 * <bluetooth.support@diasemi.com> and contributors.
 *
 ****************************************************************************************
 */

#ifndef _USER_ACCEL_BLE_IMPL_H_
#define _USER_ACCEL_BLE_IMPL_H_

/**
 ****************************************************************************************
 * @addtogroup APP
 * @ingroup RICOW
 *
 * @brief 
 *
 * @{
 ****************************************************************************************
 */
#include "lis2dh_driver.h"
#include "wkupct_quadec.h"

#if defined(__ACCEL_IF_I2C__)
#include "i2c.h"
#elif defined(__ACCEL_IF_SPI__)
#include "spi.h"
#endif


#define ACCEL_FIFO_WATERMARK 	(30)
#define ACCEL_ODR							(LIS2DH_ODR_10Hz)
#define ACCEL_POWER_MODE			(LIS2DH_NORMAL)


typedef void (*accel_interrupt_handler_cb_t)(void);

typedef enum{
	CMD_TYPE_ACCEL_STATE = 0x00,
	CMD_TYPE_ACCEL_ODR,
	CMD_TYPE_ACCEL_MODE,
}write_cmd_type_t;

typedef enum{
	CMD_ACCEL_STATE_OFF = 0x00,
	CMD_ACCEL_STATE_ON,
}accel_state_t;

struct write_cmd_if_t{
	uint8_t header;
	uint8_t cmd_type;
	uint8_t cmd;
};

typedef struct{
	LIS2DH_ODR_t 		odr;
	LIS2DH_Mode_t 	mode;
	accel_state_t 	state;
	accel_interrupt_handler_cb_t cb;
	uint8_t fifo_watermark;
} accel_config_t;


void accel_lis2dh_handle_watermark_int1(uint8_t * data);

#if defined(__ACCEL_IF_I2C__)
uint8_t accel_lis2dh_start_acquisition(uint8_t acq_len, AxesRaw_t buff[32], i2c_complete_cb_t cb);
#elif defined(__ACCEL_IF_SPI__)
uint8_t accel_lis2dh_start_acquisition(uint8_t acq_len, AxesRaw_t buff[32], spi_cb_t cb);
#endif 

uint8_t accel_lis2dh_init(LIS2DH_ODR_t odr, uint8_t watermark, accel_interrupt_handler_cb_t cb);

uint8_t accel_lis2dh_on(LIS2DH_Mode_t mode);

void accel_lis2dh_prepare_int1_pin( wakeup_handler_function_t callback );
 
 /// @} APP

#endif // _USER_ACCEL_BLE_IMPL_H_
