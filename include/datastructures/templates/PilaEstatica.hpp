#pragma once
#include <stdexcept>
#include <string>
#include <sstream>

template <typename TipoDato, int CAPACIDAD_MAXIMA = 1000>
class PilaEstatica {
private:
    TipoDato* arregloDatos_;                 // Arreglo dinámico
    int posicionTopePila_;                   // Posición del tope (-1 = vacía)
    int capacidadMaxima_;                    // Capacidad máxima

public:
    PilaEstatica()
        : posicionTopePila_(-1), capacidadMaxima_(CAPACIDAD_MAXIMA) {
        arregloDatos_ = new TipoDato[capacidadMaxima_];
    }

    PilaEstatica(const PilaEstatica& otraPila)
        : posicionTopePila_(otraPila.posicionTopePila_), capacidadMaxima_(otraPila.capacidadMaxima_) {
            arregloDatos_ = new TipoDato[capacidadMaxima_];
                for (int i = 0; i <= posicionTopePila_; ++i) {
                    arregloDatos_[i] = otraPila.arregloDatos_[i];
                }
    }

    PilaEstatica& operator=(const PilaEstatica& otraPila) {
        if (this != &otraPila) {
            delete[] arregloDatos_;
            posicionTopePila_ = otraPila.posicionTopePila_;
            capacidadMaxima_ = otraPila.capacidadMaxima_;
            arregloDatos_ = new TipoDato[capacidadMaxima_];
            
            for (int i = 0; i <= posicionTopePila_; ++i) {
                arregloDatos_[i] = otraPila.arregloDatos_[i];
            }
        }
        return *this;
    }

    ~PilaEstatica() {
        delete[] arregloDatos_;
    }

    void apilarElemento(const TipoDato& elementoNuevo) {
        if (estaPilaLlena()) {
            throw std::overflow_error(
                "Pila estática llena. No se puede apilar más elementos."
            );
        }
        posicionTopePila_++;
        arregloDatos_[posicionTopePila_] = elementoNuevo;
    }

    void apilarElementoPorMovimiento(TipoDato&& elementoNuevo) {
        if (estaPilaLlena()) {
            throw std::overflow_error("Pila estática llena");
        }
        posicionTopePila_++;
        arregloDatos_[posicionTopePila_] = std::move(elementoNuevo);
    }

    TipoDato desapilarElemento() {
        if (estaPilaVacia()) {
            throw std::underflow_error(
                "Pila estática vacía. No se puede desapilar."
            );
        }
        TipoDato elementoSacado = arregloDatos_[posicionTopePila_];
        posicionTopePila_--;
        return elementoSacado;
    }

    TipoDato& obtenerTopePila() {
        if (estaPilaVacia()) {
            throw std::underflow_error("Pila estática vacía. No hay tope.");
        }
        return arregloDatos_[posicionTopePila_];
    }

    const TipoDato& obtenerTopeConsante() const {
        if (estaPilaVacia()) {
            throw std::underflow_error("Pila estática vacía");
        }
        return arregloDatos_[posicionTopePila_];
    }

    bool estaPilaVacia() const {
        return posicionTopePila_ == -1;
    }

    bool estaPilaLlena() const {
        return posicionTopePila_ == (capacidadMaxima_ - 1);
    }

    int obtenerCantidadElementos() const {
        return posicionTopePila_ + 1;
    }

    int obtenerCapacidadMaxima() const {
        return capacidadMaxima_;
    }

    void vaciarPila() {
        posicionTopePila_ = -1;
    }

    float obtenerPorcentajeUso() const {
        return (100.0f * obtenerCantidadElementos()) / capacidadMaxima_;
    }

    std::string obtenerRepresentacionTexto(
        std::string (*convertirATexto)(const TipoDato&)
    ) const {
        std::stringstream representacion;
        representacion << "Pila Estatica (tope → base):\n";
        representacion << "Capacidad: " << obtenerCantidadElementos() << "/" << capacidadMaxima_ << "\n\n";
        
        if (estaPilaVacia()) {
            representacion << "[Vacía]\n";
            return representacion.str();
        }

        for (int i = posicionTopePila_; i >= 0; --i) {
            representacion << "[" << convertirATexto(arregloDatos_[i]) << "]\n";
        }
        return representacion.str();
    }
};