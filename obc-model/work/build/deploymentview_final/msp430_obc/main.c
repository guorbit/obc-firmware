#include <activity.h>
#include <po_hi_task.h>
#include <po_hi_main.h>
#include <deployment.h>
#include <po_hi_time.h>
#include <types.h>
/**************************************************** */
/*  This file was automatically generated by Ocarina  */
/*  Working Copy from r36f4e31c */
/*  Do NOT hand-modify this file, as your             */
/*  changes will be lost when you re-run Ocarina      */
/**************************************************** */
extern void msp430_eusci_a_serial_minimal_init 
    (__po_hi_device_id id);
process_package__taste_protected_object state_handler_entrypoint_protected;

/*!
 * \fn __PO_HI_MAIN_TYPE __PO_HI_MAIN_NAME (void)
 * \brief Main function executed by the system
 *
 * Full function name and return types are available  in the PolyORB-HI-C 
 * runtime header files.
 */
__PO_HI_MAIN_TYPE __PO_HI_MAIN_NAME (void)
{
  
/*!
 * \var period
 * \brief Variable for task period
 *
 * This variable is used to store the valueof the period of a task when we 
 * create it. The value put in the variable is set according to AADL model 
 * description
 */
  __po_hi_time_t period;

  __po_hi_initialize_early ();
  msp430_eusci_a_serial_minimal_init (node_2_msp430_eusci_a_serial_minimal_device_id);
  
/*!
 * Store the period time for task receiver
 */
  __po_hi_milliseconds (&(period), 1000);
  
/*!
 * \brief Making Periodic Task receiver
 *
 * Make a periodic task according to AADL model requirements. The first 
 * parameter is the task identifier defined in deployment.h 
 * (node_2_msp430_eusci_a_serial_minimal_receiver_k) the second is the 
 * period defined in the AADL model. Third is the task priority ( 0), fourth
 *  is the stack size ( 0 bytes) and last is the subprogram executed by the 
 * task
 */
  __po_hi_create_periodic_task (node_2_msp430_eusci_a_serial_minimal_receiver_k, &(period), __PO_HI_DEFAULT_PRIORITY, 0, 0, msp430_eusci_a_serial_minimal_others_receiver_job);
  
/*!
 * Initialize the runtime
 */
  __po_hi_initialize ();
  state_handler_entrypoint_protected.protected_id = 0;
  
/*!
 * Store the period time for task state_handler_entrypoint_poll_aoi
 */
  __po_hi_milliseconds (&(period), 10000);
  
/*!
 * \brief Making Periodic Task state_handler_entrypoint_poll_aoi
 *
 * Make a periodic task according to AADL model requirements. The first 
 * parameter is the task identifier defined in deployment.h 
 * (msp430_obc_state_handler_entrypoint_poll_aoi_k) the second is the period
 *  defined in the AADL model. Third is the task priority ( 1), fourth is 
 * the stack size ( 1024 bytes) and last is the subprogram executed by the 
 * task
 */
  __po_hi_create_periodic_task (msp430_obc_state_handler_entrypoint_poll_aoi_k, &(period), 1, 1024, 0, state_handler_entrypoint_poll_aoi_job);
  
/*!
 * Store the period time for task state_handler_entrypoint_poll_mcp
 */
  __po_hi_milliseconds (&(period), 5000);
  
/*!
 * \brief Making Periodic Task state_handler_entrypoint_poll_mcp
 *
 * Make a periodic task according to AADL model requirements. The first 
 * parameter is the task identifier defined in deployment.h 
 * (msp430_obc_state_handler_entrypoint_poll_mcp_k) the second is the period
 *  defined in the AADL model. Third is the task priority ( 1), fourth is 
 * the stack size ( 1024 bytes) and last is the subprogram executed by the 
 * task
 */
  __po_hi_create_periodic_task (msp430_obc_state_handler_entrypoint_poll_mcp_k, &(period), 1, 1024, 0, state_handler_entrypoint_poll_mcp_job);
  
/*!
 * Store the period time for task state_handler_entrypoint_toggle_pwr
 */
  __po_hi_milliseconds (&(period), 30000);
  
/*!
 * \brief Making Periodic Task state_handler_entrypoint_toggle_pwr
 *
 * Make a periodic task according to AADL model requirements. The first 
 * parameter is the task identifier defined in deployment.h 
 * (msp430_obc_state_handler_entrypoint_toggle_pwr_k) the second is the 
 * period defined in the AADL model. Third is the task priority ( 1), fourth
 *  is the stack size ( 1024 bytes) and last is the subprogram executed by 
 * the task
 */
  __po_hi_create_periodic_task (msp430_obc_state_handler_entrypoint_toggle_pwr_k, &(period), 1, 1024, 0, state_handler_entrypoint_toggle_pwr_job);
  
/*!
 * Store the period time for task state_handler_entrypoint_trig_aoi
 */
  __po_hi_milliseconds (&(period), 1);
  
/*!
 * Making Sporadic task
 */
  __po_hi_create_sporadic_task (msp430_obc_state_handler_entrypoint_trig_aoi_k, &(period), 1, 1024, 0, state_handler_entrypoint_trig_aoi_job);
  
/*!
 * Store the period time for task state_handler_entrypoint_trig_mcp
 */
  __po_hi_milliseconds (&(period), 1);
  
/*!
 * Making Sporadic task
 */
  __po_hi_create_sporadic_task (msp430_obc_state_handler_entrypoint_trig_mcp_k, &(period), 1, 1024, 0, state_handler_entrypoint_trig_mcp_job);
  
/*!
 * Store the period time for task state_handler_entrypoint_trig_pwr
 */
  __po_hi_milliseconds (&(period), 1);
  
/*!
 * Making Sporadic task
 */
  __po_hi_create_sporadic_task (msp430_obc_state_handler_entrypoint_trig_pwr_k, &(period), 1, 1024, 0, state_handler_entrypoint_trig_pwr_job);
  
/*!
 * Waiting for other tasks initialization
 */
  __po_hi_wait_initialization ();
  
/*!
 * Used to switch the main task to sleep all the time
 */
  __po_hi_wait_for_tasks ();
  
/*!
 * Return Statement
 */
  return (__PO_HI_MAIN_RETURN);
}


