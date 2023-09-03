/* 
 * File:   dc_motor.h
 * Author: mohamed
 *
 * Created on August 16, 2023, 12:55 PM
 */

#ifndef DC_MOTOR_H
#define	DC_MOTOR_H


/***************************includes section****************************************/
#include "../../MCAL/GPIO/gpio.h"
/***************************macros sections*****************************************/
#define MOTOR_ON    1
#define MOTOR_OFF   0
/***************************function like macro section*****************************/
/***************************data types section**************************************/
typedef struct{
    pin_config motor[2];
}motor_t;
/***************************software interfaces section*****************************/
Std_ReturnType motor_init(const motor_t *motor);
Std_ReturnType motor_right(const motor_t *motor);
Std_ReturnType motor_left(const motor_t *motor);
Std_ReturnType motor_off(const motor_t *motor);

#endif	/* DC_MOTOR_H */

