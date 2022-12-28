VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h src/state_handler_entrypoint.h src/state_handler_entrypoint.cc

compile-linux:
	mkdir -p obj && cd obj && g++ -c ../src/*.cc
