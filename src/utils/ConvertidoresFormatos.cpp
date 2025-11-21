#include "utils/ConvertidoresFormatos.hpp"
#include <vector>

std::string ConvertidoresFormatos::intAstring(int numero) {
    return std::to_string(numero);
}

int ConvertidoresFormatos::stringAint(const std::string& texto) {
    try {
        return std::stoi(texto);
    } catch (const std::exception&) {
        return 0;  
    }
}

std::string ConvertidoresFormatos::floatAstring(float numero, int decimales) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(decimales) << numero;
    return oss.str();
}

float ConvertidoresFormatos::stringAfloat(const std::string& texto) {
    try {
        return std::stof(texto);
    } catch (const std::exception&) {
        return 0.0f;  
    }
}

std::string ConvertidoresFormatos::doubleAstring(double numero, int decimales) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(decimales) << numero;
    return oss.str();
}

double ConvertidoresFormatos::stringAdouble(const std::string& texto) {
    try {
        return std::stod(texto);
    } catch (const std::exception&) {
        return 0.0;  
    }
}

std::string ConvertidoresFormatos::boolAstring(bool valor) {
    return valor ? "Sí" : "No";
}

bool ConvertidoresFormatos::stringAbool(const std::string& texto) {
    std::string minuscula = texto;
    std::transform(minuscula.begin(), minuscula.end(), minuscula.begin(), ::tolower);
    
    return (minuscula == "si" || 
            minuscula == "sí" || 
            minuscula == "s" ||
            minuscula == "1" || 
            minuscula == "true" || 
            minuscula == "verdadero" ||
            minuscula == "v");
}

std::string ConvertidoresFormatos::minutosAtiempoLegible(int minutos) {
    if (minutos < 0) {
        return "Tiempo inválido";
    }
    
    int horas = minutos / 60;
    int minutosRestantes = minutos % 60;
    
    std::ostringstream oss;
    
    if (horas > 0) {
        oss << horas << "h ";
    }
    
    oss << minutosRestantes << "min";
    
    return oss.str();
}

std::string ConvertidoresFormatos::formatearNumeroConComas(int numero) {
    std::string resultado = std::to_string(numero);
    int longitud = resultado.length();
    
    for (int i = longitud - 3; i > 0; i -= 3) {
        resultado.insert(i, ",");
    }
    
    return resultado;
}

std::string ConvertidoresFormatos::formatearNumeroConDecimales(double numero, int decimales) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(decimales) << numero;
    return oss.str();
}

std::string ConvertidoresFormatos::padearIzquierda(
    const std::string& texto,
    int ancho,
    char caracter
) {
    if (texto.length() >= ancho) {
        return texto;  
    }
    
    int espaciosRequeridos = ancho - texto.length();
    return std::string(espaciosRequeridos, caracter) + texto;
}

std::string ConvertidoresFormatos::padearDerecha(
    const std::string& texto,
    int ancho,
    char caracter
) {
    if (texto.length() >= ancho) {
        return texto;  
    }
    
    int espaciosRequeridos = ancho - texto.length();
    return texto + std::string(espaciosRequeridos, caracter);
}

std::string ConvertidoresFormatos::repetirString(const std::string& texto, int cantidad) {
    if (cantidad <= 0) {
        return "";
    }
    
    std::string resultado;
    for (int i = 0; i < cantidad; ++i) {
        resultado += texto;
    }
    return resultado;
}

std::string ConvertidoresFormatos::reemplazarSubstring(
    std::string texto,
    const std::string& buscar,
    const std::string& reemplazar
) {
    if (buscar.empty()) {
        return texto; 
    }
    
    size_t pos = 0;
    while ((pos = texto.find(buscar, pos)) != std::string::npos) {
        texto.replace(pos, buscar.length(), reemplazar);
        pos += reemplazar.length();  
    }
    
    return texto;
}

std::string ConvertidoresFormatos::intAhexadecimal(int numero) {
    std::ostringstream oss;
    oss << std::hex << numero;
    return oss.str();
}

std::string ConvertidoresFormatos::intAbinario(int numero) {
    if (numero == 0) {
        return "0";
    }
    
    std::string resultado;
    while (numero > 0) {
        resultado = (numero % 2 == 0 ? "0" : "1") + resultado;
        numero /= 2;
    }
    
    return resultado;
}

std::string ConvertidoresFormatos::trimear(const std::string& texto) {
    std::string resultado = texto;
    resultado.erase(0, resultado.find_first_not_of(" \t\n\r"));
    resultado.erase(resultado.find_last_not_of(" \t\n\r") + 1);
    
    return resultado;
}

std::string ConvertidoresFormatos::crearLineaseparadorTabla(
    const std::vector<int>& anchos
) {
    std::string separador = "╠";
    
    for (size_t i = 0; i < anchos.size(); ++i) {
        separador += repetirString("═", anchos[i]);
        
        if (i < anchos.size() - 1) {
            separador += "╬";
        } else {
            separador += "╣";
        }
    }
    
    return separador;
}

std::string ConvertidoresFormatos::crearFilaTabla(
    const std::vector<std::string>& columnas,
    const std::vector<int>& anchos
) {
    std::string fila = "║";
    
    for (size_t i = 0; i < columnas.size() && i < anchos.size(); ++i) {
        fila += padearDerecha(columnas[i], anchos[i], ' ');
        fila += "║";
    }
    
    return fila;
}

std::string categoriaATexto(Categoria categoria) {
    switch (categoria) {
        case Categoria::DESAYUNO:
            return "Desayuno";
        case Categoria::COMIDA:
            return "Comida";
        case Categoria::CENA:
            return "Cena";
        case Categoria::NAVIDENO:
            return "Navideño";
        case Categoria::SIN_CATEGORIZAR:
        default:
            return "Sin Categorizar";
    }
}