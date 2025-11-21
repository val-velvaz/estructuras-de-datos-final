#include "utils/ValidadorEntradas.hpp"

const std::string ValidadorEntradas::REGEX_EMAIL = 
    R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})";

const std::string ValidadorEntradas::REGEX_NOMBRE = 
    R"(^[a-zA-ZáéíóúÁÉÍÓÚñÑ\s]+$)";

const std::string ValidadorEntradas::REGEX_NUMERO_ENTERO = 
    R"(^-?\d+$)";

const std::string ValidadorEntradas::REGEX_NUMERO_DECIMAL = 
    R"(^-?\d+\.?\d*$)";

bool ValidadorEntradas::verificarQueNoEsteVacio(const std::string& entrada) {
    if (entrada.empty()) {
        return false;
    }
    
    return entrada.find_first_not_of(" \t\n\r") != std::string::npos;
}

bool ValidadorEntradas::verificarSiEsNombreValido(const std::string& nombre) {
    if (!verificarQueNoEsteVacio(nombre)) {
        return false;
    }
    
    std::regex regexNombre(REGEX_NOMBRE);
    return std::regex_match(nombre, regexNombre);
}

bool ValidadorEntradas::verificarSiEsNumeroEnteroPositivo(const std::string& entrada) {
    if (!verificarQueNoEsteVacio(entrada)) {
        return false;
    }
    
    try {
        int numero = std::stoi(entrada);
        return numero >= 0;  
    } catch (const std::exception&) {
        return false;
    }
}

bool ValidadorEntradas::verificarSiEsNumeroDecimalPositivo(const std::string& entrada) {
    if (!verificarQueNoEsteVacio(entrada)) {
        return false;
    }
    
    try {
        double numero = std::stod(entrada);
        return numero >= 0;
    } catch (const std::exception&) {
        return false;
    }
}

bool ValidadorEntradas::verificarSiEstaEnRango(int valor, int minimo, int maximo) {
    return valor >= minimo && valor <= maximo;
}

bool ValidadorEntradas::verificarLongitudString(
    const std::string& entrada,
    int longitudMinima,
    int longitudMaxima
) {
    return entrada.length() >= longitudMinima && entrada.length() <= longitudMaxima;
}

bool ValidadorEntradas::verificarSiEsEmailValido(const std::string& email) {
    if (!verificarQueNoEsteVacio(email)) {
        return false;
    }
    
    std::regex regexEmail(REGEX_EMAIL);
    return std::regex_match(email, regexEmail);
}


std::string ValidadorEntradas::limpiarYnormalizarEntrada(const std::string& entrada) {
    std::string resultado = entrada;
    
    resultado.erase(0, resultado.find_first_not_of(" \t\n\r"));
    
    resultado.erase(resultado.find_last_not_of(" \t\n\r") + 1);
    
    size_t pos = 0;
    while ((pos = resultado.find("  ", pos)) != std::string::npos) {
        resultado.replace(pos, 2, " ");
    }
    
    return resultado;
}

std::string ValidadorEntradas::convertirAminusculas(const std::string& texto) {
    std::string resultado = texto;
    std::transform(resultado.begin(), resultado.end(), resultado.begin(), ::tolower);
    return resultado;
}

std::string ValidadorEntradas::convertirAmayusculas(const std::string& texto) {
    std::string resultado = texto;
    std::transform(resultado.begin(), resultado.end(), resultado.begin(), ::toupper);
    return resultado;
}

std::string ValidadorEntradas::capitalizarPrimeraLetra(const std::string& texto) {
    if (texto.empty()) {
        return texto;
    }
    
    std::string resultado = convertirAminusculas(texto);
    resultado[0] = ::toupper(resultado[0]);
    return resultado;
}

bool ValidadorEntradas::verificarSiEsOpcionMenuValida(
    const std::string& opcion,
    const std::string& opcionesValidas
) {
    return opcionesValidas.find(opcion) != std::string::npos;
}

bool ValidadorEntradas::verificarSiEsRutaArchivoValida(const std::string& ruta) {
    if (!verificarQueNoEsteVacio(ruta)) {
        return false;
    }
    
    return ruta.find('.') != std::string::npos;
}