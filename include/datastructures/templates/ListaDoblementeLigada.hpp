#pragma once

#include "NodoDoblementeLigado.hpp"

#include <stdexcept>
#include <string>

#include <sstream>

template <typename TipoDato>
class ListaDoblementeLigada {
private:
    NodoDoblementeLigado<TipoDato>* punteroNodoInicio_; 
    NodoDoblementeLigado<TipoDato>* punteroNodoFinal_;      
    int cantidadElementosActuales_;                         

    NodoDoblementeLigado<TipoDato>* obtenerNodoEnPosicion(int posicion) const {
        if (posicion < 0 || posicion >= cantidadElementosActuales_) {
            return nullptr;
        }

        NodoDoblementeLigado<TipoDato>* nodoActual = nullptr;
        if (posicion < (cantidadElementosActuales_ / 2)) {
            nodoActual = punteroNodoInicio_;
            for (int i = 0; i < posicion; ++i) {
                nodoActual = nodoActual->punteroNodoSiguiente;
            }
        } 
        else {
            nodoActual = punteroNodoFinal_;
            for (int i = (cantidadElementosActuales_ - 1); i > posicion; --i) {
                nodoActual = nodoActual->punteroNodoPrevio;
            }
        }
        return nodoActual;
    }

public:
    ListaDoblementeLigada()
        : punteroNodoInicio_(nullptr), punteroNodoFinal_(nullptr), cantidadElementosActuales_(0) {
    }

    ListaDoblementeLigada(const ListaDoblementeLigada<TipoDato>& otraLista)
        : punteroNodoInicio_(nullptr),
        punteroNodoFinal_(nullptr),
        cantidadElementosActuales_(0) {
        
        NodoDoblementeLigado<TipoDato>* nodoActual = otraLista.punteroNodoInicio_;
        while (nodoActual != nullptr) {
            this->agregarAlFinal(nodoActual->datosAlmacenados);
            nodoActual = nodoActual->punteroNodoSiguiente;
        }
    }

    ListaDoblementeLigada(ListaDoblementeLigada<TipoDato>&& otraLista) noexcept
        : punteroNodoInicio_(otraLista.punteroNodoInicio_),
        punteroNodoFinal_(otraLista.punteroNodoFinal_),
        cantidadElementosActuales_(otraLista.cantidadElementosActuales_) {
        
        otraLista.punteroNodoInicio_ = nullptr;
        otraLista.punteroNodoFinal_ = nullptr;
        otraLista.cantidadElementosActuales_ = 0;
    }

    ~ListaDoblementeLigada() {
        limpiarLista();
    }

    ListaDoblementeLigada<TipoDato>& operator=(const ListaDoblementeLigada<TipoDato>& otraLista) {
        if (this != &otraLista) {
            limpiarLista();
            NodoDoblementeLigado<TipoDato>* nodoActual = otraLista.punteroNodoInicio_;
            while (nodoActual != nullptr) {
                this->agregarAlFinal(nodoActual->datosAlmacenados);
                nodoActual = nodoActual->punteroNodoSiguiente;
            }
        }
        return *this;
    }

    ListaDoblementeLigada<TipoDato>& operator=(ListaDoblementeLigada<TipoDato>&& otraLista) noexcept {
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
        NodoDoblementeLigado<TipoDato>* nodoNuevo = 
            new NodoDoblementeLigado<TipoDato>(elementoNuevo);

        if (this->estaVacia()) {
            punteroNodoInicio_ = nodoNuevo;
            punteroNodoFinal_ = nodoNuevo;
        } else {
            punteroNodoFinal_->punteroNodoSiguiente = nodoNuevo;
            nodoNuevo->punteroNodoPrevio = punteroNodoFinal_;
            punteroNodoFinal_ = nodoNuevo;
        }
        cantidadElementosActuales_++;
    }

    void agregarAlInicio(const TipoDato& elementoNuevo) {
        NodoDoblementeLigado<TipoDato>* nodoNuevo = 
            new NodoDoblementeLigado<TipoDato>(elementoNuevo);

        if (this->estaVacia()) {
            punteroNodoInicio_ = nodoNuevo;
            punteroNodoFinal_ = nodoNuevo;
        } else {
            nodoNuevo->punteroNodoSiguiente = punteroNodoInicio_;
            punteroNodoInicio_->punteroNodoPrevio = nodoNuevo;
            punteroNodoInicio_ = nodoNuevo;
        }
        cantidadElementosActuales_++;
    }

    void eliminarDelFinal() {
        if (estaVacia()) {
            throw std::underflow_error("No se puede eliminar de una lista vacía");
        }

        NodoDoblementeLigado<TipoDato>* nodoAeliminar = punteroNodoFinal_;

        if (cantidadElementosActuales_ == 1) {
            punteroNodoInicio_ = nullptr;
            punteroNodoFinal_ = nullptr;
        } else {
            punteroNodoFinal_ = punteroNodoFinal_->punteroNodoPrevio;
            punteroNodoFinal_->punteroNodoSiguiente = nullptr;
        }
        
        delete nodoAeliminar;
        cantidadElementosActuales_--;
    }

    void eliminarDelInicio() {
        if (estaVacia()) {
            throw std::underflow_error("No se puede eliminar de una lista vacía");
        }

        NodoDoblementeLigado<TipoDato>* nodoAeliminar = punteroNodoInicio_;

        if (cantidadElementosActuales_ == 1) {
            punteroNodoInicio_ = nullptr;
            punteroNodoFinal_ = nullptr;
        } else {
            punteroNodoInicio_ = punteroNodoInicio_->punteroNodoSiguiente;
            punteroNodoInicio_->punteroNodoPrevio = nullptr;
        }

        delete nodoAeliminar;
        cantidadElementosActuales_--;
    }

    void eliminarEnPosicion(int posicionEliminacion) {
            if (posicionEliminacion < 0 || posicionEliminacion >= cantidadElementosActuales_) {
                throw std::out_of_range("Posición inválida para eliminación");
            }
    
            // Caso 1: Es el primer nodo
            if (posicionEliminacion == 0) {
                eliminarDelInicio();
                return;
            }
    
            // Caso 2: Es el último nodo
            if (posicionEliminacion == cantidadElementosActuales_ - 1) {
                eliminarDelFinal();
                return;
            }
    
            // Caso 3: Es un nodo en medio
            // 1. Encontramos el nodo a eliminar (O(n))
            NodoDoblementeLigado<TipoDato>* nodoAeliminar = obtenerNodoEnPosicion(posicionEliminacion);
            
            // 2. Obtenemos sus vecinos
            NodoDoblementeLigado<TipoDato>* nodoPrevio = nodoAeliminar->punteroNodoPrevio;
            NodoDoblementeLigado<TipoDato>* nodoSiguiente = nodoAeliminar->punteroNodoSiguiente;
    
            // 3. "Saltamos" el nodo, conectando a sus vecinos entre sí
            nodoPrevio->punteroNodoSiguiente = nodoSiguiente;
            nodoSiguiente->punteroNodoPrevio = nodoPrevio;
    
            // 4. Borramos el nodo y actualizamos el contador
            delete nodoAeliminar;
            cantidadElementosActuales_--;
    }

    TipoDato& obtenerEnPosicion(int posicion) {
        NodoDoblementeLigado<TipoDato>* nodo = obtenerNodoEnPosicion(posicion);
        if (!nodo) throw std::out_of_range("Posición inválida");
        return nodo->datosAlmacenados;
    }

    const TipoDato& obtenerEnPosicion(int posicion) const {
        NodoDoblementeLigado<TipoDato>* nodo = obtenerNodoEnPosicion(posicion);
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
        NodoDoblementeLigado<TipoDato>* nodoActual = punteroNodoInicio_;
        while (nodoActual != nullptr) {
            NodoDoblementeLigado<TipoDato>* nodoSiguiente = nodoActual->punteroNodoSiguiente;
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
        NodoDoblementeLigado<TipoDato>* nodoActual = punteroNodoInicio_;
        int indiceElemento = 1;

        while (nodoActual != nullptr) {
            representacion << indiceElemento << ". " 
                          << convertirATexto(nodoActual->datosAlmacenados) 
                          << "\n";
            nodoActual = nodoActual->punteroNodoSiguiente;
            indiceElemento++;
        }
        return representacion.str();
    }
    

    void intercambiarDatos(int pos1, int pos2) {
        if (pos1 == pos2) return;

        NodoDoblementeLigado<TipoDato>* nodo1 = obtenerNodoEnPosicion(pos1);
        NodoDoblementeLigado<TipoDato>* nodo2 = obtenerNodoEnPosicion(pos2);

        if (nodo1 && nodo2) {
            TipoDato temp = std::move(nodo1->datosAlmacenados);
            nodo1->datosAlmacenados = std::move(nodo2->datosAlmacenados);
            nodo2->datosAlmacenados = std::move(temp);
        } else {
            throw std::out_of_range("Posición inválida para intercambio");
        }
    }
};