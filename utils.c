//
// Created by wakir on 30/03/2016.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

void checkIfNull(void * pointer){
    if(pointer==NULL){
        printf("Pointer is null\n");
        exit(EXIT_FAILURE);
    }
}

void checkIfNotZero(int value){
    if(value!=0){
        printf("Pointer is zero\n");
        exit(EXIT_FAILURE);
    }
}