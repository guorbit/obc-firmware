VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  src/tm_collection.h \
                  src/tm_collection.c

compile-linux:
	mkdir -p obj && cd obj && gcc -c ../src/*.c
