#include "mcal_external_interrupt.h"




#if INTERRUPT_INTx_ENABLE ==1
static void (*int0_handler)(void)=NULL;
static void (*int1_handler)(void)=NULL;
static void (*int2_handler)(void)=NULL;
static Std_ReturnType INTX_enable(const INTX_config *int_obj);
static Std_ReturnType INTX_select_edge(const INTX_config *int_obj);
static Std_ReturnType INTX_disable(const INTX_config *int_obj);
static Std_ReturnType INTX_pin_init(const INTX_config *int_obj);
static Std_ReturnType INTX_clear_flag(const INTX_config *int_obj);
static Std_ReturnType INTX_interrupt_handle(const INTX_config *int_obj);


/**
 * 
 * @param int_obj
 * @return ret
 */
Std_ReturnType Interrupt_INTx_Init(const  INTX_config *int_obj)
{ 
    Std_ReturnType ret=OK;
    if(NULL== int_obj)
    {
        ret=NOT_OK;
    }
    else
    {
        ret=INTX_disable(int_obj);                  //DISABLE INTX
        ret=INTX_select_edge(int_obj);              //select_edge 
        ret=INTX_pin_init(int_obj);                  //intialize pin
        ret=INTX_clear_flag(int_obj);                //CLEAR THE FALG
        ret=INTX_interrupt_handle(int_obj);          //handle interrupt
        ret=INTX_enable(int_obj);                    //enable intx
        
    }
    return ret;
}
/**
 * 
 * @param int_obj
 * @return 
 */
Std_ReturnType Interrupt_INTx_DeInit(const INTX_config *int_obj)
{
    Std_ReturnType ret=OK;
    if(NULL== int_obj)
    {
        ret=NOT_OK;
    }
    else
    {
        switch(int_obj->source)
        {
            case INT_0:
               INT0_interrupt_disable();
               break;
            case INT_1:
               INT1_interrupt_disable();
               break;  
            case INT_2:
               INT2_interrupt_disable();
               break;  
        }
    }
    return ret;
}

/**
 * 
 * @param int_obj
 * @return 
 */
static Std_ReturnType INTX_enable(const INTX_config *int_obj)
{
    Std_ReturnType ret=OK;
    if(NULL== int_obj)
    {
        ret=NOT_OK;
    }
    else
    {
        switch(int_obj->source)
        {
            case INT_0:                
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == 1
                Priority_levels_enable() ;
#else
                Global_interrupt_enable() ;
                pripherals_interrupt_enable();
#endif
                INT0_interrupt_enable() ;
                break;
                
            case INT_1:
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == 1
                Priority_levels_enable();
                if(int_obj->Priority==HIGH_PRIORITY) 
                {
                    
                    Priorit_high_enable();
                    INT1_priorit_high_priority();
                }
                
                else
                {
                    Priorit_low_enable();
                    INT1_priorit_low_priority(); 
                }
#else
                Global_interrupt_enable() ;
                pripherals_interrupt_enable();
#endif
                INT1_interrupt_enable() ;
                break;
              
            case INT_2:
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == 1
                Priority_levels_enable();
                if(int_obj->Priority==HIGH_PRIORITY) 
                {
                    Priorit_high_enable();
                    INT2_priorit_high_priority();
                }
                
                else
                {
                    Priorit_low_enable();
                    INT2_priorit_low_priority();
                }
#else
                Global_interrupt_enable() ;
                pripherals_interrupt_enable();
#endif
                INT2_interrupt_enable() ;
                break;
                     
        }
        
    }
    return ret;
}
/**
 * 
 * @param int_obj
 * @return 
 */
static Std_ReturnType INTX_select_edge(const INTX_config *int_obj)
{
    Std_ReturnType ret=OK;
    if(NULL== int_obj)
    {
        ret=NOT_OK;
    }
    else
    {
        switch(int_obj->source)
        {
            case INT_0:
                if(int_obj->edge==RISING_EDGE)
                {
                    INT0_rising_edge();
                }
                else
                {
                    INT0_falling_edge();    
                }
                break;
            case INT_1:
                if(int_obj->edge==RISING_EDGE)
                {
                    INT1_rising_edge();
                }
                else
                {
                    INT1_falling_edge();    
                }
                break;  
            case INT_2:
                if(int_obj->edge==RISING_EDGE)
                {
                    INT2_rising_edge();
                }
                else
                {
                    INT2_falling_edge();    
                }
                break;    
        }
    }
    return ret;
}
/**
 * 
 * @param int_obj
 * @return 
 */
static Std_ReturnType INTX_disable(const INTX_config *int_obj)
{
    Std_ReturnType ret=OK;
    if(NULL== int_obj)
    {
        ret=NOT_OK;
    }
    else
    {
        switch(int_obj->source)
        {
            case INT_0:
               INT0_interrupt_disable();
               break;
            case INT_1:
               INT1_interrupt_disable();
               break;  
            case INT_2:
               INT2_interrupt_disable();
               break;  
        }
    }
    return ret;
}
/**
 * 
 * @param int_obj
 * @return 
 */
static Std_ReturnType INTX_pin_init(const INTX_config *int_obj)
{
    Std_ReturnType ret=OK;
    if(NULL== int_obj)
    {
        ret=NOT_OK;
    }
    else
    {
        switch(int_obj->source)
        {
            case INT_0:
              pin_directoin_intialize(&(int_obj->pin));
               break;
            case INT_1:
               pin_directoin_intialize(&(int_obj->pin));
               break;  
            case INT_2:
                pin_directoin_intialize(&(int_obj->pin));
               break;  
        }
    }
       
    return ret;
}
/**
 * 
 * @param int_obj
 * @return 
 */
static Std_ReturnType INTX_clear_flag(const INTX_config *int_obj)
{
    Std_ReturnType ret=OK;
    if(NULL== int_obj)
    {
        ret=NOT_OK;
    }
    else
    {
        switch(int_obj->source)
        {
            case INT_0:
                INT0_clear_flag();
                break;
            case INT_1:
                INT1_clear_flag();
                break;  
            case INT_2:
                INT2_clear_flag();
                break;  
        }
    }
    return ret;
}
/**
 * 
 * @param int_obj
 * @return 
 */
static Std_ReturnType INTX_interrupt_handle(const INTX_config *int_obj)
{
    Std_ReturnType ret=OK;
    if(NULL== int_obj)
    {
        ret=NOT_OK;
    }
    else
    {
        switch(int_obj->source)
        {
            case INT_0:
                int0_handler=int_obj->interrupt_handler;
                break;
            case INT_1:
                int1_handler=int_obj->interrupt_handler;
                break;  
            case INT_2:
                int2_handler=int_obj->interrupt_handler;
                break;  
        }
    }
    return ret;
}







void INT_0_ISR(void)
{
    INT0_clear_flag();
      if(int0_handler) int0_handler();
}

void INT_1_ISR(void)
{
      INT1_clear_flag();
      if(int1_handler) int1_handler();
}

void INT_2_ISR(void)
{
    INT2_clear_flag();
    if(int2_handler) int2_handler();
}
#endif