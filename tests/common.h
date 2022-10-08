#ifndef COMMON_H
#define COMMON_H

#include <assert.h>
#include <string.h>

/* QBSD does not have these headers (and rather, has the
 * functions declared in it be implicitly called..) */
#if !defined(__QuasiBSD__)
#include <stdlib.h>
#endif

#include "libassert.h"
#include "../src/liberror.h"

#endif
