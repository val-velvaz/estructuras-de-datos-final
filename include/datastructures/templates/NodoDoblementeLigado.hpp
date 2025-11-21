#pragma once
#include <cstddef> 

template <typename TipoDato>
class NodoDoblementeLigado {
public:
    TipoDato datosAlmacenados;     
    NodoDoblementeLigado<TipoDato>* punteroNodoPrevio; 
    NodoDoblementeLigado<TipoDato>* punteroNodoSiguiente; 
    NodoDoblementeLigado(const TipoDato& datos)
        : datosAlmacenados(datos),
          punteroNodoPrevio(nullptr),
          punteroNodoSiguiente(nullptr) {
    }

    NodoDoblementeLigado(const NodoDoblementeLigado<TipoDato>& otroNodo)
        : datosAlmacenados(otroNodo.datosAlmacenados),
          punteroNodoPrevio(otroNodo.punteroNodoPrevio),
          punteroNodoSiguiente(otroNodo.punteroNodoSiguiente) {
    }

  ~NodoDoblementeLigado() {
    }
};