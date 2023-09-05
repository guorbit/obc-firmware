INCLUDEPATH += work/dataview/C
HEADERS += work/dataview/C/dataview-uniq.h
HEADERS += work/dataview/Ada/src/*.ads
include(gs_gui/gs_gui.pro)
include(hal/hal.pro)
include(mission_mode_change_tc_handler/mission_mode_change_tc_handler.pro)
include(payload_mode_tracker/payload_mode_tracker.pro)
include(pipeline_mode_tracker/pipeline_mode_tracker.pro)
include(system_mode_manager/system_mode_manager.pro)

