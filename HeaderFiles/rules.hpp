#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <vector>
#include "musicManager.hpp"
#include "Screen.hpp"

class rules : public Screen {
    private:
        // MusicManager musicManager;

    public:
        virtual void show(SDL_Renderer* renderer, ScreenType& nextScreen) override;
        ~rules();
};
