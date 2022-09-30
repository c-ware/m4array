# Makefile for 4.3 BSD

M4=m4

CC=cc
CFLAGS=
TESTS=CONVERT_FILES(tests, .m4c)

all: $(TESTS)

clean:
	rm -f $(TESTS)

.SUFFIXES:

GENERATE_RULES(tests, .c,)

.PHONY: all clean
