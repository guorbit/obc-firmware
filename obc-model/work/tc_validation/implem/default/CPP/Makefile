VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h src/tc_validation.h src/tc_validation.cc

compile-linux:
	mkdir -p obj && cd obj && g++ -c ../src/*.cc
