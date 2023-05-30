#ifndef ALLOC_H
#define ALLOC_H
#include <stdbool.h>
#include <stdio.h>

typedef struct allocation {
    size_t size;
    void* ptr;
    bool valid;
} ALLOCATION, allocation;
void my_malloc(ALLOCATION* ptr, size_t min, size_t max);
void my_free(ALLOCATION* ptr);
void my_silent_malloc(ALLOCATION* ptr, size_t min, size_t max);
void my_silent_free(ALLOCATION* ptr);
void set_block(ALLOCATION* ptr, size_t sz, void* addr);
#endif

