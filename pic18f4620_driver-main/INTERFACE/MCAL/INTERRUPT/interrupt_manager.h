/* 
 * File:   interrupt_manager.h
 * Author: mohamed
 *
 * Created on August 27, 2023, 12:11 PM
 */

#ifndef INTERRUPT_MANAGER_H
#define	INTERRUPT_MANAGER_H


/***************************includes section****************************************/
#include"interrupt_config.h"
/***************************macros sections*****************************************/
/***************************function like macro section*****************************/
/***************************data types section**************************************/
/***************************software interfaces section*****************************/
void INT_0_ISR(void);
void INT_1_ISR(void);
void INT_2_ISR(void);

#endif	/* INTERRUPT_MANAGER_H */
