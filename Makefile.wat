# A collection of m4 macros to make writing Makefiles easier.
# Recommended for a two-pass m4 system.











# Define the implicit rules









# A collection of m4 macros to make writing Makefiles easier.
# Recommended for a two-pass m4 system.











# Define the implicit rules









# Makefile for Watcom

M4=m4

CC=wcc386
LD=wlink
CFLAGS=-dLIBERROR_ENABLED -dLIBERROR_STREAM=stderr
TESTS=tests\resize.exe tests\foreach.exe tests\append.exe tests\filter.exe tests\init.exe tests\clear.exe tests\map.exe tests\find.exe tests\insert.exe tests\free.exe tests\pop.exe 

all: $(TESTS) .symbolic

clean: .symbolic
	rm -f $(TESTS)

tests\resize.obj: tests\resize.c 
	$(CC) tests\resize.c -fo=tests\resize.obj $(CFLAGS)
tests\foreach.obj: tests\foreach.c 
	$(CC) tests\foreach.c -fo=tests\foreach.obj $(CFLAGS)
tests\append.obj: tests\append.c 
	$(CC) tests\append.c -fo=tests\append.obj $(CFLAGS)
tests\filter.obj: tests\filter.c 
	$(CC) tests\filter.c -fo=tests\filter.obj $(CFLAGS)
tests\init.obj: tests\init.c 
	$(CC) tests\init.c -fo=tests\init.obj $(CFLAGS)
tests\clear.obj: tests\clear.c 
	$(CC) tests\clear.c -fo=tests\clear.obj $(CFLAGS)
tests\map.obj: tests\map.c 
	$(CC) tests\map.c -fo=tests\map.obj $(CFLAGS)
tests\find.obj: tests\find.c 
	$(CC) tests\find.c -fo=tests\find.obj $(CFLAGS)
tests\insert.obj: tests\insert.c 
	$(CC) tests\insert.c -fo=tests\insert.obj $(CFLAGS)
tests\free.obj: tests\free.c 
	$(CC) tests\free.c -fo=tests\free.obj $(CFLAGS)
tests\pop.obj: tests\pop.c 
	$(CC) tests\pop.c -fo=tests\pop.obj $(CFLAGS)

tests\resize.exe: tests\resize.obj 
	$(LD) FILE tests\resize.obj NAME tests\resize.exe
tests\foreach.exe: tests\foreach.obj 
	$(LD) FILE tests\foreach.obj NAME tests\foreach.exe
tests\append.exe: tests\append.obj 
	$(LD) FILE tests\append.obj NAME tests\append.exe
tests\filter.exe: tests\filter.obj 
	$(LD) FILE tests\filter.obj NAME tests\filter.exe
tests\init.exe: tests\init.obj 
	$(LD) FILE tests\init.obj NAME tests\init.exe
tests\clear.exe: tests\clear.obj 
	$(LD) FILE tests\clear.obj NAME tests\clear.exe
tests\map.exe: tests\map.obj 
	$(LD) FILE tests\map.obj NAME tests\map.exe
tests\find.exe: tests\find.obj 
	$(LD) FILE tests\find.obj NAME tests\find.exe
tests\insert.exe: tests\insert.obj 
	$(LD) FILE tests\insert.obj NAME tests\insert.exe
tests\free.exe: tests\free.obj 
	$(LD) FILE tests\free.obj NAME tests\free.exe
tests\pop.exe: tests\pop.obj 
	$(LD) FILE tests\pop.obj NAME tests\pop.exe


.SUFFIXES:

