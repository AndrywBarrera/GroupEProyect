#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "endswith.h"
#include <string.h>
#include "palindroma.h"
#include "splitString.h"



void mainMenu();

int main() {
    mainMenu();
    return 0;
}

 void endsWithFunction(){

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

    printf("Resultado: %d\n\n", result);

}

void palindroma() {
     char word[100];
     char wordutf[100];

     //anita lava la tina es palindroma
     //Anita, la gorda lagartona, no traga la droga latina. es palindroma
     printf("Ingrese una cadena de texto: ");
     fgets(word, 100, stdin);
     word[strcspn(word, "\n")] = 0;

     fflush(stdin);

     printf(" Respuesta: %d \n\n ", isPalindroma(word, strlen(word)));
}

void splitStrings() {
    char text[500];

    printf("Ingrese una cadena de texto: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;

    char* output = split(text);

    if (output != NULL) {
        printf("Cadena dividida en caracteres: ");
        for (int i = 0; i < strlen(text); i++) {
            printf("%c ", output[i]);
        }
        printf("\n");

        free(output);
    } else {
        printf("Error de asignación de memoria.\n");
    }
}

    void mainMenu(){

        char option;
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

        do{
            printf( menu);
            scanf("%c",&option);
            fflush(stdin);
            getchar();
            switch(option){
                case '1' : NULL;
                break;

                case '2' : NULL;
                break;

                case '3' : splitStrings();
                break;

                case '4' : NULL;
                break;

                case '5' : endsWithFunction();
                break;

                case '6' : NULL;
                break;

                case '7' : palindroma();
                break;

                case '8' : NULL;
                break;



            }
        }while( toupper(option) != 'X');
    }
