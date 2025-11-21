#include "entities/Receta.hpp"
#include "utils/ConvertidoresFormatos.hpp"
#include <sstream>

Receta::Receta()
    : nombrePlatillo("Sin nombre"),
      autorReceta(),
      categoriaReceta(Categoria::SIN_CATEGORIZAR),
      tiempoPreparacionMinutos(0),
      procedimientoPasos("Sin procedimiento"),
      rutaImagenPlatillo("") {
}

Receta::Receta(const std::string& nombrePlatillo_,
            const Nombre& autor,
            const Categoria& categoria,
            int tiempoMinutos,
            const std::string& procedimiento)
    : nombrePlatillo(nombrePlatillo_),
        autorReceta(autor),
        categoriaReceta(categoria),
        tiempoPreparacionMinutos(tiempoMinutos),
        procedimientoPasos(procedimiento),
        rutaImagenPlatillo("") {
}

Receta::Receta(const Receta& otraReceta)
    : nombrePlatillo(otraReceta.nombrePlatillo),
        autorReceta(otraReceta.autorReceta),
        categoriaReceta(otraReceta.categoriaReceta),
        tiempoPreparacionMinutos(otraReceta.tiempoPreparacionMinutos),
        procedimientoPasos(otraReceta.procedimientoPasos),
        ingredientesListaOrdenada(otraReceta.ingredientesListaOrdenada),
        rutaImagenPlatillo(otraReceta.rutaImagenPlatillo) {
}

Receta::Receta(Receta&& otraReceta) noexcept //c++11
    : nombrePlatillo(std::move(otraReceta.nombrePlatillo)),
    autorReceta(std::move(otraReceta.autorReceta)),
    categoriaReceta(otraReceta.categoriaReceta),
    tiempoPreparacionMinutos(otraReceta.tiempoPreparacionMinutos),
    procedimientoPasos(std::move(otraReceta.procedimientoPasos)),
    ingredientesListaOrdenada(std::move(otraReceta.ingredientesListaOrdenada)),
    rutaImagenPlatillo(std::move(otraReceta.rutaImagenPlatillo)) {
}

Receta& Receta::operator=(const Receta& otraReceta) {
    if (this != &otraReceta) {
        nombrePlatillo = otraReceta.nombrePlatillo;
        autorReceta = otraReceta.autorReceta;
        categoriaReceta = otraReceta.categoriaReceta;
        tiempoPreparacionMinutos = otraReceta.tiempoPreparacionMinutos;
        procedimientoPasos = otraReceta.procedimientoPasos;
        ingredientesListaOrdenada = otraReceta.ingredientesListaOrdenada;
        rutaImagenPlatillo = otraReceta.rutaImagenPlatillo;
    }
    return *this;
}

Receta& Receta::operator=(Receta&& otraReceta) noexcept {
    if (this != &otraReceta) {
        nombrePlatillo = std::move(otraReceta.nombrePlatillo);
        autorReceta = std::move(otraReceta.autorReceta);
        categoriaReceta = otraReceta.categoriaReceta;
        tiempoPreparacionMinutos = otraReceta.tiempoPreparacionMinutos;
        procedimientoPasos = std::move(otraReceta.procedimientoPasos);
        ingredientesListaOrdenada = std::move(otraReceta.ingredientesListaOrdenada);
        rutaImagenPlatillo = std::move(otraReceta.rutaImagenPlatillo);
    }
    return *this;
}


bool Receta::operator==(const Receta& otraReceta) const {
    return nombrePlatillo == otraReceta.nombrePlatillo;
}

bool Receta::operator<(const Receta& otraReceta) const {
    return nombrePlatillo < otraReceta.nombrePlatillo;
}

int Receta::compararPorNombre(const Receta& rec1, const Receta& rec2) {
    if (rec1.nombrePlatillo < rec2.nombrePlatillo) return -1;
    if (rec1.nombrePlatillo > rec2.nombrePlatillo) return 1;
    return 0;
}

int Receta::compararPorTiempoPreparacion(const Receta& rec1, const Receta& rec2) {
    if (rec1.tiempoPreparacionMinutos < rec2.tiempoPreparacionMinutos) return -1;
    if (rec1.tiempoPreparacionMinutos > rec2.tiempoPreparacionMinutos) return 1;
    return 0;
}

int Receta::compararPorCategoria(const Receta& rec1, const Receta& rec2) {
    int cat1 = static_cast<int>(rec1.categoriaReceta);
    int cat2 = static_cast<int>(rec2.categoriaReceta);
    
    if (cat1 < cat2) return -1;
    if (cat1 > cat2) return 1;
    return 0;
}

int Receta::compararPorAutor(const Receta& rec1, const Receta& rec2) {
    if (rec1.autorReceta < rec2.autorReceta) return -1;
    if (rec2.autorReceta < rec1.autorReceta) return 1;
    return 0;
}


void Receta::agregarIngredienteOrdenado(const Ingrediente& ingrediente) {
    if (ingredientesListaOrdenada.obtenerCantidadElementos() == 0) {
        ingredientesListaOrdenada.agregarAlFinal(ingrediente);
        return;
    }
    for (int i = 0; i < ingredientesListaOrdenada.obtenerCantidadElementos(); ++i) {
        if (ingrediente.obtenerNombre() < 
            ingredientesListaOrdenada.obtenerEnPosicion(i).obtenerNombre()) {
            ingredientesListaOrdenada.agregarEnPosicion(i, ingrediente);
            return;
        }
    } ingredientesListaOrdenada.agregarAlFinal(ingrediente);
}

void Receta::eliminarIngredientePorNombre(const std::string& nombreIngrediente) {
    for (int i = 0; i < ingredientesListaOrdenada.obtenerCantidadElementos(); ++i) {
        if (ingredientesListaOrdenada.obtenerEnPosicion(i).obtenerNombre() == nombreIngrediente) {
            ingredientesListaOrdenada.eliminarEnPosicion(i);
            return;
        }
    } throw std::runtime_error("Ingrediente no encontrado: " + nombreIngrediente);
}

void Receta::eliminarTodosLosIngredientes() {
    ingredientesListaOrdenada.limpiarLista();
}

bool Receta::verificarSiIngredienteExiste(const std::string& nombreBuscado) const {
    for (int i = 0; i < ingredientesListaOrdenada.obtenerCantidadElementos(); ++i) {
        if (ingredientesListaOrdenada.obtenerEnPosicion(i).obtenerNombre() == nombreBuscado) {
            return true;
        }
    }
    return false;
}

Ingrediente& Receta::obtenerIngredientePorNombre(const std::string& nombreBuscado) {
    for (int i = 0; i < ingredientesListaOrdenada.obtenerCantidadElementos(); ++i) {
        if (ingredientesListaOrdenada.obtenerEnPosicion(i).obtenerNombre() == nombreBuscado) {
            return ingredientesListaOrdenada.obtenerEnPosicion(i);
        }
    }
    throw std::runtime_error("Ingrediente no encontrado: " + nombreBuscado);
}

void Receta::modificarCantidadIngrediente(const std::string& nombreIngrediente, const std::string& nuevaCantidad) {
    Ingrediente& ingredienteAmodificar = obtenerIngredientePorNombre(nombreIngrediente);
    ingredienteAmodificar.establecerCantidad(nuevaCantidad);
}

std::string Receta::toString() const {
    return nombrePlatillo;
}

std::string Receta::obtenerResumenCorto() const {
    std::stringstream resumen;
    resumen << ">>> " << nombrePlatillo << " <<<\n";
    resumen << "Autor: " << autorReceta.obtenerNombreCompleto() << "\n";
    resumen << "Categoriaa: " << categoriaATexto(categoriaReceta) << "\n";
    resumen << "Tiempo: " << tiempoPreparacionMinutos << " minutos\n";
    resumen << "Igredientes: " << ingredientesListaOrdenada.obtenerCantidadElementos() << "\n";
    return resumen.str();
}

std::string Receta::obtenerDetalleCompleto() const {
    std::stringstream detalle;
    
    detalle << "╔════════════════════════════════════════╗\n";
    detalle << "║  RECETA: " << nombrePlatillo << "\n";
    detalle << "╚════════════════════════════════════════╝\n";
    detalle << "Autor: " << autorReceta.obtenerNombreCompleto() << "\n";
    detalle << "Categoría: " << categoriaATexto(categoriaReceta) << "\n";
    detalle << "Tiempo de Preparación: " << tiempoPreparacionMinutos << " minutos\n\n";
    
    detalle << "─── INGREDIENTES ───\n";
    for (int i = 0; i < ingredientesListaOrdenada.obtenerCantidadElementos(); ++i) {
        const Ingrediente& ing = ingredientesListaOrdenada.obtenerEnPosicion(i);
        detalle << "  • " << ing.obtenerRepresentacionFormateada() << "\n";
    }
    
    detalle << "\n─── PROCEDIMIENTO ───\n";
    detalle << procedimientoPasos << "\n";
    
    return detalle.str();
}

std::ostream& operator<<(std::ostream& salida, const Receta& receta) {
    salida << receta.nombrePlatillo << std::endl;
    salida << receta.autorReceta;
    salida << static_cast<int>(receta.categoriaReceta) << std::endl;
    salida << receta.tiempoPreparacionMinutos << std::endl;
    salida << receta.procedimientoPasos << std::endl;
    salida << receta.rutaImagenPlatillo << std::endl;
    salida << receta.ingredientesListaOrdenada.obtenerCantidadElementos() << std::endl;
    for (int i = 0; i < receta.ingredientesListaOrdenada.obtenerCantidadElementos(); ++i) {
        salida << receta.ingredientesListaOrdenada.obtenerEnPosicion(i);
    } return salida;
}

std::istream& operator>>(std::istream& entrada, Receta& receta) {
    std::getline(entrada, receta.nombrePlatillo);
    entrada >> receta.autorReceta;
    
    int categoriaInt;
    entrada >> categoriaInt;
    entrada.ignore();
    receta.categoriaReceta = static_cast<Categoria>(categoriaInt);
    
    entrada >> receta.tiempoPreparacionMinutos;
    entrada.ignore();
    std::getline(entrada, receta.procedimientoPasos);
    
    std::getline(entrada, receta.rutaImagenPlatillo);
    
    int cantidadIngredientes;
    entrada >> cantidadIngredientes;
    entrada.ignore();
    
    for (int i = 0; i < cantidadIngredientes; ++i) {
        Ingrediente ing;
        entrada >> ing;
        receta.ingredientesListaOrdenada.agregarAlFinal(ing);
    } return entrada;
}