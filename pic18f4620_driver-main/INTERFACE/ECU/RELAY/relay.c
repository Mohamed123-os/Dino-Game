#include "relay.h"


/**
 * 
 * @param relay
 * @return Std_ReturnType OK or NOT_OK
 */
Std_ReturnType relay_init(const relay_t *relay)
{
    Std_ReturnType ret=OK;
    if(NULL==relay)
    {
        ret=NOT_OK;
    }
    else
    {
        pin_config relay_status={.pin=relay->pin,.port=relay->port,.state=relay->relay_status,.direction=OUTPUT};
        ret=pin_directoin_intialize(&relay_status);
    }
    return ret;
}
/**
 * 
 * @param relay
 * @return Std_ReturnType OK or NOT_OK
 */
Std_ReturnType relay_on(const relay_t *relay)
{
    Std_ReturnType ret=OK;
    if(NULL==relay)
    {
        ret=NOT_OK;
    }
    else
    {
        pin_config relay_status={.pin=relay->pin,.port=relay->port,.state=relay->relay_status,.direction=OUTPUT};
        ret=pin_write_value(&relay_status,RELAY_ON);
    }
    return ret;
}
/**
 * 
 * @param relay
* @return Std_ReturnType OK or NOT_OK
 */
Std_ReturnType relay_off(const relay_t *relay)
{
    Std_ReturnType ret=OK;
    if(NULL==relay)
    {
        ret=NOT_OK;
    }
    else
    {
         pin_config relay_status={.pin=relay->pin,.port=relay->port,.state=relay->relay_status,.direction=OUTPUT};
         ret=pin_write_value(&relay_status,RELAY_OFF);
    }
    return ret;
}
