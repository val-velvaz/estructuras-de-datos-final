// ============================================================================
// ARCHIVO: src/persistence/RutasAssets.cpp
// Implementación del gestor de rutas
// ============================================================================
#include "persistence/RutasAssets.hpp"
#include "utils/ConvertidoresFormatos.hpp" // Necesitamos "categoriaATexto"
#include <iostream> // Para debugging si es necesario

// ============================================================================
// INICIALIZACIÓN DE CONSTANTES ESTÁTICAS
// ============================================================================

// Definimos las variables estáticas declaradas en el .hpp
const std::string RutasAssets::RUTA_RELATIVA_ASSETS = "assets";
const std::string RutasAssets::RUTA_RELATIVA_FONTS = "assets/fonts";
const std::string RutasAssets::RUTA_RELATIVA_ICONS = "assets/images/icons";
const std::string RutasAssets::RUTA_RELATIVA_PLATILLOS = "assets/images/platillos";
const std::string RutasAssets::RUTA_RELATIVA_DATA = "assets/data";

// ============================================================================
// RUTAS A FUENTES (FONTS)
// ============================================================================

std::string RutasAssets::obtenerRutaFuenteRegular() {
    return RUTA_RELATIVA_FONTS + "/font.ttf";
}

std::string RutasAssets::obtenerRutaFuenteNegrita() {
    return RUTA_RELATIVA_FONTS + "/font.ttf";
}

// ========================================================================
// RUTAS A ICONOS Y BOTONES
// ========================================================================

std::string RutasAssets::obtenerRutaIconoBotonAgregar() {
    return RUTA_RELATIVA_ICONS + "/boton_agregar.png";
}

std::string RutasAssets::obtenerRutaIconoBotonEditar() {
    return RUTA_RELATIVA_ICONS + "/boton_editar.png";
}

std::string RutasAssets::obtenerRutaIconoBotonEliminar() {
    return RUTA_RELATIVA_ICONS + "/boton_eliminar.png";
}

std::string RutasAssets::obtenerRutaIconoBotonVolver() {
    return RUTA_RELATIVA_ICONS + "/boton_volver.png";
}

std::string RutasAssets::obtenerRutaIconoBotonGuardar() {
    return RUTA_RELATIVA_ICONS + "/boton_guardar.png";
}

std::string RutasAssets::obtenerRutaCarpetaImagenesPorCategoria(const Categoria& categoria) {
    std::string nombreCarpeta = categoriaATexto(categoria); 
    
    for (char& c : nombreCarpeta) {
        c = tolower(c);
    }
    
    return RUTA_RELATIVA_PLATILLOS + "/" + nombreCarpeta;
}

std::string RutasAssets::obtenerRutaImagenPlatillo(
    const Categoria& categoria,
    const std::string& nombrePlatillo)
{
    std::string nombreArchivo = "default.png"; 
    return obtenerRutaCarpetaImagenesPorCategoria(categoria) + "/" + nombreArchivo;
}

std::string RutasAssets::obtenerRutaArchivoRecetario() {
    return RUTA_RELATIVA_DATA + "/recetario.dat";
}