#include "alloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void free_all(ALLOCATION* buf, int size);

void random_allocate(ALLOCATION buf[], int size, size_t min, size_t max, int rounds) {
    // printf("Performing random allocation\n");
    int count = rounds * size;
    while (count) {
        int off = rand() % size;
        if (buf[off].valid) {
            my_free(&buf[off]);
        } else {
            my_malloc(&buf[off], min, max);
        }
        count--;
    }

    free_all(buf, size);
}

static void free_all(ALLOCATION* buf, int size) {
    for (int i = 0; i < size; ++i) {
        if (buf[i].valid)
            my_free(&buf[i]);
    }
}
