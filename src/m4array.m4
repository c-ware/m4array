dnl C-Ware License
dnl 
dnl Copyright (c) 2022, C-Ware
dnl All rights reserved.
dnl 
dnl Redistribution and use in source and binary forms, with or without
dnl modification, are permitted provided that the following conditions are met:
dnl 
dnl 1. Redistributions of source code must retain the above copyright notice, this
dnl    list of conditions and the following disclaimer.
dnl 
dnl 2. Redistributions in binary form must reproduce the above copyright notice,
dnl    this list of conditions and the following disclaimer in the documentation
dnl    and/or other materials provided with the distribution.
dnl 
dnl 3. Redistributions of modified source code must append a copyright notice in
dnl    the form of 'Copyright <YEAR> <NAME>' to each modified source file's
dnl    copyright notice, and the standalone license file if one exists.
dnl 
dnl A "redistribution" can be constituted as any version of the source code
dnl that is intended to comprise some other derivative work of this code. A
dnl fork created for the purpose of contributing to any version of the source
dnl does not constitute a truly "derivative work" and does not require listing.
dnl 
dnl THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
dnl AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
dnl IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
dnl DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
dnl FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
dnl DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
dnl SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
dnl CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
dnl OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
dnl OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

dnl @docgen_start
dnl @type: project
dnl @name: m4array
dnl @brief: an implementation of a dynamic array in m4
dnl
dnl @include: m4array/m4array.m4
dnl
dnl @embed: M4ARRAY_FREE
dnl @show_brief: 0
dnl @embed: M4ARRAY_FIND
dnl @show_brief: 0
dnl @embed: M4ARRAY_POP
dnl @show_brief: 0
dnl @embed: M4ARRAY_INSERT
dnl @show_brief: 0
dnl @embed: M4ARRAY_APPEND
dnl @show_brief: 0
dnl @embed: M4ARRAY_INIT
dnl @show_brief: 0
dnl @embed: M4ARRAY_FOREACH
dnl @show_brief: 0
dnl @embed: M4ARRAY_MAP
dnl @show_brief: 0
dnl @embed: M4ARRAY_CLEAR
dnl @show_brief: 0
dnl
dnl
dnl @description
dnl @An implementation of a dynamic array in \Bm4\B(1). It is type safe, and provides
dnl @all of the basic necessities when it comes to a dynamic array, including insertion,
dnl @appending, searching, and more. This implmenetation is highly portable. It will compile
dnl @on each of the following operating systems without error (assuming code is preprocessed
dnl @with m4):
dnl @   - FreeBSD 13.1
dnl @   - NetBSD 9.3
dnl @   - OpenBSD 7.1
dnl @   - OpenSolaris 10
dnl @   - ULTRIX 4.5
dnl @   - QuasijarusBSD 4.3
dnl @   - OS/2 4.52 Warp
dnl @   - DragonflyBSD 6.2.1
dnl @   - NeXTSTEP 4.2
dnl @   - UNIXWare 7.1.4
dnl @
dnl @As stated above, it is recommended that you preprocess your \Bm4\B(1) into C files before shipping
dnl @the code. This makes your code much portable as not all systems have \Bm4\B(1).
dnl @
dnl @Below is a table of the manual of each of operation, along with a brief description.
dnl @\T
dnl @\S ;
dnl @\H Manual;Description
dnl @\E M4ARRAY_INIT(cware);initialize a new array
dnl @\E M4ARRAY_APPEND(cware);append a value
dnl @\E M4ARRAY_INSERT(cware);insert a value at a specific index
dnl @\E M4ARRAY_POP(cware);pop a value out of an index
dnl @\E M4ARRAY_FIND(cware);find the location of a value based off a predicate
dnl @\E M4ARRAY_FOREACH(cware);run an operaton for each element
dnl @\E M4ARRAY_MAP(cware);apply an operation in place
dnl @\E M4ARRAY_CLEAR(cware);free each element and set the length to 0
dnl @\T
dnl @description
dnl
dnl @examples
dnl @This is a table of documentation which holds example code, along with a
dnl @brief description of it, and the macros it involves.
dnl @
dnl @\T
dnl @\S ;
dnl @\H Manual;Description;Macros
dnl @\E m4array-examples-join(cware);joining strings;init,foreach,append,free
dnl @\T
dnl @examples
dnl
dnl @docgen_end

#include <stdio.h>
#include <assert.h>
#include <string.h>

dnl =============================
dnl # M4array portability macros #
dnl ==============================

#if defined(__ULTRIX__) || defined(__QuasiBSD__)
#   if !defined(CWUTILS_GENERIC)
#       define CWUTILS_GENERIC char *
#   endif
#   if !defined(CWUTILS_NULL)
#       define CWUTILS_NULL    ((char *) 0)
#   endif
#else
#   if !defined(CWUTILS_GENERIC)
#      define CWUTILS_GENERIC void *
#   endif
#   if !defined(CWUTILS_NULL)
#      define CWUTILS_NULL    ((void *) 0)
#   endif
#endif

dnl ==========================
dnl	# M4array utility macros #
dnl ==========================

define(`M4ARRAY_INITIAL_LENGTH', `3')
define(`M4ARRAY_NEXT_SIZE', `(($1)->capacity * 2)')

dnl @docgen_start
dnl @type: macro
dnl @name: M4ARRAY_INIT
dnl @brief: initialize a new array
dnl
dnl @include: m4array/m4array.m4
dnl 
dnl @description
dnl @This will initialize a new array on the heap.
dnl @description
dnl
dnl @examples
dnl @For examples, please see the examples section in \Bm4array\B(cware)
dnl @examples
dnl
dnl @param: 1
dnl @brief: pointer to the array to initialize
dnl
dnl @param: 2
dnl @brief: namespace of the array
dnl
dnl @reference: m4array(cware)
dnl
dnl @docgen_end
define(`M4ARRAY_INIT', `
	($2_ARRAY_TYPE *) malloc(sizeof(*($1)));
	($1)->length = 0;
	($1)->capacity = M4ARRAY_INITIAL_LENGTH;
	($1)->contents = ($2_TYPE *) malloc(sizeof($2_TYPE) * M4ARRAY_INITIAL_LENGTH)
')

dnl @docgen_start
dnl @type: macro
dnl @name: M4ARRAY_APPEND
dnl @brief: append to an array
dnl
dnl @include: m4array/m4array.m4
dnl
dnl @description
dnl @This macro will append a value to an array given, and resize the
dnl @array if needed using the M4ARRAY_NEXT_SIZE(cware) macro.
dnl @description
dnl
dnl @examples
dnl @For examples, please see the examples section in \Bm4array\B(cware)
dnl @examples
dnl
dnl @param: 1
dnl @brief: pointer to the array to append to
dnl
dnl @param: 2
dnl @brief: the value to append
dnl
dnl @param: 3
dnl @brief: the namespace of the array
dnl
dnl @reference: m4array(cware)
dnl
dnl @docgen_end
define(`M4ARRAY_APPEND', `
	if(($1)->length == ($1)->capacity) {
		($1)->contents = ($3_TYPE *) realloc(($1)->contents, sizeof($3_TYPE) * M4ARRAY_NEXT_SIZE($1));
		($1)->capacity = M4ARRAY_NEXT_SIZE($1);
	}

	($1)->contents[($1)->length] = ($2);
	($1)->length++
')

dnl @docgen_start
dnl @type: macro
dnl @name: M4ARRAY_INSERT
dnl @brief: insert a value into an array at an index
dnl
dnl @include: m4array/m4array.m4
dnl
dnl @description
dnl @This macro will take a value, and insert it into an array at a given
dnl @index.
dnl @description
dnl
dnl @examples
dnl @For examples, please see the examples section in \Bm4array\B(cware)
dnl @examples
dnl
dnl @param: 1
dnl @brief: pointer to the array to insert into
dnl
dnl @param: 2
dnl @brief: the value to insert
dnl
dnl @param: 3
dnl @brief: the location to insert into
dnl
dnl @param: 4
dnl @brief: the namespace of the array
dnl
dnl @reference: m4array(cware)
dnl 
dnl @docgen_end
define(`M4ARRAY_INSERT', `
	/* Resize the array if necessary */
	if(($1)->length == ($1)->capacity) {
		($1)->contents = ($4_TYPE *) realloc(($1)->contents, sizeof($4_TYPE) * M4ARRAY_NEXT_SIZE($1));
		($1)->capacity = M4ARRAY_NEXT_SIZE($1);
	}

	do {
		int __M4_INDEX = ($1)->length - 1;

		/* Shift each element before ($3 - 1) over by 1 */
		while(__M4_INDEX != ($3) - 1) {
			($1)->contents[__M4_INDEX + 1] = ($1)->contents[__M4_INDEX];
			__M4_INDEX--;
		}

		($1)->contents[$3] = $2;
		($1)->length++;
	} while(0)
')

dnl @docgen_start
dnl @type: macro
dnl @name: M4ARRAY_POP
dnl @brief: pop a value out of an array at some index
dnl
dnl @include: m4array/m4array.m4
dnl
dnl @description
dnl @This macro will pop a value out of an index in the array, and write it to a
dnl @variable.
dnl @description
dnl
dnl @examples
dnl @For examples, please see the examples section in \Bm4array\B(cware)
dnl @examples
dnl
dnl @param: 1
dnl @brief: pointer to the array to pop out of
dnl
dnl @param: 2
dnl @brief: the index to pop out
dnl
dnl @param: 3
dnl @brief: the variable to put the value in
dnl
dnl @param: 4
dnl @brief: the namespace of the array
dnl
dnl @reference: m4array(cware)
dnl
dnl @docgen_end
define(`M4ARRAY_POP', `
	($1)->contents[0];

	($3) = ($1)->contents[$2];

	do {
		int __M4_INDEX = $2;

		/* Pull everything from index ($2), onwards, back by 1. */
		while(__M4_INDEX < ($1)->length) {
			($1)->contents[__M4_INDEX] = ($1)->contents[__M4_INDEX + 1];
			__M4_INDEX++;
		}

		($1)->length--;
	} while(0)
')

dnl @docgen_start
dnl @type: macro
dnl @name: M4ARRAY_FIND
dnl @brief: find the first occurrence of a value
dnl
dnl @include: m4array/m4array.m4
dnl
dnl @description
dnl @This macro will find the first occurrence of a value that matches
dnl @a predicate. The predicate must be an expression that evaluates to
dnl @either 1, or 0. If the value is never found, -1 is written to the
dnl @output variable. Otherwise, the index is written to it.
dnl @description
dnl
dnl @examples
dnl @For examples, please see the examples section in \Bm4array\B(cware)
dnl @examples
dnl
dnl @param: 1
dnl @brief: pointer to the array to search
dnl
dnl @param: 2
dnl @brief: the variable to put the index into
dnl
dnl @param: 3
dnl @brief: the macro body to execute
dnl
dnl @reference: m4array(cware)
dnl
dnl @docgen_end
define(`M4ARRAY_FIND', `
	-1;

	($2) = -1;

	define(`M4ARRAY_LAMBDA', `$3')

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < ($1)->length) {
			if((M4ARRAY_LAMBDA(($1)->contents[__M4_INDEX])) == 0) {
				__M4_INDEX++;
				continue;
			}

			($2) = __M4_INDEX;
			break;
		}
	} while(0)
')

dnl @docgen_start
dnl @type: macro
dnl @name: M4ARRAY_MAP
dnl @brief: apply an operation to each element of an array
dnl
dnl @include: m4array/m4array.m4
dnl
dnl @description
dnl @This macro will apply an operation on each member of an array. The macro
dnl @is in-place, and will a[i] with the output of f(x), where a[i] is any
dnl @given array element, and f(x) is a macro which uses a[i].
dnl @description
dnl
dnl @examples
dnl @For examples, please see the examples section in \Bm4array\B(cware)
dnl @examples
dnl
dnl @param: 1
dnl @brief: pointer to the array to map to
dnl
dnl @param: 2
dnl @brief: the macro body to execute
dnl
dnl @reference: m4array(cware)
dnl
dnl @docgen_end
define(`M4ARRAY_MAP', `
	define(`M4ARRAY_LAMBDA', `$2')

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < ($1)->length) {
			($1)->contents[__M4_INDEX] = (M4ARRAY_LAMBDA(($1)->contents[__M4_INDEX]));
            __M4_INDEX++;
		}
	} while(0)
')

dnl @docgen_start
dnl @type: macro
dnl @name: M4ARRAY_CLEAR
dnl @brief: release the contents of an array, without freeing the array
dnl
dnl @include: m4array/m4array.m4
dnl
dnl @description
dnl @This macro will "clear" the array by freeing each element of the array,
dnl @and setting the length of the array to zero.
dnl @description
dnl
dnl @examples
dnl @For examples, please see the examples section in \Bm4array\B(cware)
dnl @examples
dnl
dnl @param: 1
dnl @brief: pointer to the array to clear
dnl
dnl @param: 2
dnl @brief: the namespace of the array
dnl
dnl @reference: m4array(cware)
dnl
dnl @docgen_end
define(`M4ARRAY_CLEAR', `
	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < ($1)->length) {
			$2_FREE(($1)->contents[__M4_INDEX]);
            __M4_INDEX++;
		}

        ($1)->length = 0;
	} while(0)
')

dnl @docgen_start
dnl @type: macro
dnl @name: M4ARRAY_FOREACH
dnl @brief: run code for each element in an array
dnl
dnl @include: m4array/m4array.m4
dnl
dnl @description
dnl @This macro will run an operation for each element in an array. The
dnl @operation will have the element of the array passed as the first
dnl @argument.
dnl @description
dnl
dnl @examples
dnl @For examples, please see the examples section in \Bm4array\B(cware)
dnl @examples
dnl
dnl @param: 1
dnl @brief: pointer to the array to loop over
dnl
dnl @param: 2
dnl @brief: the macro to execute for each element
dnl
dnl @reference: m4array(cware)
dnl 
dnl @docgen_end
define(`M4ARRAY_FOREACH', `
	define(`M4ARRAY_LAMBDA', `$2')

    do {
        int __M4_INDEX = 0;

        while(__M4_INDEX < ($1)->length) {
            M4ARRAY_LAMBDA(($1)->contents[__M4_INDEX]);

            __M4_INDEX++;
        }
    } while(0)
')

dnl @docgen_start
dnl @type: macro
dnl @name: M4ARRAY_FREE
dnl @brief: release an array and its contents from memory
dnl 
dnl @include: m4array/m4array.m4
dnl
dnl @description
dnl @This macro will apply a free-macro for each element of the array, and 
dnl @release the array itself. The macro that will be called has the suffix
dnl @_FREE.
dnl @description
dnl
dnl @examples
dnl @For examples, please see the examples section in \Bm4array\B(cware)
dnl @examples
dnl
dnl @param: 1
dnl @brief: pointer to the array to release
dnl
dnl @param: 2
dnl @brief: the namespace of the array
dnl
dnl @reference: m4array(cware)
dnl
dnl @docgen_end
define(`M4ARRAY_FREE', `
	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < ($1)->length) {
			$2_FREE(($1)->contents[__M4_INDEX]);
			__M4_INDEX++;
		}

		free(($1)->contents);
		free(($1));
	} while(0)
')
