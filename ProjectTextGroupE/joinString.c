//
// Created by Home on 14/09/2024.
//

#include "joinString.h"
#include <iostream>
#include <vector>
#include <string>

// Función para unir un arreglo de caracteres en una cadena usando un separador
std::string unirCaracteres(const std::vector<std::string>& arr, char separador) {
    std::string resultado;
    if (!arr.empty()) {
        resultado += arr[0];  // Agregar el primer elemento sin el separador al inicio
        for (size_t i = 1; i < arr.size(); ++i) {
            resultado += separador + arr[i];  // Agregar los siguientes elementos con el separador
        }
    }
    return resultado;
}