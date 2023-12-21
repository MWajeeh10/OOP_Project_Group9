#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <vector>
#include "welcomeScreen.hpp"
#include "play.hpp"

// WelcomeScreen::WelcomeScreen():{}


void WelcomeScreen::show(SDL_Renderer* renderer, ScreenType& nextScreen) {
    SDL_Surface* image = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\welcome\\screen1.png");
    SDL_Surface* imageClicked = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\welcome\\screen2.png");
    SDL_Surface* rulesImage = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\rules\\rulesblink.png");
    // musicManager.loadScreenMusic(ScreenType::WELCOME, "C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\audio1.mp3");
    // musicManager.playScreenMusic(ScreenType::WELCOME);

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);   //! representing an image
    SDL_Texture* textureClicked = SDL_CreateTextureFromSurface(renderer, imageClicked); 
    SDL_Texture* rulesTexture = SDL_CreateTextureFromSurface(renderer, rulesImage);

    SDL_FreeSurface(image);
    SDL_FreeSurface(imageClicked);
    SDL_FreeSurface(rulesImage);

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    bool startGame = false;

    //event handling loop
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            nextScreen = ScreenType::EXIT;  // Set nextScreen to EXIT when the window is closed
            break;
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";
            if (x >= 222 && x <= 560 && y >= 246 && y <= 299) {
                // Create a blinking effect for the "Start" button
                for (int i = 0; i < 3; ++i) {
                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, textureClicked, NULL, NULL);
                    SDL_RenderPresent(renderer);
                    SDL_Delay(250);

                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, texture, NULL, NULL);
                    SDL_RenderPresent(renderer);
                    SDL_Delay(250);
                }
                startGame = true;
                break;
            } else if (x >= 222 && x <= 558 && y >= 438 && y <= 490) {
                // Create a blinking effect for the "Rules" button
                for (int i = 0; i < 3; ++i) {
                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, rulesTexture, NULL, NULL);
                    SDL_RenderPresent(renderer);
                    SDL_Delay(250);

                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, texture, NULL, NULL);
                    SDL_RenderPresent(renderer);
                    SDL_Delay(250);
                }
                // Set the flag to transition to the rules screen
                nextScreen = ScreenType::RULES;
                break;  // Break out of the loop after showing the rules
            }
        }
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(textureClicked);
    SDL_DestroyTexture(rulesTexture);

    if (startGame) {
        nextScreen = ScreenType::PLAYER_SELECTION;
    }
}

WelcomeScreen::~WelcomeScreen() {
    // Add any cleanup code if needed
        // musicManager.stopMusic();

}


