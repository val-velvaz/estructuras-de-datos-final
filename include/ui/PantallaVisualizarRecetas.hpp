#pragma once
#include "ui/GameState.hpp"
#include "Game.hpp"
#include <vector>

class PantallaVisualizarRecetas : public GameState {
private:
    TTF_Font* fuenteTitulo;
    TTF_Font* fuenteListado;
    SDL_Texture* texTitulo;
    SDL_FRect rectTitulo;

    SDL_Texture* texBotonVolver;
    SDL_FRect rectBotonVolver;

    struct ItemLista {
        SDL_Texture* textura;
        SDL_FRect rect;
    };
    std::vector<ItemLista> itemsRenderizados;

    void generarCacheListado(Game& game);
    bool puntoEnRectangulo(float x, float y, const SDL_FRect& rect);

public:
    PantallaVisualizarRecetas();
    virtual ~PantallaVisualizarRecetas();

    virtual void init(Game& game) override;
    virtual void cleanup() override;
    virtual void handleEvents(Game& game) override;
    virtual void update(Game& game) override;
    virtual void render(Game& game) override;
};