#include <string.h>
#include "endswith.h"
#include <ctype.h>
#include <stdio.h>

int endsWith(char *str, char *suffix) {
    size_t strLen = strlen(str); //Longitud Cadena
    size_t suffixLen = strlen(suffix); //Longitud SubCadena

    // Recorrer la cadena desde el final
    while (strLen > 0 && isspace((unsigned char) str[strLen - 1])) {
        strLen--;
    }
    while (suffixLen > 0 && isspace((unsigned char) str[suffixLen - 1])) {
        suffixLen--;
    }

    // Agregar el carácter nulo al final de la cadena truncada
    str[strLen] = '\0';
    str[suffixLen] = '\0';

    //Compara si la longitud de la SubCadena es mayor a la Cadena
    if (suffixLen > strLen) {
        return 0;
    }
    //String Comparador, Mover el apuntador al final de la longitud supuesta de la SubCadena
    //Cadena y Numero de caracteres a comparar
    if (strncmp(str + strLen - suffixLen, suffix, suffixLen) == 0) {
        return 1;
    } else {
        return 0;
    }
}
