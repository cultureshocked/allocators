#include "alloc.h"
#include <stdbool.h>
#include <stdio.h>
extern FILE* fp;

void batch_allocate(ALLOCATION buf[], int size, size_t min, size_t max, int rounds) {
    for (int r = 0; r < rounds; ++r) {
        for (int i = 0; i < size; ++i) {
            my_malloc(&buf[i], min, max);
        }
        for (int i = 0; i < size; ++i) {
            my_free(&buf[i]);
        }
    }
}
