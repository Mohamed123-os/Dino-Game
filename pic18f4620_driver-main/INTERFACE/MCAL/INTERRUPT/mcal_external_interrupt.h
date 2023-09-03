/* 
 * File:   mcal_external_interrupt.h
 * Author: mohamed
 *
 * Created on August 27, 2023, 12:10 PM
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

/***************************includes section****************************************/
#include "interrupt_config.h"
/***************************macros sections*****************************************/
/***************************function like macro section*****************************/

#if INTERRUPT_INTx_ENABLE ==1            //if external interrupts are enabled
/*for EXTERNAL INTERRUPT INT0*/
#define INT0_interrupt_enable()         INTCONbits.INT0IE=1          //enable intx0
#define INT0_interrupt_disable()        INTCONbits.INT0IE=0          //disable intx0
#define INT0_clear_flag()               INTCONbits.INT0IF=0         // intx0 clear flag
#define INT0_rising_edge()              INTCON2bits.INTEDG0=1       // interrupt_at rising_edge 
#define INT0_falling_edge()             INTCON2bits.INTEDG0=0       // interrupt_at falling_edge 

/*for EXTERNAL INTERRUPT INT1*/
#define INT1_interrupt_enable()         INTCON3bits.INT1IE=1          //enable intx1
#define INT1_interrupt_disable()        INTCON3bits.INT1E=0          //disable intx1
#define INT1_clear_flag()               INTCON3bits.INT1IF=0         // intx1 clear flag
#define INT1_rising_edge()              INTCON2bits.INTEDG1=1       // interrupt_at rising_edge 
#define INT1_falling_edge()             INTCON2bits.INTEDG1=0       // interrupt_at falling_edge 

/*for EXTERNAL INTERRUPT INT2*/
#define INT2_interrupt_enable()         INTCON3bits.INT2IE=1          //enable intx2
#define INT2_interrupt_disable()        INTCON3bits.INT2IE=0          //disable intx2
#define INT2_clear_flag()               INTCON3bits.INT2IF=0         // intx2 clear flag
#define INT2_rising_edge()              INTCON2bits.INTEDG2=1       // interrupt_at rising_edge 
#define INT2_falling_edge()             INTCON2bits.INTEDG2=0       // interrupt_at falling_edge 

#if INTERRUPT_PRIORITY_LEVELS_ENABLE==1    //if priority levels are enabled
#define INT1_priorit_high_priority()    INTCON3bits.INT1IP=1        //enalbe high priorit for int1
#define INT1_priorit_low_priority()     INTCON3bits.INT1IP=0        //enalbe low priorit for int1

#define INT2_priorit_high_priority()    INTCON3bits.INT2IP=1        //enalbe high priorit for int2
#define INT2_priorit_low_priority()     INTCON3bits.INT2IP=0        //enalbe low priorit for int2

#endif
#endif
/***************************data types section**************************************/
typedef enum{
    FALLING_EDGE,
    RISING_EDGE        
}interrupt_edge;

typedef enum{
    INT_0,
    INT_1,
    INT_2
}external_source;



typedef struct{
    void(*interrupt_handler)(void);  
    prioirty Priority;
    interrupt_edge edge;
    external_source source;
    pin_config  pin; 
}INTX_config;

/***************************software interfaces section*****************************/

Std_ReturnType Interrupt_INTx_Init(const  INTX_config *int_obj);    //for intialization of INTX
Std_ReturnType Interrupt_INTx_DeInit(const INTX_config *int_obj);   //for deintialization of INTX



#endif	/* MCAL_EXTERNAL_INTERRUPT_H */


