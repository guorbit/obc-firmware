VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  src/led_blinker.h \
                  src/led_blinker.c

compile-linux:
	mkdir -p obj && cd obj && gcc -c ../src/*.c
