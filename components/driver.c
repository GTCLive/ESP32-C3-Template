/*
 * MyLibrary.c
 *
 *  Created on: Jul 5, 2022
 *      Author: GTC
 */


#include "driver.h"

uint8_t driver(uint8_t data){

	uint8_t temp = data;
	temp = data*8;

	return temp;
}
