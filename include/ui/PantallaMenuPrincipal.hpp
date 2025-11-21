#pragma once
#include "ui/GameState.hpp"
#include "Game.hpp" 

class PantallaMenuPrincipal : public GameState {
private:
    TTF_Font* fuenteTitulo;
    SDL_Texture* texturaTitulo;
    SDL_FRect rectTitulo;

    SDL_Texture* texBotonAgregar;
    SDL_FRect rectBotonAgregar;

    SDL_Texture* texBotonVer;
    SDL_FRect rectBotonVer;

    SDL_Texture* texBotonSalir;
    SDL_FRect rectBotonSalir;

    bool puntoEnRectangulo(float x, float y, const SDL_FRect& rect);

public:
    PantallaMenuPrincipal();
    virtual ~PantallaMenuPrincipal();

    virtual void init(Game& game) override;
    virtual void cleanup() override;
    virtual void handleEvents(Game& game) override;
    virtual void update(Game& game) override;
    virtual void render(Game& game) override;
};