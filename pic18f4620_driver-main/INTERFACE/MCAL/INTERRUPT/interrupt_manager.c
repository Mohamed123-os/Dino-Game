
#include "interrupt_manager.h"


#if INTERRUPT_PRIORITY_LEVELS_ENABLE == 1 
void __interrupt() InterruptManagerHigh(void)
{
#if INTERRUPT_INTx_ENABLE==1     
    if((INTERRUPT_ENABLE == INTCONbits.INT0IE) && (INTERRUPT_OCCEUR == INTCONbits.INT0IF))
    {
        INT_0_ISR();
    }
    else{ /* Nothing */ }
    
    if((INTERRUPT_ENABLE == INTCON3bits.INT1IE) && (INTERRUPT_OCCEUR == INTCON3bits.INT1IE))
    {
        INT_1_ISR();
    }
    
    else{ /* Nothing */ }
    if((INTERRUPT_ENABLE == INTCON3bits.INT2IE) && (INTERRUPT_OCCEUR == INTCON3bits.INT2IF))
    {
        INT_2_ISR();
    }
    else{ /* Nothing */ }
#endif
    
}


void __interrupt(low_priority) InterruptManagerLow(void)
{
#if INTERRUPT_INTx_ENABLE==1 
    if((INTERRUPT_ENABLE == INTCONbits.INT0IE) && (INTERRUPT_OCCEUR == INTCONbits.INT0IF)){
        INT_0_ISR();
    }
    else{ /* Nothing */ }
    
    if((INTERRUPT_ENABLE == INTCON3bits.INT1IE) && (INTERRUPT_OCCEUR == INTCON3bits.INT1IE)){
        INT_1_ISR();
    }
    
    else{ /* Nothing */ }
     if((INTERRUPT_ENABLE == INTCON3bits.INT2IE) && (INTERRUPT_OCCEUR == INTCON3bits.INT2IF)){
        INT_2_ISR();
    }
    else{ /* Nothing */ }
#endif
}

#else
void __interrupt() InterruptManager(void)
{
    #if INTERRUPT_INTx_ENABLE==1 
    if((INTERRUPT_ENABLE == INTCONbits.INT0IE) && (INTERRUPT_OCCEUR == INTCONbits.INT0IF)){
        INT_0_ISR();
    }
    else{ /* Nothing */ }
    
    if((INTERRUPT_ENABLE == INTCON3bits.INT1IE) && (INTERRUPT_OCCEUR == INTCON3bits.INT1IE)){
        INT_1_ISR();
    }
    
    else{ /* Nothing */ }
     if((INTERRUPT_ENABLE == INTCON3bits.INT2IE) && (INTERRUPT_OCCEUR == INTCON3bits.INT2IF)){
        INT_2_ISR();
    }
    else{ /* Nothing */ }
#endif
}
#endif