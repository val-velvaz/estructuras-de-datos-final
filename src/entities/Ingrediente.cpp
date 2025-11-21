#include "entities/Ingrediente.hpp"

Ingrediente::Ingrediente() : 
    nombreIngrediente(""), 
    cantidadIngrediente("0"), 
    unidadMedida("") {}

Ingrediente::Ingrediente(const std::string& nombre, const std::string& cantidad, const std::string& unidad)
    : nombreIngrediente(nombre), 
    cantidadIngrediente(cantidad), 
    unidadMedida(unidad) {}

Ingrediente::Ingrediente(const Ingrediente& otro)
    : nombreIngrediente(otro.nombreIngrediente),
    cantidadIngrediente(otro.cantidadIngrediente),
    unidadMedida(otro.unidadMedida) {}

Ingrediente::Ingrediente(Ingrediente&& otro) noexcept
    : nombreIngrediente(std::move(otro.nombreIngrediente)),
    cantidadIngrediente(std::move(otro.cantidadIngrediente)),
    unidadMedida(std::move(otro.unidadMedida)) {}

Ingrediente& Ingrediente::operator=(const Ingrediente& otro) {
    if (this != &otro) {
        nombreIngrediente = otro.nombreIngrediente;
        cantidadIngrediente = otro.cantidadIngrediente;
        unidadMedida = otro.unidadMedida;
    }
    return *this;
}

Ingrediente& Ingrediente::operator = (Ingrediente&& otro) noexcept {
    if (this != &otro) {
        nombreIngrediente = std::move(otro.nombreIngrediente);
        cantidadIngrediente = std::move(otro.cantidadIngrediente);
        unidadMedida = std::move(otro.unidadMedida);
    }
    return *this;
}

bool Ingrediente::operator == (const Ingrediente& otro) const {
    return nombreIngrediente == otro.nombreIngrediente;
}

bool Ingrediente::operator < (const Ingrediente& otro) const {
    return nombreIngrediente < otro.nombreIngrediente;
}

int Ingrediente::compararPorNombre(const Ingrediente& ing1, const Ingrediente& ing2) {
    if (ing1.nombreIngrediente < ing2.nombreIngrediente) return -1;
    if (ing1.nombreIngrediente > ing2.nombreIngrediente) return 1;
    return 0;
}
std::string Ingrediente::toString() const {
    return nombreIngrediente;
}

std::string Ingrediente::obtenerRepresentacionFormateada() const {
    return cantidadIngrediente + " " + unidadMedida + " de " + nombreIngrediente;
}

std::ostream& operator<<(std::ostream& salida, const Ingrediente& ing) {
    salida << ing.nombreIngrediente << "\n" << ing.cantidadIngrediente << "\n" << ing.unidadMedida;
    return salida;
}

std::istream& operator>>(std::istream& entrada, Ingrediente& ing) {
    std::getline(entrada >> std::ws, ing.nombreIngrediente);
    std::getline(entrada, ing.cantidadIngrediente);
    std::getline(entrada, ing.unidadMedida);
    return entrada;
}