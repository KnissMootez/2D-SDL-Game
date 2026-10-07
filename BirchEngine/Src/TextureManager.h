#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* ren);
    static void SetTexture(SDL_Texture* texture, SDL_Renderer* ren, const char* fileName);
};
