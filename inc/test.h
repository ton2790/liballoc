#ifndef TEST_H
#define TEST_H

#include <stdbool.h>

static int tests = 0;
static int passed = 0;

void test(bool expr, char* name);
void summary();

#endif
