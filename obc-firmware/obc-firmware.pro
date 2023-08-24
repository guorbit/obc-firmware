TEMPLATE = lib
CONFIG -= qt
CONFIG += generateC

DISTFILES +=  $(HOME)/tool-inst/share/taste-types/taste-types.asn
DISTFILES += obc-firmware.msc
DISTFILES += interfaceview.xml
DISTFILES += work/binaries/*.msc
DISTFILES += work/binaries/coverage/index.html
DISTFILES += work/binaries/filters
DISTFILES += work/system.asn

DISTFILES += deploymentview_cpp.dv.xml
DISTFILES += deploymentview_pohic.dv.xml
DISTFILES += obc-firmware.asn
DISTFILES += obc-firmware.acn
include(work/taste.pro)
message($$DISTFILES)

