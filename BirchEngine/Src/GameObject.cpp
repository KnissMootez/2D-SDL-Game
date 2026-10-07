// GameObject.cpp
#include "TextureManager.h"
#include "GameObject.h"
#include <iostream>

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y, int destWidth, int destHeight)
    : xpos(x), ypos(y), renderer(ren), width(0), height(0) {
    objTexture = TextureManager::LoadTexture(texturesheet, ren);

    // Get the dimensions of the loaded texture
    SDL_QueryTexture(objTexture, NULL, NULL, &width, &height);

    srcRect.h = height;
    srcRect.w = width;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = destWidth;
    destRect.h = destHeight;
}

GameObject::~GameObject() {}

void GameObject::Update(int height, int width) {
    SDL_ShowCursor(SDL_ENABLE);
        xpos++;
        ypos++;

        srcRect.h = height;
        srcRect.w = width;
        srcRect.x = 0;
        srcRect.y = 0;

        destRect.x = xpos;
        destRect.y = ypos;
        destRect.w = width / 2.5;
        destRect.h = height / 2.5;
}

void GameObject::Render() {
    SDL_RenderCopyEx(renderer, objTexture, &srcRect, &destRect, 0.0, NULL, SDL_FLIP_NONE);
}

//EventData GameObject::handleEvent(const SDL_Event& event) {
    // Event handling logic
//}

bool GameObject::isPointInsideRect(SDL_Rect rect) {
    // Check if the point is inside the rectangle defined by the destination rectangle
    return (rect.x >= destRect.x && rect.x <= destRect.x + destRect.w && rect.y >= destRect.y && rect.y <= destRect.y + destRect.h);
}
