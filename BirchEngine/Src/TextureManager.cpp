#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture, SDL_Renderer* ren)
{
    SDL_Surface* tempSurface = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
    SDL_FreeSurface(tempSurface);
    return tex;
}

void TextureManager::SetTexture(SDL_Texture* texture, SDL_Renderer* ren, const char* fileName)
{
    // Load the new texture
    SDL_Surface* surface = IMG_Load(fileName);
    if (!surface) {
        // Handle error
        std::cerr << "Failed to load texture: " << IMG_GetError() << std::endl;
        return;
    }

    // Create texture from surface
    SDL_Texture* newTex = SDL_CreateTextureFromSurface(ren, surface);
    if (!newTex) {
        // Handle error
        std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(surface);
        return;
    }

    // Copy the pixels to the existing texture
    SDL_SetRenderTarget(ren, texture);
    SDL_RenderCopy(ren, newTex, NULL, NULL);
    SDL_SetRenderTarget(ren, NULL);

    // Free the new texture
    SDL_DestroyTexture(newTex);

    // Free the surface
    SDL_FreeSurface(surface);
}
