TEMPLATE = lib
CONFIG -= qt
CONFIG += generateC

DISTFILES +=  $(HOME)/tool-inst/share/taste-types/taste-types.asn

DISTFILES += obc-firmware.asn
DISTFILES += obc-firmware.acn
DISTFILES += interfaceview.xml
DISTFILES += deploymentview.dv.xml
DISTFILES += obc-firmware.msc
DISTFILES += work/binaries/*.msc
DISTFILES += work/binaries/coverage/index.html
DISTFILES += work/binaries/filters

include(work/taste.pro)
message($$DISTFILES)

STATECHARTS +=

DISTFILES +=
DISTFILES += work/doc/database/obc_firmware.png
