//
// Created by juan on 13/09/2024.
//

#include "CapitalizeTextstring.h"
#include <string.h>
#include <ctype.h>

/**
* Capitalizar una cadena.
*
* Esta función recibe una candena cualquiera y la capitaliza con lo exacto de poner las primeras
* letras de cada palabra en mayuscula y poner en minuscula alguna que otra.
*
* @param str La palabra o frase a capitalizar.
* @return nothing
*/

void capitalizeString(char *str) {
    int len = strlen(str);
    int newWord = 1;

    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            if (newWord && (i + 1 < len && isalpha(str[i + 1]))) {
                str[i] = toupper(str[i]);
                newWord = 0;
            } else {
                str[i] = tolower(str[i]);
            }
        } else {
            newWord = 1;
        }
    }
}