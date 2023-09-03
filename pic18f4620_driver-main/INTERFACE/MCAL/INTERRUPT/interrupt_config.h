/* 
 * File:   interrupt_config.h
 * Author: mohamed
 *
 * Created on August 27, 2023, 12:11 PM
 */

#ifndef INTERRUPT_CONFIG_H
#define	INTERRUPT_CONFIG_H
/***************************includes section****************************************/
#include "../../MCAL/GPIO/gpio.h"
#include "interrupt_generation.h"

/***************************macros sections*****************************************/
#define INTERRUPT_ENABLE              1
#define INTERRUPT_DISABLE             0
#define INTERRUPT_OCCEUR              1
#define INTERRUPT_NOT_OCCEUR          0
#define INTERRUPT_PRIORITY_ENABLE     1
#define INTERRUPT_PRIORITY_DISABLE    0
/***************************function like macro section*****************************/
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == 1      //if priority is enabled

#define Priority_levels_enable()   RCONbits.IPEN=1  //ENABLE PRIORITY LEVELS
#define Priority_levels_disable()   RCONbits.IPEN=0  //DISABLE PRIORITY LEVELS

#define Priorit_high_enable()     INTCONbits.GIEH=1 //ENABLE HIGH PRIORIYT
#define Priorit_high_disable()    INTCONbits.GIEH=0 //DISABLE HIGH PRIORIYT

#define Priorit_low_enable()       INTCONbits.GIEL=1 //ENABLE LOW PRIORIYT
#define Priorit_low_disable()      INTCONbits.GIEL=0 //DISBLE LOW PRIORIYT

#else //if priority not enabled 

#define Global_interrupt_enable()      INTCONbits.GIE=1  //enable global interrpt
#define Global_interrupt_disable()     INTCONbits.GIE=0  //disable global interrpt

#define pripherals_interrupt_enable()  INTCONbits.PEIE=1   //enable pripheral interrpt
#define pripherals_interrupt_disable() INTCONbits.PEIE=0  //disable pripheral interrpt


#endif





/***************************data types section**************************************/
typedef enum{
   LOW_PRIORITY,
   HIGH_PRIORITY        
}prioirty;
/***************************software interfaces section*****************************/

#endif	/* INTERRUPT_CONFIG_H */

