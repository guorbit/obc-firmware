VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  ../../dataview/C/Context-tm-provider.h \
                  ../../dataview/C/Context-tm-provider.c \
                  src/tm_provider.h \
                  src/tm_provider.c

compile-linux:
	mkdir -p obj && cd obj && gcc -c ../src/*.c
