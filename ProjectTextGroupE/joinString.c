//
// Created by Home on 14/09/2024.
//

#include "joinString.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/**
* Función para unir un arreglo de caracteres en una cadena usando un separador
*
* Esta función recibe un arreglo de caracteres y luego un separador a partir de eso
* une el arreglo de caracteres identificado por el separador seleccionado.
*
* @param array Arreglo de caracteres.
* @param separator Separador para la frase.
* @return result que devuelve el arreglo con los separadores y arreglo de caracteres unido.
*/

char* unirCaracteres(const char* array, char separator) {
    int size = strlen(array);
    char* result = (char*)malloc((size * 2) * sizeof(char) + 1);
    if (result == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    int cont = 0;
    for (int i = 0; i < size; i++) {
        result[cont++] = array[i];
        if (i < size - 1) {
            result[cont++] = separator;
        }
    }

    result[cont] = '\0';
    return result;
}
