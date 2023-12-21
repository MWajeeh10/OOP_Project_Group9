#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <vector>
#include "rules.hpp"


void rules::show(SDL_Renderer* renderer, ScreenType& nextScreen) {
    SDL_Surface* rules1 = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\rules\\rules1.png");
    SDL_Texture* rules1Texture = SDL_CreateTextureFromSurface(renderer, rules1);
    SDL_FreeSurface(rules1);
    // musicManager.loadScreenMusic(ScreenType::RULES, "C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\audio2.mp3");
    // musicManager.playScreenMusic(ScreenType::RULES);

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, rules1Texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    // Wait for a quit event or a mouse click
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            nextScreen = ScreenType::EXIT;  // Update nextScreen if the user quits
            break;
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";

            // Check if the BACK button is clicked
            if (x >= 504 && x <= 700 && y >= 700 && y <= 735) {
                nextScreen = ScreenType::WELCOME;
                return;  // Return to the previous screen (Welcome screen)
            }
        }
    }

    SDL_DestroyTexture(rules1Texture);
}

rules::~rules(){
    // musicManager.stopMusic();

} 