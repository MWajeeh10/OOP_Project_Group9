#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <vector>
#include "screenManager.hpp"
#include "welcomeScreen.hpp"
#include "play.hpp"
#include "rules.hpp"

ScreenManager::ScreenManager()
    : window(nullptr), renderer(nullptr), currentScreen(ScreenType::WELCOME) {
    window = SDL_CreateWindow("Ludo Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 750, 750, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

ScreenManager::~ScreenManager() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    // Mix_Quit();
    SDL_Quit();
}
 void ScreenManager::run() {
        while (currentScreen != ScreenType::EXIT) {
            // playMusicBasedOnScreen();
            switch (currentScreen) {
                case ScreenType::WELCOME: {
                    WelcomeScreen welcomeScreen;
                    welcomeScreen.show(renderer, currentScreen);
                    break;
                }
                case ScreenType::PLAYER_SELECTION: {
                    play boardscreen(renderer);
                    boardscreen.show(renderer, currentScreen);
                    break;
                }
                case ScreenType::RULES: {
                    rules rulesScreen;
                    rulesScreen.show(renderer, currentScreen);
                    break;
                }
                // Add more cases for other screens as needed
                default:
                    // Handle unknown screen type
                    break;
            }
        }
    }