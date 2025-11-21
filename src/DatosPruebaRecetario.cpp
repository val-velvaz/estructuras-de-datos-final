#include "DatosPruebaRecetario.hpp"

ListaDoblementeLigada<Receta> DatosPruebaRecetario::obtenerRecetasDeEjemplo() {
    ListaDoblementeLigada<Receta> recetas;
    
    recetas.agregarAlFinal(crearChilaquilesVerdes());
    recetas.agregarAlFinal(crearMolePolano());
    recetas.agregarAlFinal(crearPozoleRojo());
    recetas.agregarAlFinal(crearTamalesDeRajas());
    recetas.agregarAlFinal(crearEnchaladasSuizas());
    recetas.agregarAlFinal(crearCarneAsada());
    recetas.agregarAlFinal(crearQuesadillasFlordeCalabazo());
    recetas.agregarAlFinal(crearChilesRellenos());
    recetas.agregarAlFinal(crearCochinitaPibil());
    recetas.agregarAlFinal(crearPastelTresLeches());
    recetas.agregarAlFinal(crearSopaDeTortilla());
    recetas.agregarAlFinal(crearFajitasDePollo());
    
    return recetas;
}

Receta DatosPruebaRecetario::crearChilaquilesVerdes() {
    Nombre autorChilaquiles("Maria", "Garcia", "Lopez");
    Receta chilaquiles("Chilaquiles Verdes", autorChilaquiles, Categoria::DESAYUNO, 25,
        "1. Cortar las tortillas en triángulos\n"
        "2. Freír los triángulos en aceite caliente\n"
        "3. Cocer los tomatillos verdes\n"
        "4. Licuar tomatillos con cilantro y chile\n"
        "5. Verter salsa sobre los chilaquiles\n"
        "6. Servir con queso y crema");

    chilaquiles.agregarIngredienteOrdenado(Ingrediente("Aceite vegetal", "3", "cucharadas"));
    chilaquiles.agregarIngredienteOrdenado(Ingrediente("Agua", "1", "taza"));
    chilaquiles.agregarIngredienteOrdenado(Ingrediente("Cebolla blanca", "1/2", "pieza"));
    chilaquiles.agregarIngredienteOrdenado(Ingrediente("Cilantro fresco", "1/2", "taza"));
    chilaquiles.agregarIngredienteOrdenado(Ingrediente("Crema mexicana", "1/2", "taza"));
    chilaquiles.agregarIngredienteOrdenado(Ingrediente("Chile serrano verde", "2", "piezas"));
    chilaquiles.agregarIngredienteOrdenado(Ingrediente("Queso fresco", "200", "gramos"));
    chilaquiles.agregarIngredienteOrdenado(Ingrediente("Sal", "1", "cucharadita"));
    chilaquiles.agregarIngredienteOrdenado(Ingrediente("Tortillas de maíz", "12", "piezas"));
    chilaquiles.agregarIngredienteOrdenado(Ingrediente("Tomatillo verde", "500", "gramos"));

    return chilaquiles;
}
Receta DatosPruebaRecetario::crearMolePolano() {
    Nombre autorMole("Roberto", "Sanchez", "Martinez");
    Receta mole("Mole Poblano", autorMole, Categoria::COMIDA, 120,
        "1. Tostar los chiles\n"
        "2. Remojar chiles en agua caliente\n"
        "3. Tostar especias en comal\n"
        "4. Licuar chiles con especias\n"
        "5. Freír la pasta de mole\n"
        "6. Cocinar el pollo\n"
        "7. Combinar pollo con la salsa\n"
        "8. Servir con arroz y tortillas");

    mole.agregarIngredienteOrdenado(Ingrediente("Ajo", "6", "dientes"));
    mole.agregarIngredienteOrdenado(Ingrediente("Almendra", "1/2", "taza"));
    mole.agregarIngredienteOrdenado(Ingrediente("Anís", "1", "cucharadita"));
    mole.agregarIngredienteOrdenado(Ingrediente("Canela", "1", "rama"));
    mole.agregarIngredienteOrdenado(Ingrediente("Caldo de pollo", "1", "litro"));
    mole.agregarIngredienteOrdenado(Ingrediente("Cebolla", "1", "pieza"));
    mole.agregarIngredienteOrdenado(Ingrediente("Chocolate amargo", "100", "gramos"));
    mole.agregarIngredienteOrdenado(Ingrediente("Clavo", "4", "piezas"));
    mole.agregarIngredienteOrdenado(Ingrediente("Comino", "1/2", "cucharadita"));
    mole.agregarIngredienteOrdenado(Ingrediente("Chile pasilla", "4", "piezas"));
    mole.agregarIngredienteOrdenado(Ingrediente("Jengibre", "1", "cucharadita"));
    mole.agregarIngredienteOrdenado(Ingrediente("Mermelada", "1", "cucharada"));
    mole.agregarIngredienteOrdenado(Ingrediente("Pasita", "1/4", "taza"));
    mole.agregarIngredienteOrdenado(Ingrediente("Pechuga de pollo", "1", "pieza"));

    return mole;
}

Receta DatosPruebaRecetario::crearPozoleRojo() {
    Nombre autorPozole("Carmen", "Ruiz", "Hernandez");
    Receta pozole("Pozole Rojo", autorPozole, Categoria::COMIDA, 90,
        "1. Limpiar el maíz pozolero\n"
        "2. Cocer el maíz en agua con cal\n"
        "3. Enjuagar bien el maíz cocido\n"
        "4. Cocer el cerdo\n"
        "5. Preparar la salsa de chiles\n"
        "6. Combinar maíz y cerdo\n"
        "7. Agregar la salsa roja\n"
        "8. Servir con lechuga, orégano y tostadas");

    pozole.agregarIngredienteOrdenado(Ingrediente("Agua", "3", "litros"));
    pozole.agregarIngredienteOrdenado(Ingrediente("Ajo", "4", "dientes"));
    pozole.agregarIngredienteOrdenado(Ingrediente("Caldo de pollo", "2", "litros"));
    pozole.agregarIngredienteOrdenado(Ingrediente("Cebolla", "1", "pieza"));
    pozole.agregarIngredienteOrdenado(Ingrediente("Chile ancho", "6", "piezas"));
    pozole.agregarIngredienteOrdenado(Ingrediente("Chile guajillo", "4", "piezas"));
    pozole.agregarIngredienteOrdenado(Ingrediente("Espaldilla de cerdo", "800", "gramos"));
    pozole.agregarIngredienteOrdenado(Ingrediente("Lechuga fresca", "1/2", "pieza"));
    pozole.agregarIngredienteOrdenado(Ingrediente("Limón", "2", "piezas"));
    pozole.agregarIngredienteOrdenado(Ingrediente("Maíz pozolero", "1", "kilogramo"));
    pozole.agregarIngredienteOrdenado(Ingrediente("Orégano seco", "1", "cucharada"));
    pozole.agregarIngredienteOrdenado(Ingrediente("Sal", "2", "cucharaditas"));
    pozole.agregarIngredienteOrdenado(Ingrediente("Tostadas", "150", "gramos"));

    return pozole;
}

Receta DatosPruebaRecetario::crearTamalesDeRajas() {
    Nombre autorTamales("Ana", "Flores", "Cruz");
    Receta tamales("Tamales de Rajas", autorTamales, Categoria::DESAYUNO, 45,
        "1. Preparar la masa de maíz\n"
        "2. Asar y desvenar los chiles poblanos\n"
        "3. Rellenar los chiles con queso\n"
        "4. Preparar hojas de maíz\n"
        "5. Rellenar las hojas con masa y chile\n"
        "6. Cocer al vapor por 45 minutos\n"
        "7. Servir con salsa fresca");

    tamales.agregarIngredienteOrdenado(Ingrediente("Agua", "1.5", "tazas"));
    tamales.agregarIngredienteOrdenado(Ingrediente("Ajo", "2", "dientes"));
    tamales.agregarIngredienteOrdenado(Ingrediente("Caldo de pollo", "2", "tazas"));
    tamales.agregarIngredienteOrdenado(Ingrediente("Cebolla", "1/2", "pieza"));
    tamales.agregarIngredienteOrdenado(Ingrediente("Chile poblano", "8", "piezas"));
    tamales.agregarIngredienteOrdenado(Ingrediente("Crema", "1/2", "taza"));
    tamales.agregarIngredienteOrdenado(Ingrediente("Harina de maíz", "500", "gramos"));
    tamales.agregarIngredienteOrdenado(Ingrediente("Hojas de maíz secas", "50", "piezas"));
    tamales.agregarIngredienteOrdenado(Ingrediente("Mantequilla", "200", "gramos"));
    tamales.agregarIngredienteOrdenado(Ingrediente("Polvo de hornear", "1", "cucharadita"));
    tamales.agregarIngredienteOrdenado(Ingrediente("Queso Oaxaca", "300", "gramos"));
    tamales.agregarIngredienteOrdenado(Ingrediente("Sal", "1", "cucharadita"));

    return tamales;
}
Receta DatosPruebaRecetario::crearEnchaladasSuizas() {
    Nombre autorEnchaladas("Lupita", "Jimenez", "Vega");
    Receta enchaladas("Enchiladas Suizas", autorEnchaladas, Categoria::COMIDA, 60,
        "1. Preparar la salsa verde\n"
        "2. Cocinar el pollo desmenuzado\n"
        "3. Calentar aceite\n"
        "4. Empapar tortillas en salsa\n"
        "5. Rellenar con pollo\n"
        "6. Rodar las tortillas\n"
        "7. Cubrirlas con salsa y queso\n"
        "8. Hornear a 180°C por 20 minutos");

    enchaladas.agregarIngredienteOrdenado(Ingrediente("Aceite", "2", "cucharadas"));
    enchaladas.agregarIngredienteOrdenado(Ingrediente("Agua", "1", "taza"));
    enchaladas.agregarIngredienteOrdenado(Ingrediente("Ajo", "3", "dientes"));
    enchaladas.agregarIngredienteOrdenado(Ingrediente("Caldo de pollo", "1", "taza"));
    enchaladas.agregarIngredienteOrdenado(Ingrediente("Cebolla", "1/2", "pieza"));
    enchaladas.agregarIngredienteOrdenado(Ingrediente("Chile serrano", "3", "piezas"));
    enchaladas.agregarIngredienteOrdenado(Ingrediente("Cilantro", "1/4", "taza"));
    enchaladas.agregarIngredienteOrdenado(Ingrediente("Crema agria", "1", "taza"));
    enchaladas.agregarIngredienteOrdenado(Ingrediente("Pechuga de pollo", "500", "gramos"));
    enchaladas.agregarIngredienteOrdenado(Ingrediente("Queso blanco", "250", "gramos"));
    enchaladas.agregarIngredienteOrdenado(Ingrediente("Sal", "1", "cucharadita"));
    enchaladas.agregarIngredienteOrdenado(Ingrediente("Tomate", "4", "piezas"));
    enchaladas.agregarIngredienteOrdenado(Ingrediente("Tortillas de maíz", "12", "piezas"));

    return enchaladas;
}

Receta DatosPruebaRecetario::crearCarneAsada() {
    Nombre autorCarne("Javier", "Moreno", "Ramirez");
    Receta carneAsada("Carne Asada", autorCarne, Categoria::COMIDA, 30,
        "1. Limpiar la carne de grasa\n"
        "2. Preparar marinada\n"
        "3. Marinar la carne por 4 horas\n"
        "4. Precalentar la parrilla\n"
        "5. Asar la carne 5 minutos cada lado\n"
        "6. Reposar 5 minutos\n"
        "7. Servir con tortillas y salsa");

    carneAsada.agregarIngredienteOrdenado(Ingrediente("Aceite de oliva", "1/4", "taza"));
    carneAsada.agregarIngredienteOrdenado(Ingrediente("Ajo molido", "4", "dientes"));
    carneAsada.agregarIngredienteOrdenado(Ingrediente("Carne de res", "1", "kilogramo"));
    carneAsada.agregarIngredienteOrdenado(Ingrediente("Cilantro", "1/2", "manojo"));
    carneAsada.agregarIngredienteOrdenado(Ingrediente("Comino", "1", "cucharadita"));
    carneAsada.agregarIngredienteOrdenado(Ingrediente("Jalapeño", "2", "piezas"));
    carneAsada.agregarIngredienteOrdenado(Ingrediente("Limón", "3", "piezas"));
    carneAsada.agregarIngredienteOrdenado(Ingrediente("Orégano seco", "1", "cucharada"));
    carneAsada.agregarIngredienteOrdenado(Ingrediente("Pimienta negra", "1", "cucharadita"));
    carneAsada.agregarIngredienteOrdenado(Ingrediente("Sal", "1", "cucharada"));

    return carneAsada;
}

Receta DatosPruebaRecetario::crearQuesadillasFlordeCalabazo() {
    Nombre autorQuesadillas("Erica", "Dominguez", "Perez");
    Receta quesadillas("Quesadillas de Flor de Calabaza", autorQuesadillas, Categoria::DESAYUNO, 20,
        "1. Limpiar las flores de calabaza\n"
        "2. Picar las flores\n"
        "3. Dorar cebolla en aceite\n"
        "4. Agregar las flores\n"
        "5. Cocinar 5 minutos\n"
        "6. Calentar tortillas\n"
        "7. Rellenar con flores y queso\n"
        "8. Doblar y servir con salsa");

    quesadillas.agregarIngredienteOrdenado(Ingrediente("Aceite vegetal", "2", "cucharadas"));
    quesadillas.agregarIngredienteOrdenado(Ingrediente("Cebolla", "1/2", "pieza"));
    quesadillas.agregarIngredienteOrdenado(Ingrediente("Epazote", "4", "hojas"));
    quesadillas.agregarIngredienteOrdenado(Ingrediente("Flor de calabaza", "500", "gramos"));
    quesadillas.agregarIngredienteOrdenado(Ingrediente("Jalapeño", "1", "pieza"));
    quesadillas.agregarIngredienteOrdenado(Ingrediente("Queso Oaxaca", "200", "gramos"));
    quesadillas.agregarIngredienteOrdenado(Ingrediente("Sal", "1", "cucharadita"));
    quesadillas.agregarIngredienteOrdenado(Ingrediente("Tortillas de maíz", "8", "piezas"));

    return quesadillas;
}
Receta DatosPruebaRecetario::crearChilesRellenos() {
    Nombre autorChiles("Patricia", "Gutierrez", "Lopez");
    Receta chiles("Chiles Rellenos", autorChiles, Categoria::COMIDA, 50,
        "1. Asar los chiles\n"
        "2. Devenar los chiles cuidadosamente\n"
        "3. Preparar el relleno\n"
        "4. Rellenar los chiles\n"
        "5. Preparar la salsa de jitomate\n"
        "6. Batir las claras\n"
        "7. Freír los chiles capados\n"
        "8. Servir cubiertos con salsa");

    chiles.agregarIngredienteOrdenado(Ingrediente("Aceite para freír", "500", "mililitros"));
    chiles.agregarIngredienteOrdenado(Ingrediente("Ajo", "2", "dientes"));
    chiles.agregarIngredienteOrdenado(Ingrediente("Caldo de pollo", "1", "taza"));
    chiles.agregarIngredienteOrdenado(Ingrediente("Cebolla", "1/2", "pieza"));
    chiles.agregarIngredienteOrdenado(Ingrediente("Claras de huevo", "6", "piezas"));
    chiles.agregarIngredienteOrdenado(Ingrediente("Harina", "1", "cucharada"));
    chiles.agregarIngredienteOrdenado(Ingrediente("Jitomate", "6", "piezas"));
    chiles.agregarIngredienteOrdenado(Ingrediente("Queso blanco", "300", "gramos"));
    chiles.agregarIngredienteOrdenado(Ingrediente("Sal", "1", "cucharadita"));
    chiles.agregarIngredienteOrdenado(Ingrediente("Yemas de huevo", "6", "piezas"));
    chiles.agregarIngredienteOrdenado(Ingrediente("Chile poblano", "10", "piezas"));

    return chiles;
}

Receta DatosPruebaRecetario::crearCochinitaPibil() {
    Nombre autorCochinita("Ignacio", "Martinez", "Soto");
    Receta cochinita("Cochinita Pibil", autorCochinita, Categoria::COMIDA, 180,
        "1. Asar los achiotes\n"
        "2. Hacer pasta con achiote\n"
        "3. Marinar la carne\n"
        "4. Preparar papel aluminio\n"
        "5. Envolver la carne\n"
        "6. Hornear 3 horas a 160°C\n"
        "7. Desmuzar la carne\n"
        "8. Servir con tortillas y cebolla morada");

    cochinita.agregarIngredienteOrdenado(Ingrediente("Achiote", "3", "cucharadas"));
    cochinita.agregarIngredienteOrdenado(Ingrediente("Agua", "1/2", "taza"));
    cochinita.agregarIngredienteOrdenado(Ingrediente("Ajo", "8", "dientes"));
    cochinita.agregarIngredienteOrdenado(Ingrediente("Canela", "1/2", "cucharadita"));
    cochinita.agregarIngredienteOrdenado(Ingrediente("Cebolla morada", "2", "piezas"));
    cochinita.agregarIngredienteOrdenado(Ingrediente("Clavo", "2", "piezas"));
    cochinita.agregarIngredienteOrdenado(Ingrediente("Comino", "1", "cucharadita"));
    cochinita.agregarIngredienteOrdenado(Ingrediente("Limón agrio", "3", "piezas"));
    cochinita.agregarIngredienteOrdenado(Ingrediente("Orégano", "1", "cucharadita"));
    cochinita.agregarIngredienteOrdenado(Ingrediente("Paleta de cerdo", "2", "kilogramos"));
    cochinita.agregarIngredienteOrdenado(Ingrediente("Pimienta", "1", "cucharadita"));
    cochinita.agregarIngredienteOrdenado(Ingrediente("Sal", "2", "cucharaditas"));

    return cochinita;
}

Receta DatosPruebaRecetario::crearPastelTresLeches() {
    Nombre autorPastel("Valentina", "Solis", "Navarro");
    Receta pastel("Pastel de Tres Leches", autorPastel, Categoria::NAVIDENO, 40,
        "1. Preparar la masa esponjosa\n"
        "2. Hornear la masa 25 minutos\n"
        "3. Enfriar la masa\n"
        "4. Mezclar las tres leches\n"
        "5. Humedecer el pastel con la mezcla\n"
        "6. Preparar la crema batida\n"
        "7. Cubrir el pastel\n"
        "8. Decorar con fresas y refrigerar");

    pastel.agregarIngredienteOrdenado(Ingrediente("Azúcar", "1", "taza"));
    pastel.agregarIngredienteOrdenado(Ingrediente("Claras de huevo", "5", "piezas"));
    pastel.agregarIngredienteOrdenado(Ingrediente("Crema Evaporada", "1", "lata"));
    pastel.agregarIngredienteOrdenado(Ingrediente("Crema Lechera", "1", "lata"));
    pastel.agregarIngredienteOrdenado(Ingrediente("Crema fresca", "1", "taza"));
    pastel.agregarIngredienteOrdenado(Ingrediente("Esencia de vainilla", "1", "cucharadita"));
    pastel.agregarIngredienteOrdenado(Ingrediente("Fresa fresca", "500", "gramos"));
    pastel.agregarIngredienteOrdenado(Ingrediente("Harina de trigo", "1", "taza"));
    pastel.agregarIngredienteOrdenado(Ingrediente("Leche condensada", "1", "lata"));
    pastel.agregarIngredienteOrdenado(Ingrediente("Polvo de hornear", "1", "cucharadita"));
    pastel.agregarIngredienteOrdenado(Ingrediente("Yema de huevo", "5", "piezas"));

    return pastel;
}
Receta DatosPruebaRecetario::crearSopaDeTortilla() {
    Nombre autorSopa("Guadalupe", "Reyes", "Aguirre");
    Receta sopa("Sopa de Tortilla", autorSopa, Categoria::COMIDA, 35,
        "1. Preparar el caldo\n"
        "2. Cocinar jitomates y cebolla\n"
        "3. Licuar jitomates\n"
        "4. Colar la sopa\n"
        "5. Cortar tortillas en tiras\n"
        "6. Freír las tiras de tortilla\n"
        "7. Verter caldo sobre tortillas\n"
        "8. Agregar aguacate, queso y crema");

    sopa.agregarIngredienteOrdenado(Ingrediente("Aguacate", "1", "pieza"));
    sopa.agregarIngredienteOrdenado(Ingrediente("Ajo", "2", "dientes"));
    sopa.agregarIngredienteOrdenado(Ingrediente("Caldo de pollo", "2", "litros"));
    sopa.agregarIngredienteOrdenado(Ingrediente("Cebolla", "1/2", "pieza"));
    sopa.agregarIngredienteOrdenado(Ingrediente("Chile guajillo", "2", "piezas"));
    sopa.agregarIngredienteOrdenado(Ingrediente("Crema mexicana", "1/2", "taza"));
    sopa.agregarIngredienteOrdenado(Ingrediente("Jitomate maduro", "6", "piezas"));
    sopa.agregarIngredienteOrdenado(Ingrediente("Limón", "1", "pieza"));
    sopa.agregarIngredienteOrdenado(Ingrediente("Queso fresco", "150", "gramos"));
    sopa.agregarIngredienteOrdenado(Ingrediente("Sal", "1", "cucharadita"));
    sopa.agregarIngredienteOrdenado(Ingrediente("Tortillas de maíz", "8", "piezas"));

    return sopa;
}

Receta DatosPruebaRecetario::crearFajitasDePollo() {
    Nombre autorFajitas("Fernando", "Castillo", "Romero");
    Receta fajitas("Fajitas de Pollo", autorFajitas, Categoria::COMIDA, 45,
        "1. Limpiar el pollo\n"
        "2. Preparar marinada\n"
        "3. Marinar 2 horas\n"
        "4. Cortar pimientos\n"
        "5. Precalentar parrilla\n"
        "6. Asar pollo 8 minutos\n"
        "7. Asar verduras\n"
        "8. Servir con tortillas calientes");

    fajitas.agregarIngredienteOrdenado(Ingrediente("Aceite de oliva", "3", "cucharadas"));
    fajitas.agregarIngredienteOrdenado(Ingrediente("Ajo", "3", "dientes"));
    fajitas.agregarIngredienteOrdenado(Ingrediente("Cebolla", "2", "piezas"));
    fajitas.agregarIngredienteOrdenado(Ingrediente("Cilantro", "1/4", "manojo"));
    fajitas.agregarIngredienteOrdenado(Ingrediente("Comino", "1", "cucharadita"));
    fajitas.agregarIngredienteOrdenado(Ingrediente("Jalapeño", "2", "piezas"));
    fajitas.agregarIngredienteOrdenado(Ingrediente("Limón", "2", "piezas"));
    fajitas.agregarIngredienteOrdenado(Ingrediente("Orégano", "1", "cucharadita"));
    fajitas.agregarIngredienteOrdenado(Ingrediente("Pimiento rojo", "2", "piezas"));
    fajitas.agregarIngredienteOrdenado(Ingrediente("Pimiento verde", "2", "piezas"));
    fajitas.agregarIngredienteOrdenado(Ingrediente("Pollo pechuga", "1", "kilogramo"));
    fajitas.agregarIngredienteOrdenado(Ingrediente("Sal", "1", "cucharada"));
    fajitas.agregarIngredienteOrdenado(Ingrediente("Tortillas de trigo", "16", "piezas"));

    return fajitas;
}