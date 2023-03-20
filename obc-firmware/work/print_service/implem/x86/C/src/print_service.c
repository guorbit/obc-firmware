/* Body file for function print_service
 * Generated by TASTE on 2023-03-18 12:19:25
 * You can edit this file, it will not be overwritten
 * Provided interfaces : print
 * Required interfaces : 
 * User-defined properties for this function:
 *   |_ Taste::Startup_Priority = 1
 * Timers              : 
 */

#include "print_service.h"

#include <stdio.h>
#include <string.h>

void print_service_startup(void)
{
   // Write your initialisation code, but DO NOT CALL REQUIRED INTERFACES
   puts ("[print_service] Startup");
}

void print_service_PI_print( const asn1SccOString *IN_stri )
{
    puts(IN_stri->arr);
}

void print_service_PI_wait( void )
{
    puts(".");
}
