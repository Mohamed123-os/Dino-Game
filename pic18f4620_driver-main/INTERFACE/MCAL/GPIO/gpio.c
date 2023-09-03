
#include"gpio.h"

volatile uint8* TRIS_array[]={&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
volatile uint8* PORT_array[]={&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};
volatile uint8* LAT_array[]={&LATA,&LATB,&LATC,&LATD,&LATE};

/**
 * @brief Initialize the direction of a specific pin @ref pin_config
 * @param _pin_config pointer to the configurations @ref pin_config 
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType pin_directoin_intialize(const pin_config *pin)
{
    Std_ReturnType ret = OK;
    if(NULL == pin || pin->pin > PIN_MAX-1){
        ret = NOT_OK;
    }
    else
    {
        switch(pin->direction)
        {
            case INPUT:SET_BIT(*TRIS_array[pin->port],pin->pin);break;
            case OUTPUT:CLEAR_BIT(*TRIS_array[pin->port],pin->pin);break;                
            default: ret=NOT_OK;
        }
    }
    return ret;
}

/**
 * @brief get direction status of  a specific pin @ref pin_config
 * @param pin pointer to the configurations @ref pin_config ,pointer to variable of type uint8
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType get_pin_directoin_status(const pin_config *pin,uint8 *status)
{
    Std_ReturnType ret = OK;
    if(NULL == pin || pin->pin > PIN_MAX-1){
        ret = NOT_OK;
    }
    else
    {
        *status=READ_BIT(*TRIS_array[pin->port],pin->pin);
    }
    return ret;
}


/**
 * @brief WRITE VALUE AT specific pin @ref pin_config
 * @param pin pointer to the configurations @ref pin_config , variable of type uint8
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType pin_write_value(const pin_config *pin,uint8 value)
{
    Std_ReturnType ret = OK;
    if(NULL == pin || pin->pin > PIN_MAX-1){
        ret = NOT_OK;
    }
    else
    {
        switch(value)
        {
            case HIGH:SET_BIT(*LAT_array[pin->port],pin->pin); break;
            case LOW:CLEAR_BIT(*LAT_array[pin->port],pin->pin); break;
            default :ret=NOT_OK;
        }
    }
    return ret;
}


/**
 * @brief READ VALUE AT specific pin @ref pin_config
 * @param pin pointer to the configurations @ref pin_config ,POINTER TO variable of type uint8
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType pin_read_value(const pin_config *pin,uint8 *value)
{
     Std_ReturnType ret = OK;
    if(NULL == pin || pin->pin > PIN_MAX-1){
        ret = NOT_OK;
    }
    else
    {
        *value=READ_BIT(*PORT_array[pin->port],pin->pin);
    }
     return ret;
}

/**
 * @brief TOGGLE VALUE OF A specific pin @ref pin_config
 * @param pin pointer to the configurations @ref pin_config ,POINTER TO variable of type uint8
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType pin_toggle_value(const pin_config *pin)
{
     Std_ReturnType ret = OK;
    if(NULL == pin || pin->pin > PIN_MAX-1){
        ret = NOT_OK;
    }
    else
    {
        TOGGLE_BIT(*LAT_array[pin->port],pin->pin);
    }
     return ret;
}

/**
 * @brief intialize direction of specific port 
  * @param port_index ox the configurations logic,variabel of direcetion
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType gpio_port_direction_intialize(port_index port, uint8 direction)
{
    Std_ReturnType ret = OK;
    if(port > PORT_MAX-1){
        ret = NOT_OK;
    }
    else
    {
        *TRIS_array[port]=direction;
    }  
    return ret;
}


/**
 * @brief get direction of specific port 
 * @param port_index ox the configurations logic,pointer to variable of type uint8 
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */

Std_ReturnType gpio_port_get_direction_status(port_index port, uint8 *direction_status)
{
   Std_ReturnType ret = OK;
    if(port > PORT_MAX-1){
        ret = NOT_OK;
    }
    else
    {
        *direction_status=*TRIS_array[port];
    }
   return ret;
}


/**
 * @brief WRITE LOGIC of specific port 
 * @param port_index ox the configurations logic
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType gpio_port_write_logic(port_index port, uint8 logic)
{
      Std_ReturnType ret = OK;
    if(port > PORT_MAX-1){
        ret = NOT_OK;
    }
    else
    {
        *LAT_array[port]=logic;
    }
   return ret;
}

/**
 * @brief READ LOGIC of specific port 
 * @param port to the configurations ,LOGIC
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType gpio_port_read_logic(port_index port, uint8 *logic)
{
      Std_ReturnType ret = OK;
    if(port > PORT_MAX-1){
        ret = NOT_OK;
    }
    else
    {
        *logic=*PORT_array[port];
    }
   return ret;
}
/**
 * @brief TOGGLE LOGIC of specific port 
 * @param port_index ox the configurations 
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */

Std_ReturnType gpio_port_toggle_logic(port_index port)
{
     Std_ReturnType ret = OK;
    if(port > PORT_MAX-1){
        ret = NOT_OK;
    }
    else
    {
       *LAT_array[port]^=0xFF;
    }
   return ret;
    
}
