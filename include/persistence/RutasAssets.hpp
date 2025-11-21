#pragma once
#include <string>
#include "entities/Categoria.hpp"
#include <cctype> 

class RutasAssets {
private:
    static const std::string RUTA_RELATIVA_ASSETS;
    static const std::string RUTA_RELATIVA_FONTS;
    static const std::string RUTA_RELATIVA_ICONS;
    static const std::string RUTA_RELATIVA_PLATILLOS;
    static const std::string RUTA_RELATIVA_DATA;

    RutasAssets() = delete;

public:

    static std::string obtenerRutaFuenteRegular();
    static std::string obtenerRutaFuenteNegrita();
    
    static std::string obtenerRutaIconoBotonAgregar();
    static std::string obtenerRutaIconoBotonEditar();
    static std::string obtenerRutaIconoBotonEliminar();
    static std::string obtenerRutaIconoBotonVolver();
    static std::string obtenerRutaIconoBotonGuardar();

    static std::string obtenerRutaImagenPlatillo( const Categoria& categoria, const std::string& nombrePlatillo );
    static std::string obtenerRutaCarpetaImagenesPorCategoria(const Categoria& categoria);
    static std::string obtenerRutaArchivoRecetario();
};