#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <vector>
#include <SDL.h>


enum ScreenType {
    WELCOME,
    PLAYER_SELECTION,
    RULES,
    EXIT
};

class Screen {
public:
    virtual ~Screen() {}
    virtual void show(SDL_Renderer* renderer, ScreenType& nextScreen) = 0;
};
