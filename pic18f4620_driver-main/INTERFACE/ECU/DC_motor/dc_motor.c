#include"dc_motor.h"


/**
 * 
 * @param motor
 * @return 
 */
Std_ReturnType motor_init(const motor_t *motor)
{
    Std_ReturnType ret=OK;
    if(NULL==motor)
    {
        ret=NOT_OK;
    }
    else
    {
       ret=pin_directoin_intialize(&(motor->motor[0]));
       ret=pin_directoin_intialize(&(motor->motor[1]));
       
    }
    return ret;
}
/**
 * 
 * @param motor
 * @return 
 */
Std_ReturnType motor_right(const motor_t *motor)
{
    Std_ReturnType ret=OK;
    if(NULL==motor)
    {
        ret=NOT_OK;
    }
    else
    {
         ret=pin_write_value(&(motor->motor[0]),MOTOR_ON);
         ret=pin_write_value(&(motor->motor[1]),MOTOR_OFF);
    }
    return ret;
}
/**
 * 
 * @param motor
 * @return 
 */
Std_ReturnType motor_left(const motor_t *motor)
{
    Std_ReturnType ret=OK;
    if(NULL==motor)
    {
        ret=NOT_OK;
    }
    else
    {
         ret=pin_write_value(&(motor->motor[0]),MOTOR_OFF);
         ret=pin_write_value(&(motor->motor[1]),MOTOR_ON);
    }
    return ret;
}
/**
 * 
 * @param motor
 * @return 
 */
Std_ReturnType motor_off(const motor_t *motor)
{
    Std_ReturnType ret=OK;
    if(NULL==motor)
    {
        ret=NOT_OK;
    }
    else
    {
         ret=pin_write_value(&(motor->motor[0]),MOTOR_OFF);
         ret=pin_write_value(&(motor->motor[1]),MOTOR_OFF);
    }
    return ret;
}

