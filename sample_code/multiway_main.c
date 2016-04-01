/* ============================================================================
 *  main.c (k-way mergesort) 
 * ============================================================================
 *  Irene Finocchi (finocchi@di.uniroma1.it)
*/

#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include "multiwayMergesort.h"
#include "multiway_main.h"

/* type of file items */
typedef unsigned long ItemType;

// comparator for ItemType integers
int compar(const void* a, const void* b){
    return *(ItemType*)a-*(ItemType*)b;
}




int multiway_sort_custom(char * file, long block_size_in_bytes, long internal_external_0_1, long main_memory_size,int (*compare)(const void*, const void*)){

    int theErrCode;

    /* check command line parameters */
//    if (argc < 5)
//        exit((fprintf(stderr,
//                      "Usage: fileName block_size_in_bytes k internal/external(0/1)\nMain memory size M = blockSize x k\n"),1));

    /* sort file of ItemType integers */
    theErrCode = sort(	file, sizeof(unsigned long)*2,
                          compare, block_size_in_bytes, internal_external_0_1, main_memory_size, 1);

    /* check if the call failed */
    if (theErrCode != 0)
        fprintf(stderr, "%s\n", GetErrorString(theErrCode));

    return theErrCode;
}

