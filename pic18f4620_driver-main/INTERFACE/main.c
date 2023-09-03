
#include"main.h"
#include "MCAL/GPIO/gpio.h"
#include "ECU/LED/led.h"
#include "ECU/KEYPAD/keypad.h"
#include "ECU/RELAY/relay.h"
#include "ECU/7_SEGMENT/_7_segment.h"
#include "ECU/DC_motor/dc_motor.h"
#include "ECU/LCD/lcd.h"
#include "MCAL/INTERRUPT/mcal_external_interrupt.h"
#include"MCAL/temp_timer1/timer1.h"


void int_1_handler(void);

uint8 dinasour[8]={0b00011,0b00011,0b00010,0b11110,0b01110,0b01010,0b01010,0b01010};
uint8 cactus[8] = {0b10101,0b10101,0b10101,0b11111,0b00100,0b10101,0b01110,0b00100};
uint8 ground[8] = {0b11111,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000};

INTX_config int_t={
    .pin.direction=INPUT,
    .pin.port=PORTB_INDEX,
    .pin.pin=PIN1,
    .Priority=HIGH_PRIORITY,
    .edge=RISING_EDGE,
    .source=INT_1,
    .interrupt_handler=int_1_handler
};

lcd_4_bit_mode lcd={
  .rs.pin=PIN0,.rs.port=PORTC_INDEX,.rs.direction=OUTPUT,
  .en.pin=PIN1,.en.port=PORTC_INDEX,.en.direction=OUTPUT,
  ._4_bit[0].pin=PIN2,._4_bit[0].port=PORTC_INDEX,._4_bit[0].direction=OUTPUT,  
  ._4_bit[1].pin=PIN3,._4_bit[1].port=PORTC_INDEX,._4_bit[1].direction=OUTPUT,
  ._4_bit[2].pin=PIN4,._4_bit[2].port=PORTC_INDEX,._4_bit[2].direction=OUTPUT,
  ._4_bit[3].pin=PIN5,._4_bit[3].port=PORTC_INDEX,._4_bit[3].direction=OUTPUT,
};

uint8 x=0,y=0,counter=0;
uint8 num[7];
uint8 speed=100,operator=1;
int main()
{
    Timer1_init();
    Interrupt_INTx_Init(&int_t);
    lcd_4_bit_init(&lcd);
    
    loop:
    
    for(y=20;y>0;y--)
    {
        display_custom_char(&lcd,4,y,ground,5);
    }
    
    display_custom_char(&lcd,3,4,dinasour,1);
    __delay_ms(30);
    
    while(1)
    {  
        for(x=20;x>0;x--)
        {
           display_custom_char(&lcd,3,x,cactus,4);
           display_char_at_position(&lcd,3,x+1,'\0');
           display_char_at_position(&lcd,3,1,'\0');
           __delay_ms(100);
           
           
           if(x==4)
           {
              display_string_at_position(&lcd,1,5,"game over");  
              counter=0;
              __delay_ms(1000);
               display_string_at_position(&lcd,1,5,"         "); 
                display_char_at_position(&lcd,1,13,'\0');
              goto loop;
           }
          
           short_to_string(counter,num);
           display_string_at_position(&lcd,1,6,"score=");
           display_string_at_position(&lcd,1,13,num);
        }
        
      
        
    }
    return 0;
}

void int_1_handler(void)
{
      
      display_char_at_position(&lcd,3,4,'\0');
      display_custom_char(&lcd,1,4,dinasour,1);
      
      
      if(x==5||x==6){
        while(x>=3)
        {
             display_custom_char(&lcd,3,x,cactus,4);
             display_char_at_position(&lcd,3,x+1,'\0');
             __delay_ms(80);
             x--;
        }
        counter++;
        x=3;
      }
      
        __delay_ms(200);
     display_char_at_position(&lcd,1,4,'\0');
     display_custom_char(&lcd,3,4,dinasour,1);
     
     
    
}
