// #include "game.hpp"
// #include <iostream>

// Game::Game() 
//     : startGame(false) {
//     // Initialize SDL
//     if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//         std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
//         return;
//     }

//     // Create a window
//     window = SDL_CreateWindow("Ludo Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
//     if (!window) {
//         std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
//         return;
//     }

//     // Create a renderer
//     renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//     if (!renderer) {
//         std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
//         return;
//     }
// }

// Game::~Game() {
//     // Clean up
//     SDL_DestroyRenderer(renderer);
//     SDL_DestroyWindow(window);
//     SDL_Quit();
// }

// void Game::run() {
//     showWelcomeScreen();
//     if (startGame) {
//         showPlayerSelectionScreen();
//     }
//     // showWelcomeScreen();
// 	// showPlayerSelectionScreen();
//     // Run the rest of the game
//     // ...
// }


// void Game::showWelcomeScreen() {
//     // Load the image
//     SDL_Surface* image = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\screen1.png");
//     if (!image) {
//         std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
//         return;
//     }

//     // Create a texture from the image
//     SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
//     if (!texture) {
//         std::cout << "Unable to create texture from image! SDL_Error: " << SDL_GetError() << std::endl;
//         return;
//     }

//     // Free the image surface
//     SDL_FreeSurface(image);

//     // Render the texture
//     SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, texture, NULL, NULL);
//     SDL_RenderPresent(renderer);

//     // Wait for a click on the "Start" button
//     SDL_Event event;
//     while (SDL_WaitEvent(&event)) {
//         if (event.type == SDL_QUIT) {
//             break;
//         } else if (event.type == SDL_MOUSEBUTTONDOWN) {
//             int x, y;
//             SDL_GetMouseState(&x, &y);
//             std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";
//             // Check if the click was within the "Start" button's area
//             // Replace these values with the actual position and size of your "Start" button
//             if (x >= 186 && x <= 478 && y >= 158 && y <= 192) {
//                 startGame = true;
//                 break;
//             }
//         }
//     }

//     // Destroy the texture
//     SDL_DestroyTexture(texture);
// }

// void Game::showPlayerSelectionScreen() {
//     // Load the image
//     SDL_Surface* image = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\board.png");
//     if (!image) {
//         std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
//         return;
//     }

//     // Create a texture from the image
//     SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
//     if (!texture) {
//         std::cout << "Unable to create texture from image! SDL_Error: " << SDL_GetError() << std::endl;
//         return;
//     }

//     // Free the image surface
//     SDL_FreeSurface(image);

//     // Render the texture
//     SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, texture, NULL, NULL);
//     SDL_RenderPresent(renderer);

//     // Wait for a quit event
//     bool running = true;
//     SDL_Event event;
//     while (running) {
//         while (SDL_PollEvent(&event)) {
//             if (event.type == SDL_QUIT) {
//                 running = false;
//             }
//         }
//     }

//     // Destroy the texture
//     SDL_DestroyTexture(texture);
// }



// Include the necessary header files
#include "game.hpp"
#include <iostream>

// Constructor for the Game class
Game::Game() 
    : startGame(false) {  // Initialize startGame to false
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        // If SDL could not initialize, print an error message
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    // Create a window
    window = SDL_CreateWindow("OOP Project Team 09", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        // If the window could not be created, print an error message
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    // Create a renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        // If the renderer could not be created, print an error message
        std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }
}

// Destructor for the Game class
Game::~Game() {
    // Clean up
    SDL_DestroyRenderer(renderer);  // Destroy the renderer
    SDL_DestroyWindow(window);  // Destroy the window
    SDL_Quit();  // Quit SDL
}

// Method to run the game
void Game::run() {
    showWelcomeScreen();  // Show the welcome screen
    if (startGame) {  // If the user clicked "Start" on the welcome screen...
        showPlayerSelectionScreen();  // ...show the player selection screen
    }
    // Run the rest of the game
    // ...
}

// Method to show the welcome screen
void Game::showWelcomeScreen() {
    // Load the image
    SDL_Surface* image = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\screen1.png");
    if (!image) {
        // If the image could not be loaded, print an error message
        std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }

    // Create a texture from the image
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
    if (!texture) {
        // If the texture could not be created, print an error message
        std::cout << "Unable to create texture from image! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    // Free the image surface
    SDL_FreeSurface(image);

    // Render the texture
    SDL_RenderClear(renderer);  // Clear the current rendering target with the drawing color
    SDL_RenderCopy(renderer, texture, NULL, NULL);  // Copy a portion of the texture to the current rendering target
    SDL_RenderPresent(renderer);  // Update the screen with any rendering performed since the previous call

    // Wait for a click on the "Start" button
    SDL_Event event;
    while (SDL_WaitEvent(&event)) {  // Wait for an event
        if (event.type == SDL_QUIT) {  // If the event is a quit event (like closing the window)...
            break;  // ...break the loop
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {  // If the event is a mouse button down event...
            int x, y;
            SDL_GetMouseState(&x, &y);  // Get the current state of the mouse
            std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";  // Print the mouse coordinates
            
            // Check if the click was within the "Start" button's area
            // Will be replaced these values with the actual position and size of our "Start" button and screen resolution
            if (x >= 186 && x <= 479 && y >= 198 && y <= 239) {
                startGame = true;  // Set startGame to true
                break;  // Break the loop
            }
        }
    }

    // Destroy the texture
    SDL_DestroyTexture(texture);
}

// Method to show the player selection screen
void Game::showPlayerSelectionScreen() {
    // Load the image
    SDL_Surface* image = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\board.png");
    if (!image) {
        // If the image could not be loaded, print an error message
        std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }

    // Create a texture from the image
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
    if (!texture) {
        // If the texture could not be created, print an error message
        std::cout << "Unable to create texture from image! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    // Free the image surface
    SDL_FreeSurface(image);

    // Render the texture
    SDL_RenderClear(renderer);  // Clear the current rendering target with the drawing color
    SDL_RenderCopy(renderer, texture, NULL, NULL);  // Copy a portion of the texture to the current rendering target
    SDL_RenderPresent(renderer);  // Update the screen with any rendering performed since the previous call

    // Wait for a quit event
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {  // Poll for currently pending events
            if (event.type == SDL_QUIT) {  // If the event is a quit event...
                running = false;  // ...set running to false
            }
        }
    }

    // Destroy the texture
    SDL_DestroyTexture(texture);
}