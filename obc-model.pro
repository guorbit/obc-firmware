TEMPLATE = lib
CONFIG -= qt
CONFIG += generateC

DISTFILES +=  $(HOME)/tool-inst/share/taste-types/taste-types.asn \
    deploymentview.dv.xml \
    deploymentview.dv.xml
DISTFILES += obc-model.msc
DISTFILES += interfaceview.xml
DISTFILES += work/binaries/*.msc
DISTFILES += work/binaries/coverage/index.html
DISTFILES += work/binaries/filters

DISTFILES += obc-model.asn
DISTFILES += obc-model.acn
include(work/taste.pro)
message($$DISTFILES)

STATECHARTS += \
    fsm.scxml

DISTFILES += work/doc/database/obc_model.png
