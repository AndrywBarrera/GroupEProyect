#include "verifyBrackets.h"

bool verifyBrackets(char word[100]){
	int cont = 0;  // Contador para los paréntesis '()'

	for (int i = 0; i < strlen(word); i++) {  // Bucle con condición correcta
		char ch = word[i];
		// Verificar paréntesis
		if (ch == '(') {
			cont++;
		}
		else if (ch == ')') {
			cont--;
			if (cont < 0) {
				return false;  // Hay más paréntesis de cierre que de apertura
			}
		}
	}
	// Verificación al final, después de procesar toda la cadena
	if (cont == 0) {
		return true;  // Los paréntesis están balanceados
	}
	else {
		return false;  // Hay más paréntesis de apertura que de cierre
	}
}
