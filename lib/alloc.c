#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "alloc.h"
extern FILE* fp;
extern int minified;

void my_malloc(ALLOCATION* ptr, size_t min, size_t max) {
    size_t size = min + (rand() % (max - min));
    ptr->ptr = malloc(size);
    ptr->size = size;
    ptr->valid = true;
    fprintf(fp, (minified) ? "A %zu %lu\n" : "Allocated chunk of %3zu bytes to %lu\n", size, (long int) ptr->ptr);
}

void my_free(ALLOCATION* ptr) {
    fprintf(fp, (minified) ? "F %zu %lu\n" : "Freeing chunk of %3zu bytes at %lu\n", ptr->size, (long int) ptr->ptr);
    free(ptr->ptr);
    ptr->size = 0;
    ptr->valid = false;
}

void set_block(ALLOCATION* ptr, size_t sz, void* addr) {
    ptr->ptr = addr;
    ptr->size = sz;
    ptr->valid = true;
    fprintf(fp, (minified) ? "A %zu %lu\n" : "Allocated chunk of %3zu bytes to %lu\n", sz, (long int) ptr->ptr);
}

void my_silent_malloc(ALLOCATION* ptr, size_t min, size_t max) {
    size_t size = min + (rand() % (max - min));
    ptr->ptr = malloc(size);
    ptr->size = size;
    ptr->valid = true;
}

void my_silent_free(ALLOCATION* ptr) {
    free(ptr->ptr);
    ptr->size = 0;
    ptr->valid = false;
}
