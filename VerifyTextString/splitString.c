//
// Created by Home on 8/09/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "splitString.h"

char* split(const char* cadena) {
    int length = strlen(cadena);
    char* arreglo = malloc(length + 1);
    if (arreglo == NULL) {
        return NULL;
    }
    for (int i = 0; i < length; i++) {
        arreglo[i] = cadena[i];
    }
    arreglo[length] = '\0';
    return arreglo;
}