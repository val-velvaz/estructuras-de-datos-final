#include "ui/PantallaMenuPrincipal.hpp"
#include "ui/PantallaVisualizarRecetas.hpp"
#include "persistence/RutasAssets.hpp"
#include <iostream>

PantallaMenuPrincipal::PantallaMenuPrincipal() 
    : fuenteTitulo(nullptr), texturaTitulo(nullptr), texBotonAgregar(nullptr), texBotonVer(nullptr), texBotonSalir(nullptr) {
    rectTitulo = {0,0,0,0};
    rectBotonAgregar = {0,0,0,0};
    rectBotonVer = {0,0,0,0};
    rectBotonSalir = {0,0,0,0};
}

PantallaMenuPrincipal::~PantallaMenuPrincipal() {
    cleanup();
}

bool PantallaMenuPrincipal::puntoEnRectangulo(float x, float y, const SDL_FRect& rect) {
    return (x >= rect.x && x <= (rect.x + rect.w) &&
            y >= rect.y && y <= (rect.y + rect.h));
}


void PantallaMenuPrincipal::init(Game& game) {
    SDL_Renderer* renderer = game.getRenderer();
    
    int ancho, alto;
    SDL_GetRenderOutputSize(renderer, &ancho, &alto);

    // 1. Cargar Título
    std::string rutaFuente = RutasAssets::obtenerRutaFuenteNegrita();
    fuenteTitulo = TTF_OpenFont(rutaFuente.c_str(), 48);
    
    if (fuenteTitulo) {
        SDL_Color color = { 80, 80, 80, 255 };
        SDL_Surface* sup = TTF_RenderText_Blended(fuenteTitulo, "RECETARIO DE LA ABUELA", 0, color);
        if (sup) {
            texturaTitulo = SDL_CreateTextureFromSurface(renderer, sup);
            rectTitulo.w = (float)sup->w;
            rectTitulo.h = (float)sup->h;
            rectTitulo.x = (ancho - rectTitulo.w) / 2.0f;
            rectTitulo.y = 80.0f;
            SDL_DestroySurface(sup);
        }
    } else {
        std::cerr << "[ERROR] No se pudo cargar fuente: " << rutaFuente 
                  << " | Error: " << SDL_GetError() << std::endl;
    }

    // 2. Cargar Botones (Con Debugging)
    float tamBoton = 100.0f; 
    float espaciado = 50.0f;
    float totalAncho = (tamBoton * 3) + (espaciado * 2);
    float xInicial = (ancho - totalAncho) / 2.0f;
    float yBotones = 300.0f;

    // Helper para cargar y reportar errores
    auto cargarTextura = [&](const std::string& ruta) -> SDL_Texture* {
        SDL_Texture* tex = IMG_LoadTexture(renderer, ruta.c_str());
        if (!tex) {
            std::cerr << "[ERROR] Faltante: " << ruta << " | " << SDL_GetError() << std::endl;
        } else {
            std::cout << "[OK] Cargado: " << ruta << std::endl;
        }
        return tex;
    };

    texBotonAgregar = cargarTextura(RutasAssets::obtenerRutaIconoBotonAgregar());
    rectBotonAgregar = { xInicial, yBotones, tamBoton, tamBoton };

    texBotonVer = cargarTextura(RutasAssets::obtenerRutaIconoBotonGuardar()); // Placeholder para "Ver"
    rectBotonVer = { xInicial + tamBoton + espaciado, yBotones, tamBoton, tamBoton };

    texBotonSalir = cargarTextura(RutasAssets::obtenerRutaIconoBotonEliminar());
    rectBotonSalir = { xInicial + (tamBoton + espaciado) * 2, yBotones, tamBoton, tamBoton };
}


void PantallaMenuPrincipal::cleanup() {
    if (texturaTitulo) SDL_DestroyTexture(texturaTitulo);
    if (texBotonAgregar) SDL_DestroyTexture(texBotonAgregar);
    if (texBotonVer) SDL_DestroyTexture(texBotonVer);
    if (texBotonSalir) SDL_DestroyTexture(texBotonSalir);
    
    if (fuenteTitulo) TTF_CloseFont(fuenteTitulo);

    texturaTitulo = nullptr;
    texBotonAgregar = nullptr;
    texBotonVer = nullptr;
    texBotonSalir = nullptr;
    fuenteTitulo = nullptr;
}

void PantallaMenuPrincipal::handleEvents(Game& game) {
    SDL_Event evento;
    while (SDL_PollEvent(&evento)) {
        if (evento.type == SDL_EVENT_QUIT) {
            game.setEstaCorriendo(false);
        }
        else if (evento.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
            if (evento.button.button == SDL_BUTTON_LEFT) {
                float mx = evento.button.x;
                float my = evento.button.y;

                if (puntoEnRectangulo(mx, my, rectBotonSalir)) {
                    std::cout << "Salir..." << std::endl;
                    game.setEstaCorriendo(false);
                }
                else if (puntoEnRectangulo(mx, my, rectBotonAgregar)) {
                    std::cout << "TODO: Ir a Pantalla Agregar" << std::endl;
                }
                else if (puntoEnRectangulo(mx, my, rectBotonVer)) {
                    std::cout << "Ver Recetas..." << std::endl;
                    game.cambiarEstado(new PantallaVisualizarRecetas());
                }
            }
        }
    }
}

void PantallaMenuPrincipal::update(Game& game) {
}

void PantallaMenuPrincipal::render(Game& game) {
    SDL_Renderer* renderer = game.getRenderer();

    // Dibujar Título
    if (texturaTitulo) SDL_RenderTexture(renderer, texturaTitulo, nullptr, &rectTitulo);

    // Dibujar Botones
    if (texBotonAgregar) SDL_RenderTexture(renderer, texBotonAgregar, nullptr, &rectBotonAgregar);
    if (texBotonVer) SDL_RenderTexture(renderer, texBotonVer, nullptr, &rectBotonVer);
    if (texBotonSalir) SDL_RenderTexture(renderer, texBotonSalir, nullptr, &rectBotonSalir);
}