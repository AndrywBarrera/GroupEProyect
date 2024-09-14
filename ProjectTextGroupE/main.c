#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "endswith.h"
#include "palindroma.h"
#include "splitString.h"
#include "lastMeeting.h"
#include "formatNumeric.h"
#include "verifyBrackets.h"
#include "CapitalizeTextstring.h"
#include "joinString.h"


void mainMenu();

int main() {
    mainMenu();
    return 0;
}

void clearWord(char *word) {
    memset(word, 0, sizeof(word));
};
bool isNumericValidated(const char *cadena) {
    char *endptr;
    char modCadena[256];
    clearWord(modCadena);
    strncpy(modCadena, cadena, sizeof(modCadena) - 1);
    modCadena[sizeof(modCadena) - 1] = '\0';  // Asegurar terminador nulo

    strtod(modCadena, &endptr);
    // Verifica si se produjo una conversión completa y si no hay caracteres no numéricos
    return *endptr == '\0' && endptr != modCadena;
}

bool isEmptyText(const char *cadena) {
    while (*cadena != '\0') {
        if (!isspace((unsigned char) *cadena)) {
            return false;
        }
        cadena++;
    }
    return true;
}

void inCapitalizeTextstring() {
    char cadena[200];
    bool verify = false;
    clearWord(cadena);
    do {
        printf("Introduce una cadena de texto: ");
        fgets(cadena, 200, stdin);
        verify = isEmptyText(cadena);
        if (verify) {
            printf("-- No puedes dejar vacia la cadena --\n");
        }
    } while (verify);

    cadena[strcspn(cadena, "\n")] = 0;

    capitalizeString(cadena);

    printf("Cadena capitalizada: %s\n", cadena);
    getchar();
}

void searchSubFfix() {
    char cadena[100], subcadena[100];
    clearWord(cadena);
    clearWord(subcadena);
    bool verify = false;
    do {
        printf("Introduce la cadena: ");
        fgets(cadena, 100, stdin);
        verify = isEmptyText(cadena);
        if (verify) {
            printf("-- No puedes dejar vacia la cadena --\n");
        }
    } while (verify);
    do {
        printf("Introduce la subcadena a buscar: ");
        fgets(subcadena, 100, stdin);
        verify = isEmptyText(subcadena);
        if (verify) {
            printf("-- No puedes dejar vacia la SubCadena --\n");
        }
    } while (verify);

    cadena[strcspn(cadena, "\n")] = '\0';
    subcadena[strcspn(subcadena, "\n")] = '\0';

    int resultado = searchLastMeeting(cadena, subcadena);

    if (resultado != 0) {
        printf("* La subcadena comienza en la posición: %d\n", resultado);
    } else {
        printf("* La subcadena no se encuentra en la cadena.\n");
    }
    getchar();
}

void endsWithFunction() {
    char str[100];
    char suffix[100];
    clearWord(str);
    clearWord(suffix);
    bool verify = false;
    do {
        //Cadena
        printf("Ingrese la cadena completa: ");
        //Entrada estandar de Usuario, cadena del apuntador
        //Tiene su tamaño predefinido
        fgets(str, sizeof(str), stdin);
        verify = isEmptyText(str);
        if (verify) {
            printf("-- No puedes dejar vacia la cadena --\n");
        }
    } while (verify);

    do {
        //SubCadena
        printf("Ingrese la subcadena: ");
        fgets(suffix, sizeof(suffix), stdin);
        verify = isEmptyText(suffix);
        if (verify) {
            printf("-- No puedes dejar vacia la SubCadena --\n");
        }
    } while (verify);
    //Buscar Caracter de Salto y Eliminarlo para evitar Problemas con fgets
    str[strcspn(str, "\n")] = '\0';
    suffix[strcspn(suffix, "\n")] = '\0';
    int result = endsWith(str, suffix);
    printf("* Resultado: %d\n\n", result);
}

void formatValue() {
    char str[100];
    double valor;
    char resultado[50];
    valor = 0.0;
    clearWord(str);
    clearWord(resultado);
    bool isNumeric = true;
    fflush(stdin);
    do {
        bool verify = false;
        do {
            //Cadena
            printf("Ingrese un valor numérico: ");
            //Entrada estandar de Usuario, cadena del apuntador
            //Tiene su tamaño predefinido
            fgets(str, sizeof(str), stdin);
            verify = isEmptyText(str);
            if (verify) {
                printf("-- No puedes dejar vacio el numero --\n");
            }
        } while (verify);
        str[strcspn(str, "\n")] = '\0';
        fflush(stdin);
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == '.') {
                str[i] = ',';
            }
        }
        isNumeric = isNumericValidated(str);
        if (isNumeric) {
            // Convertir la cadena a
            sscanf(str, "%lf", &valor);
            formatValor(valor, resultado);
            printf("* Valor formateado: %s\n", resultado);
            getchar();
        } else {
            printf("Entrada invalida. Asegurate de ingresar un numero.\n");
        }
    } while (!isNumeric);
}

void palindroma() {
    char word[100];
    clearWord(word);
    //anita lava la tina es palindroma
    //Anita, la gorda lagartona, no traga la droga latina. es palindroma
    bool verify = false;
    do {
        printf("Ingrese una cadena de texto: ");
        fgets(word, 100, stdin);
        verify = isEmptyText(word);
        if (verify) {
            printf("-- No puedes dejar vacia la cadena --\n");
        }
    } while (verify);
    word[strcspn(word, "\n")] = '\0';

    fflush(stdin);
    getchar();
    printf("* Respuesta: %d \n\n ", isPalindroma(word, strlen(word)));
}

void splitStrings() {
    char text[500];
    clearWord(text);
    bool verify = false;
    do {
        printf("Ingrese una cadena de texto: ");
        fgets(text, sizeof(text), stdin);
        verify = isEmptyText(text);
        if (verify) {
            printf("-- No puedes dejar vacia la cadena --\n");
        }
    } while (verify);
    char *output = split(text);

    if (output != NULL) {
        printf("* Cadena dividida en caracteres: ");
        for (int i = 0; i < strlen(text); i++) {
            printf("%c ", output[i]);
        }
        printf("\n");

        free(output);
    } else {
        printf("* Error de asignación de memoria.\n");
    }
}

void joinStrings() {
    char cadena[100];  // Arreglo para almacenar la cadena ingresada por el usuario
    char separador;
    clearWord(cadena);
    separador = '\0';
    // Pidiendo la cadena de texto
    printf("Ingrese una cadena de texto: ");
    fgets(cadena, sizeof(cadena), stdin);
    // Eliminar el salto de línea que agrega fgets
    cadena[strcspn(cadena, "\n")] = '\0';

    // Pidiendo el separador
    printf("Ingrese el caracter separador: ");
    scanf(" %c", &separador);

    // Llamar al método unirChars con la cadena ingresada y el separador
    char* resultado = unirCaracteres(cadena, separador);

    // Mostrar la cadena unida
    printf("Cadena separada: %s\n\n", resultado);


}


void brackets() {
    char cadena[100];
    clearWord(cadena);
    bool verify = false;
    do {
        printf("Ingrese la expresion con parentesis: ");
        fgets(cadena, sizeof(cadena), stdin);
        verify = isEmptyText(cadena);
        if (verify) {
            printf("-- No puedes dejar vacia la cadena --\n");
        }
    } while (verify);

    if (strlen(cadena) > 0 && cadena[strlen(cadena) - 1] == '\n') {
        cadena[strlen(cadena) - 1] = '\0';
    }

    printf("* Respuesta: %d \n\n", (verifyBrackets(cadena)));
    getchar();
}


void mainMenu() {
    char option;
    char input[100];
    clearWord(input);
    option = '\0';
    char *menu = "<<<<<<<MENU PRINCIPAL>>>>>>\n\n"
            "1. Buscar la ultima ocurrencia de una subcadena dentro de otra \n\n"
            "2. Capitalizar una cadena de texto\n\n"
            "3. Dividir una cadena en un arreglo de caracteres\n\n"
            "4. Unir arreglo de caracteres en una cadena\n\n"
            "5. Verificar si una cadena de texto finaliza con otra\n\n"
            "6. Formatear un valor numerico\n\n"
            "7. Verificar si una cadena de texto es palindroma\n\n"
            "8. Validar parentesis\n\n"
            "X. Salir\n\n"

            "Digite su Opcion: ";

    do {
        do {
            printf(menu);
            fgets(input, sizeof(input), stdin);

            input[strcspn(input, "\n")] = '\0';
            if (strlen(input) == 0) {
                printf("-- No puedes dejar vacio --\n");
                option = '\0';
                getchar();
            } else if (strlen(input) > 1) {
                printf("-- Entrada invalida, solo se permite un caracter --\n");
                option = '\0';
                getchar();
            } else if (isspace((unsigned char) input[0])) {
                printf("-- Espacio no valido --\n");
                option = '\0';
                getchar();
            } else {
                option = input[0];
            }
            fflush(stdin);
        } while (option == '\0'); // Continuar si la entrada estaba vacía o era inválida

        fflush(stdin);
        if (option != 'X') {
            printf("\n<<<OPCION %c>>>\n\n", option);
        }
        switch (option) {
            case '1': searchSubFfix();
                break;

            case '2': inCapitalizeTextstring();
                break;

            case '3': splitStrings();
                break;

            case '4': joinStrings();
                break;

            case '5': endsWithFunction();
                break;

            case '6': formatValue();
                break;

            case '7': palindroma();
                break;

            case '8': brackets();
                break;

            case 'X': printf("Tenga un Buen Dia, Hasta Luego");
                break;
            case 'x': printf("Tenga un Buen Dia, Hasta Luego");
                break;
            default: printf("Opcion Invalida");
                break;
        }
    } while (toupper(option) != 'X');
}
