#include "_7_segment.h"
/**
 * 
 * @param segment
 * @return 
 */
Std_ReturnType segment_init(const segments_t *segment)
{
    uint8 counter=0;
   Std_ReturnType ret=OK;
   if(NULL==segment)
   {
       ret=NOT_OK;
   }
   else
   {
       for(counter=0;counter<4;counter++)
       {
            ret=pin_directoin_intialize(&(segment->segments[counter]));
       }
   }
   return ret;
}

/**
 * 
 * @param segment
 * @param value
 * @return 
 */
Std_ReturnType segment_write(const segments_t *segment,uint8 value)
{
   Std_ReturnType ret=OK;
    uint8 counter=0;
   if(NULL==segment)
   {
       ret=NOT_OK;
   }
   else
   {
       for(counter=0;counter<4;counter++)
       {
         ret= pin_write_value(&(segment->segments[counter]),(value>>counter)&0x01);   
       }
   }
   return ret;
}

