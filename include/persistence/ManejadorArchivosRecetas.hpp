#pragma once
#include <string>
#include <vector>

struct InfoArchivo {
    std::string ruta;                          
    bool existe;                               
    long tamanoByte;                           
    std::string fechaUltimaModificacion;      
};

class ManejadorArchivosRecetas {
private:    
    static bool verificarIntegridad(const std::string& rutaArchivo);
    static void crearRespaldo(const std::string& rutaArchivo);

public:
    ManejadorArchivosRecetas() = delete;

    static InfoArchivo obtenerInformacionArchivo(const std::string& rutaArchivo);

    static bool crearArchivoSiNoExiste(const std::string& rutaArchivo);
    
    static bool eliminarArchivo(const std::string& rutaArchivo);
    
    static bool renombrarArchivo(const std::string& rutaActual, const std::string& rutaNueva);

    static bool crearRespaldoAutomatico(const std::string& rutaArchivo);
    static bool restaurarDesdeRespaldo(const std::string& rutaRespaldo, const std::string& rutaDestino);

    static bool verificarIntegridad(const std::string& rutaArchivo);
    static void limpiarArchivosAntiguos(const std::string& ruta, int diasAntiguedad);
};