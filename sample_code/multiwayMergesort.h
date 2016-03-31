/* ============================================================================
 *  kWayMergeSort.h
 * ============================================================================
 *  Irene Finocchi (finocchi@di.uniroma1.it)
*/

#ifndef __kWayMergeSort__
#define __kWayMergeSort__

/* includes */
#include <stdlib.h>

/* error messages */
enum {
    CANT_OPEN_FILE = 1,
    CANT_CREATE_TEMP_FILE,
    CANT_ALLOCATE_MEMORY,
    WRONG_FILE_SIZE,
    FILE_READ_ERROR,
    FILE_WRITE_ERROR
};

extern char* ErrTable[];

#define GetErrorString(errCode) (ErrTable[errCode])

int sort(const char* inPathName, size_t inItemSize,
              int (*inCompar)(const void*, const void*),
              size_t inBlockSize, size_t inCacheBlockNum, size_t externalFlag, int inVerbose);

#endif
