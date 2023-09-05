#!/usr/bin/env python3
#
# TASTE Automatically generated file...You may edit at will.
# ----------------------------------------------------------------------------
import os
import sys
import time
import signal
import queue
from PySide6.QtCore                  import QCoreApplication, Qt
# ----------------------------------------------------------------------------
from asn1_value_editor.Scenario      import Scenario, PollerThread
from asn1_value_editor.udpcontroller import tasteUDP
# ----------------------------------------------------------------------------
#  You may edit the scenario below or create new ones (@Scenario decorator)
#  When you add new scenarios, they will all run in parallel.
#
#  You can use these three API functions to communicate with the main binary:
#  (1) queue.sendMsg('Name of Provided Interface', 'Parameter')
#          The parameters are expressed textually in ASN.1 Value Notation
#          (also called GSER). For example a record's syntax is:
#          { fieldName1 value1, fieldName2 value2 }
#  (2) queue.expectMsg ('Name of RI',
#                       'Parameter value in Extended ASN.1 format',
#                       lineNo=optional line reference,
#                       ignoreOther=True/False)
#          Extended ASN.1 format lets you replace a field value with a star (*)
#          meaning that you do not want the tool to check it against any
#          specific value
#          ignoreOther: set True if you want the tool to ignore other messages
#                       and want to trigger an error only when you get this
#                       message with the wrong parameters
# (3) (msgId, val) = queue.getNextMsg(timeout=10)
#      if msgId == 'Name of an interface':
#          print 'The value is', val.fieldName.Get()
# ----------------------------------------------------------------------------
# First document
# from the section : mscdocument Untitled_Document
# Type of MSC: AND
# Depends on ASN.1 model in file: dataview-uniq.asn
# tc_change_mission_mode (Mission-Mode-Change-TC-T)
# report_mission_mode_change (Mission-Mode-Change-Report-T)
# ----------------------------------------------------------------------------
# from the section : mscdocument Untitled_Leaf
# Type of MSC: LEAF
# Depends on ASN.1 model in file: dataview-uniq.asn
# ----------------------------------------------------------------------------
# msc Untitled_MSC;
@Scenario
def Exercise_gs_gui(queue):
   # set up text fixture state and consume report without checking
   queue.sendMsg('tc_change_mission_mode', '''{target-mission-mode mission-processing}''')
   queue.expectMsg('report_mission_mode_change', '''{ target-mission-mode  *, system-mode-status-report  * }''', ignoreOther=False)
   # send mission mode change telecommand and check the response report
   queue.sendMsg('tc_change_mission_mode', '''{ target-mission-mode  mission-processing }''')
   queue.expectMsg('report_mission_mode_change', '''{ target-mission-mode  mission-processing, system-mode-status-report  { eps-report  { eps-mode  eps-high-power, eps-last-op  mode-status-nop }, comms-report  { comms-mode  comms-downlink, comms-last-op  mode-status-nop }, deployer-report  { deployer-mode  deployer-idle, deployer-last-op  mode-status-nop }, adcs-report  { adcs-mode  adcs-idle, adcs-last-op  mode-status-nop }, payload-report  { payload-mode  payload-idle, payload-last-op  mode-status-nop }, pipeline-report  { pipeline-mode  pipeline-processing-lp, pipeline-last-op  mode-status-nop } } }''', ignoreOther=False)
# Entry point
def runScenario(pipe_in=None, pipe_out=None, udpController=None):
    # Queue for getting scenario status
    log = queue.Queue()
    if udpController:
        gs_gui = Exercise_gs_gui(log, name='Exercise_gs_gui')
        udpController.slots.append(gs_gui.msq_q)
        gs_gui.wait()
        udpController.slots.remove(gs_gui.msg_q)
        return 0 # gs_gui.status
    else:
    # Use message queue (TASTE default)
        poller = PollerThread()
        gs_gui = Exercise_gs_gui(log, name='Exercise_gs_gui')
        poller.slots.append(gs_gui.msg_q)
        poller.start()
        gs_gui.start()
        # Wait and log messages from both scenarii
        while True:
            time.sleep(0.001)
            try:
                scenario, severity, msg = log.get(block=False)
            except queue.Empty:
                pass
            else:
                log.task_done()
                try:
                    # If called from the GUI, send log through pipe
                    pipe_out.send((scenario, severity, msg))
                except AttributeError:
                    print('[{level}] {name} - {msg}'.format
                        (level=severity, name=scenario, msg=msg))
                if severity == 'ERROR' or msg == 'END':
                    # Stop execution on first error or completed scenario
                    try:
                        # send to GUI
                        pipe_out.send(('All', 'COMMAND', 'END'))
                    except AttributeError:
                        gs_gui.stop()
                        poller.stop()
                        if severity == 'ERROR':
                            return 1
                        else:
                            return 0
                try:
                    if pipe_out.poll():
                        cmd = pipe_out.recv()
                        if cmd == 'STOP':
                            gs_gui.stop()
                            poller.stop()
                            return 0
                except AttributeError:
                    pass


# End of first document
# Entry point when scenario is executed from the command line
if __name__ == "__main__":
    signal.signal(signal.SIGINT, signal.SIG_DFL)
    udpController = None
    if '--udp' in sys.argv:
        # Create UDP Controller with default IP/Port values (127.0.0.1:7755:7756)
        udpController = tasteUDP()
    QCoreApplication(sys.argv)
    sys.exit(runScenario(udpController))
