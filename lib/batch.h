#ifndef BATCH_H
#define BATCH_H
#include "alloc.h"

void batch_allocate(ALLOCATION buf[], int size, size_t min, size_t max, int rounds);

#endif
