#include <sys/mman.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "alloc.h"

static void *arena = NULL;
static size_t offset = 0;

static const size_t page_size = 4096;

static size_t align(size_t size)
{
  return (size + 7) & ~7;
}

void *malloc(size_t size)
{
  if (arena == NULL) {
    arena = mmap(NULL, page_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  }
  if (offset + size > page_size) {
    return NULL;
  }
  void *ptr = arena + offset;
  offset += size;
  return ptr;
}

void *realloc(void *ptr, size_t size)
{
  // Doesn't really make sense for an arena allocator
  return NULL;
}

void free(void *ptr)
{
  offset = 0;
}
