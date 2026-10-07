#pragma once
#include "GameObject.h"
class Button : public GameObject
{
public:
	Button(const char* texturesheet, SDL_Renderer* ren, int x, int y, int destWidth, int destHeight) : GameObject(texturesheet, ren, x, y, destWidth, destHeight) {}
    bool IsHovered(const SDL_Point& mousePosition) const {
        return SDL_PointInRect(&mousePosition, &destRect);
    }

    bool IsClicked(const SDL_Point& mousePosition, bool mouseButtonState) const {
        return IsHovered(mousePosition) && mouseButtonState;
    }
    void ChangeButton(const char* texturesheet);
};

