/*
 * MyLibrary.c
 *
 *  Created on: Jul 5, 2022
 *      Author: GTC
 */


#include "led.h"

uint8_t driverLed(uint8_t data){

	uint8_t temp = data;
	temp = data*6;

	return temp;
}
