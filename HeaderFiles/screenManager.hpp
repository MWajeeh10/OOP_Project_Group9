#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <vector>
#include <SDL.h>
#include "screen.hpp"

class ScreenManager {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    ScreenType currentScreen;

public:
    ScreenManager();
    ~ScreenManager();
    void run();
};
