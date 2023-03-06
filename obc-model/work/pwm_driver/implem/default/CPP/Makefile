VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h src/pwm_driver.h src/pwm_driver.cc

compile-linux:
	mkdir -p obj && cd obj && g++ -c ../src/*.cc
