#include "Game.hpp"
#include "ui/PantallaMenuPrincipal.hpp"
#include <iostream>
#include <stdexcept>

Game::Game() : ventana(nullptr), renderer(nullptr), estaCorriendo(false) {
    try {
        inicializarSDL();
        cargarDatos();
        
        this->estaCorriendo = true;
        
        pushEstado(new PantallaMenuPrincipal()); 
        
        std::cout << "Sistema inicializado correctamente." << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error fatal durante la inicializacion: " << e.what() << std::endl;
        this->estaCorriendo = false;
    }
}

Game::~Game() {
    limpiar();
}

void Game::inicializarSDL() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        throw std::runtime_error(std::string("Error al inicializar SDL: ") + SDL_GetError());
    }

    ventana = SDL_CreateWindow("Recetario Interactivo (EDA)", 1024, 768, 0);
    if (!ventana) throw std::runtime_error("Error creando ventana: " + std::string(SDL_GetError()));

    renderer = SDL_CreateRenderer(ventana, NULL);
    if (!renderer) throw std::runtime_error("Error creando renderer: " + std::string(SDL_GetError()));
    
    SDL_SetRenderVSync(renderer, 1);
    SDL_SetRenderDrawColor(renderer, 255, 230, 230, 255); // Rosa pastel

    if (!TTF_Init()) {
        throw std::runtime_error("Error al inicializar TTF: " + std::string(SDL_GetError()));
    }
}

void Game::cargarDatos() {
    try {
        manejadorRecetas.cargarRecetasDesdeArchivo(RUTA_ARCHIVO_RECETAS);
        std::cout << "Recetas cargadas: " << manejadorRecetas.obtenerCantidadRecetas() << std::endl;
    } catch (...) {
        std::cout << "Iniciando recetario vacio (Archivo no encontrado o nuevo)." << std::endl;
    }
}

// [En Game.cpp]

void Game::limpiar() {
    // --- ¡QUITAR COMENTARIO DE ESTE BLOQUE! ---
    try {
        std::cout << "Guardando recetas..." << std::endl;
        manejadorRecetas.guardarRecetasAarchivo(RUTA_ARCHIVO_RECETAS);
        std::cout << "Recetas guardadas exitosamente." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error al guardar recetas: " << e.what() << std::endl;
    }
    // --- FIN DEL BLOQUE A MODIFICAR ---

    // Limpiar estados de la FSM
    while (!estadosJuego.estaVacia()) {
        try {
            GameState* estadoActual = estadosJuego.consultarTope();
            if (estadoActual) {
                estadoActual->cleanup();
                delete estadoActual;
                // Opcional: Para mayor seguridad, aunque delete ya lo hace.
                // estadoActual = nullptr; 
            }
        } catch (const std::exception& e) {
            // ¡Nunca ignores errores críticos durante el apagado!
            std::cerr << "Error critico durante cleanup del estado: " 
                      << e.what() << std::endl;
        } catch (...) {
            std::cerr << "Error critico desconocido durante cleanup del estado." << std::endl;
        }
        
        // Desapilar siempre, fuera del try-catch, para evitar bucles
        // infinitos si consultarTope() funciona pero desapilar() no.
        try {
            estadosJuego.desapilar();
        } catch (const std::exception& e) {
             std::cerr << "Error critico al desapilar estado: " 
                       << e.what() << std::endl;
             // Si desapilar falla, estamos en problemas. Rompemos el bucle
             // para evitar un bucle infinito de limpieza.
             break; 
        }
    }

    // Destruir recursos de SDL
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    if (ventana) {
        SDL_DestroyWindow(ventana);
        ventana = nullptr;
    }
    
    TTF_Quit();
    // IMG_Quit(); // IMG_Quit es opcional en SDL3, se maneja internamente.
    SDL_Quit();
    
    std::cout << "SDL limpiado correctamente. Adios." << std::endl;
}

void Game::procesarEventos() {
    if (!estadosJuego.estaVacia()) {
        estadosJuego.consultarTope()->handleEvents(*this);
    }
}

void Game::actualizar() {
    if (!estadosJuego.estaVacia()) {
        estadosJuego.consultarTope()->update(*this);
    }
}

void Game::dibujar() {
    SDL_SetRenderDrawColor(renderer, 255, 230, 230, 255); // Limpiar con rosa
    SDL_RenderClear(renderer);

    if (!estadosJuego.estaVacia()) {
        estadosJuego.consultarTope()->render(*this);
    }

    SDL_RenderPresent(renderer);
}

void Game::pushEstado(GameState* estado) {
    estadosJuego.apilar(estado);
    estadosJuego.consultarTope()->init(*this);
}

void Game::popEstado() {
    if (!estadosJuego.estaVacia()) {
        estadosJuego.consultarTope()->cleanup();
        delete estadosJuego.consultarTope();
        estadosJuego.desapilar();
    }
}

void Game::cambiarEstado(GameState* estado) {
    popEstado();
    pushEstado(estado);
}

void Game::run() {
    // El bucle se mantiene mientras "estaCorriendo" sea verdad
    while (estaCorriendo) {
        
        // --- INICIO DE MODIFICACIÓN (PROGRAMACIÓN DEFENSIVA) ---
        // Si por cualquier motivo la pila de estados se queda vacía
        // (ej. hicimos pop al último estado), debemos terminar la aplicación
        // para evitar el bucle infinito que congela el sistema.
        if (estadosJuego.estaVacia()) {
            std::cout << "Diagnostico: Pila de estados vacia detectada. Terminando aplicacion..." << std::endl;
            estaCorriendo = false; // Forzamos la salida del bucle
            continue; // Saltamos a la siguiente (y última) comprobación del while
        }
        // --- FIN DE MODIFICACIÓN ---

        procesarEventos();
        actualizar();
        dibujar();
    }
}