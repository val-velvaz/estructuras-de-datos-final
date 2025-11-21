// ============================================================================
// ARCHIVO: include/utils/ConvertidoresFormatos.hpp
// Definición de convertidores de formatos
// ============================================================================
#pragma once
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "entities/Categoria.hpp"

std::string categoriaATexto(Categoria categoria);
class ConvertidoresFormatos {
private:
    ConvertidoresFormatos() = delete;

    static std::string trimear(const std::string& texto);

public:
    static std::string intAstring(int numero);
    static int stringAint(const std::string& texto);
    static std::string floatAstring(float numero, int decimales = 2);
    static float stringAfloat(const std::string& texto);
    static std::string doubleAstring(double numero, int decimales = 2);
    static double stringAdouble(const std::string& texto);
    static std::string boolAstring(bool valor);
    
    static bool stringAbool(const std::string& texto);

    static std::string minutosAtiempoLegible(int minutos);

    static std::string formatearNumeroConComas(int numero);
    
    static std::string formatearNumeroConDecimales(double numero, int decimales);

    static std::string padearIzquierda(
        const std::string& texto,
        int ancho,
        char caracter = ' '
    );
    
    static std::string padearDerecha(
        const std::string& texto,
        int ancho,
        char caracter = ' '
    );

    static std::string repetirString(const std::string& texto, int cantidad);
    
    static std::string reemplazarSubstring(
        std::string texto,
        const std::string& buscar,
        const std::string& reemplazar
    );

    static std::string intAhexadecimal(int numero);
    static std::string intAbinario(int numero);
    static std::string crearLineaseparadorTabla(
        const std::vector<int>& anchos
    );
    
    static std::string crearFilaTabla(
        const std::vector<std::string>& columnas,
        const std::vector<int>& anchos
    );
};