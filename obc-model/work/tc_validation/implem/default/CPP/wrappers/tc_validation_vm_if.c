/* Body file for function tc_validation
 * Generated by TASTE on 2023-03-06 19:54:19
 */
#include "tc_validation_vm_if.h"




unsigned tc_validation_initialized = 0;
void init_tc_validation(void)
{
   if (0 == tc_validation_initialized) {
      tc_validation_initialized = 1;
      // Call user code startup function
      extern void tc_validation_startup(void);
      tc_validation_startup();
      tc_validation_initialized = 2;
   }
}
void tc_validation_validate_mc_vs_tm()
{

   //  Directly call user code, no parameters to pass
   extern void tc_validation_PI_validate_mc_vs_tm(void);
   tc_validation_PI_validate_mc_vs_tm();
   // puts ("tc_validation_validate_mc_vs_tm called");
}

