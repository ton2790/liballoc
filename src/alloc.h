#ifndef ALLOC_H
#define ALLOC_H

#include <stddef.h>

extern void *malloc(size_t size);
extern void *realloc(void *ptr, size_t size);
extern void free(void *ptr);

#endif
