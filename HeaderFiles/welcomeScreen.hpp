#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <vector>
#include "Screen.hpp"
// #include "musicManager.hpp"

class WelcomeScreen : public Screen {
private:
    bool startGame;
    // MusicManager musicManager;
public:
    // WelcomeScreen();
    virtual void show(SDL_Renderer* renderer, ScreenType& nextScreen) override;
    ~WelcomeScreen();
};
