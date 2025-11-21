#include "ui/PantallaAgregarReceta.hpp"
#include "ui/PantallaMenuPrincipal.hpp"
#include "persistence/RutasAssets.hpp"
#include <iostream>

void PantallaAgregarReceta::init(Game& game) {
    SDL_Renderer* renderer = game.getRenderer();
    std::string rutaFuente = RutasAssets::obtenerRutaFuenteRegular();
    fuenteInfo = TTF_OpenFont(rutaFuente.c_str(), 24);

    if (fuenteInfo) {
        SDL_Color color = { 50, 50, 50, 255 };
        // Mensaje simple
        const char* mensaje = "Presiona [ENTER] para agregar una receta de prueba\nPresiona [ESC] para volver";
        SDL_Surface* sup = TTF_RenderText_Blended_Wrapped(fuenteInfo, mensaje, 0, color, 800);
        if (sup) {
            texInfo = SDL_CreateTextureFromSurface(renderer, sup);
            rectInfo = { 100, 200, (float)sup->w, (float)sup->h };
            SDL_DestroySurface(sup);
        }
    }
}

void PantallaAgregarReceta::cleanup() {
    if (texInfo) SDL_DestroyTexture(texInfo);
    if (fuenteInfo) TTF_CloseFont(fuenteInfo);
}

void PantallaAgregarReceta::handleEvents(Game& game) {
    SDL_Event evento;
    while (SDL_PollEvent(&evento)) {
        if (evento.type == SDL_EVENT_QUIT) {
            game.setEstaCorriendo(false);
        }
        else if (evento.type == SDL_EVENT_KEY_DOWN) {
            // Volver con ESC
            if (evento.key.key == SDLK_ESCAPE) {
                game.cambiarEstado(new PantallaMenuPrincipal());
            }
            // Agregar con ENTER
            else if (evento.key.key == SDLK_RETURN) {
                // --- LOGICA DE AGREGAR ---
                try {
                    std::cout << "Agregando receta..." << std::endl;
                    
                    // Crear receta dummy
                    Receta nueva("Chilaquiles " + std::to_string(rand() % 100), 
                                 Nombre("Juan", "Perez"), 
                                 Categoria::DESAYUNO, 
                                 45, 
                                 "1. Freir tortillas.\n2. Echar salsa.");
                    
                    // Guardar en el manejador
                    game.getManejadorRecetas().agregarRecetaNueva(nueva);
                    
                    std::cout << "Receta agregada con exito!" << std::endl;
                    game.cambiarEstado(new PantallaMenuPrincipal());
                    
                } catch (const std::exception& e) {
                    std::cerr << "Error al agregar: " << e.what() << std::endl;
                }
            }
        }
    }
}

void PantallaAgregarReceta::update(Game& game) {}

void PantallaAgregarReceta::render(Game& game) {
    SDL_Renderer* renderer = game.getRenderer();
    if (texInfo) SDL_RenderTexture(renderer, texInfo, nullptr, &rectInfo);
}