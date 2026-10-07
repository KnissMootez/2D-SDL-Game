// GameObject.h

#pragma once

#include "SDL.h"
#include "Vector2D.h"
#include "TextureManager.h"
#include "Game.h"
// Enumeration for event types
enum class EventType {
    None,
    MouseButtonDown,
    KeyDown
};

// Structure to hold event information
struct EventData {
    EventType eventType;
    Vector2D mousePosition; // Only used for mouse events
    SDL_Keycode keyCode;    // Only used for keyboard events
};
class GameObject : public TextureManager {
public:
    GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y, int destWidth, int destHeight);
    ~GameObject();

    void Update(int height, int width);
    void Render();
    EventData handleEvent(const SDL_Event& event);

    // Function to check if a point is inside the rectangle defined by the destination rectangle
    bool isPointInsideRect(SDL_Rect rect);
    SDL_Rect srcRect, destRect;
    int xpos;
    int ypos;

    int width; // Width of the object texture
    int height; // Height of the object texture

    SDL_Texture* objTexture;
    SDL_Renderer* renderer;
};
