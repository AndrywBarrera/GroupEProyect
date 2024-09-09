#include <string.h>
#include "endswith.h"

int endsWith(const char *str, const char *suffix) {
    size_t strLen = strlen(str);//Longitud Cadena
    size_t suffixLen = strlen(suffix);//Longitud SubCadena

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
