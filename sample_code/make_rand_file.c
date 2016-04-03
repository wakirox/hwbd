//
// Created by wakir on 30/03/2016.
//

#include "../main.h"
#include "../utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/* type of file items */
typedef unsigned item_type;



int makePermutationFile(char * filename, unsigned long items){

    FILE* f;
    item_type i;

    char * tmpFile = "D:/BIG_DATA/tmp_test.txt";
    srand(time(NULL));
    /* check command line parameters */
//    if (argc < 3) exit (printf("Usage: %s file-name num-items\n", argv[0]));

    /* convert number of items from string to integer format */
//    N = items;

    printf("file offset model: %lu bit\n", sizeof(off_t)*8);
    printf("creating random file of %lu %lu bit integers...\n", items, sizeof(item_type)*8);

    /* open file for writing */
    f = fopen64(tmpFile, "wb+");
    if (f == NULL) exit(printf("can't open file\n"));

    /* make N sequential file accesses */
    item_type val;
    for (i=1; i<=items; i++) {
        val = (item_type) rand();
        fwrite(&val, sizeof(int), 1, f);
        fwrite(&i, sizeof(int), 1, f);
    }

//    fflush(f);
    fclose(f);
//    ftruncate(fileno(f), sizeof(item_type)*8*items);


    sortAccordingToFirstIndex(tmpFile);



    f = fopen64(tmpFile, "rb+");
    if (f == NULL) exit(printf("can't open file\n"));
    FILE * fresult = fopen(filename, "wb");
    if (fresult == NULL) exit(printf("can't open file\n"));

//    fseeko64(f,sizeof(item_type),SEEK_SET);

    printf("INIT FILE : %d\n",ftell(f));
    int reads = 0;

    fseeko64(f, sizeof(item_type),SEEK_SET);

    while(fread(&val, sizeof(item_type) ,1,f)!=0){
        fwrite(&val,sizeof(item_type),1,fresult);
        fseeko64(f, sizeof(item_type),SEEK_CUR);
        reads++;
    }

    printf("Reads total %d\n size %lu\n",reads, sizeof(item_type));

    checkIfNotZero(fclose(f));
    checkIfNotZero(fclose(fresult));
//    remove(tmpFile);
    printf("Fine della generazione del file di permutazione random\n");
    return 0;
}
