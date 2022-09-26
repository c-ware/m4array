# Makefile for 4.3 BSD

M4=m4

CC=cc
CPP=/lib/cpp
CFLAGS=
CPPFLAGS=-I/usr/include
TESTS=CONVERT_FILES(tests, .m4)

all: $(TESTS)

clean:
	rm -f $(TESTS)

.SUFFIXES:

GENERATE_RULES(tests, .c,)

.PHONY: all clean
