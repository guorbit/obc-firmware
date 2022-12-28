INCLUDEPATH += work/dataview/C
HEADERS += work/dataview/C/dataview-uniq.h
HEADERS += work/dataview/Ada/src/*.ads
include(gui/gui.pro)
include(loc_provider/loc_provider.pro)
include(state_handler_entrypoint/state_handler_entrypoint.pro)
include(tc_provider/tc_provider.pro)
include(tc_validation/tc_validation.pro)
include(tm_collection/tm_collection.pro)
include(tm_provider/tm_provider.pro)

