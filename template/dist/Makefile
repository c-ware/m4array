dnl Makefile to be used for distribution. Compiles templates for source
dnl files, generates documentation, etc.

M4=m4

CC=cc
CFLAGS=-Wall -Wextra -Wpedantic -Wno-unused-but-set-variable -g
SRCS=CONVERT_FILES(tests, .m4c, .c) CONVERT_FILES(examples, .m4c, .c)
TESTS=CONVERT_FILES(tests, .m4c)
EXAMPLES=CONVERT_FILES(examples, .m4c)

all: $(SRCS) $(TESTS) $(EXAMPLES)

clean:
	rm -f $(TESTS)
	rm -f $(EXAMPLES)

dnl Run templating
dist: $(SRCS)

dnl Cleanup files created by the distribution rule.
dist_clean:
	rm -rf $(SRCS)

.SUFFIXES:

GENERATE_RULES(tests, .m4c, .c)
GENERATE_RULES(tests, .m4c, ,.c)

GENERATE_RULES(examples, .m4c, .c)
GENERATE_RULES(examples, .m4c, ,.c)

.PHONY: all clean dist dist_clean
