#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

// Calcular coeficiente binomial
unsigned long long calcularBinomial(int n, int r) {
    if (r > n - r) r = n - r;
    unsigned long long resultado = 1;
    for (int i = 1; i <= r; ++i) {
        resultado *= (n - (i - 1));
        resultado /= i;
    }
    return resultado;
}

// Mostrar combinación en consola con formato a<b<c
std::string formatearCombinacion(const std::vector<std::string>& combinacion) {
    std::string resultado = "(";
    for (size_t i = 0; i < combinacion.size(); ++i) {
        resultado += combinacion[i];
        if (i < combinacion.size() - 1) resultado += "<";
    }
    resultado += ")";
    return resultado;
}

// Convertir combinación a línea CSV
std::string combinacionToCSV(const std::vector<std::string>& combinacion) {
    std::string resultado;
    for (size_t i = 0; i < combinacion.size(); ++i) {
        resultado += combinacion[i];
        if (i < combinacion.size() - 1) resultado += ",";
    }
    return resultado;
}

// Generar combinaciones
void generarCombinaciones(int n, int r, const std::vector<std::string>& palabras) {
    if (n < 1 || r < 0 || r > n) {
        std::cout << "Error: Valores invalidos. Debe cumplirse n >= 1, 0 <= r <= n.\n";
        return;
    }

    std::string nombreArchivo = "combinaciones_" + std::to_string(n) + "_" + std::to_string(r) + ".csv";
    std::ofstream archivoCSV(nombreArchivo);

    if (!archivoCSV.is_open()) {
        std::cout << "Error: No se pudo crear el archivo CSV.\n";
        return;
    }

    std::vector<int> indices(r);
    for (int i = 0; i < r; ++i) indices[i] = i;

    std::vector<std::vector<std::string>> todasLasCombinaciones;
    unsigned long long conteo = 0;

    std::cout << "\nLista de ccombinaciones de elementos: ";

    bool hayMas = true;
    bool primeraCombinacion = true;
    while (hayMas) {
        std::vector<std::string> combinacionActual(r);
        for (int i = 0; i < r; ++i) {
            combinacionActual[i] = palabras[indices[i]];
        }

        if (!primeraCombinacion) {
            std::cout << ", ";
        } else {
            primeraCombinacion = false;
        }
        std::cout << formatearCombinacion(combinacionActual);

        archivoCSV << combinacionToCSV(combinacionActual) << std::endl;
        todasLasCombinaciones.push_back(combinacionActual);
        conteo++;

        int m = r - 1;
        while (m >= 0 && indices[m] == n - r + m) m--;

        if (m < 0) {
            hayMas = false;
        } else {
            indices[m]++;
            for (int j = m + 1; j < r; ++j) {
                indices[j] = indices[j - 1] + 1;
            }
        }
    }
    std::cout << std::endl;

    archivoCSV.close();

    std::sort(todasLasCombinaciones.begin(), todasLasCombinaciones.end());

    std::cout << "\nCombinaciones ordenadas lexicograficamente: ";
    primeraCombinacion = true;
    for (const auto& combinacion : todasLasCombinaciones) {
        if (!primeraCombinacion) {
            std::cout << " < ";
        } else {
            primeraCombinacion = false;
        }
        std::cout << formatearCombinacion(combinacion);
    }
    std::cout << std::endl;

    std::cout << "\nInformacion final:\n";
    std::cout << "- Numero total de combinaciones generadas: " << conteo << std::endl;
    std::cout << "- Numero teorico de combinaciones C(" << n << "," << r << "): " << calcularBinomial(n, r) << std::endl;
    std::cout << "- Las combinaciones han sido guardadas en: " << nombreArchivo << std::endl;
}

int main() {
    int r;
    std::vector<std::string> palabras;
    std::string entradaUsuario;
    std::string palabra;

    std::cout << "Ingrese grupos de letras separados por comas (ej: ab,cf,kl): ";
    std::getline(std::cin, entradaUsuario);
    std::stringstream ss(entradaUsuario);

    while (std::getline(ss, palabra, ',')) {
        palabra.erase(std::remove_if(palabra.begin(), palabra.end(), ::isspace), palabra.end());
        if (!palabra.empty()) palabras.push_back(palabra);
    }

    int n = palabras.size();
    if (n < 1) {
        std::cout << "Error: No se ingresaron grupos validos.\n";
        return 1;
    }

    std::cout << "\nGrupos ingresados: {";
    for (size_t i = 0; i < palabras.size(); ++i) {
        std::cout << palabras[i];
        if (i < palabras.size() - 1) std::cout << ", ";
    }
    std::cout << "}\n";

    do {
        std::cout << "Ingrese el tamano de las combinaciones (r): ";
        std::cin >> r;

        if (r < 0 || r > n) {
            std::cout << "Error: r debe estar entre 0 y " << n << ".\n";
        } else {
            break;
        }
    } while (true);

    generarCombinaciones(n, r, palabras);

    return 0;
}
