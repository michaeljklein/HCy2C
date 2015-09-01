// Copyright (C) YelloSoft

#include "/usr/local/Cellar/bdw-gc/7.4.2/include/gc.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "qc.h"

static bool QC_INITIALIZED = false;

void qc_init(void) {
  GC_INIT();
  srand((unsigned int) time(NULL));

  QC_INITIALIZED = true;
}

void gen_bool(/*@out@*/ blob const data) {
  bool b = rand() % 2 == 0;

  qc_return(bool, b);
}

void gen_int(/*@out@*/ blob const data) {
  int i = rand();

  qc_return(int, i);
}

void gen_char(/*@out@*/ blob const data) {
  char c = (char)(rand() % 128);

  qc_return(char, c);
}

void _gen_array(/*@out@*/ blob const data, gen const g, size_t const size) {
  int len = rand() % 100;

  blob arr = GC_MALLOC((size_t) len * size);

  size_t i;

  for (i = 0; i < (size_t) len; i++) {
    g(arr + i * size);
  }

  qc_return(blob, arr);
}

void gen_string(/*@out@*/ blob const data) {
  char *s;

  gen_array(&s, gen_char, char);

  qc_return(char *, s);
}

void print_bool(blob const data) {
  bool b = qc_args(bool, 0, bool);

  printf("%s", b ? "true" : "false");
}

void print_int(blob const data) {
  int i = qc_args(int, 0, int);

  printf("%d", i);
}

void print_char(blob const data) {
  char c = qc_args(char, 0, char);

  printf("\'%c\'", c);
}

void print_string(blob const data) {
  char *s = qc_args(char *, 0, char *);

  printf("%s", s);
}

// Syntax:
//
// For simplicity, _for_all is called using the for_all macro (see qc.h).
//
// In this example, for_all is testing whether all integers are odd (they are not).
//
// Every for_all call begins with a property function. For example, is_odd takes
// an int and returns a bool.
//
// bool is_odd(blob data);
//
// In order to handle arbitrarily-typed property functions, qc uses a special
// protocol, qc_args,  to pass test values to the property function.
//
// bool is_odd(blob data) {
//    int n = qc_args(int, 0, int);
//
//    return n % 2 == 1;
// }
//
// qc_args' first argument is a type: int, char, int*, char*, int**, char**, ...
// The second argument is the index (qc internally stores all test cases in a
// single array).
// The final argument is the maximum byte size of the property's input types. For
// example, is_equal(short, int)'s maximum byte size would be sizeof(int).

//
// for_all's first argument is the name of such a property function. The next
// argument is an array of generator functions. The is_odd property
// function has a single argument, an integer. Thus each test case consists of a
// random integer to be passed to the is_odd property function. More complicated
// property functions (e.g. cmp(int, int)) may have multiple arguments, and
// therefore require multiple generators.
//
// gen gs[] = { gen_int };
//
// When a test case fails, the values for which the property returns false will be
// printed. For each generator, a corresponding printer function is necessary.
// for_all is designed to test properties of arbitrary numbers of arbitrary types;
// because C has no universal print(some_object) function, the framework user must
// specify printer functions for each generator function. More complicated types,
// such as trees, graphs, and linked lists require the framework user to write
// custom printer functions, but the syntax remains the same.
//
// print ps[] = { print_int };
//
// Finally, for_all requires the maximum byte size of the types to be passed to the
// property function. This information helps for_all hold all test values in a single array,
// which it passes to the test property.
//
// for_all(is_odd, 1, gs, ps, int);

bool _for_all(
  prop const property,
  size_t const arglen,
  gen const gs[],
  print const ps[],
  size_t const max_size
) {
  size_t i, j;
  blob values;

  // Because GC_MALLOC will segfault if GC_INIT() is not called beforehand.
  if (!QC_INITIALIZED) {
    printf("*** Error: Run qc_init() before calling for_all().\n");
    return false;
  }

  values = GC_MALLOC(arglen * max_size);

  for (i = 0; i < 100; i++) {
    for (j = 0; j < arglen; j++) {
      gs[j](values + j * max_size);
    }

    bool holds = property(values);

    if (!holds) {
      printf("*** Failed!\n");

      for (j = 0; j < arglen; j++) {
        ps[j](values + j * max_size);
        printf("\n");
      }

      return false;
    }
  }

  printf("+++ OK, passed 100 tests.\n");

  return true;
}
