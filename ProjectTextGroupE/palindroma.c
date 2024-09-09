#include "palindroma.h"
#include <string.h>

/**
 * @brief Verifica si una palabra o frase es pal�ndroma.
 *
 * Esta funcion limpia la entrada eliminando los espacios, caracteres especiales y
 * luego compara la palabra o frase resultante para verificar si se lee igual en ambos sentidos.
 *
 * @param word La palabra o frase a verificar.
 * @param size El tama�o de la palabra o frase (n�mero de caracteres).
 * @return true Si la palabra o frase es pal�ndroma.
 * @return false Si la palabra o frase no es pal�ndroma.
 */



bool isPalindroma(char word[100], int size) {
	//1 es palindroma
	//0 no es
	int cont = 0;
	int i = 0;
	char cleaned_word[100];  // Cadena limpia donde se almacenar� la frase procesada

	// Limpiar la frase: quitar espacios, tildes y caracteres especiales
	for (int j = 0; j < size; j++) {
		char c = word[j];
		// Solo tomar letras y n�meros
		if (isalnum(c)) {
			cleaned_word[i++] = tolower(c);  // Convertir a min�scula y sin tilde
		}
	}
	cleaned_word[i] = '\0';  // Terminar la cadena limpia
	int new_size = strlen(cleaned_word);  // Nueva longitud de la frase limpia

	// Verificar si es pal�ndroma
	for (int i = 0, j = new_size - 1; i < j; i++, j--) {
		if (cleaned_word[i] != cleaned_word[j]) {
			return false;
		}
	}
	return true;
}

