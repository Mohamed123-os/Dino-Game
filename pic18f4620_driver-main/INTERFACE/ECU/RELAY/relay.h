/* 
 * File:   relay.h
 * Author: mohamed
 *
 * Created on August 16, 2023, 10:31 AM
 */

#ifndef RELAY_H
#define	RELAY_H


/***************************includes section****************************************/
#include "../../MCAL/GPIO/gpio.h"
/***************************macros sections*****************************************/
#define  RELAY_ON   0x01
#define  RELAY_OFF  0x00
/***************************function like macro section*****************************/
/***************************data types section**************************************/
typedef struct 
{
    uint8 port;
    uint8 pin;
    uint8 relay_status;
}relay_t;
/***************************software interfaces section*****************************/
Std_ReturnType relay_init(const relay_t *relay);
Std_ReturnType relay_on(const relay_t *relay);
Std_ReturnType relay_off(const relay_t *relay);


#endif	/* RELAY_H */

