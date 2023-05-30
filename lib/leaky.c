#include <stdio.h>
#include <stdlib.h>
#include "alloc.h"

void leaky_allocate(ALLOCATION buf[], int size, size_t min, size_t max, int rounds) {
    // printf("Performing leaky allocation\n");
    for (int i = 0; i < rounds; ++i) {
        for (int j = 0; j < size; ++j) {
            size_t p1_sz = min + (rand() % (max - min));
            size_t p2_sz = min + (rand() % (max - min));
            size_t p3_sz = min + (rand() % (max - min));
            void* p1 = malloc(p1_sz);
            void* p2 = malloc(p2_sz);
            void* p3 = malloc(p3_sz);

            set_block(&buf[j], p2_sz, p2);
            free(p1);
            free(p3);
        }
        for (int i = 0; i < size; ++i) {
            if (buf[i].valid)
                my_free(&buf[i]);
        }
    }
}
