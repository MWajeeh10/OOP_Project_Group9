#include "game.hpp"
#include <iostream>

Game::Game() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    // Create a window
    window = SDL_CreateWindow("Ludo Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    // Create a renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }
}

Game::~Game() {
    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::run() {
    showWelcomeScreen();
	showPlayerSelectionScreen();
    // Run the rest of the game
    // ...
}

void Game::showWelcomeScreen() {
    // Load the image
    SDL_Surface* image = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\sampleRulesScreen.png");
    if (!image) {
        std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }

    // Create a texture from the image
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
    if (!texture) {
        std::cout << "Unable to create texture from image! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    // Free the image surface
    SDL_FreeSurface(image);

    // Render the texture for 4 seconds
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_Delay(4000);

    // Destroy the texture
    SDL_DestroyTexture(texture);
}

void Game::showPlayerSelectionScreen() {
    // Load the image
    SDL_Surface* image = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\board.png");
    if (!image) {
        std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }

    // Create a texture from the image
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
    if (!texture) {
        std::cout << "Unable to create texture from image! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    // Free the image surface
    SDL_FreeSurface(image);

    // Render the texture
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    // Wait for a quit event
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
    }

    // Destroy the texture
    SDL_DestroyTexture(texture);
}
