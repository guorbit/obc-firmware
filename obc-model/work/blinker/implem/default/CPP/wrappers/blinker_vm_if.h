/* Header file for function blinker
 * Generated by TASTE on 2023-03-11 00:05:02
 * DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
 */

/* The purpose of this file is to provide a wrapper around the user code,
 * with a single interface that is independent of the implementation language
 * of the function. The parameters of each PI are blackboxes encoded
 * in the form specified in the interface view (Native, uPER, or ACN)
*/

#pragma once
#if defined(__unix__) || defined (__MSP430__)
   #include <stdlib.h>
   #include <stdio.h>
#else
   typedef unsigned size_t;
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "blinker.h"

// Function initialization - calls user startup code of all dependent functions
void init_blinker(void);


/* Provided interfaces */
void blinker_blink_trigger(void);


#ifdef __cplusplus
}
#endif

