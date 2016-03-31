//
// Created by wakir on 29/03/2016.
//

#include <mem.h>
#include "stdio.h"
#include "stdlib.h"
#include "utils.h"

#include "sample_code/multiway_main.h"
#include "sample_code/make_rand_file.h"
struct pair{
    int val;
    int idx;
};
typedef unsigned item_type;

void generateFilePairs(char *file, char *tempFile);

void sortAccordingToFirstIndex(char *file);

char * permutationFile = "D:/BIG_DATA/source_file.txt";
char * tempFile = "D:/BIG_DATA/temp_file.txt";
char * responseFile = "D:/BIG_DATA/response_file.txt";

void clearFiles(){

    fclose(fopen64(tempFile,"w"));
    fclose(fopen64(responseFile,"w"));

}

void createTestPermutation(){
    FILE * file = fopen64(permutationFile,"w");
    checkIfNull(file);

    unsigned permut[] = {3,1,2};

    int i;
    for(i=0; i<3;i++){
        fwrite(&permut[i], sizeof(unsigned), 1, file);
        printf("Scritto una volta %u\n",permut[i]);
    }
}

int main(int argc, char * argv[]) {


    clearFiles();

    createTestPermutation();

//    make_rand_file(permutationFile,4);

    generateFilePairs(permutationFile,tempFile);
//
//    sortAccordingToFirstIndex(tempFile);


}

void sortAccordingToFirstIndex(char *file) {
    multiway_sort_custom(file,1000,1,2000);
}

void generateFilePairs(char *file, char *tempFile) {
    FILE * source = fopen64(file,"r");
    checkIfNull(source);

    FILE * destination = fopen64(tempFile,"w");
    checkIfNull(destination);

    int * read_buff = malloc(sizeof(int));
    unsigned long index = 0;
//    while( fread(&read_buff,sizeof(unsigned long),1,source) != 0){
//        printf("This -> %lu",read_buff);
//        fprintf(destination,"%lu%lu",read_buff,index++);
//    }

    fseek(source, 0, SEEK_SET);
    int count;
    for (count = 0; count<10000; count++) {
        unsigned val;
        if (!fread(&val, sizeof(unsigned), 1, source)) {
            printf("Breaking\n");
            break;
        }


        printf("%u",val);
//        fseeko(f, (S-1)*sizeof(item_type), SEEK_CUR);
    }

    checkIfNotZero(fclose(source));
    checkIfNotZero(fclose(destination));

}




