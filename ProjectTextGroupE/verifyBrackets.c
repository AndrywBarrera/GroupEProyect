#include "verifyBrackets.h"
#include <string.h>

/**
 * Verifica si los parentesis abiertos coinciden con los de salida
 *
 * Esta funcion  verifica que los parentesis "(" tengo el respectivo de cierre ")" leyendo todo el arreglo de caracteres
 *y luego guardando en un contador los de abertura "(", y encuentra  de cierre ")" restara uno a ese conatdor, por ende
 * si cont=0 se cumple el balance de parentesis de ser !=0 no se cumple el balance
 * 
 * @param word La palabra o arreglo de caracteres a validar.
 * @return true Si los parentesis estan balanceados.
 * @return false Si los parentesis no estan balanceados.
 */

bool verifyBrackets(char word[100]){
	int cont = 0;  // Contador para los par�ntesis '()'

	for (int i = 0; i < strlen(word); i++) {  // Bucle con condici�n correcta
		char ch = word[i];
		// Verificar par�ntesis
		if (ch == '(') {
			cont++;
		}
		else if (ch == ')') {
			cont--;
			if (cont < 0) {
				return false;  // Hay m�s par�ntesis de cierre que de apertura
			}
		}
	}
	// Verificaci�n al final, despu�s de procesar toda la cadena
	if (cont == 0) {
		return true;  // Los par�ntesis est�n balanceados
	}
	else {
		return false;  // Hay m�s par�ntesis de apertura que de cierre
	}
}
