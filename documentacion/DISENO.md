# ESTRUCTURA DEL PROYECTO - RECETARIO INTERACTIVO

## 📁 Organización de Carpetas

```
RecetarioGame/
├── CMakeLists.txt                    # Build system moderno
├── Makefile                          # Alternativa
│
├── src/
│   ├── main.cpp
│   ├── Game.cpp
│   ├── entities/
│   │   ├── Ingrediente.cpp
│   │   ├── Nombre.cpp
│   │   ├── Receta.cpp
│   │   └── Categoria.cpp
│   │
│   ├── datastructures/
│   │   ├── implementations/
│   │   │   ├── NodoSimplementeLigado.cpp
│   │   │   ├── NodoCircularDoble.cpp
│   │   │   ├── PilaEstatica.cpp
│   │   │   ├── PilaDinamica.cpp
│   │   │   └── ColaDinamica.cpp
│   │   └── managers/
│   │       ├── ManejadorRecetas.cpp
│   │       └── ManejadorIngredientes.cpp
│   │
│   ├── persistence/
│   │   ├── ManejadorArchivosRecetas.cpp
│   │   ├── ManejadorArchivosIngredientes.cpp
│   │   └── RutasAssets.cpp
│   │
│   ├── ui/
│   │   ├── GameState.cpp
│   │   ├── PantallaMenuPrincipal.cpp
│   │   ├── PantallaVisualizarRecetas.cpp
│   │   ├── PantallaAgregarReceta.cpp
│   │   ├── PantallaEditarReceta.cpp
│   │   ├── PantallaEliminarReceta.cpp
│   │   ├── PantallaOrddenarRecetas.cpp
│   │   └── ElementosUIReutilizables.cpp
│   │
│   └── utils/
│       ├── ValidadorEntradas.cpp
│       ├── ConvertidoresFormatos.cpp
│       └── RenderizadorTextos.cpp
│
├── include/
│   ├── Game.hpp
│   ├── entities/
│   │   ├── Ingrediente.hpp
│   │   ├── Nombre.hpp
│   │   ├── Receta.hpp
│   │   └── Categoria.hpp
│   │
│   ├── datastructures/
│   │   ├── templates/
│   │   │   ├── ListaSimplementeLigada.hpp
│   │   │   ├── ListaDoblementeLigada.hpp
│   │   │   ├── ListaCircularDoble.hpp
│   │   │   ├── PilaEstatica.hpp
│   │   │   ├── PilaDinamica.hpp
│   │   │   ├── ColaDinamica.hpp
│   │   │   ├── NodoSimplementeLigado.hpp
│   │   │   └── NodoCircularDoble.hpp
│   │   │
│   │   └── managers/
│   │       ├── ManejadorRecetas.hpp
│   │       └── ManejadorIngredientes.hpp
│   │
│   ├── persistence/
│   │   ├── ManejadorArchivosRecetas.hpp
│   │   ├── ManejadorArchivosIngredientes.hpp
│   │   └── RutasAssets.hpp
│   │
│   ├── ui/
│   │   ├── GameState.hpp
│   │   ├── Pantalla.hpp
│   │   ├── PantallaMenuPrincipal.hpp
│   │   ├── PantallaVisualizarRecetas.hpp
│   │   ├── PantallaAgregarReceta.hpp
│   │   ├── PantallaEditarReceta.hpp
│   │   ├── PantallaEliminarReceta.hpp
│   │   ├── PantallaOrdenarRecetas.hpp
│   │   └── ElementosUIReutilizables.hpp
│   │
│   └── utils/
│       ├── ValidadorEntradas.hpp
│       ├── ConvertidoresFormatos.hpp
│       └── RenderizadorTextos.hpp
│
├── assets/
│   ├── fonts/
│   │   ├── MontserratRegular.ttf
│   │   └── MontserratBold.ttf
│   │
│   ├── images/
│   │   ├── icons/
│   │   │   ├── boton_agregar.png
│   │   │   ├── boton_editar.png
│   │   │   ├── boton_eliminar.png
│   │   │   ├── boton_volver.png
│   │   │   └── boton_guardar.png
│   │   │
│   │   └── platillos/
│   │       ├── desayuno/
│   │       ├── comida/
│   │       ├── cena/
│   │       └── navideno/
│   │
│   ├── data/
│   │   ├── recetario.dat
│   │   └── ingredientes_respaldo.dat
│   │
│   └── themes/
│       ├── colores.txt
│       └── configuracion.txt
│
├── tests/
│   ├── TestListas.cpp
│   ├── TestPilas.cpp
│   ├── TestOrdenmiento.cpp
│   └── DatosRecetasPrueba.txt
│
└── documentacion/
    ├── DISENO.md
    ├── MANUAL_USUARIO.md
    └── README.md
```

## 🎯 Convenciones de Nombres

### Clases y Estructuras
```cpp
// Clases principales (sustantivo + propósito)
class ListaSimplementeLigadaRecetas { }
class PilaEstaticaOperacionesTemp { }
class ManejadorArchivosRecetas { }

// Nodos de estructuras
class NodoSimplementeLigado { }
class NodoCircularDoble { }
```

### Variables Miembro
```cpp
// Privadas (guion bajo al inicio o sufijo)
class Lista {
private:
    Nodo* punteroInicio_;
    Nodo* punteroFinal_;
    int cantidadElementosAlmacenados_;
};

// Públicas (descriptivo y claro)
class Receta {
public:
    std::string nombrePlatillo;
    Nombre autorReceta;
    Categoria categoriaReceta;
};
```

### Funciones y Métodos
```cpp
// Acciones claramente descritas
void agregarRecetaAlFinal(const Receta& recetaAinsertar);
void eliminarRecetaPorPosicion(int posicionAeliminar);
ListaSimplementeLigada<Receta> obtenerRecetasOrdenadosPorTiempo();
bool verificarSiRecetaExistePorNombre(const std::string& nombreBuscado);
```

### Parámetros y Variables Locales
```cpp
void procesarReceta(
    const Receta& recetaEntrada,
    int& posicionSalidaEncontrada,
    bool& booleanoExitoOperacion
) {
    std::string nombreTemporalProcesamiento = recetaEntrada.nombrePlatillo;
    int contadorIteracionesActual = 0;
}
```

## 📋 Especificaciones de Implementación

### Estructuras de Datos MANUALMENTE
- ✅ Lista Simplemente Ligada<T> (template)
- ✅ Lista Doblemente Ligada<T> (template)
- ✅ Lista Circular Doble<T> (template)
- ✅ Pila Estática<T> (template)
- ✅ Pila Dinámica<T> (template)
- ✅ Cola Dinámica<T> (template)
- ✅ Árbol Binario de Búsqueda (opcional, para búsquedas O(log n))

### Algoritmos de Ordenamiento MANUALMENTE
- ✅ Quicksort Recursivo
- ✅ Mergesort Recursivo
- ✅ Inserción Ordenada (para ingredientes)
- ✅ Búsqueda Binaria Recursiva
- ✅ Búsqueda Lineal

### Gestión de Memoria
- Constructores por defecto
- Constructores parametrizados
- Constructores de copia
- Constructores de movimiento (C++11)
- Operador asignación (=)
- Operador asignación por movimiento (C++11)
- Destructores (¡IMPORTANTE!)

### Archivos de Persistencia
- Formato: Binario personalizado (NO JSON/XML, ya que es clase de EDD)
- Compresión: Opcional (pero implementable)
- Validación: Checksum simple

## 🎨 Sistema de Rutas para Assets

```cpp
// Archivo: include/persistence/RutasAssets.hpp

class RutasAssets {
private:
    static const std::string RUTA_BASE_ASSETS;
    static const std::string RUTA_FONTS;
    static const std::string RUTA_ICONOS;
    static const std::string RUTA_IMAGENES_PLATILLOS;
    static const std::string RUTA_DATOS;

public:
    static std::string obtenerRutaFuenteNormal();
    static std::string obtenerRutaFuenteNegrita();
    static std::string obtenerRutaIconoBotonAgregar();
    static std::string obtenerRutaImagenPlatillo(
        const Categoria& categoria,
        const std::string& nombrePlatillo
    );
    static std::string obtenerRutaArchivoRecetas();
};
```

## 🔍 Características de "Código Estudiantil Auténtico"

- Algunas variables innecesariamente redundantes (pero NO tóxicas)
- Métodos a veces con lógica ligeramente ineficiente
- Comments ocasionales que dicen "lo obvio" en conceptos educativos
- Falta de optimización en algunos lugares (pero funciona)
- Manejo de errores robusto (el perfeccionista)
- Uso de `bool` con nombres descriptivos en lugar de IFs complejos
- Comentarios en código sección como: "TODO: mejorar", "HACK: funciona pero..."

Ejemplo:
```cpp
// PILA ESTÁTICA - Es un arreglo, pero con operaciones LIFO
// Operaciones: push (agregar al tope), pop (sacar del tope), peek (mirar sin sacar)
template <typename TipoElemento>
class PilaEstatica {
private:
    TipoElemento* arregloDatos;
    int posicionTopePila;
    int capacidadMaxima;
    
    // TODO: Implementar con un multiplicador dinámico si se llena
    // HACK: Por ahora solo sacamos error
    
public:
    void apilarElemento(const TipoElemento& elementoAinsertar);
    TipoElemento desapilarElemento();
    // ...
};
```

## 📊 Pruebas Incluidas

Mínimo 10 recetas con 10+ ingredientes cada una:
1. Chilaquiles Verdes
2. Mole Poblano
3. Pozole Rojo
4. Tamales de Rajas
5. Enchiladas Suizas
6. Carne Asada
7. Quesadillas de Flor de Calabaza
8. Chiles Rellenos
9. Cochinita Pibil
10. Pastel de Tres Leches

---

**Próximos pasos:**
1. Crear todas las clases de Estructuras de Datos
2. Implementar entidades (Ingrediente, Receta, Nombre)
3. Sistema de persistencia
4. Interfaz gráfica SDL3
5. Validaciones y manejo de errores