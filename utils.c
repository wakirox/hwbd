//
// Created by wakir on 30/03/2016.
//

#include <stddef.h>
#include <stdlib.h>
#include "utils.h"

void checkIfNull(void * pointer){
    if(pointer==NULL){
        exit(EXIT_FAILURE);
    }
}

void checkIfNotZero(int value){
    if(value!=0){
        exit(EXIT_FAILURE);
    }
}