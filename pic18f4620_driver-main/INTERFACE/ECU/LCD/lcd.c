#include"lcd.h"

static Std_ReturnType lcd_send_4bits(const lcd_4_bit_mode *lcd, uint8 _data_command);
static Std_ReturnType lcd_send_enable_4bit(const lcd_4_bit_mode *lcd);
static Std_ReturnType lcd_send_enable_8bit(const lcd_8_bit_mode *lcd);
 Std_ReturnType lcd_4_bit_set_cursor(const lcd_4_bit_mode *lcd,uint8 row,uint8 column);
 Std_ReturnType lcd_8_bit_set_cursor(const lcd_8_bit_mode *lcd,uint8 row,uint8 column);


/**
 * 
 * @param lcd
 * @return 
 */
Std_ReturnType   lcd_4_bit_init(const lcd_4_bit_mode *lcd)
{
    uint8 counter=0;
    Std_ReturnType ret=OK;
    if(NULL==lcd)
    {
        ret=NOT_OK;
    }
    else
    {
        ret=pin_directoin_intialize(&(lcd->en));
        ret=pin_directoin_intialize(&(lcd->rs));
       for(counter=0;counter<4;counter++)
       {
          ret= pin_directoin_intialize(&(lcd->_4_bit[counter]));
       }
       
       __delay_ms(20);
        ret = send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
        ret = send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        
        ret = send_command(lcd, _LCD_CLEAR);
        ret = send_command(lcd, _LCD_RETURN_HOME);
        ret = send_command(lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
        ret = send_command(lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
        ret = send_command(lcd, _LCD_4BIT_MODE_2_LINE);
        
        ret = send_command(lcd, 0x80);
          
    }
    return ret;
}
/**
 * 
 * @param lcd
 * @param command
 * @return 
 */
Std_ReturnType   send_command(const lcd_4_bit_mode *lcd, uint8 command)
{
    Std_ReturnType ret=OK;
    if(NULL==lcd)
    {
        ret=NOT_OK;
    }
    else
    {
        ret=pin_write_value(&(lcd->rs),LOW);
        
        ret=lcd_send_4bits(lcd,command>>4);
        ret=lcd_send_enable_4bit(lcd);
        
        ret=lcd_send_4bits(lcd,command);
        ret=lcd_send_enable_4bit(lcd);
          
    }
    return ret;
}
/**
 * 
 * @param lcd
 * @param data
 * @return 
 */
Std_ReturnType   display_char (const lcd_4_bit_mode *lcd,uint8 data)
{
    Std_ReturnType ret=OK;
    if(NULL==lcd)
    {
        ret=NOT_OK;
    }
    else
    {
        ret=pin_write_value(&(lcd->rs),HIGH);
        
        ret=lcd_send_4bits(lcd,data>>4);
        ret=lcd_send_enable_4bit(lcd);
        
        ret=lcd_send_4bits(lcd,data);
        ret=lcd_send_enable_4bit(lcd);     
    }
    
    return ret;
}
/**
 * 
 * @param lcd
 * @param row
 * @param coloumn
 * @param data
 * @return 
 */
Std_ReturnType   display_char_at_position (const lcd_4_bit_mode *lcd,uint8 row,uint8 coloumn,uint8 data)
{
    Std_ReturnType ret=OK;
    if(NULL==lcd)
    {
        ret=NOT_OK;
    }
    else
    {
        ret=lcd_4_bit_set_cursor(lcd,row,coloumn);
        ret=pin_write_value(&(lcd->rs),HIGH);
        ret=lcd_send_4bits(lcd,data>>4);
        ret=lcd_send_enable_4bit(lcd);
        ret=lcd_send_4bits(lcd,data);
        ret=lcd_send_enable_4bit(lcd);
          
    }
    return ret;
}
/**
 * 
 * @param lcd
 * @param data
 * @return 
 */
Std_ReturnType   display_string (const lcd_4_bit_mode *lcd,uint8 *data)
{
    Std_ReturnType ret=OK;
    if(NULL==lcd)
    {
        ret=NOT_OK;
    }
    else
    {
        while(*data!='\0')
        {
            ret=display_char(lcd,*data++);
        }
    }
    return ret;
}
/**
 * 
 * @param lcd
 * @param row
 * @param coloumn
 * @param data
 * @return 
 */
Std_ReturnType   display_string_at_position (const lcd_4_bit_mode *lcd,uint8 row,uint8 coloumn,uint8 *data)
{
    Std_ReturnType ret=OK;
    if(NULL==lcd)
    {
        ret=NOT_OK;
    }
    else
    {
        ret=lcd_4_bit_set_cursor(lcd,row,coloumn);
        while(*data!='\0')
        {
            ret=display_char(lcd,*data++);
        }
    }
    return ret;
}
/**
 * 
 * @param lcd
 * @param row
 * @param cloumn
 * @param data
 * @return 
 */
Std_ReturnType   display_custom_char(const lcd_4_bit_mode *lcd, uint8 row, uint8 cloumn , uint8 data[],uint8 mem_pos)
{
    Std_ReturnType ret=OK;
    uint8 counter=0;
    if(NULL==lcd)
    {
        ret=NOT_OK;
    }
    else
    {
        ret = send_command(lcd,_LCD_CGRAM_START+(mem_pos*8));
        for(counter=0;counter<=7;counter++)
        {
            ret=display_char(lcd,data[counter]);
        }
         ret =display_char_at_position(lcd, row, cloumn, mem_pos);
       
    }
    return ret;
}






/**
 * 
 * @param lcd
 * @return 
 */
Std_ReturnType   lcd_8_bit_init(const lcd_8_bit_mode *lcd)
{
    Std_ReturnType ret=OK;
    uint8 counter=0;
    if(NULL==lcd)
    {
        ret=NOT_OK;
    }
    else
    {
        ret=pin_directoin_intialize(&(lcd->en));
        ret=pin_directoin_intialize(&(lcd->rs));
       for(counter=0;counter<8;counter++)
       {
          ret= pin_directoin_intialize(&(lcd->_8_bit[counter]));
       }
        __delay_ms(20);
        ret = send_command_8(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = send_command_8(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
        ret = send_command_8(lcd, _LCD_8BIT_MODE_2_LINE);
        
        ret = send_command_8(lcd, _LCD_CLEAR);
        ret = send_command_8(lcd, _LCD_RETURN_HOME);
        ret = send_command_8(lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
        ret = send_command_8(lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
        ret = send_command_8(lcd, _LCD_8BIT_MODE_2_LINE);
        ret = send_command_8(lcd, 0x80);
    }
    return ret;
}
/**
 * 
 * @param lcd
 * @param command
 * @return 
 */
Std_ReturnType   send_command_8(const lcd_8_bit_mode *lcd, uint8 command)
{
    Std_ReturnType ret=OK;
    uint8 counter=0;
    if(NULL==lcd)
    {
        ret=NOT_OK;
    }
    else
    {
          ret=pin_write_value(&(lcd->rs),LOW);
        
       
        for(counter=0;counter<8;counter++)
        {
            ret=pin_write_value(&(lcd->_8_bit[counter]),(command>>counter)&(uint8)0x01);
        }
        ret=lcd_send_enable_8bit(lcd);
        
    }
    return ret;
}
/**
 * 
 * @param lcd
 * @param data
 * @return 
 */
Std_ReturnType   display_char_8 (const lcd_8_bit_mode *lcd,uint8 data)
{
    Std_ReturnType ret=OK;
    uint8 counter=0;
    if(NULL==lcd)
    {
        ret=NOT_OK;
    }
    else
    {
        ret=pin_write_value(&(lcd->rs),HIGH);
        for(counter=0;counter<8;counter++)
        {
            ret=pin_write_value(&(lcd->_8_bit[counter]),(data>>counter)&(uint8)0x01);
        }
        ret=lcd_send_enable_8bit(lcd);
          
    }
    return ret;
}
/**
 * 
 * @param lcd
 * @param row
 * @param coloumn
 * @param data
 * @return 
 */
Std_ReturnType   display_char_at_position_8 (const lcd_8_bit_mode *lcd,uint8 row,uint8 coloumn,uint8 data)
{
    Std_ReturnType ret=OK;
    uint8 counter=0;
    if(NULL==lcd)
    {
        ret=NOT_OK;
    }
    else
    {
        lcd_8_bit_set_cursor(lcd,row,coloumn);
        
        ret=pin_write_value(&(lcd->rs),HIGH);
        for(counter=0;counter<8;counter++)
        {
            ret=pin_write_value(&(lcd->_8_bit[counter]),(data>>counter)&(uint8)0x01);
        }
        ret=lcd_send_enable_8bit(lcd);
        
    }
    return ret;
}
/**
 * 
 * @param lcd
 * @param data
 * @return 
 */
Std_ReturnType   display_string_8 (const lcd_8_bit_mode *lcd,uint8 *data)
{
    Std_ReturnType ret=OK;
    if(NULL==lcd)
    {
        ret=NOT_OK;
    }
    else
    {
        while(*data!='\0')
        {
            display_char_8(lcd,*data++);
        }
    }
    return ret;
}
/**
 * 
 * @param lcd
 * @param row
 * @param coloumn
 * @param data
 * @return 
 */
Std_ReturnType   display_string_at_position_8 (const lcd_8_bit_mode *lcd,uint8 row,uint8 coloumn,uint8 *data)
{
    Std_ReturnType ret=OK;
    if(NULL==lcd)
    {
        ret=NOT_OK;
    }
    else
    {
        lcd_8_bit_set_cursor(lcd,row,coloumn);
        while(*data!='\0')
        {
            display_char_8(lcd,*data++);
        }
          
    }
    return ret;
}
/**
 * 
 * @param lcd
 * @param row
 * @param cloumn
 * @param data
 * @return 
 */
Std_ReturnType   display_custom_char_8(const lcd_8_bit_mode *lcd, uint8 row, uint8 cloumn , uint8 data[],uint8 mem_pos)
{
    Std_ReturnType ret=OK;
    uint8 counter=0;
    if(NULL==lcd)
    {
        ret=NOT_OK;
    }
    else
    {
        ret = send_command_8(lcd,_LCD_CGRAM_START+(mem_pos*8));
        for(counter=0;counter<=7;counter++)
        {
            ret=display_char_8(lcd,data[counter]);
        }
         ret =display_char_at_position_8(lcd, row, cloumn, mem_pos);
       
 
    }
    return ret;
}



/**
 * 
 * @param data
 * @param str
 * @return 
 */

Std_ReturnType int_to_string(uint32 data,uint8 *str)
{
    Std_ReturnType ret = OK;
    if(NULL == str)
    {
        ret = NOT_OK;
    }
    else
    {    
        memset((char *)str, '\0', 11);
        sprintf(str, "%i", data);
    }
     return ret;
    
}
/**
 * 
 * @param data
 * @param str
 * @return 
 */
Std_ReturnType short_to_string(uint16 data,uint8 *str)
{
    Std_ReturnType ret = OK;
    uint8 Temp[6] = {0};
    uint8 DataCounter = 0;
    if(NULL == str)
    {
        ret = NOT_OK;
    }
    else
    {    
        memset(str, ' ', 5);
        str[5] = '\0';
        sprintf((char *)Temp, "%i", data);
        while(Temp[DataCounter] != '\0')
        {
            str[DataCounter] = Temp[DataCounter]; 
            DataCounter++;
        }
    }
    return ret;
        
}
/**
 * 
 * @param data
 * @param str
 * @return 
 */
Std_ReturnType byte_to_string(uint8 data,uint8 *str)
{
    Std_ReturnType ret = OK;
    if(NULL == str){
        ret = NOT_OK;
    }
    else{    
        memset((char *)str, '\0', 11);
        sprintf(str, "%i", data);
    }
    return ret;
}

/***********************helaper functions*********************************/

/**
 * 
 * @param lcd
 * @param _data_command
 * @return 
 */
static Std_ReturnType lcd_send_4bits(const lcd_4_bit_mode *lcd, uint8 _data_command)
{
    uint8 counter=0;
    Std_ReturnType ret=OK;
    if(NULL==lcd)
    {
        ret=NOT_OK;
    }
    else
    {
        for(counter=0;counter<4;counter++)
        {
            ret=pin_write_value(&(lcd->_4_bit[counter]),(_data_command>>counter)&(uint8)0x01);
        }
    }
    return ret;
}
/**
 * 
 * @param lcd
 * @return 
 */
static Std_ReturnType lcd_send_enable_4bit(const lcd_4_bit_mode *lcd)
{
    Std_ReturnType ret=OK;
    if(NULL==lcd)
    {
        ret=NOT_OK;
    }
    else
    {
        ret=pin_write_value(&(lcd->en),HIGH);
        __delay_us(10);
        ret=pin_write_value(&(lcd->en),LOW);
        
    }
    return ret;
}
/**
 * 
 * @param lcd
 * @return 
 */
static Std_ReturnType lcd_send_enable_8bit(const lcd_8_bit_mode *lcd)
{
    
    Std_ReturnType ret=OK;
    if(NULL==lcd)
    {
        ret=NOT_OK;
    }
    else
    {
        ret=pin_write_value(&(lcd->en),HIGH);
        __delay_us(10);
        ret=pin_write_value(&(lcd->en),LOW);
        
    }
    return ret;
    
}

/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @return 
 */
 Std_ReturnType lcd_4_bit_set_cursor(const lcd_4_bit_mode *lcd,uint8 row,uint8 column)
{
     
    Std_ReturnType ret=OK;
    if(NULL==lcd)
    {
        ret=NOT_OK;
    }
    else
    {
        column--;
        switch(row)
        {
            case ROW1:     ret = send_command(lcd, (0x80+column));      break;
            case ROW2:     ret = send_command(lcd, (0xC0+column));      break;
            case ROW3:     ret = send_command(lcd, (0x94+column));      break;
            case ROW4:     ret = send_command(lcd, (0xD4+column));      break;
        }
    }
    return ret;
}

/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @return 
 */
 Std_ReturnType lcd_8_bit_set_cursor(const lcd_8_bit_mode *lcd,uint8 row,uint8 column)
{
     
    Std_ReturnType ret=OK;
    if(NULL==lcd)
    {
        ret=NOT_OK;
    }
    else
    {
        column--;
        switch(row)
        {
            case ROW1:     ret = send_command_8(lcd, (0x80+column));      break;
            case ROW2:     ret = send_command_8(lcd, (0xC0+column));      break;
            case ROW3:     ret = send_command_8(lcd, (0x94+column));      break;
            case ROW4:     ret = send_command_8(lcd, (0xD4+column));      break;
        }
    }
    return ret;
}