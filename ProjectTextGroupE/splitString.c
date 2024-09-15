//
// Created by Home on 8/09/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "splitString.h"


/**
* Función para dividir una cadena en un arreglo de caracteres.
*
* Esta función recibe una cadena y a partir de eso la divide en un arreglo de caracteres
* en sí retorna el arreglo de caracteres ya diferenciado.
*
* @param cadena Cadena a examinar.
* @return arreglo, arreglo de caracteres ya procesado.
*/
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