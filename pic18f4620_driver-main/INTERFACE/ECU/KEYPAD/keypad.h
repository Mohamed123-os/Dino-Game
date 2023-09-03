/* 
 * File:   keypad.h
 * Author: mohamed
 *
 * Created on August 15, 2023, 11:18 AM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

/***************************includes section****************************************/
#include "../../MCAL/GPIO/gpio.h"
/***************************macros sections*****************************************/
#define  ROWS       4
#define  COLOUMS    4
/***************************function like macro section*****************************/

/***************************data types section**************************************/
typedef struct{
    pin_config rows[ROWS];
    pin_config coloums[COLOUMS];
}keypad;
/***************************software interfaces section*****************************/

Std_ReturnType  keypad_init(const keypad *key);
Std_ReturnType  keypad_read(const keypad *key,uint8 *value);

#endif	/* KEYPAD_H */

