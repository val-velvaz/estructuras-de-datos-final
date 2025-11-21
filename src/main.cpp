#include <SDL3/SDL.h>       
#include <SDL3/SDL_main.h>  
#include "Game.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    try {
        Game recetarioGame;
        if (recetarioGame.estaCorriendoApp()) {
            recetarioGame.run();
        }
    } catch (const std::exception& e) {
        std::cerr << "Error catastrofico: " << e.what() << std::endl;
        return -1;
    } catch (...) {
        std::cerr << "Error desconocido." << std::endl;
        return -1;
    }
    return 0;
}