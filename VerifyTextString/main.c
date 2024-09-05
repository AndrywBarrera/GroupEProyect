#include <stdio.h>
#include "endswith.h"
#include <string.h>

int main() {
    char str[100];
    char suffix[100];
    //Cadena
    printf("Ingrese la cadena completa: ");
    //Entrada estandar de Usuario, cadena del apuntador
    //Tiene su tamaño predefinido
    fgets(str, sizeof(str), stdin);
    //Buscar Caracter de Salto y Eliminarlo para evitar Problemas con fgets
    str[strcspn(str, "\n")] = '\0';

    //SubCadena
    printf("Ingrese la subcadena: ");
    fgets(suffix, sizeof(suffix), stdin);

    suffix[strcspn(suffix, "\n")] = '\0';


    int result = endsWith(str, suffix);

    printf("Resultado: %d\n", result);

    return 0;
}
