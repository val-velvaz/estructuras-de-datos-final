#pragma once

#include "datastructures/templates/ListaSimplementeLigada.hpp"
#include <stdexcept>

template <typename TipoDato>
class PilaDinamica {
private:
    ListaSimplementeLigada<TipoDato> listaContenedora;

public:
    PilaDinamica() {}
    
    PilaDinamica(const PilaDinamica<TipoDato>& otraPila) 
        : listaContenedora(otraPila.listaContenedora) {}

    ~PilaDinamica() {
    }

    void apilar(const TipoDato& elementoNuevo) {
        listaContenedora.agregarAlInicio(elementoNuevo);
    }

    void desapilar() {
        if (estaVacia()) {
            throw std::underflow_error("Error: Intento de desapilar una pila vacía.");
        }
        listaContenedora.eliminarDelInicio();
    }

    TipoDato& consultarTope() {
        if (estaVacia()) {
            throw std::underflow_error("Error: Intento de consultar tope de pila vacía.");
        }
        return listaContenedora.obtenerEnPosicion(0);
    }

    bool estaVacia() const {
        return listaContenedora.estaVacia();
    }

    int obtenerCantidadElementos() const {
        return listaContenedora.obtenerCantidadElementos();
    }

    void limpiarPila() {
        listaContenedora.limpiarLista();
    }
};