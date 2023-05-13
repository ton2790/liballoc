#include <stdio.h>
#include "test.h"

void test(bool expr, char* name)
{
  tests++;
  if (!expr) {
    passed++;
    printf("Passed test %2d:\n", tests - 1);
    return;
  }
  printf("Failed test %2d: %s\n", tests - 1, name);
}

void summary()
{
  printf("Passed %d out of %d tests\n", passed, tests);
}
