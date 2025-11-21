#pragma once
#include <string>
#include <iostream>
#include <stdexcept>

class Ingrediente {
private:
    std::string nombreIngrediente;      // Nombre del ingrediente
    std::string cantidadIngrediente;    // Cantidad (ej: "2", "1/2", "3.5")
    std::string unidadMedida;           // Unidad (ej: "tazas", "gramos", "piezas")

public:
    Ingrediente();
    
    Ingrediente(const std::string& nombre, const std::string& cantidad, const std::string& unidad);
    
    Ingrediente(const Ingrediente& otro);
    
    Ingrediente(Ingrediente&& otro) noexcept;

    Ingrediente& operator=(const Ingrediente& otro);
    
    Ingrediente& operator=(Ingrediente&& otro) noexcept;

    bool operator==(const Ingrediente& otro) const;
    
    bool operator<(const Ingrediente& otro) const;

    static int compararPorNombre(const Ingrediente& ing1, const Ingrediente& ing2);

    std::string obtenerNombre() const { 
        return nombreIngrediente; 
    }
    
    std::string obtenerCantidad() const { 
        return cantidadIngrediente; 
    }
    
    std::string obtenerUnidad() const { 
        return unidadMedida; 
    }
    void establecerNombre(const std::string& nombre) { 
        nombreIngrediente = nombre; 
    }
    
    void establecerCantidad(const std::string& cantidad) { 
        cantidadIngrediente = cantidad; 
    }
    
    void establecerUnidad(const std::string& unidad) { 
        unidadMedida = unidad; 
    }

    std::string toString() const;

    std::string obtenerRepresentacionFormateada() const;

    friend std::ostream& operator<<(std::ostream& salida, const Ingrediente& ing);
    
    // Lectura desde stream (para cargar desde archivos)
    friend std::istream& operator>>(std::istream& entrada, Ingrediente& ing);
};