#include "../LED/led.h"

/**
 * 
 * @param led
 * @return  Std_ReturnType ok or not_ok
 */
Std_ReturnType led_init(const led_t *led)
{
    Std_ReturnType ret = OK;
    if(NULL == led ){
        ret = NOT_OK;
    }
    else
    {
        pin_config led_x=
        {
            .direction=OUTPUT,
            .pin=led->pin,
            .port=led->port_name,
            .state=led->led_status
        };
         pin_directoin_intialize(&led_x);
    }
     return ret;
}
/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_turn_on(const led_t *led)
{
     Std_ReturnType ret = OK;
    if(NULL == led){
        ret = NOT_OK;
    }
    else
    {
        pin_config led_x=
        {
            .direction=OUTPUT,
            .pin=led->pin,
            .port=led->port_name,
            .state=led->led_status
        };
        ret= pin_write_value(&led_x,LED_ON);
    }
     return ret;
}
/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_turn_off(const led_t *led)
{
     Std_ReturnType ret = OK;
    if(NULL == led){
        ret = NOT_OK;
    }
    else
    {
        pin_config led_x=
        {
            .direction=OUTPUT,
            .pin=led->pin,
            .port=led->port_name,
            .state=led->led_status
        };
        ret= pin_write_value(&led_x,LED_OFF);
    }
     return ret;
}
/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_toggle(const led_t *led)
{
    Std_ReturnType ret = OK;
    if(NULL == led){
        ret = NOT_OK;
    }
    else
    {
        pin_config led_x=
        {
            .direction=OUTPUT,
            .pin=led->pin,
            .port=led->port_name,
            .state=led->led_status
        };
         pin_toggle_value(&led_x);
    }
     return ret ;
}