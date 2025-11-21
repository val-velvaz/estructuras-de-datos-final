#pragma once

#include "entities/Receta.hpp"
#include "datastructures/templates/ListaDoblementeLigada.hpp"
#include <string>
#include <vector>
#include <stdexcept>


class ManejadorRecetas {
private:
    ListaDoblementeLigada<Receta> recetasAlmacenadas;

    int encontrarIndiceRecetaPorNombre(const std::string& nombreBuscado) const;
    int encontrarIndicePrimeraRecetaPorCategoria(const Categoria& categoriaBuscada) const;

    void quickSortRecursivo(
        ListaDoblementeLigada<Receta>& lista,
        int izquierda,
        int derecha,
        int (*comparador)(const Receta&, const Receta&)
    );

public:
    ManejadorRecetas();
    ~ManejadorRecetas();

    void agregarRecetaNueva(const Receta& recetaAinsertar);

    Receta& obtenerRecetaPorNombre(const std::string& nombreBuscado);
    
    const Receta& obtenerRecetaPorNombreConstante(const std::string& nombreBuscado) const;
    
    Receta& obtenerPrimeraRecetaPorCategoria(const Categoria& categoriaBuscada);

    void eliminarRecetaPorNombre(const std::string& nombreAeliminar);
    void eliminarTodasLasRecetas();
    void ordenarRecetasPorNombre();
    void ordenarRecetasPorTiempoPreparacion();
    void ordenarRecetasPorCategoria();
    void ordenarRecetasPorAutor();

    bool verificarSiRecetaExiste(const std::string& nombreReceta) const;
    
    std::vector<Receta> obtenerRecetasFiltradasPorCategoria(const Categoria& categoria) const;
    
    std::vector<Receta> obtenerRecetasOrdenadas(
        int (*comparador)(const Receta&, const Receta&)
    ) const;

    const ListaDoblementeLigada<Receta>& obtenerTodasLasRecetas() const {
        return recetasAlmacenadas;
    }
    
    ListaDoblementeLigada<Receta>& obtenerTodasLasRecetasModificables() {
        return recetasAlmacenadas;
    }

    int obtenerCantidadRecetas() const {
        return recetasAlmacenadas.obtenerCantidadElementos();
    }

    void guardarRecetasAarchivo(const std::string& rutaArchivo);
    void cargarRecetasDesdeArchivo(const std::string& rutaArchivo);
    std::string obtenerEstadisticasRecetario() const;
    std::string obtenerListadoCompleto(bool ordenado = false) const;
};