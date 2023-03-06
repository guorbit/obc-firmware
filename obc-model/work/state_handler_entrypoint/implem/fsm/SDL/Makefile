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
	cd src && $(OPENGEODE) system_structure.pr state_handler_entrypoint.pr

sdl-to-if:
	cd src &&\
	   sdl2if --output-dir ../../../build/modelchecking  ../src/state_handler_entrypoint.pr ../src/system_structure.pr

# C
generate-code:
	mkdir -p code && cd code && \
	   opengeode --taste --toC ../src/state_handler_entrypoint.pr ../src/system_structure.pr

compile-linux: generate-code
	   CODE_PATH=code ADA_INCLUDE_PATH=../../../dataview/Ada gprbuild -p -P state_handler_entrypoint_ada.gpr

