//
// Created by Home on 14/09/2024.
//

#include "joinString.h"
#define JOINSTRING_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void unirCaracteres(char **palabras, int numeroPalabras, char *resultado, char separador) {
    if (numeroPalabras == 0) return;

    strcpy(resultado, palabras[0]);  // Inicia con la primera palabra

    for (int i = 1; i < numeroPalabras; i++) {
        int len = strlen(resultado);
        resultado[len] = separador;  // Añadir el separador
        resultado[len + 1] = '\0';   // Terminar la cadena
        strcat(resultado, palabras[i]);  // Añadir la siguiente palabra
    }
}