#pragma once

class Game; 

class GameState {
public:
    virtual ~GameState() {}
    virtual void init(Game& game) = 0;
    virtual void cleanup() = 0;
    virtual void handleEvents(Game& game) = 0;
    virtual void update(Game& game) = 0;
    virtual void render(Game& game) = 0;

protected:
    GameState() {}
};