//
// Created by juan on 08/09/2024.
//

#include "lastMeeting.h"
#include <string.h>
int searchLastMeeting(const char* cadena, const char* subcadena) {
    int lenCadena = strlen(cadena);
    int lenSubcadena = strlen(subcadena);

    if (lenSubcadena > lenCadena) {
        return 0;
    }

    int ultimaPosicion = 0;

    for (int i = 0; i <= lenCadena - lenSubcadena; i++) {
        if (strncmp(&cadena[i], subcadena, lenSubcadena) == 0) {
            ultimaPosicion = i + 1;
        }
    }

    return ultimaPosicion;
}