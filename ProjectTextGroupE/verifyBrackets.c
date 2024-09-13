#include "verifyBrackets.h"
#include <string.h>

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
