dnl Makefile to be used for distribution. Compiles templates for source
dnl files, generates documentation, etc.

M4=m4

CC=cc
CFLAGS=-Wall -Wextra -Wpedantic
SRCS=CONVERT_FILES(tests, .m4, .c) CONVERT_FILES(examples, .m4, .c)
TESTS=CONVERT_FILES(tests, .m4)
EXAMPLES=CONVERT_FILES(examples, .m4)

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

GENERATE_RULES(tests, .m4, .c)
GENERATE_RULES(tests, .m4, ,.c)

GENERATE_RULES(examples, .m4, .c)
GENERATE_RULES(examples, .m4, ,.c)

.PHONY: all clean dist dist_clean
