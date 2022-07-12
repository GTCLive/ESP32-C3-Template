/*
 * MyLibrary.c
 *
 *  Created on: Jul 5, 2022
 *      Author: GTC
 */


#include "button.h"

uint8_t myButton(uint8_t data){

	uint8_t temp = data;
	temp = data*12;

	return temp;
}
