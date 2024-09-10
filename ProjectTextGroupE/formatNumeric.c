//
// Created by andry on 10/09/2024.
//

#include "formatNumeric.h"
#include <locale.h>
#include <stdio.h>

void formatValor(double valor, char *resultado) {
    setlocale(LC_NUMERIC, "");  // Establece la configuración regional para el separador de miles
    sprintf(resultado, "$%' .2f", valor);  // Usa %' para incluir separador de miles y %.2f para dos decimales
}
