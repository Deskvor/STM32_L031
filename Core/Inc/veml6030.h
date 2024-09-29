#ifndef __VEML6030_H_
#define __VEML6030_H_

#include "stm32l0xx_hal.h"

#define VEML6030_I2C_ADDR 0x10 // (I2C 7-bit address) (0010000 = 0x10)

// VEML6030 Register Addresses
#define VEML6030_ALS_CONF          0x00  // Configuration register (controls gain, integration time, etc.)
#define VEML6030_ALS_WH_THRESHOLD  0x01  // ALS high threshold window setting (for interrupt generation)
#define VEML6030_ALS_WL_THRESHOLD  0x02  // ALS low threshold window setting (for interrupt generation)
#define VEML6030_POWER_SAVE        0x03  // Power saving modes register (used for saving power)
#define VEML6030_ALS_DATA          0x04  // ALS output data register (read the ambient light level)
#define VEML6030_WHITE_DATA        0x05  // White channel output data register (reads white light levels)
#define VEML6030_INT_STATUS        0x06  // Interrupt status register (indicates if an interrupt occurred)
#define VEML6030_ID                0x07  // ID register (contains the sensor's identification value)

void VEML6030_Init(I2C_HandleTypeDef *hi2c);
uint16_t VEML6030_ReadALS(I2C_HandleTypeDef *hi2c);
void VEML6030_WriteRegister(I2C_HandleTypeDef *hi2c, uint8_t reg, uint16_t value);
uint16_t VEML6030_ReadRegister(I2C_HandleTypeDef *hi2c, uint8_t reg);

#endif /* __VEML6030_H_ */
