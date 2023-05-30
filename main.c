#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#include "lib/alloc.h"
#include "lib/batch.h"
#include "lib/random.h"
#include "lib/file.h"
#include "lib/leaky.h"

#define MAX_ALLOC 50    //Max number of allocations per round
#define MAX_SIZE 512    //Max bytes to allocate
#define MIN_SIZE 32     //Min bytes to allocate
#define ROUNDS 5        //Number of rounds

extern FILE* fp;

static void (*allocation_method)(ALLOCATION*, int, size_t, size_t, int) = NULL;

//Helpers
void display_help(char* str);
bool set_method(char* str);
bool set_file(char* str);

int main(int argc, char** argv) {
    if (argc > 3)
        display_help(argv[0]);

    if (argc == 3) {
        if (!(set_method(argv[1]) && set_file(argv[2])))
            display_help(argv[0]);
    } else if (argc == 2) {
        if (argv[1][0] == '-') {        //Argument is option
            if (!set_method(argv[1]))
                display_help(argv[0]);
            fp = stdout;
        } else {
            if (!set_file(argv[1]))     //Argument is filename
                display_help(argv[0]);
            allocation_method = batch_allocate;
        }
    } else {                            //Defaults
        fp = stdout;
        allocation_method = batch_allocate;
    }

    srand((unsigned int) time(0));
    ALLOCATION tmp_ptr;
    //simple zeromem-type loop
    ALLOCATION buf[MAX_ALLOC];
    for (int i = 0; i < MAX_ALLOC; ++i) {
        buf[i].ptr = NULL;
        buf[i].size = 0;
        buf[i].valid = false;
    }
    //First malloc is always in different virtual page for some reason.
    my_silent_malloc(&tmp_ptr, MIN_SIZE, MAX_SIZE);

    allocation_method(buf, MAX_ALLOC, MIN_SIZE, MAX_SIZE, ROUNDS);

    if (fp != stdout) {
        fclose(fp);
    }

    //Freeing that temporary pointer before exiting.
    my_silent_free(&tmp_ptr);

    return 0;
}

void display_help(char* str) {
    printf("usage: %s [option] [filename]\n\n", str);
    puts("File is set to stdout by default");
    puts("  -b => Batch allocation (default)");
    puts("  -r => Random allocation");
    puts("  -l => Leaky allocation");
    puts("  -bm, -rm, -lm => Above methods with minified output");
    exit(EXIT_FAILURE);
}

bool set_method(char* str) {
    size_t len = strlen(str);
    if (!(len == 2 || len == 3)) {
        puts("ERR: Invalid flag specified.");
        return false;
    }
    if (len == 3 && str[2] != 'm') {
        puts("ERR: Invalid modifier (did you mean to enable minified mode?)");
        return false;
    } else if (len == 3) {
        minified = 1;
    }
    char ch = str[1];
    switch (ch) {
        case 'b':
            allocation_method = batch_allocate;
            return true;
        case 'r':
            allocation_method = random_allocate;
            return true;
        case 'l':
            allocation_method = leaky_allocate;
            return true;
        default:
            puts("ERR: Flag not recognized.");
            return false;
    }
}

bool set_file(char* str) {
    if ((fp = fopen(str, "w")) == NULL) {
        puts("ERR: Could not open file! (Check permissions?)");
        return false;
    }
    return true;
}
