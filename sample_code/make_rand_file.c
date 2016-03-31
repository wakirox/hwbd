//
// Created by wakir on 30/03/2016.
//

#include "make_rand_file.h"
#include <stdio.h>
#include <stdlib.h>

/* type of file items */
typedef unsigned item_type;

int make_rand_file(char * filename, long items){

    FILE* f;
    long long N, i;

    /* check command line parameters */
//    if (argc < 3) exit (printf("Usage: %s file-name num-items\n", argv[0]));

    /* convert number of items from string to integer format */
//    N = atoll(argv[2]);

    printf("file offset model: %lu bit\n", sizeof(off_t)*8);
    printf("creating random file of %lld %lu bit integers...\n", N, sizeof(item_type)*8);

    /* open file for writing */
    f = fopen(filename, "w+");
    if (f == NULL) exit(printf("can't open file\n"));

    /* make N sequential file accesses */
    for (i=0; i<items; ++i) {
        item_type val = rand();
        fwrite(&val, sizeof(item_type), 1, f);
    }

    fclose(f);
}
