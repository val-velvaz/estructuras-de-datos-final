#pragma once

#include "NodoSimplementeLigado.hpp"
#include <stdexcept>
#include <string>
#include <sstream>

template <typename TipoDato>
class ListaSimplementeLigada {
private:
    NodoSimplementeLigado<TipoDato>* punteroNodoInicio_; 
    NodoSimplementeLigado<TipoDato>* punteroNodoFinal_;   
    int cantidadElementosActuales_;                          


    NodoSimplementeLigado<TipoDato>* obtenerNodoEnPosicion(int posicion) const {
        if (posicion < 0 || posicion >= cantidadElementosActuales_) {
            return nullptr;
        }

        NodoSimplementeLigado<TipoDato>* nodoActual = punteroNodoInicio_;
        for (int i = 0; i < posicion; ++i) {
            nodoActual = nodoActual->punteroSiguienteNodo;
        }
        return nodoActual;
    }

public:

    ListaSimplementeLigada()
        : punteroNodoInicio_(nullptr),
        punteroNodoFinal_(nullptr),
        cantidadElementosActuales_(0) {
    }

    ListaSimplementeLigada(const ListaSimplementeLigada<TipoDato>& otraLista)
        : punteroNodoInicio_(nullptr),
        punteroNodoFinal_(nullptr),
        cantidadElementosActuales_(0) {
        
        NodoSimplementeLigado<TipoDato>* nodoActual = otraLista.punteroNodoInicio_;
        while (nodoActual != nullptr) {
            this->agregarAlFinal(nodoActual->datosAlmacenados);
            nodoActual = nodoActual->punteroSiguienteNodo;
        }
    }

    // Constructor de movimiento
    ListaSimplementeLigada(ListaSimplementeLigada<TipoDato>&& otraLista) noexcept
        : punteroNodoInicio_(otraLista.punteroNodoInicio_),
        punteroNodoFinal_(otraLista.punteroNodoFinal_),
        cantidadElementosActuales_(otraLista.cantidadElementosActuales_) {
        
        otraLista.punteroNodoInicio_ = nullptr;
        otraLista.punteroNodoFinal_ = nullptr;
        otraLista.cantidadElementosActuales_ = 0;
    }

    ~ListaSimplementeLigada() {
        limpiarLista();
    }

    ListaSimplementeLigada<TipoDato>& operator=(const ListaSimplementeLigada<TipoDato>& otraLista) {
        if (this != &otraLista) {
            limpiarLista();
            
            NodoSimplementeLigado<TipoDato>* nodoActual = otraLista.punteroNodoInicio_;
            while (nodoActual != nullptr) {
                this->agregarAlFinal(nodoActual->datosAlmacenados);
                nodoActual = nodoActual->punteroSiguienteNodo;
            }
        }
        return *this;
    }

    ListaSimplementeLigada<TipoDato>& operator=(ListaSimplementeLigada<TipoDato>&& otraLista) noexcept {
        if (this != &otraLista) {
            limpiarLista();
            punteroNodoInicio_ = otraLista.punteroNodoInicio_;
            punteroNodoFinal_ = otraLista.punteroNodoFinal_;
            cantidadElementosActuales_ = otraLista.cantidadElementosActuales_;

            otraLista.punteroNodoInicio_ = nullptr;
            otraLista.punteroNodoFinal_ = nullptr;
            otraLista.cantidadElementosActuales_ = 0;
        }
        return *this;
    }

    void agregarAlFinal(const TipoDato& elementoNuevo) {
        NodoSimplementeLigado<TipoDato>* nodoNuevo = 
            new NodoSimplementeLigado<TipoDato>(elementoNuevo);

        if (this->estaVacia()) {
            punteroNodoInicio_ = nodoNuevo;
            punteroNodoFinal_ = nodoNuevo;
        } else {
            punteroNodoFinal_->punteroSiguienteNodo = nodoNuevo;
            punteroNodoFinal_ = nodoNuevo;
        }
        cantidadElementosActuales_++;
    }

    void agregarAlInicio(const TipoDato& elementoNuevo) {
        NodoSimplementeLigado<TipoDato>* nodoNuevo = 
            new NodoSimplementeLigado<TipoDato>(elementoNuevo);

        if (this->estaVacia()) {
            punteroNodoInicio_ = nodoNuevo;
            punteroNodoFinal_ = nodoNuevo;
        } else {
            nodoNuevo->punteroSiguienteNodo = punteroNodoInicio_;
            punteroNodoInicio_ = nodoNuevo;
        }
        cantidadElementosActuales_++;
    }

    void agregarEnPosicion(int posicionInsercion, const TipoDato& elementoNuevo) {
        if (posicionInsercion < 0 || posicionInsercion > cantidadElementosActuales_) {
            throw std::out_of_range("Posición inválida para inserción");
        }

        if (posicionInsercion == 0) {
            agregarAlInicio(elementoNuevo);
            return;
        }

        if (posicionInsercion == cantidadElementosActuales_) {
            agregarAlFinal(elementoNuevo);
            return;
        }

        NodoSimplementeLigado<TipoDato>* nodoAnterior = obtenerNodoEnPosicion(posicionInsercion - 1);
        NodoSimplementeLigado<TipoDato>* nodoNuevo = 
            new NodoSimplementeLigado<TipoDato>(elementoNuevo);

        nodoNuevo->punteroSiguienteNodo = nodoAnterior->punteroSiguienteNodo;
        nodoAnterior->punteroSiguienteNodo = nodoNuevo;
        cantidadElementosActuales_++;
    }

    void eliminarDelFinal() {
        if (estaVacia()) {
            throw std::underflow_error("No se puede eliminar de una lista vacía");
        }

        if (cantidadElementosActuales_ == 1) {
            delete punteroNodoInicio_;
            punteroNodoInicio_ = nullptr;
            punteroNodoFinal_ = nullptr;
        } else {
            NodoSimplementeLigado<TipoDato>* nodoAnteriorAlFinal = 
                obtenerNodoEnPosicion(cantidadElementosActuales_ - 2);
            delete punteroNodoFinal_;
            punteroNodoFinal_ = nodoAnteriorAlFinal;
            punteroNodoFinal_->punteroSiguienteNodo = nullptr;
        }
        cantidadElementosActuales_--;
    }

    void eliminarDelInicio() {
        if (estaVacia()) {
            throw std::underflow_error("No se puede eliminar de una lista vacía");
        }

        NodoSimplementeLigado<TipoDato>* nodoAeliminar = punteroNodoInicio_;
        punteroNodoInicio_ = punteroNodoInicio_->punteroSiguienteNodo;

        if (cantidadElementosActuales_ == 1) {
            punteroNodoFinal_ = nullptr;
        }

        delete nodoAeliminar;
        cantidadElementosActuales_--;
    }

    void eliminarEnPosicion(int posicionEliminacion) {
        if (posicionEliminacion < 0 || posicionEliminacion >= cantidadElementosActuales_) {
            throw std::out_of_range("Posición inválida para eliminación");
        }

        if (posicionEliminacion == 0) {
            eliminarDelInicio();
            return;
        }

        if (posicionEliminacion == cantidadElementosActuales_ - 1) {
            eliminarDelFinal();
            return;
        }

        NodoSimplementeLigado<TipoDato>* nodoAnterior = 
            obtenerNodoEnPosicion(posicionEliminacion - 1);
        NodoSimplementeLigado<TipoDato>* nodoAeliminar = nodoAnterior->punteroSiguienteNodo;

        nodoAnterior->punteroSiguienteNodo = nodoAeliminar->punteroSiguienteNodo;
        delete nodoAeliminar;
        cantidadElementosActuales_--;
    }

    TipoDato& obtenerEnPosicion(int posicion) {
        NodoSimplementeLigado<TipoDato>* nodo = obtenerNodoEnPosicion(posicion);
        if (!nodo) throw std::out_of_range("Posición inválida");
        return nodo->datosAlmacenados;
    }

    const TipoDato& obtenerEnPosicion(int posicion) const {
        NodoSimplementeLigado<TipoDato>* nodo = obtenerNodoEnPosicion(posicion);
        if (!nodo) throw std::out_of_range("Posición inválida");
        return nodo->datosAlmacenados;
    }

    bool estaVacia() const {
        return cantidadElementosActuales_ == 0;
    }

    int obtenerCantidadElementos() const {
        return cantidadElementosActuales_;
    }

    void limpiarLista() {
        NodoSimplementeLigado<TipoDato>* nodoActual = punteroNodoInicio_;
        while (nodoActual != nullptr) {
            NodoSimplementeLigado<TipoDato>* nodoSiguiente = nodoActual->punteroSiguienteNodo;
            delete nodoActual;
            nodoActual = nodoSiguiente;
        }
        punteroNodoInicio_ = nullptr;
        punteroNodoFinal_ = nullptr;
        cantidadElementosActuales_ = 0;
    }

    std::string obtenerRepresentacionTexto(
        std::string (*convertirATexto)(const TipoDato&)
    ) const {
        std::stringstream representacion;
        NodoSimplementeLigado<TipoDato>* nodoActual = punteroNodoInicio_;
        int indiceElemento = 1;

        while (nodoActual != nullptr) {
            representacion << indiceElemento << ". " 
            << convertirATexto(nodoActual->datosAlmacenados) 
            << "\n";
            nodoActual = nodoActual->punteroSiguienteNodo;
            indiceElemento++;
        }

        return representacion.str();
    }

    class Iterador {
    private:
        NodoSimplementeLigado<TipoDato>* nodoActual_;
    public:
        Iterador(NodoSimplementeLigado<TipoDato>* nodo) : nodoActual_(nodo) {}

        TipoDato& operator*() {
            if (!nodoActual_) throw std::runtime_error("Iterador nulo");
            return nodoActual_->datosAlmacenados;
        }

        Iterador& operator++() {
            if (nodoActual_) nodoActual_ = nodoActual_->punteroSiguienteNodo;
            return *this;
        }

        bool operator!=(const Iterador& otro) const {
            return nodoActual_ != otro.nodoActual_;
        }
    };

    Iterador comenzar() { return Iterador(punteroNodoInicio_); }
    Iterador finalizar() { return Iterador(nullptr); }
};