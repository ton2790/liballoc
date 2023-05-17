#include <stdio.h>
#include "test.h"

static int tests = 0;
static int passed = 0;

void test(bool expr, char* name)
{
  tests++;
  if (expr) {
    passed++;
    return;
  }
  printf("Failed test %2d: %s\n", tests, name);
}

void summary()
{
  printf("Passed %d out of %d tests\n", passed, tests);
}
