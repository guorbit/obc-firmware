#!/usr/bin/env python3

import os
import sys
from pathlib import Path

# This system contains the following nodes:
# node_1, node_2

def name_converter(task_name: str):
    task_name_job = task_name
    return task_name_job


def report_node_1():

   error_sentinel = [False]
   functions = []

   
   def report_partition_x86_ground_station():
   
       print("[-] Checking callgraph files' presence in x86_ground_station...")
   
       ci_files =[file.name.strip(' \n\'\"') for file in Path('.').rglob('*.ci')]
   
       if len(ci_files) == 0:
           print(f"[!]\033[93m WARNING: No *.ci files found in {os.path.abspath('.')}, using old stack analyzer.\033[00m")
           version = 9     # GCC == 9.X
       else:
           version = 10    # GCC >= 10.X
   
       print("[-] Checking stack usage of tasks inside x86_ground_station...")
   
       def add_task(task_name):
           task_name_job = name_converter(task_name)
           functions.append(task_name_job)
   
       functions[:] = []
       add_task("gui_poll")
       add_task("gui_send_tm_aoi")
       add_task("gui_send_tm_mcp")
   
       stack_usage = {}
       if version == 9:
           elf_binary = "../binaries/x86_ground_station"
       else:
           elf_binary = ''  # binary not needed for new stack analyzer
   
       shift_offset = 0
       # On Linux, a constant named PTHREAD_STACK_MIN gives the minimum stack size for a thread
       # in addition to the user space stack. We have to add this offest to the computed value:
       shift_offset = 16384
       if (version == 9) and (not os.path.exists(elf_binary)):
           print("[x]\033[91m Failed to locate ELF binary:", elf_binary, "\033[00m")
           print("[x]\033[91m Aborting...\033[00m")
           sys.exit(1)
   
       for line in os.popen(f"FindStackUsageMain.py --gcc={version} --binary={elf_binary} --path=./node_1 --roots={','.join(functions)} --verbose"):
           data = line.strip().split(';;')
           try:
               if len(data) == 3:
                   stack_usage[data[1].split(':')[-1].strip()] = int(data[0]), data[2]
           except:
               pass
       pohic_stack_of = {
           
           "gui_poll" : 8388608,  # Linux threads default to "ulimit -s" (8192K by default)
           
           "gui_send_tm_aoi" : 8388608,  # Linux threads default to "ulimit -s" (8192K by default)
           
           "gui_send_tm_mcp" : 8388608,  # Linux threads default to "ulimit -s" (8192K by default)
           
       }
   
       def check_task(task_name, version):
           task_name_job = name_converter(task_name)
           if version == 9:
               pass
   
           elif version >= 10:
               pass
           else:
               raise ValueError(f"Invalid GCC Version: {version} ; Must be >= 9")
   
           if task_name not in pohic_stack_of:
               print("[!]\033[93m WARNING: Unable to check stack usage of", task_name_job, "\033[00m")
               return
   
           elif task_name_job not in stack_usage:
               print("[!]\033[93m WARNING: ", task_name_job, " is either recursive or missing\033[00m")
               return
   
           reserved_stack = pohic_stack_of[task_name]
           actual_stack, path = stack_usage[task_name_job]
           actual_stack += shift_offset
           if reserved_stack < actual_stack:
               print("[x]\033[91m ERROR: Stack usage of", task_name_job, "is", actual_stack,
                       "which is higher than", reserved_stack, "\033[00m")
               print("[x]\033[91m ERROR: Call chain is: ", path, "\033[00m")
               error_sentinel[0] = True
           else:
               print("[-]\033[92m Stack usage of %32s" % task_name_job, "is %7d /%7d \033[00m" % (
                   actual_stack, reserved_stack))
   
       check_task("gui_poll", version)
       check_task("gui_send_tm_aoi", version)
       check_task("gui_send_tm_mcp", version)
   

   report_partition_x86_ground_station()
   if error_sentinel[0]:
       sys.exit(1)
def report_node_2():

   error_sentinel = [False]
   functions = []

   
   def report_partition_msp430_obc():
   
       print("[-] Checking callgraph files' presence in msp430_obc...")
   
       ci_files =[file.name.strip(' \n\'\"') for file in Path('.').rglob('*.ci')]
   
       if len(ci_files) == 0:
           print(f"[!]\033[93m WARNING: No *.ci files found in {os.path.abspath('.')}, using old stack analyzer.\033[00m")
           version = 9     # GCC == 9.X
       else:
           version = 10    # GCC >= 10.X
   
       print("[-] Checking stack usage of tasks inside msp430_obc...")
   
       def add_task(task_name):
           task_name_job = name_converter(task_name)
           functions.append(task_name_job)
   
       functions[:] = []
       add_task("state_handler_entrypoint_poll_aoi")
       add_task("state_handler_entrypoint_poll_mcp")
       add_task("state_handler_entrypoint_toggle_pwr")
       add_task("state_handler_entrypoint_trig_aoi")
       add_task("state_handler_entrypoint_trig_mcp")
       add_task("state_handler_entrypoint_trig_pwr")
   
       stack_usage = {}
       if version == 9:
           elf_binary = "../binaries/msp430_obc"
       else:
           elf_binary = ''  # binary not needed for new stack analyzer
   
       shift_offset = 0
       if (version == 9) and (not os.path.exists(elf_binary)):
           print("[x]\033[91m Failed to locate ELF binary:", elf_binary, "\033[00m")
           print("[x]\033[91m Aborting...\033[00m")
           sys.exit(1)
   
       for line in os.popen(f"FindStackUsageMain.py --gcc={version} --binary={elf_binary} --path=./node_2 --roots={','.join(functions)} --verbose"):
           data = line.strip().split(';;')
           try:
               if len(data) == 3:
                   stack_usage[data[1].split(':')[-1].strip()] = int(data[0]), data[2]
           except:
               pass
       pohic_stack_of = {
           
           "state_handler_entrypoint_poll_aoi" :  1024,
           
           "state_handler_entrypoint_poll_mcp" :  1024,
           
           "state_handler_entrypoint_toggle_pwr" :  1024,
           
           "state_handler_entrypoint_trig_aoi" :  1024,
           
           "state_handler_entrypoint_trig_mcp" :  1024,
           
           "state_handler_entrypoint_trig_pwr" :  1024,
           
       }
   
       def check_task(task_name, version):
           task_name_job = name_converter(task_name)
           if version == 9:
               pass
   
           elif version >= 10:
               pass
           else:
               raise ValueError(f"Invalid GCC Version: {version} ; Must be >= 9")
   
           if task_name not in pohic_stack_of:
               print("[!]\033[93m WARNING: Unable to check stack usage of", task_name_job, "\033[00m")
               return
   
           elif task_name_job not in stack_usage:
               print("[!]\033[93m WARNING: ", task_name_job, " is either recursive or missing\033[00m")
               return
   
           reserved_stack = pohic_stack_of[task_name]
           actual_stack, path = stack_usage[task_name_job]
           actual_stack += shift_offset
           if reserved_stack < actual_stack:
               print("[x]\033[91m ERROR: Stack usage of", task_name_job, "is", actual_stack,
                       "which is higher than", reserved_stack, "\033[00m")
               print("[x]\033[91m ERROR: Call chain is: ", path, "\033[00m")
               error_sentinel[0] = True
           else:
               print("[-]\033[92m Stack usage of %32s" % task_name_job, "is %7d /%7d \033[00m" % (
                   actual_stack, reserved_stack))
   
       check_task("state_handler_entrypoint_poll_aoi", version)
       check_task("state_handler_entrypoint_poll_mcp", version)
       check_task("state_handler_entrypoint_toggle_pwr", version)
       check_task("state_handler_entrypoint_trig_aoi", version)
       check_task("state_handler_entrypoint_trig_mcp", version)
       check_task("state_handler_entrypoint_trig_pwr", version)
   

   report_partition_msp430_obc()
   if error_sentinel[0]:
       sys.exit(1)

def check_all():
    report_node_1()
    return

if __name__ == '__main__':
    ''' Run main application '''
    check_all()
