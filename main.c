//
// Created by Marius Gabriel Magadan 1526407 on 29/03/2016.
//

#include <mem.h>
#include <io.h>
#include <stdlib.h>
#include "stdio.h"
#include "utils.h"

#include "sample_code/multiwayMergesort.h"
#include "sample_code/make_rand_file.h"

typedef unsigned item_type;
size_t  sz = sizeof(item_type);

int custom_comparatorFirstElement(const void * a, const void * b){

    return  (int) ((*(item_type *)(a))- (*(item_type *)(b)));

}

int custom_comparatorSecondElement(const void * a, const void * b){
    return (int) ( *(item_type *)(a+ sizeof(item_type))
                   - *(item_type *)(b+ sizeof(item_type)));
}

void generateFilePairs(char *file, char *tempFile);

void sortAccordingToFirstIndex(char *file);

void replaceFirstItem(char *file, char *tempFile);

void sortAccordingToSecondIndex(char * file);

void writeSolution(char * inputFile) ;

int multiway_sort_custom(char * file, long block_size_in_bytes, long internal_external_0_1, long main_memory_size,int (*compare)(const void*, const void*));

char * tempFile = "./temp_file.txt";


int main(int argc, char * argv[]) {

    makePermutationFile("D:/BIG_DATA/randPermutation.txt",100);
    return 0;

    if(argc!=3){
        printf("Usage: %s <file_path_of_input_file> <file_path_of_permutation_file>",argv[0]);
        exit(EXIT_FAILURE);
    }

    char * inputFile = argv[1];
    char * permutationFile = argv[2];

    generateFilePairs(permutationFile,tempFile);

    sortAccordingToFirstIndex(tempFile);

    replaceFirstItem(inputFile,tempFile);

    sortAccordingToSecondIndex(tempFile);

    writeSolution(inputFile);

    exit(EXIT_SUCCESS);
}

void sortAccordingToSecondIndex(char * file){
    multiway_sort_custom(file, 4096, 1,  1048576,custom_comparatorSecondElement);
}

void writeSolution(char * inputFile) {
    FILE * source = fopen64(tempFile,"r");
    checkIfNull(source);

    FILE * destination = fopen64(inputFile,"r+");
    checkIfNull(destination);

    unsigned long val;
    while(fread(&val, sz ,1,source)!=0){
        fwrite(&val,sz,1,destination);
        fseeko64(source,sz,SEEK_CUR);
    }

    checkIfNotZero(fclose(source));
    checkIfNotZero(fclose(destination));

    remove(tempFile);
}


void replaceFirstItem(char *file, char *tempFile) {
    FILE * source = fopen64(file,"r");
    checkIfNull(source);

    FILE * destination = fopen64(tempFile,"r+");
    checkIfNull(destination);

    unsigned long val;

    while(fread(&val, sz ,1,source)!=0){
        fwrite(&val,sz,1,destination);
        fseeko64(destination,sz,SEEK_CUR);
    }

    checkIfNotZero(fclose(source));
    checkIfNotZero(fclose(destination));
}

void sortAccordingToFirstIndex(char *file) {
    multiway_sort_custom(file, 4096,1,1048576 , custom_comparatorFirstElement);
}

void generateFilePairs(char *file, char *tempFile) {
    FILE * source = fopen64(file,"r");
    checkIfNull(source);

    FILE * destination = fopen64(tempFile,"w");
    checkIfNull(destination);
    unsigned long val;

    unsigned long index = 1;
    while(fread(&val, sz ,1,source)!=0){
        fwrite(&val,sz,1,destination);
        fwrite(&index,sz,1,destination);
        index++;
    }

    checkIfNotZero(fclose(source));
    checkIfNotZero(fclose(destination));
}

int multiway_sort_custom(char * file, long block_size_in_bytes, long internal_external_0_1, long main_memory_size,int (*compare)(const void*, const void*)){

    int theErrCode;

    /* check command line parameters */
//    if (argc < 5)
//        exit((fprintf(stderr,
//                      "Usage: fileName block_size_in_bytes k internal/external(0/1)\nMain memory size M = blockSize x k\n"),1));

    /* sort file of ItemType integers */
    theErrCode = sort(	file, sz*2,
                          compare, block_size_in_bytes, internal_external_0_1, main_memory_size, 0);

    /* check if the call failed */
    if (theErrCode != 0)
        fprintf(stderr, "%s\n", GetErrorString(theErrCode));

    return theErrCode;
}



