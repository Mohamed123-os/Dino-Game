


#include "keypad.h"
static const uint8 buttons_array[ROWS][COLOUMS]={{'7','8','9','/'},
                                                 {'4','5','6','*'},
                                                 {'1','2','3','-'},
                                                 {'%','0','=','+'}};



/**
 * 
 * @param key
 * @return 
 */
Std_ReturnType  keypad_init(const keypad *key)
{
    Std_ReturnType ret=OK;
    uint8 counter_rows=0,counter_coloums=0;
    if(key==NULL)
    {
        ret=NOT_OK;
    }
    else
    {
        for(counter_rows=0;counter_rows<ROWS;counter_rows++)
        {
           ret= pin_directoin_intialize(&(key->rows[counter_rows]));
        }
        for(counter_coloums=0;counter_coloums<COLOUMS;counter_coloums++)
        {
           ret= pin_directoin_intialize(&(key->coloums[counter_coloums]));
        }
               
    }
    return ret;
}
/**
 * 
 * @param key
 * @param value
 * @return 
 */
Std_ReturnType  keypad_read(const keypad *key,uint8 *value)
{
    Std_ReturnType ret=OK;
     uint8 counter_rows=0,counter_coloums=0,L_counter=0;
     uint8 temp=0;
    if(key==NULL)
    {
        ret=NOT_OK;
    }
    else
    {
        for(counter_rows=0;counter_rows<ROWS;counter_rows++)
        {
            for(L_counter=0;L_counter<ROWS;L_counter++)
            {
                ret= pin_write_value(&(key->rows[L_counter]),LOW);
            }
             ret= pin_write_value(&(key->rows[counter_rows]),HIGH);
             __delay_ms(10);
             
            for(counter_coloums=0;counter_coloums<COLOUMS;counter_coloums++)
            {
                ret= pin_read_value(&(key->coloums[counter_coloums]),&temp);
                if(temp==HIGH)
                {
                    *value=buttons_array[counter_rows][counter_coloums];
                }
            }
           
        }
        
    }
    return ret;
    
}



