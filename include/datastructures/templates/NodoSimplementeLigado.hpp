#pragma once
#include <memory>

template <typename TipoDato>
class NodoSimplementeLigado {
public:
    TipoDato datosAlmacenados;     
    NodoSimplementeLigado<TipoDato>* punteroSiguienteNodo;

    NodoSimplementeLigado(const TipoDato& datosIngresados)
        : datosAlmacenados(datosIngresados), punteroSiguienteNodo(nullptr) {
    }

    NodoSimplementeLigado(TipoDato&& datosIngresados)
        : datosAlmacenados(std::move(datosIngresados)),  punteroSiguienteNodo(nullptr) {
    }

    ~NodoSimplementeLigado() = default;

    bool tieneNodoSiguiente() const {
        return punteroSiguienteNodo != nullptr;
    }

    void vincularConSiguienteNodo(NodoSimplementeLigado<TipoDato>* nodoSiguiente) {
        punteroSiguienteNodo = nodoSiguiente;
    }

    NodoSimplementeLigado<TipoDato>* obtenerNodoSiguiente() const {
        return punteroSiguienteNodo;
    }

    TipoDato& obtenerDatos() {
        return datosAlmacenados;
    }

    const TipoDato& obtenerDatosConstantes() const {
        return datosAlmacenados;
    }
};


// ============================================================================
// TEMPLATE: NodoCircularDoble<T>
// Nodo para lista circular doblemente ligada
// Características:
// - Almacena un dato de tipo genérico T
// - Contiene punteros al nodo anterior Y siguiente
// - Permite navegación bidireccional
// - Puede forma círculos (útil para colas circulares)
// ============================================================================
template <typename TipoDato>
class NodoCircularDoble {
public:
    TipoDato datosAlmacenados;                              // El dato
    NodoCircularDoble<TipoDato>* punteroAnteriorNodo;      // Puntero anterior
    NodoCircularDoble<TipoDato>* punteroSiguienteNodo;     // Puntero siguiente

    // ========================================================================
    // CONSTRUCTORES
    // ========================================================================
    
    // Constructor parametrizado
    NodoCircularDoble(const TipoDato& datosIngresados)
        : datosAlmacenados(datosIngresados),
          punteroAnteriorNodo(nullptr),
          punteroSiguienteNodo(nullptr) {
    }

    // Constructor de movimiento
    NodoCircularDoble(TipoDato&& datosIngresados)
        : datosAlmacenados(std::move(datosIngresados)),
          punteroAnteriorNodo(nullptr),
          punteroSiguienteNodo(nullptr) {
    }

    // Destructor
    ~NodoCircularDoble() = default;

    // ========================================================================
    // MÉTODOS AUXILIARES - Validación
    // ========================================================================
    
    // Verificar si existe nodo siguiente
    bool tieneNodoSiguiente() const {
        return punteroSiguienteNodo != nullptr;
    }

    // Verificar si existe nodo anterior
    bool tieneNodoAnterior() const {
        return punteroAnteriorNodo != nullptr;
    }

    // ========================================================================
    // MÉTODOS AUXILIARES - Navegación (vincular)
    // ========================================================================
    
    // Vincular con nodo anterior
    void vincularAnterior(NodoCircularDoble<TipoDato>* nodoAnterior) {
        punteroAnteriorNodo = nodoAnterior;
    }

    // Vincular con nodo siguiente
    void vincularSiguiente(NodoCircularDoble<TipoDato>* nodoSiguiente) {
        punteroSiguienteNodo = nodoSiguiente;
    }

    // Vincular bidireccional con otro nodo (conecta ambas direcciones)
    void vincularBidireccional(NodoCircularDoble<TipoDato>* nodoAnterior,
                              NodoCircularDoble<TipoDato>* nodoSiguiente) {
        punteroAnteriorNodo = nodoAnterior;
        punteroSiguienteNodo = nodoSiguiente;
    }

    // ========================================================================
    // MÉTODOS AUXILIARES - Navegación (obtener)
    // ========================================================================
    
    // Obtener nodo siguiente
    NodoCircularDoble<TipoDato>* obtenerNodoSiguiente() const {
        return punteroSiguienteNodo;
    }

    // Obtener nodo anterior
    NodoCircularDoble<TipoDato>* obtenerNodoAnterior() const {
        return punteroAnteriorNodo;
    }

    // ========================================================================
    // MÉTODOS AUXILIARES - Acceso a datos
    // ========================================================================
    
    // Obtener datos (modificable)
    TipoDato& obtenerDatos() {
        return datosAlmacenados;
    }

    // Obtener datos (constante)
    const TipoDato& obtenerDatosConstantes() const {
        return datosAlmacenados;
    }

    // ========================================================================
    // MÉTODO ESPECIAL - Para depuración
    // ========================================================================
    
    // Información si está completamente desvinculado
    bool estaDesvinculado() const {
        return punteroAnteriorNodo == nullptr && punteroSiguienteNodo == nullptr;
    }

    // Información si es un nodo circular (apunta a sí mismo)
    bool esCircular() const {
        return (punteroAnteriorNodo == this && punteroSiguienteNodo == this);
    }
};