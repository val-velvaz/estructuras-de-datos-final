#pragma once
#include "ui/GameState.hpp"
#include "Game.hpp"

class PantallaAgregarReceta : public GameState {
private:
    TTF_Font* fuenteInfo;
    SDL_Texture* texInfo;
    SDL_FRect rectInfo;

public:
    PantallaAgregarReceta() : fuenteInfo(nullptr), texInfo(nullptr) {}
    virtual ~PantallaAgregarReceta() { cleanup(); }

    virtual void init(Game& game) override;
    virtual void cleanup() override;
    virtual void handleEvents(Game& game) override;
    virtual void update(Game& game) override;
    virtual void render(Game& game) override;
};