/* Header file for function tm_provider
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

#include "tm_provider.h"

// Function initialization - calls user startup code of all dependent functions
void init_tm_provider(void);


/* Provided interfaces */
void tm_provider_request_tm
      (char *OUT_temp, size_t *OUT_temp_len,
       char *OUT_depl_d, size_t *OUT_depl_d_len,
       char *OUT_depl_a, size_t *OUT_depl_a_len);


#ifdef __cplusplus
}
#endif

