#pragma once
#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <stdexcept>

class Nombre {
private:
    std::string primerNombre;
    std::string apellidoPrimero;
    std::string apellidoSegundo;

    void validarYnormalizarNombre(std::string& texto);

public:

    Nombre();
    
    Nombre(const std::string& primerNombreIngreso, const std::string& apellidoUno, const std::string& apellidoDos = "");
    
    Nombre(const Nombre& otroNombre);
    
    Nombre(Nombre&& otroNombre) noexcept;

    Nombre& operator = (const Nombre& otroNombre);
    
    Nombre& operator = (Nombre&& otroNombre) noexcept;

    bool operator == (const Nombre& otroNombre) const;
    
    bool operator<(const Nombre& otroNombre) const;

    std::string obtenerPrimerNombre() const { 
        return primerNombre; 
    }
    
    std::string obtenerApellidoPrimero() const { 
        return apellidoPrimero; 
    }
    
    std::string obtenerApellidoSegundo() const { 
        return apellidoSegundo; 
    }

    void establecerPrimerNombre(const std::string& nombre);
        void establecerApellidos(const std::string& apl1, const std::string& apl2 = "");
    
    std::string obtenerNombreCompleto() const;
    
    std::string obtenerIniciales() const;
    
    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& salida, const Nombre& nombre);
    
    friend std::istream& operator>>(std::istream& entrada, Nombre& nombre);
};