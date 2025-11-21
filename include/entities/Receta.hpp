// ============================================================================
// ARCHIVO: include/entities/Receta.hpp
// Definición de la clase Receta
// ============================================================================
#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
#include "entities/Nombre.hpp"
#include "entities/Ingrediente.hpp"
#include "entities/Categoria.hpp"
#include "datastructures/templates/ListaSimplementeLigada.hpp"

class Receta {
private:
    std::string nombrePlatillo;                        
    Nombre autorReceta;                              
    Categoria categoriaReceta;                        
    int tiempoPreparacionMinutos;                       
    std::string procedimientoPasos;                      
    ListaSimplementeLigada<Ingrediente> ingredientesListaOrdenada;  
    std::string rutaImagenPlatillo;                     

public:
    Receta();
    
    Receta(const std::string& nombrePlatillo_, const Nombre& autor, const Categoria& categoria, int tiempoMinutos, const std::string& procedimiento);
    
    Receta(const Receta& otraReceta);
    Receta(Receta&& otraReceta) noexcept;
    Receta& operator=(const Receta& otraReceta);
    Receta& operator=(Receta&& otraReceta) noexcept;

    bool operator==(const Receta& otraReceta) const;
    bool operator<(const Receta& otraReceta) const;

    static int compararPorNombre(const Receta& rec1, const Receta& rec2);
    static int compararPorTiempoPreparacion(const Receta& rec1, const Receta& rec2);
    static int compararPorCategoria(const Receta& rec1, const Receta& rec2);
    static int compararPorAutor(const Receta& rec1, const Receta& rec2);

    std::string obtenerNombrePlatillo() const { 
        return nombrePlatillo; 
    }
    
    Nombre obtenerAutor() const { 
        return autorReceta; 
    }
    
    Categoria obtenerCategoria() const { 
        return categoriaReceta; 
    }
    
    int obtenerTiempoPreparacion() const { 
        return tiempoPreparacionMinutos; 
    }
    
    std::string obtenerProcedimiento() const { 
        return procedimientoPasos; 
    }
    
    ListaSimplementeLigada<Ingrediente>& obtenerIngredientes() { 
        return ingredientesListaOrdenada; 
    }
    
    const ListaSimplementeLigada<Ingrediente>& obtenerIngredientesConstante() const { 
        return ingredientesListaOrdenada; 
    }
    
    std::string obtenerRutaImagen() const { 
        return rutaImagenPlatillo; 
    }

    void establecerNombrePlatillo(const std::string& nombre) { 
        nombrePlatillo = nombre; 
    }
    
    void establecerAutor(const Nombre& autor) { 
        autorReceta = autor; 
    }
    
    void establecerCategoria(const Categoria& categoria) { 
        categoriaReceta = categoria; 
    }
    
    void establecerTiempoPreparacion(int minutos) { 
        tiempoPreparacionMinutos = minutos; 
    }
    
    void establecerProcedimiento(const std::string& procedimiento) { 
        procedimientoPasos = procedimiento; 
    }
    
    void establecerRutaImagen(const std::string& ruta) { 
        rutaImagenPlatillo = ruta; 
    }

    void agregarIngredienteOrdenado(const Ingrediente& ingrediente);
    
    void eliminarIngredientePorNombre(const std::string& nombreIngrediente);
    
    void eliminarTodosLosIngredientes();
    
    bool verificarSiIngredienteExiste(const std::string& nombreBuscado) const;
    
    Ingrediente& obtenerIngredientePorNombre(const std::string& nombreBuscado);
    
    void modificarCantidadIngrediente(const std::string& nombreIngrediente, const std::string& nuevaCantidad);

    std::string toString() const;
    
    std::string obtenerResumenCorto() const;
    
    std::string obtenerDetalleCompleto() const;
    
    int obtenerCantidadIngredientes() const { 
        return ingredientesListaOrdenada.obtenerCantidadElementos(); 
    }

    // ========================================================================
    // OPERADORES DE FLUJO - Serialización
    // ========================================================================
    
    // Escritura a stream (para guardar en archivos)
    friend std::ostream& operator<<(std::ostream& salida, const Receta& receta);
    
    // Lectura desde stream (para cargar desde archivos)
    friend std::istream& operator>>(std::istream& entrada, Receta& receta);
};