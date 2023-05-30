allocators: main.c lib/alloc.c lib/batch.c lib/random.c lib/leaky.c
	gcc -O3 -Wall -s -o allocators main.c lib/alloc.c lib/batch.c lib/random.c lib/leaky.c
