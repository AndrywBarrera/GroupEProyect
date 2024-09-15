//
// Created by andry on 10/09/2024.
//

#include "formatNumeric.h"
#include <locale.h>
#include <stdio.h>


/**
* Dar formato a un número.
*
* Esta función da formato de moneda a un número a partir de tomar la localidad por defecto
* adicionalmente, le da formato de decimales y comas para que quede formateado totalmente.
*
* @param valor Variable numérica a formartear.
* @param resultado Variable donde se guardará el valor sobrescribiéndolo.
* @return nothing
*/

void formatValor(double valor, char *resultado) {
    setlocale(LC_NUMERIC, "");  // Establece la configuración regional para el separador de miles
    sprintf(resultado, "$%' .2f", valor);  // Usa %' para incluir separador de miles y %.2f para dos decimales
}
