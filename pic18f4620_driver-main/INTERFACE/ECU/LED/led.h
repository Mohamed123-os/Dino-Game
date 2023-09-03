/* 
 * File:   led.h
 * Author: mohamed
 *
 * Created on August 14, 2023, 2:34 PM
 */

#ifndef LED_H
#define	LED_H

/* Section : Includes */
#include "../../MCAL/GPIO/gpio.h"

/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */

/* Section: Data Type Declarations */
typedef enum{
    LED_OFF,
    LED_ON
}led_status_t;

typedef struct{
    uint8 port_name : 4;
    uint8 pin : 3;
    uint8 led_status : 1;
}led_t;

/* Section: Function Declarations */
Std_ReturnType led_init(const led_t *led);
Std_ReturnType led_turn_on(const led_t *led);
Std_ReturnType led_turn_off(const led_t *led);
Std_ReturnType led_toggle(const led_t *led);
#endif	/* LED_H */

