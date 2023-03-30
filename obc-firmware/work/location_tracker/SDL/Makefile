# SDL
#Taste::Startup_Priority 1
#TASTE_IV_Properties::Default_CodeGen c
SEDS_CONVERTER?=spacecreator.AppImage --sedsconverter
OPENGEODE?=opengeode
VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	cd src && $(OPENGEODE) system_structure.pr location_tracker.pr

sdl-to-if:
	cd src &&\
	   sdl2if --output-dir ../../../build/modelchecking  ../src/location_tracker.pr ../src/system_structure.pr

# C
generate-code:
	mkdir -p code && cd code && \
	   opengeode --taste --toC ../src/location_tracker.pr ../src/system_structure.pr

compile-linux: generate-code
	   CODE_PATH=code ADA_INCLUDE_PATH=../../../dataview/Ada gprbuild -p -P location_tracker_ada.gpr

