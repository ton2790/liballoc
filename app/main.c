#include "test.h"
#include "alloc.h"
#include <stdio.h>

int main()
{
  void *base;
  void *ptr;
  base = malloc(0);

  ptr = malloc(2048);
  test(ptr==base, "malloc");
  
  ptr = malloc(1024);
  test(ptr==base + 2048, "malloc");
  
  ptr = malloc(4096);
  test(ptr==NULL, "malloc");
  
  free(ptr);
  
  ptr = malloc(1024);
  test(ptr==base, "malloc");
  
  summary();
}
