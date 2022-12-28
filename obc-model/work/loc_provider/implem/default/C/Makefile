VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  src/loc_provider.h \
                  src/loc_provider.c

compile-linux:
	mkdir -p obj && cd obj && gcc -c ../src/*.c
