/* 
 * File:   _7_segment.h
 * Author: mohamed
 *
 * Created on August 16, 2023, 11:02 AM
 */

#ifndef _7_SEGMENT_H
#define	_7_SEGMENT_H


/***************************includes section****************************************/
#include "../../MCAL/GPIO/gpio.h"
/***************************macros sections*****************************************/
/***************************function like macro section*****************************/
/***************************data types section**************************************/
typedef struct{
    pin_config segments[4];
}segments_t;
/***************************software interfaces section*****************************/
Std_ReturnType segment_init(const segments_t *segment);
Std_ReturnType segment_write(const segments_t *segment,uint8 value);


#endif	/* _7_SEGMENT_H */

