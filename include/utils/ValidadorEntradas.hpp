#pragma once
#include <string>
#include <regex>
#include <algorithm>
#include <cctype>

class ValidadorEntradas {
private:
    static const std::string REGEX_EMAIL;
    static const std::string REGEX_NOMBRE;
    static const std::string REGEX_NUMERO_ENTERO;
    static const std::string REGEX_NUMERO_DECIMAL;

    ValidadorEntradas() = delete;

public:

    static bool verificarQueNoEsteVacio(const std::string& entrada);
    static bool verificarSiEsNombreValido(const std::string& nombre);
    static bool verificarSiEsNumeroEnteroPositivo(const std::string& entrada);
    static bool verificarSiEsNumeroDecimalPositivo(const std::string& entrada);
    static bool verificarSiEstaEnRango(int valor, int minimo, int maximo);
    static bool verificarLongitudString(
        const std::string& entrada,
        int longitudMinima,
        int longitudMaxima
    );

    static bool verificarSiEsEmailValido(const std::string& email);
    static bool verificarSiEsRutaArchivoValida(const std::string& ruta);

    static std::string limpiarYnormalizarEntrada(const std::string& entrada);
    static std::string convertirAminusculas(const std::string& texto);
    static std::string convertirAmayusculas(const std::string& texto);
    static std::string capitalizarPrimeraLetra(const std::string& texto);

    static bool verificarSiEsOpcionMenuValida( const std::string& opcion, const std::string& opcionesValidas);
};

namespace MensajesError {
    const std::string ENTRADA_VACIA = "La entrada no puede estar vacía";
    const std::string NOMBRE_INVALIDO = "Nombre inválido: solo letras y espacios permitidos";
    const std::string NUMERO_INVALIDO = "Número inválido: debe ser un número válido";
    const std::string FUERA_RANGO = "El valor está fuera del rango permitido";
    const std::string LONGITUD_INVALIDA = "La longitud de la entrada no es válida";
    const std::string EMAIL_INVALIDO = "Email inválido: formato no reconocido";
    const std::string OPCION_INVALIDA = "Opción inválida: selecciona una opción válida";
}