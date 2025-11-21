#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h> 
#include <SDL3_ttf/SDL_ttf.h>  
#include <string>
#include "datastructures/templates/PilaDinamica.hpp"
#include "datastructures/managers/ManejadorRecetas.hpp"
#include "ui/GameState.hpp"

class GameState; 

class Game {
private:
    SDL_Window* ventana;
    SDL_Renderer* renderer;

    bool estaCorriendo;
    PilaDinamica<GameState*> estadosJuego; 
    
    ManejadorRecetas manejadorRecetas;
    const std::string RUTA_ARCHIVO_RECETAS = "assets/data/recetario.dat";

    void inicializarSDL();
    void cargarDatos();
    void limpiar();
    
    void procesarEventos();
    void actualizar();
    void dibujar();

public:
    Game();
    ~Game();

    void run();

    void pushEstado(GameState* estado);
    void popEstado();
    void cambiarEstado(GameState* estado);

    SDL_Renderer* getRenderer() { return renderer; }
    ManejadorRecetas& getManejadorRecetas() { return manejadorRecetas; }
    bool estaCorriendoApp() const { return estaCorriendo; }
    
    void setEstaCorriendo(bool valor) { estaCorriendo = valor; }
};