#include "Button.h"
void Button::ChangeButton(const char* texturesheet) {
    // Load the new texture
    SDL_Surface* surface = IMG_Load(texturesheet);
    if (!surface) {
        // Handle error
        std::cerr << "Failed to load texture: " << IMG_GetError() << std::endl;
        return;
    }

    // Free the existing texture
    if (objTexture) {
        SDL_DestroyTexture(objTexture);
    }

    // Create new texture from surface
    objTexture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!objTexture) {
        // Handle error
        std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
    }

    // Free the surface
    SDL_FreeSurface(surface);
}