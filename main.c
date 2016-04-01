//
// Created by Marius Gabriel Magadan 1526407 on 29/03/2016.
//

#include <mem.h>
#include <io.h>
#include <stdlib.h>
#include "stdio.h"
#include "utils.h"

#include "sample_code/multiway_main.h"

typedef unsigned long item_type;
size_t  sz = sizeof(unsigned long);

int custom_comparatorFirstElement(const void * a, const void * b){
    return (int) ( *(item_type *)(a)- *(item_type *)(b));
}

int custom_comparatorSecondElement(const void * a, const void * b){
    return (int) ( *(item_type *)(a+ sizeof(item_type))
                   - *(item_type *)(b+ sizeof(item_type)));
}

void generateFilePairs(char *file, char *tempFile);

void sortAccordingToFirstIndex(char *file);

void replaceFirstItem(char *file, char *tempFile);

char * tempFile = "./temp_file.txt";

void sortAccordingToSecondIndex(char * file){
    multiway_sort_custom(file,1000,1,2000,custom_comparatorSecondElement);
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

int main(int argc, char * argv[]) {

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

void replaceFirstItem(char *file, char *tempFile) {
    FILE * source = fopen64(file,"r");
    checkIfNull(source);

    FILE * destination = fopen64(tempFile,"r+");
    checkIfNull(destination);

//    fseeko64(destination,0,SEEK_SET);

    unsigned long val;



    while(fread(&val, sz ,1,source)!=0){
        fwrite(&val,sz,1,destination);
        fseeko64(destination,sz,SEEK_CUR);
        printf("Scritto \n");
    }

    checkIfNotZero(fclose(source));
    checkIfNotZero(fclose(destination));
    printf("Finito di scrivere\n");
}

void sortAccordingToFirstIndex(char *file) {
    multiway_sort_custom(file,1000,1,2000,custom_comparatorFirstElement);
}

void generateFilePairs(char *file, char *tempFile) {
    FILE * source = fopen64(file,"r");
    checkIfNull(source);

    FILE * destination = fopen64(tempFile,"w");
    checkIfNull(destination);

//    int * read_buff = malloc(sizeof(int));

//    while( fread(&read_buff,sizeof(unsigned long),1,source) != 0){
//        printf("This -> %lu",read_buff);
//        fprintf(destination,"%lu%lu",read_buff,index++);
//    }

//    fseek(source, 0, SEEK_SET);

    unsigned long val;


    size_t  sz = sizeof(unsigned long);
    unsigned long index = 1;
    while(fread(&val, sz ,1,source)!=0){
        fwrite(&val,sz,1,destination);
        fwrite(&index,sz,1,destination);
        index++;
        printf("Scritto \n");
    }

    checkIfNotZero(fclose(source));
    checkIfNotZero(fclose(destination));
    printf("Finito di scrivere\n");
}




