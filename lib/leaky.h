#ifndef LEAKY_H
#define LEAKY_H

#include <stdio.h>
#include <stdlib.h>
#include "alloc.h"

void leaky_allocate(ALLOCATION buf[], int size, size_t min, size_t max, int rounds);

#endif
