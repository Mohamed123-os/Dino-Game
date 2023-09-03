/* 
 * File:   timer1.h
 * Author: mohamed
 *
 * Created on September 2, 2023, 12:26 AM
 */

#ifndef TIMER1_H
#define	TIMER1_H


/***************************includes section****************************************/
#include "../../MCAL/GPIO/gpio.h"
#include "../proc/pic18f4620.h"
/***************************macros sections*****************************************/
/***************************function like macro section*****************************/
/***************************data types section**************************************/
/***************************software interfaces section*****************************/
void Timer1_init();
void Timer1_delay(uint16 time);

    

#endif	/* TIMER1_H */

