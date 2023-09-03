/* 
 * File:   gpio.h
 * Author: mohamed
 *
 * Created on August 14, 2023, 10:49 AM
 */

#ifndef GPIO_H
#define	GPIO_H


/***************************includes section****************************************/
#include"../proc/pic18f4620.h"
#include"../std_types.h"
#include"../device_config.h"
/***************************macros sections*****************************************/
#define  PIN_MAX   8
#define  PORT_MAX  5
#define _XTAL_FREQ 8000000UL

/***************************function like macro section*****************************/
#define REG(x)            (*((volatiole uint8*)x))


#define SET_BIT(REG,BIT)   (REG|=(1<<BIT))
#define CLEAR_BIT(REG,BIT) (REG&=~(1<<BIT))
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))
#define READ_BIT(REG,BIT)   ((REG >> BIT) & 0X01)
/***************************data types section**************************************/
typedef enum
{
    OUTPUT =0,
    INPUT
}direction;

typedef enum
{
    PORTA_INDEX,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_index;
  
typedef enum
{
    PIN0=0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7        
}pin_index;

typedef enum
{
    LOW_STATE,
    HIGH_STATE        
}state;

typedef struct
{
    uint8 port :3;
    uint8 pin:3;
    uint8 direction :1;
    uint8 state:1;
    
}pin_config;
/***************************software interfaces section*****************************/
Std_ReturnType pin_directoin_intialize(const pin_config *pin);
Std_ReturnType get_pin_directoin_status(const pin_config *pin,uint8 *status);
Std_ReturnType pin_write_value(const pin_config *pin,uint8 value);
Std_ReturnType pin_read_value(const pin_config *pin,uint8 *value);
Std_ReturnType pin_toggle_value(const pin_config *pin);


Std_ReturnType gpio_port_direction_intialize(port_index port, uint8 direction);
Std_ReturnType gpio_port_get_direction_status(port_index port, uint8 *direction_status);
Std_ReturnType gpio_port_write_logic(port_index port, uint8 logic);
Std_ReturnType gpio_port_read_logic(port_index port, uint8 *logic);
Std_ReturnType gpio_port_toggle_logic(port_index port);

#endif	/* GPIO_H */

