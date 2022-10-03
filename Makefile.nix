# A collection of m4 macros to make writing Makefiles easier.
# Recommended for a two-pass m4 system.











# Define the implicit rules






# A collection of m4 macros to make writing Makefiles easier.
# Recommended for a two-pass m4 system.











# Define the implicit rules






# Makefile for gemeral UNIX operating systems

M4=m4

CC=cc
CFLAGS=
PREFIX=/usr/local
TESTS=tests/append tests/filter tests/free tests/clear tests/resize tests/map tests/pop tests/foreach tests/init tests/insert tests/find 
DOCS=doc/M4ARRAY_INSERT.cware doc/m4array-intro.cware doc/M4ARRAY_POP.cware doc/M4ARRAY_DECLARE.cware doc/M4ARRAY_FIND.cware doc/m4array-examples-join.cware doc/M4ARRAY_FOREACH.cware doc/m4array.cware doc/M4ARRAY_INIT.cware doc/M4ARRAY_MAP.cware doc/M4ARRAY_CLEAR.cware doc/M4ARRAY_FREE.cware doc/M4ARRAY_FILTER.cware doc/M4ARRAY_APPEND.cware 

all: $(TESTS)

install: maninstall

maninstall:
	mkdir -p $(PREFIX)/share/man/mancware
	cp $(DOCS) $(PREFIX)/share/man/mancware

clean:
	rm -f $(TESTS)
	rm -f $(EXAMPLES)

.SUFFIXES:

tests/resize: tests/resize.c 
	$(CC) tests/resize.c $(CFLAGS) -o tests/resize
tests/foreach: tests/foreach.c 
	$(CC) tests/foreach.c $(CFLAGS) -o tests/foreach
tests/append: tests/append.c 
	$(CC) tests/append.c $(CFLAGS) -o tests/append
tests/filter: tests/filter.c 
	$(CC) tests/filter.c $(CFLAGS) -o tests/filter
tests/init: tests/init.c 
	$(CC) tests/init.c $(CFLAGS) -o tests/init
tests/clear: tests/clear.c 
	$(CC) tests/clear.c $(CFLAGS) -o tests/clear
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


.PHONY: all clean install maninstall
