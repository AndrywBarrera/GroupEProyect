//
// Created by juan on 08/09/2024.
//

#include "lastMeeting.h"
#include <string.h>

/**
* Función para buscar la última ocurrencia de una subcadena dentro de otra.
*
* Esta función recibe una cadena y una subcadena. La subcadena se busca dentro de la cadena
* para ver si está contenida, en tal caso que si está contenida, retorna a su posición donde
* empieza la subcadena en la cadena y si no está, retorna 0.
*
* @param cadena Cadena a examinar.
* @param subcadena Subcadena a buscar dentro de la cadena.
* @return ultimaPosicion, posición numérica donde comienza la subcadena.
*/
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