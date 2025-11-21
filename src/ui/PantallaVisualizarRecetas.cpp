#include "ui/PantallaVisualizarRecetas.hpp"
#include "ui/PantallaMenuPrincipal.hpp" 
#include "persistence/RutasAssets.hpp"
#include <iostream>
#include <string>

PantallaVisualizarRecetas::PantallaVisualizarRecetas()
    : fuenteTitulo(nullptr), fuenteListado(nullptr), texTitulo(nullptr), texBotonVolver(nullptr) {}

PantallaVisualizarRecetas::~PantallaVisualizarRecetas() {
    cleanup();
}

void PantallaVisualizarRecetas::init(Game& game) {
    SDL_Renderer* renderer = game.getRenderer();
    
    fuenteTitulo = TTF_OpenFont(RutasAssets::obtenerRutaFuenteNegrita().c_str(), 36);
    fuenteListado = TTF_OpenFont(RutasAssets::obtenerRutaFuenteRegular().c_str(), 24);

    if (fuenteTitulo) {
        SDL_Color color = { 80, 80, 80, 255 };
        SDL_Surface* sup = TTF_RenderText_Blended(fuenteTitulo, "MIS RECETAS", 0, color);
        if (sup) {
            texTitulo = SDL_CreateTextureFromSurface(renderer, sup);
            rectTitulo = { 50, 30, (float)sup->w, (float)sup->h }; 
            SDL_DestroySurface(sup);
        }
    }

    texBotonVolver = IMG_LoadTexture(renderer, RutasAssets::obtenerRutaIconoBotonVolver().c_str());
    rectBotonVolver = { 950, 30, 50, 50 }; 

    generarCacheListado(game);
}

void PantallaVisualizarRecetas::generarCacheListado(Game& game) {
    // Limpiar caché anterior
    for (auto& item : itemsRenderizados) {
        if (item.textura) SDL_DestroyTexture(item.textura);
    }
    itemsRenderizados.clear();

    const auto& listaRecetas = game.getManejadorRecetas().obtenerTodasLasRecetas();
    int cantidad = listaRecetas.obtenerCantidadElementos();
    SDL_Renderer* renderer = game.getRenderer();
    SDL_Color colorTexto = { 50, 50, 100, 255 }; 

    float posY = 100.0f; 

    for (int i = 0; i < cantidad; ++i) {
        Receta receta = listaRecetas.obtenerEnPosicion(i);
        std::string texto = std::to_string(i + 1) + ". " + receta.obtenerNombrePlatillo();
        
        texto += " (" + std::to_string(receta.obtenerTiempoPreparacion()) + " mins)";

        if (fuenteListado) {
            SDL_Surface* sup = TTF_RenderText_Blended(fuenteListado, texto.c_str(), 0, colorTexto);
            if (sup) {
                ItemLista newItem;
                newItem.textura = SDL_CreateTextureFromSurface(renderer, sup);
                newItem.rect = { 60, posY, (float)sup->w, (float)sup->h };
                itemsRenderizados.push_back(newItem);
                
                SDL_DestroySurface(sup);
                posY += 40.0f; 
            }
        }
    }

    if (cantidad == 0 && fuenteListado) {
        SDL_Color colorGris = { 150, 150, 150, 255 };
        SDL_Surface* sup = TTF_RenderText_Blended(fuenteListado, "(El recetario esta vacio)", 0, colorGris);
        if (sup) {
            ItemLista newItem;
            newItem.textura = SDL_CreateTextureFromSurface(renderer, sup);
            newItem.rect = { 60, posY, (float)sup->w, (float)sup->h };
            itemsRenderizados.push_back(newItem);
            SDL_DestroySurface(sup);
        }
    }
}

void PantallaVisualizarRecetas::cleanup() {
    if (texTitulo) SDL_DestroyTexture(texTitulo);
    if (texBotonVolver) SDL_DestroyTexture(texBotonVolver);
    if (fuenteTitulo) TTF_CloseFont(fuenteTitulo);
    if (fuenteListado) TTF_CloseFont(fuenteListado);

    // Limpiar lista cacheada
    for (auto& item : itemsRenderizados) {
        if (item.textura) SDL_DestroyTexture(item.textura);
    }
    itemsRenderizados.clear();
}

bool PantallaVisualizarRecetas::puntoEnRectangulo(float x, float y, const SDL_FRect& rect) {
    return (x >= rect.x && x <= (rect.x + rect.w) &&
            y >= rect.y && y <= (rect.y + rect.h));
}

void PantallaVisualizarRecetas::handleEvents(Game& game) {
    SDL_Event evento;
    while (SDL_PollEvent(&evento)) {
        if (evento.type == SDL_EVENT_QUIT) {
            game.setEstaCorriendo(false);
        }
        else if (evento.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
            if (evento.button.button == SDL_BUTTON_LEFT) {
                float mx = evento.button.x;
                float my = evento.button.y;

                if (puntoEnRectangulo(mx, my, rectBotonVolver)) {
                    game.cambiarEstado(new PantallaMenuPrincipal());
                }
            }
        }
    }
}

void PantallaVisualizarRecetas::update(Game& game) {
}

void PantallaVisualizarRecetas::render(Game& game) {
    SDL_Renderer* renderer = game.getRenderer();

    if (texTitulo) SDL_RenderTexture(renderer, texTitulo, nullptr, &rectTitulo);
    if (texBotonVolver) SDL_RenderTexture(renderer, texBotonVolver, nullptr, &rectBotonVolver);

    for (const auto& item : itemsRenderizados) {
        SDL_RenderTexture(renderer, item.textura, nullptr, &item.rect);
    }
}