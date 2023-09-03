/* 
 * File:   std_types.h
 * Author: mohamed
 *
 * Created on August 14, 2023, 10:16 AM
 */

#ifndef STD_TYPES_H
#define	STD_TYPES_H


/***************************includes section****************************************/
#include"std_libraries.h"
#include "compiler.h"
/***************************data types section**************************************/
typedef unsigned char                   uint8;
typedef unsigned short                  uint16;
typedef unsigned int                    uint32;

typedef signed char                    sint8;
typedef signed short                   sint16;
typedef signed int                     sint32;

typedef uint8                       Std_ReturnType ;

/***************************macros sections*****************************************/


#define HIGH      1
#define LOW       0
#define ON        1
#define OFF       0
#define ACTIVE    1
#define IDLE      0
#define OK     (Std_ReturnType)0x01
#define NOT_OK    (Std_ReturnType)0x00
/***************************function like macro section*****************************/

/***************************software interfaces section*****************************/
#endif	/* STD_TYPES_H */

