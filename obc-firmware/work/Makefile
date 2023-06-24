# MAKEFILE_PATH   := $(abspath $(lastword $(MAKEFILE_LIST)))
MAKEFILE_PATH   := $(lastword $(MAKEFILE_LIST))
TOOL_INST       := $(shell taste-config --prefix)
OUTDIR          := $(dir $(MAKEFILE_PATH))
TASTE_SHARED_TYPES?=${HOME}/.local/share/QtProject/QtCreator/shared_types
ASN1_FILES      := ../obc-firmware.asn ${TOOL_INST}/share/taste-types/taste-types.asn system.asn
CP_FILES        :=       # Context parameters
DATAVIEW_PATH   := ${OUTDIR}/dataview
DATAVIEW_UNIQ   := ${DATAVIEW_PATH}/dataview-uniq.asn
DATAVIEW_ACN    := ${DATAVIEW_PATH}/dataview-uniq.acn
DATAVIEW_AADLV1 := ${DATAVIEW_PATH}/dataview_aadlv1.aadl
DATAVIEW_AADLV2 := ${DATAVIEW_PATH}/dataview_aadlv2.aadl
ASN1_POLICY_FLAGS ?= -typePrefix asn1Scc -renamePolicy 3 -equal -fp AUTO -c -uPER -ACN
#TASTE_SHARED_TYPES?=${TOOL_INST}/share/SharedTypes  # Ellidiss only

# Project cache folder is used to speed up all ASN.1-related processing
export PROJECT_CACHE=${HOME}/.taste_AST_cache
export IV_FILE=$(shell readlink -f ../interfaceview.xml)
all:	build-default
	$(info Run "make -C work check_stack" to analyze the stack usage of your application")

# Call the stack checker
check_stack:
	$(MAKE) -C build -f Makefile.taste check_stack


# Check that all runtimes used in the system are installed
check_targets:
	$(MAKE) -C build -f Makefile.taste check_targets

# Generate the language-specific data view needed before editing user code
dataview:	dataview/C/built dataview/Ada/built
	# Copy the dataview to SDL/SEDS function adcs_mode_tracker (no context parameters)
	cp -u ${DATAVIEW_UNIQ} adcs_mode_tracker/SDL/src
	# Compute MD5 of the dataview, needed to decide if code needs to be re-generated
	md5sum -c "adcs_mode_tracker/SDL/src/dataview.md5"  &> /dev/null || md5sum  "adcs_mode_tracker/SDL/src/dataview-uniq.asn" >  "adcs_mode_tracker/SDL/src/dataview.md5"
	# Copy the dataview to SDL/SEDS function comms_mode_tracker (no context parameters)
	cp -u ${DATAVIEW_UNIQ} comms_mode_tracker/SDL/src
	# Compute MD5 of the dataview, needed to decide if code needs to be re-generated
	md5sum -c "comms_mode_tracker/SDL/src/dataview.md5"  &> /dev/null || md5sum  "comms_mode_tracker/SDL/src/dataview-uniq.asn" >  "comms_mode_tracker/SDL/src/dataview.md5"
	# Copy the dataview to SDL/SEDS function deployer_mode_tracker (no context parameters)
	cp -u ${DATAVIEW_UNIQ} deployer_mode_tracker/SDL/src
	# Compute MD5 of the dataview, needed to decide if code needs to be re-generated
	md5sum -c "deployer_mode_tracker/SDL/src/dataview.md5"  &> /dev/null || md5sum  "deployer_mode_tracker/SDL/src/dataview-uniq.asn" >  "deployer_mode_tracker/SDL/src/dataview.md5"
	# Copy the dataview to SDL/SEDS function eps_mode_tracker (no context parameters)
	cp -u ${DATAVIEW_UNIQ} eps_mode_tracker/SDL/src
	# Compute MD5 of the dataview, needed to decide if code needs to be re-generated
	md5sum -c "eps_mode_tracker/SDL/src/dataview.md5"  &> /dev/null || md5sum  "eps_mode_tracker/SDL/src/dataview-uniq.asn" >  "eps_mode_tracker/SDL/src/dataview.md5"
	# Copy the dataview to SDL/SEDS function mission_mode_change_tc_handler (no context parameters)
	cp -u ${DATAVIEW_UNIQ} mission_mode_change_tc_handler/SDL/src
	# Compute MD5 of the dataview, needed to decide if code needs to be re-generated
	md5sum -c "mission_mode_change_tc_handler/SDL/src/dataview.md5"  &> /dev/null || md5sum  "mission_mode_change_tc_handler/SDL/src/dataview-uniq.asn" >  "mission_mode_change_tc_handler/SDL/src/dataview.md5"
	# Copy the dataview to SDL/SEDS function mode_status_report_collector (no context parameters)
	cp -u ${DATAVIEW_UNIQ} mode_status_report_collector/SDL/src
	# Compute MD5 of the dataview, needed to decide if code needs to be re-generated
	md5sum -c "mode_status_report_collector/SDL/src/dataview.md5"  &> /dev/null || md5sum  "mode_status_report_collector/SDL/src/dataview-uniq.asn" >  "mode_status_report_collector/SDL/src/dataview.md5"
	# Copy the dataview to SDL/SEDS function payload_mode_tracker (no context parameters)
	cp -u ${DATAVIEW_UNIQ} payload_mode_tracker/SDL/src
	# Compute MD5 of the dataview, needed to decide if code needs to be re-generated
	md5sum -c "payload_mode_tracker/SDL/src/dataview.md5"  &> /dev/null || md5sum  "payload_mode_tracker/SDL/src/dataview-uniq.asn" >  "payload_mode_tracker/SDL/src/dataview.md5"
	# Copy the dataview to SDL/SEDS function pipeline_mode_tracker (no context parameters)
	cp -u ${DATAVIEW_UNIQ} pipeline_mode_tracker/SDL/src
	# Compute MD5 of the dataview, needed to decide if code needs to be re-generated
	md5sum -c "pipeline_mode_tracker/SDL/src/dataview.md5"  &> /dev/null || md5sum  "pipeline_mode_tracker/SDL/src/dataview-uniq.asn" >  "pipeline_mode_tracker/SDL/src/dataview.md5"
	# Copy the dataview to SDL/SEDS function system_mode_manager (no context parameters)
	cp -u ${DATAVIEW_UNIQ} system_mode_manager/SDL/src
	# Compute MD5 of the dataview, needed to decide if code needs to be re-generated
	md5sum -c "system_mode_manager/SDL/src/dataview.md5"  &> /dev/null || md5sum  "system_mode_manager/SDL/src/dataview-uniq.asn" >  "system_mode_manager/SDL/src/dataview.md5"

# Generate the complete dataview, including Python bindings if there is a GUI
${DATAVIEW_PATH}/built:	dataview dataview/Python/built
	touch $@

# Build based on the deployment view
# The parallel invocation can not be added here because of matlab remote error
# For local matlab instalation it can be added
build-default:	aadl2glueC build/system_config.h ${DATAVIEW_PATH}/built build/deploymentview_final/Makefile
	$(MAKE) -C build -f Makefile.taste

# Execute the generated binaries (used in Space Creator when using the Run button)
run: # Space creator will always build before, so no need to depend on build-default
	$(MAKE) -j -C build -f Makefile.taste run

# Run the Concurrency View analysis tool (cheddar/marzhin)
run_cv: build/ConcurrencyView.aadl
	TASTECV --load $^

# The Concurrency View needed by Cheddar is the concatenation of system.aadl and ocarina_components.aadl
build/ConcurrencyView.aadl:	build/system.aadl
	cat $^ $(shell taste-config --prefix)/share/ocarina/AADLv2/ocarina_components.aadl > $@

# Rule to invoke Ocarina (generation of POHI middleware code)
build/deploymentview_final/Makefile:	build/main.aadl ${DATAVIEW_AADLV2}
	$(MAKE) -C build -f Makefile.taste ocarina

# Optionally manage SQL Database (run taste-create-database to enable)
sql_db/DV.py:
	mkdir -p sql_db && touch $@

# Create dataview-uniq.asn by concatenating all asn1 input files
${DATAVIEW_UNIQ}:	${ASN1_FILES}
	mkdir -p ${PROJECT_CACHE} && mkdir -p ${DATAVIEW_PATH}
	sed -e '$$s/$$/\n/' -s $^ > $@

# Create dataview-uniq.acn by concatenating all input files
${DATAVIEW_ACN}:	../obc-firmware.acn
	mkdir -p ${DATAVIEW_PATH}
	sed -e '$$s/$$/\n/' -s $^ > $@

# system_config.h is used to filter out non-needed ASN.1 encoder/decoders
build/system_config.h:	$(wildcard */*/wrappers/*_system_config.h)
	cat $^ > $@

#  Call DMT/aadl2glueC to generate glue code from the mini-cv.aadl files
aadl2glueC:	adcs_mode_tracker/SDL/wrappers/aadl2glueC_built comms_mode_tracker/SDL/wrappers/aadl2glueC_built deployer_mode_tracker/SDL/wrappers/aadl2glueC_built eps_mode_tracker/SDL/wrappers/aadl2glueC_built gs_gui/GUI/wrappers/aadl2glueC_built hal/C/wrappers/aadl2glueC_built mission_mode_change_tc_handler/SDL/wrappers/aadl2glueC_built mode_status_report_collector/SDL/wrappers/aadl2glueC_built payload_mode_tracker/SDL/wrappers/aadl2glueC_built pipeline_mode_tracker/SDL/wrappers/aadl2glueC_built system_mode_manager/SDL/wrappers/aadl2glueC_built

# Build dataview.aadl in AADLv1 format, used by DMT to generate glue code
${DATAVIEW_AADLV1}: ${DATAVIEW_UNIQ}
	asn2aadlPlus  $< $@

# Build dataview.aadl in AADLv2 format, used by Ocarina to generate glue code
${DATAVIEW_AADLV2}: ${DATAVIEW_UNIQ}
	asn2aadlPlus --aadlv2  $< $@

adcs_mode_tracker/SDL/wrappers/aadl2glueC_built: adcs_mode_tracker/SDL/wrappers/adcs_mode_tracker_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

comms_mode_tracker/SDL/wrappers/aadl2glueC_built: comms_mode_tracker/SDL/wrappers/comms_mode_tracker_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

deployer_mode_tracker/SDL/wrappers/aadl2glueC_built: deployer_mode_tracker/SDL/wrappers/deployer_mode_tracker_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

eps_mode_tracker/SDL/wrappers/aadl2glueC_built: eps_mode_tracker/SDL/wrappers/eps_mode_tracker_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

gs_gui/GUI/wrappers/aadl2glueC_built: gs_gui/GUI/wrappers/gs_gui_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

hal/C/wrappers/aadl2glueC_built: hal/C/wrappers/hal_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

mission_mode_change_tc_handler/SDL/wrappers/aadl2glueC_built: mission_mode_change_tc_handler/SDL/wrappers/mission_mode_change_tc_handler_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

mode_status_report_collector/SDL/wrappers/aadl2glueC_built: mode_status_report_collector/SDL/wrappers/mode_status_report_collector_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

payload_mode_tracker/SDL/wrappers/aadl2glueC_built: payload_mode_tracker/SDL/wrappers/payload_mode_tracker_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

pipeline_mode_tracker/SDL/wrappers/aadl2glueC_built: pipeline_mode_tracker/SDL/wrappers/pipeline_mode_tracker_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

system_mode_manager/SDL/wrappers/aadl2glueC_built: system_mode_manager/SDL/wrappers/system_mode_manager_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@


# Compile the ASN.1 models in C
dataview/C/built: ${DATAVIEW_UNIQ} ${DATAVIEW_ACN} ${CP_FILES}
	mkdir -p $(dir $@)
	# asn2dataModel does not take the ACN files, and only calls asn1scc
	# asn2dataModel -o $(dir $@) -toC ${DATAVIEW_UNIQ} ${DATAVIEW_ACN}
	asn1scc ${ASN1SCC_FLAGS} -o $(dir $@) ${ASN1_POLICY_FLAGS} $^
	cp ${TOOL_INST}/share/AutoGUI/debug_messages.? dataview/C
	cp ${TOOL_INST}/share/AutoGUI/timeInMS.? dataview/C
	#cd dataview/C && msgPrinter ../dataview-uniq.asn  (disabled: this is not used anywhere)
	cd dataview/C && msgPrinterASN1 ../dataview-uniq.asn
	touch $@

# Compile the ASN.1 models in Python for the autogenerated GUIs
dataview/Python/built:	dataview/C/built gs_gui/GUI/wrappers/aadl2glueC_built sql_db/DV.py
	mkdir -p $(dir $@)
	asn2dataModel -o $(dir $@) -toPython ${DATAVIEW_UNIQ}
	$(MAKE) -C dataview/Python -f Makefile.python
	cp dataview/Python/* gs_gui/GUI/wrappers/python
	cp dataview/C/timeInMS.[ch] dataview/C/debug_messages.c gs_gui/GUI/wrappers/python
	cd gs_gui/GUI/wrappers/python && \
	   gcc -g -fPIC -c  gui_api.c ../../src/queue_manager.c timeInMS.c debug_messages.c -I. -I../../src && \
	   gcc -g -shared -o PythonAccess.so gui_api.o queue_manager.o timeInMS.o debug_messages.o -lrt
	mkdir -p binaries/gs_gui_GUI
	cp -f gs_gui/GUI/wrappers/python/* binaries/gs_gui_GUI
	cp -f gs_gui/GUI/wrappers/*.py binaries/gs_gui_GUI
	cp -f gs_gui/GUI/wrappers/*.ui binaries/gs_gui_GUI
	echo "errCodes = \\" >> binaries/gs_gui_GUI/datamodel.py
	taste-asn1-errCodes binaries/gs_gui_GUI/dataview-uniq.h >> binaries/gs_gui_GUI/datamodel.py
	if [ -f sql_db/db.info ]; then cd binaries/gs_gui_GUI && ln -fs ../../sql_db; fi
	#  Interface view must be placed in the gui folder to allow replaying MSCs
	cp -u ../InterfaceView.aadl binaries/gs_gui_GUI
	touch $@

dataview/Ada/built: ${DATAVIEW_UNIQ} ${CP_FILES}
	mkdir -p $(dir $@)
	asn2dataModel -allboards -o $(dir $@) -toAda $^
	touch $@
	cd dataview/Ada && rm -f gnat.cfg GPS_project.gpr IgnoredExaminerWarnings.wrn runSpark.sh

simulink_skeletons:
	# target required only for SIMULINK, QGenC or QGenAda InterfaceView function blocks
	# empty otherwise


clean:
	rm -rf binaries dataview
	$(MAKE) -C build -f Makefile.taste clean

.PHONY: clean simu compile-all-linux function-instances-linux function-types-linux build-default dataview build-rtems-ada dataview build/modelchecking modelchecking/subtypes/$(SUBTYPE) obs-to-if aadl-to-if asn-to-if $(PROPERTIES_CONFIG) run_cv simulink_skeletons

