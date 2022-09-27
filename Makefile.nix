# A collection of m4 macros to make writing Makefiles easier.
# Recommended for a two-pass m4 system.











# Define the implicit rules






# A collection of m4 macros to make writing Makefiles easier.
# Recommended for a two-pass m4 system.











# Define the implicit rules






# Makefile for 4.3 BSD

M4=m4

CC=cc
CFLAGS=
TESTS=tests/pop tests/insert tests/map tests/init tests/foreach tests/free tests/find tests/append 

all: $(TESTS)

clean:
	rm -f $(TESTS)

.SUFFIXES:

tests/foreach: tests/foreach.c 
	$(CC) tests/foreach.c $(CFLAGS) -o tests/foreach
tests/append: tests/append.c 
	$(CC) tests/append.c $(CFLAGS) -o tests/append
tests/init: tests/init.c 
	$(CC) tests/init.c $(CFLAGS) -o tests/init
tests/map: tests/map.c 
	$(CC) tests/map.c $(CFLAGS) -o tests/map
tests/find: tests/find.c 
	$(CC) tests/find.c $(CFLAGS) -o tests/find
tests/insert: tests/insert.c 
	$(CC) tests/insert.c $(CFLAGS) -o tests/insert
tests/free: tests/free.c 
	$(CC) tests/free.c $(CFLAGS) -o tests/free
tests/pop: tests/pop.c 
	$(CC) tests/pop.c $(CFLAGS) -o tests/pop


.PHONY: all clean
