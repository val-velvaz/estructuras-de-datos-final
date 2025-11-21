
#include "entities/Nombre.hpp"

Nombre::Nombre() 
    : primerNombre(""), apellidoPrimero(""), apellidoSegundo("") {}

Nombre::Nombre(const std::string& primerNombreIngreso, 
    const std::string& apellidoUno, 
    const std::string& apellidoDos)
    : primerNombre(primerNombreIngreso), apellidoPrimero(apellidoUno), apellidoSegundo(apellidoDos) {}

Nombre::Nombre(const Nombre& otroNombre)
    : primerNombre(otroNombre.primerNombre), apellidoPrimero(otroNombre.apellidoPrimero), apellidoSegundo(otroNombre.apellidoSegundo) {}

Nombre::Nombre(Nombre&& otroNombre) noexcept
    : primerNombre(std::move(otroNombre.primerNombre)), apellidoPrimero(std::move(otroNombre.apellidoPrimero)),apellidoSegundo(std::move(otroNombre.apellidoSegundo)) {}

Nombre& Nombre::operator=(const Nombre& otroNombre) {
    if (this != &otroNombre) {
        primerNombre = otroNombre.primerNombre;
        apellidoPrimero = otroNombre.apellidoPrimero;
        apellidoSegundo = otroNombre.apellidoSegundo;
    }
    return *this;
}

Nombre& Nombre::operator=(Nombre&& otroNombre) noexcept {
    if (this != &otroNombre) {
        primerNombre = std::move(otroNombre.primerNombre);
        apellidoPrimero = std::move(otroNombre.apellidoPrimero);
        apellidoSegundo = std::move(otroNombre.apellidoSegundo);
    }
    return *this;
}


bool Nombre::operator==(const Nombre& otroNombre) const {
    return primerNombre == otroNombre.primerNombre 
    && apellidoPrimero == otroNombre.apellidoPrimero 
    && apellidoSegundo == otroNombre.apellidoSegundo;
}

bool Nombre::operator<(const Nombre& otroNombre) const {
    if (apellidoPrimero != otroNombre.apellidoPrimero) {
        return apellidoPrimero < otroNombre.apellidoPrimero;
    }
    if (apellidoSegundo != otroNombre.apellidoSegundo) {
        return apellidoSegundo < otroNombre.apellidoSegundo;
    }
    return primerNombre < otroNombre.primerNombre;
}

void Nombre::establecerPrimerNombre(const std::string& nombre) {
    primerNombre = nombre;
}

void Nombre::establecerApellidos(const std::string& apl1, const std::string& apl2) {
    apellidoPrimero = apl1;
    apellidoSegundo = apl2;
}
std::string Nombre::obtenerNombreCompleto() const {
    std::string completo = primerNombre + " " + apellidoPrimero;
    if (!apellidoSegundo.empty()) {
        completo += " " + apellidoSegundo;
    }
    return completo;
}

std::string Nombre::obtenerIniciales() const {
    std::string iniciales = "";
    if (!primerNombre.empty()) iniciales += primerNombre[0];
    if (!apellidoPrimero.empty()) iniciales += apellidoPrimero[0];
    if (!apellidoSegundo.empty()) iniciales += apellidoSegundo[0];
    return iniciales;
}

std::string Nombre::toString() const {
    return obtenerNombreCompleto();
}

void Nombre::validarYnormalizarNombre(std::string& texto) {
    // TODO: Implementar lógica de validación (quitar espacios, mayúsculas)
}

std::ostream& operator<<(std::ostream& salida, const Nombre& nombre) {
    salida << nombre.primerNombre << "\n" 
        << nombre.apellidoPrimero << "\n" 
        << nombre.apellidoSegundo;
    return salida;
}

std::istream& operator>>(std::istream& entrada, Nombre& nombre) {
    std::getline(entrada >> std::ws, nombre.primerNombre);
    std::getline(entrada, nombre.apellidoPrimero);
    std::getline(entrada, nombre.apellidoSegundo);
    return entrada;
}