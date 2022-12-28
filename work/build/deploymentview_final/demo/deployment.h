#ifndef __OCARINA_GENERATED_DEPLOYMENT_H_
#define __OCARINA_GENERATED_DEPLOYMENT_H_ 
#include <po_hi_types.h>
/**************************************************** */

/*  This file was automatically generated by Ocarina  */

/*  Working Copy from r36f4e31c */

/*  Do NOT hand-modify this file, as your             */

/*  changes will be lost when you re-run Ocarina      */

/**************************************************** */

#define __PO_HI_MY_NODE demo_k

#define __PO_HI_MY_NODE_NAME "demo_k"

#define __po_hi_gui_poll_nb_ports 3

#define __po_hi_gui_send_tm_aoi_nb_ports 4

#define __po_hi_gui_send_tm_mcp_nb_ports 4

#define __po_hi_state_handler_entrypoint_poll_aoi_nb_ports 2

#define __po_hi_state_handler_entrypoint_poll_mcp_nb_ports 2

#define __po_hi_state_handler_entrypoint_toggle_pwr_nb_ports 2

#define __po_hi_state_handler_entrypoint_trig_aoi_nb_ports 3

#define __po_hi_state_handler_entrypoint_trig_mcp_nb_ports 3

#define __po_hi_state_handler_entrypoint_trig_pwr_nb_ports 3

/*  For each node in the distributed application add an enumerator */

typedef enum
{
  demo_k = 0
} __po_hi_node_t;

typedef enum
{
  invalid_protocol = -1
} __po_hi_protocol_t;

/*  For each thread in the distributed application nodes, add an enumerator */

typedef enum
{
  demo_gui_poll_k_entity = 0,
  demo_gui_send_tm_aoi_k_entity = 1,
  demo_gui_send_tm_mcp_k_entity = 2,
  demo_state_handler_entrypoint_poll_aoi_k_entity = 3,
  demo_state_handler_entrypoint_poll_mcp_k_entity = 4,
  demo_state_handler_entrypoint_toggle_pwr_k_entity = 5,
  demo_state_handler_entrypoint_trig_aoi_k_entity = 6,
  demo_state_handler_entrypoint_trig_mcp_k_entity = 7,
  demo_state_handler_entrypoint_trig_pwr_k_entity = 8,
  invalid_entity = -1
} __po_hi_entity_t;

typedef enum
{
  demo_gui_poll_k = 0,
  demo_gui_send_tm_aoi_k = 1,
  demo_gui_send_tm_mcp_k = 2,
  demo_state_handler_entrypoint_poll_aoi_k = 3,
  demo_state_handler_entrypoint_poll_mcp_k = 4,
  demo_state_handler_entrypoint_toggle_pwr_k = 5,
  demo_state_handler_entrypoint_trig_aoi_k = 6,
  demo_state_handler_entrypoint_trig_mcp_k = 7,
  demo_state_handler_entrypoint_trig_pwr_k = 8,
  invalid_task_id = -1
} __po_hi_task_id;

typedef enum
{
  invalid_device_id = -1
} __po_hi_device_id;

typedef enum
{
  invalid_bus_id = -1
} __po_hi_bus_id;

#define __PO_HI_NB_TASKS 9

#define __PO_HI_TASKS_STACK 0

#define __PO_HI_NB_PROTECTED 2

#define __PO_HI_NB_NODES 1

#define __PO_HI_NB_ENTITIES 9

#define __PO_HI_NB_PORTS 26

typedef enum
{
  gui_poll_global_outport_state_handler_entrypoint_trig_aoi = 0,
  gui_poll_global_outport_state_handler_entrypoint_trig_mcp = 1,
  gui_poll_global_outport_state_handler_entrypoint_trig_pwr = 2,
  gui_send_tm_aoi_global_inport_send_tm_aoi = 3,
  gui_send_tm_aoi_global_outport_state_handler_entrypoint_trig_aoi = 4,
  gui_send_tm_aoi_global_outport_state_handler_entrypoint_trig_mcp = 5,
  gui_send_tm_aoi_global_outport_state_handler_entrypoint_trig_pwr = 6,
  gui_send_tm_mcp_global_inport_send_tm_mcp = 7,
  gui_send_tm_mcp_global_outport_state_handler_entrypoint_trig_aoi = 8,
  gui_send_tm_mcp_global_outport_state_handler_entrypoint_trig_mcp = 9,
  gui_send_tm_mcp_global_outport_state_handler_entrypoint_trig_pwr = 10,
  state_handler_entrypoint_poll_aoi_global_outport_gui_send_tm_aoi = 11,
  state_handler_entrypoint_poll_aoi_global_outport_gui_send_tm_mcp = 12,
  state_handler_entrypoint_poll_mcp_global_outport_gui_send_tm_aoi = 13,
  state_handler_entrypoint_poll_mcp_global_outport_gui_send_tm_mcp = 14,
  state_handler_entrypoint_toggle_pwr_global_outport_gui_send_tm_aoi = 15,
  state_handler_entrypoint_toggle_pwr_global_outport_gui_send_tm_mcp = 16,
  state_handler_entrypoint_trig_aoi_global_inport_trig_aoi = 17,
  state_handler_entrypoint_trig_aoi_global_outport_gui_send_tm_aoi = 18,
  state_handler_entrypoint_trig_aoi_global_outport_gui_send_tm_mcp = 19,
  state_handler_entrypoint_trig_mcp_global_inport_trig_mcp = 20,
  state_handler_entrypoint_trig_mcp_global_outport_gui_send_tm_aoi = 21,
  state_handler_entrypoint_trig_mcp_global_outport_gui_send_tm_mcp = 22,
  state_handler_entrypoint_trig_pwr_global_inport_trig_pwr = 23,
  state_handler_entrypoint_trig_pwr_global_outport_gui_send_tm_aoi = 24,
  state_handler_entrypoint_trig_pwr_global_outport_gui_send_tm_mcp = 25,
  invalid_port_t = -1,
  constant_out_identifier = 27
} __po_hi_port_t;

typedef enum
{
  gui_poll_local_outport_state_handler_entrypoint_trig_aoi = 0,
  gui_poll_local_outport_state_handler_entrypoint_trig_mcp = 1,
  gui_poll_local_outport_state_handler_entrypoint_trig_pwr = 2,
  gui_send_tm_aoi_local_inport_send_tm_aoi = 0,
  gui_send_tm_aoi_local_outport_state_handler_entrypoint_trig_aoi = 1,
  gui_send_tm_aoi_local_outport_state_handler_entrypoint_trig_mcp = 2,
  gui_send_tm_aoi_local_outport_state_handler_entrypoint_trig_pwr = 3,
  gui_send_tm_mcp_local_inport_send_tm_mcp = 0,
  gui_send_tm_mcp_local_outport_state_handler_entrypoint_trig_aoi = 1,
  gui_send_tm_mcp_local_outport_state_handler_entrypoint_trig_mcp = 2,
  gui_send_tm_mcp_local_outport_state_handler_entrypoint_trig_pwr = 3,
  state_handler_entrypoint_poll_aoi_local_outport_gui_send_tm_aoi = 0,
  state_handler_entrypoint_poll_aoi_local_outport_gui_send_tm_mcp = 1,
  state_handler_entrypoint_poll_mcp_local_outport_gui_send_tm_aoi = 0,
  state_handler_entrypoint_poll_mcp_local_outport_gui_send_tm_mcp = 1,
  state_handler_entrypoint_toggle_pwr_local_outport_gui_send_tm_aoi = 0,
  state_handler_entrypoint_toggle_pwr_local_outport_gui_send_tm_mcp = 1,
  state_handler_entrypoint_trig_aoi_local_inport_trig_aoi = 0,
  state_handler_entrypoint_trig_aoi_local_outport_gui_send_tm_aoi = 1,
  state_handler_entrypoint_trig_aoi_local_outport_gui_send_tm_mcp = 2,
  state_handler_entrypoint_trig_mcp_local_inport_trig_mcp = 0,
  state_handler_entrypoint_trig_mcp_local_outport_gui_send_tm_aoi = 1,
  state_handler_entrypoint_trig_mcp_local_outport_gui_send_tm_mcp = 2,
  state_handler_entrypoint_trig_pwr_local_inport_trig_pwr = 0,
  state_handler_entrypoint_trig_pwr_local_outport_gui_send_tm_aoi = 1,
  state_handler_entrypoint_trig_pwr_local_outport_gui_send_tm_mcp = 2,
  invalid_local_port_t = -1
} __po_hi_local_port_t;

#define __PO_HI_NB_DEVICES 0

#define __PO_HI_NB_BUSES 0

#define __PO_HI_NB_PROTOCOLS 0

#define __PO_HI_PORT_TYPE_CONTENT __po_hi_gui_poll_nb_ports, __po_hi_gui_send_tm_aoi_nb_ports, __po_hi_gui_send_tm_mcp_nb_ports, __po_hi_state_handler_entrypoint_poll_aoi_nb_ports, __po_hi_state_handler_entrypoint_poll_mcp_nb_ports, __po_hi_state_handler_entrypoint_toggle_pwr_nb_ports, __po_hi_state_handler_entrypoint_trig_aoi_nb_ports, __po_hi_state_handler_entrypoint_trig_mcp_nb_ports, __po_hi_state_handler_entrypoint_trig_pwr_nb_ports

#endif
