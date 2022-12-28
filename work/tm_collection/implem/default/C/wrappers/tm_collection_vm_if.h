/* Header file for function tm_collection
 * Generated by TASTE on 2022-12-28 10:47:30
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

#include "tm_collection.h"

// Function initialization - calls user startup code of all dependent functions
void init_tm_collection(void);


/* Provided interfaces */
void tm_collection_collect_tm(void);


#ifdef __cplusplus
}
#endif

