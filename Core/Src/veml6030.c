#include "veml6030.h"

// Function to initialize VEML6030 sensor
void VEML6030_Init(I2C_HandleTypeDef *hi2c) {
	// Set ALS Configuration: Gain x1, Integration time 100ms, No interrupt
	uint16_t als_conf = 0x0000;  // Default config
	VEML6030_WriteRegister(hi2c, VEML6030_ALS_CONF, als_conf);
}

// Function to read ALS (ambient light sensor) value
uint16_t VEML6030_ReadALS(I2C_HandleTypeDef *hi2c) {
	return VEML6030_ReadRegister(hi2c, VEML6030_ALS_DATA);
}

// Function to write a 16-bit value to a register
void VEML6030_WriteRegister(I2C_HandleTypeDef *hi2c, uint8_t reg,
		uint16_t value) {

	uint8_t data[3];
	data[0] = reg;               // Register address
	data[1] = value & 0xFF;      // Lower byte
	data[2] = (value >> 8) & 0xFF; // Upper byte
	HAL_I2C_Master_Transmit(hi2c, VEML6030_I2C_ADDR << 1, data, 3, 200);
	HAL_StatusTypeDef status = HAL_I2C_Master_Transmit(hi2c,
			VEML6030_I2C_ADDR << 1, data, 3, 200);
	if (status != HAL_OK) {
		printf("I2C Transmit Error: %d\n", status);
	}
}

// Function to read a 16-bit value from a register
uint16_t VEML6030_ReadRegister(I2C_HandleTypeDef *hi2c, uint8_t reg) {
	uint8_t data[2];
	HAL_I2C_Master_Transmit(hi2c, VEML6030_I2C_ADDR << 1, &reg, 1, 200);
	HAL_I2C_Master_Receive(hi2c, VEML6030_I2C_ADDR << 1, data, 2, 200);
	return (uint16_t) (data[1] << 8 | data[0]);


	HAL_StatusTypeDef status = HAL_I2C_Master_Transmit(hi2c,
			VEML6030_I2C_ADDR << 1, data, 3, 200);
	if (status != HAL_OK) {
		printf("I2C Transmit Error: %d\n", status);
	}
	status = HAL_I2C_Master_Receive(hi2c,
			VEML6030_I2C_ADDR << 1, data, 3, 200);
	if (status != HAL_OK) {
		printf("I2C Receive Error: %d\n", status);
	}
}
