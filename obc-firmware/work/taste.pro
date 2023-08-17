INCLUDEPATH += work/dataview/C
HEADERS += work/dataview/C/dataview-uniq.h
HEADERS += work/dataview/Ada/src/*.ads
include(adcs_mode_tracker/adcs_mode_tracker.pro)
include(comms_mode_tracker/comms_mode_tracker.pro)
include(deployer_mode_tracker/deployer_mode_tracker.pro)
include(eps_mode_tracker/eps_mode_tracker.pro)
include(gs_gui/gs_gui.pro)
include(hal/hal.pro)
include(mission_mode_change_tc_handler/mission_mode_change_tc_handler.pro)
include(payload_mode_tracker/payload_mode_tracker.pro)
include(pipeline_mode_tracker/pipeline_mode_tracker.pro)
include(system_mode_manager/system_mode_manager.pro)

