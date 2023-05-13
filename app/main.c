#include <stdio.h>
#include "test.h"
#include "alloc.h"

int main()
{
  void *ptr = malloc(0);
  test(ptr==NULL, "malloc");
  ptr = realloc(ptr, 0);
  test(ptr==NULL, "realloc");
  free(ptr);
  test(true, "free");
  summary();
}
