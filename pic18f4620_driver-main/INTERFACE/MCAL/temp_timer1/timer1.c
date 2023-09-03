#include"timer1.h"


void Timer1_init()
{
    OSCCON=0x72; 
}
void Timer1_delay(uint16 time)
{
    /* Enable 16-bit TMR1 register, No pre-scale, internal clock,timer OFF */
    T1CON=0x31;  
    
    TMR1=time;	/* Load count for generating delay of time*/
    T1CONbits.TMR1ON=1;  	/* Turn ON Timer1 */
    while(PIR1bits.TMR1IF==0); 	/* Wait for Timer1 overflow interrupt flag */
    TMR1ON=0;  			/* Turn OFF timer */
    TMR1IF=0;  			/* Make Timer1 overflow flag to '0' */
}
