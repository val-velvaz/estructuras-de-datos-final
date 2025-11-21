#pragma once
#include "entities/Receta.hpp"
#include "datastructures/templates/ListaDoblementeLigada.hpp"

class DatosPruebaRecetario {
public:

    static ListaDoblementeLigada<Receta> obtenerRecetasDeEjemplo();

private:

    static Receta crearChilaquilesVerdes();
    static Receta crearMolePolano();    
    static Receta crearPozoleRojo();
    static Receta crearTamalesDeRajas();
    static Receta crearEnchaladasSuizas();
    static Receta crearCarneAsada();
    static Receta crearQuesadillasFlordeCalabazo();
    static Receta crearChilesRellenos();
    static Receta crearCochinitaPibil();    
    static Receta crearPastelTresLeches();
    static Receta crearSopaDeTortilla();
    static Receta crearFajitasDePollo();
};

