/* Header file for function gui
 * Generated by TASTE on 2023-03-06 19:54:19
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

#include "gui.h"

// Function initialization - calls user startup code of all dependent functions
void init_gui(void);


/* Provided interfaces */
void gui_Poll(void);


void gui_send_tm_aoi
      (const char *IN_lfp, size_t IN_lfp_len);



void gui_send_tm_mcp
      (const char *IN_mcp, size_t IN_mcp_len);


#ifdef __cplusplus
}
#endif

