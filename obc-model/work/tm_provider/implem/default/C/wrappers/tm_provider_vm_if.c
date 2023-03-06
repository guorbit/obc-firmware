/* Body file for function tm_provider
 * Generated by TASTE on 2023-03-06 19:54:19
 */
#include "tm_provider_vm_if.h"
#include "C_ASN1_Types.h"




unsigned tm_provider_initialized = 0;
void init_tm_provider(void)
{
   if (0 == tm_provider_initialized) {
      tm_provider_initialized = 1;
      // Call user code startup function
      extern void tm_provider_startup(void);
      tm_provider_startup();
      tm_provider_initialized = 2;
   }
}
void tm_provider_request_tm
      (char *OUT_temp, size_t *OUT_temp_len,
       char *OUT_depl_d, size_t *OUT_depl_d_len,
       char *OUT_depl_a, size_t *OUT_depl_a_len)

{

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void tm_provider_PI_request_tm
      (asn1SccTemperature_Generic *,
       asn1SccDeployment_Digital *,
       asn1SccDeployment_Analogue *);





   // Call user code
   tm_provider_PI_request_tm ((asn1SccTemperature_Generic *)OUT_temp, (asn1SccDeployment_Digital *)OUT_depl_d, (asn1SccDeployment_Analogue *)OUT_depl_a);

}

