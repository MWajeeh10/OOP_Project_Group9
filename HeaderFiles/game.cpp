#include "game.hpp"
#include <SDL_mixer.h>
#include <iostream>

Game::Game() 
    : startGame(false) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) { // Add SDL_INIT_AUDIO to initialize the SDL_mixer library
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }


    // Initialize SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return;
    }


    window = SDL_CreateWindow("Ludo Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 640, SDL_WINDOW_SHOWN);
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
    Mix_Quit();
    SDL_Quit();
}



void Game::run() {
    showWelcomeScreen();
    if (startGame) {
        showPlayerSelectionScreen();
    }
}


void Game::showWelcomeScreen() {
    // Load the music
    Mix_Music* music = Mix_LoadMUS("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\audio2.mp3");
    if (!music) {
        std::cout << "Unable to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return;
    }

    // Play the music
    Mix_PlayMusic(music, -1); // The second argument is the number of loops. -1 means infinite loops.


    // Load the image
    SDL_Surface* image = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\screen1.png");
    SDL_Surface* imageClicked = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\screen2.png"); // Load the image with the differently colored "Start" button
    if (!image || !imageClicked) {
        std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }

    // Create a texture from the image
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_Texture* textureClicked = SDL_CreateTextureFromSurface(renderer, imageClicked); // Create a texture from the image with the differently colored "Start" button
    if (!texture || !textureClicked) {
        std::cout << "Unable to create texture from image! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_FreeSurface(image);
    SDL_FreeSurface(imageClicked);

    // Render the texture
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    // Wait for a click on the "Start" button
    SDL_Event event;
    while (SDL_WaitEvent(&event)) {
        if (event.type == SDL_QUIT) {
            break;
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";
            if (x >= 187 && x <= 478 && y >= 208 && y <= 253) {
                // Create a blinking effect
                for (int i = 0; i < 3; ++i) {
                    // Render the texture with the differently colored "Start" button
                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, textureClicked, NULL, NULL);
                    SDL_RenderPresent(renderer);
                    SDL_Delay(250); // Reduced delay time

//                     // Render the original texture
//                     SDL_RenderClear(renderer);
//                     SDL_RenderCopy(renderer, texture, NULL, NULL);
//                     SDL_RenderPresent(renderer);
//                     SDL_Delay(250); // Reduced delay time
//                 }
//                 startGame = true;
//                 break;
//             }
//         }
//     }

//     SDL_DestroyTexture(texture);
//     SDL_DestroyTexture(textureClicked);
//     // Stop the music when the "Start" button is clicked
//     if (startGame) {
//         Mix_HaltMusic(); // Stop the music
//     }

//     // Free the music
//     Mix_FreeMusic(music);
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

//     // Wait for a quit event or a mouse click
//     bool running = true;
//     SDL_Event event;
//     while (running) {
//         while (SDL_PollEvent(&event)) {
//             if (event.type == SDL_QUIT) {
//                 running = false;
//             } else if (event.type == SDL_MOUSEBUTTONDOWN) {
//                 int x, y;
//                 SDL_GetMouseState(&x, &y);
//                 std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";
//             }
//         }
//     }

//     // Destroy the texture
//     SDL_DestroyTexture(texture);
// }



//------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------//



#include "game.hpp"
#include <SDL_mixer.h>
#include <iostream>
#include <vector>

class Token {
public:
    Token(std::string color) : color(color), position(0) {}
    void move(int squares) { position += squares; }
    int getPosition() { return position; }
private:
    std::string color;
    int position;
};

class Player {
public:
    Player(std::string name, std::string color) : name(name), color(color) {
        for (int i = 0; i < 4; ++i) {
            tokens[i] = new Token(color);
        }
    }
    ~Player() {
        for (int i = 0; i < 4; ++i) {
            delete tokens[i];
        }
    }
    void moveToken(int tokenIndex, int squares) { tokens[tokenIndex]->move(squares); }
private:
    std::string name;
    std::string color;
    Token* tokens[4];
};

class Game {
public:
    Game();
    ~Game();
    void run();
    void showWelcomeScreen();
    void showPlayerSelectionScreen();
    void startGame(int numPlayers);
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::vector<Player*> players;
};

Game::Game() 
    : startGame(false) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) { // Add SDL_INIT_AUDIO to initialize the SDL_mixer library
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    // Initialize SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return;
    }

    window = SDL_CreateWindow("Ludo Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 640, SDL_WINDOW_SHOWN);
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
    Mix_Quit();
    SDL_Quit();
}

void Game::run() {
    showWelcomeScreen();
    if (startGame) {
        showPlayerSelectionScreen();
    }
}

void Game::showWelcomeScreen() {
    // Load the music
    Mix_Music* music = Mix_LoadMUS("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\audio2.mp3");
    if (!music) {
        std::cout << "Unable to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return;
    }

    // Play the music
    Mix_PlayMusic(music, -1); // The second argument is the number of loops. -1 means infinite loops.

    // Load the image
    SDL_Surface* image = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\screen1.png");
    SDL_Surface* imageClicked = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\screen2.png"); // Load the image with the differently colored "Start" button
    if (!image || !imageClicked) {
        std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }

    // Create a texture from the image
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_Texture* textureClicked = SDL_CreateTextureFromSurface(renderer, imageClicked); // Create a texture from the image with the differently colored "Start" button
    if (!texture || !textureClicked) {
        std::cout << "Unable to create texture from image! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_FreeSurface(image);
    SDL_FreeSurface(imageClicked);

    // Render the texture
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    // Wait for a click on the "Start" button
    SDL_Event event;
    while (SDL_WaitEvent(&event)) {
        if (event.type == SDL_QUIT) {
            break;
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";
            if (x >= 187 && x <= 478 && y >= 208 && y <= 253) {
                // Create a blinking effect
                for (int i = 0; i < 3; ++i) {
                    // Render the texture with the differently colored "Start" button
                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, textureClicked, NULL, NULL);
                    SDL_RenderPresent(renderer);
                    SDL_Delay(250); // Reduced delay time

                    // Render the original texture
                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, texture, NULL, NULL);
                    SDL_RenderPresent(renderer);
                    SDL_Delay(250); // Reduced delay time
                }
                startGame = true;
                break;
            }
        }
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(textureClicked);
    // Stop the music when the "Start" button is clicked
    if (startGame) {
        Mix_HaltMusic(); // Stop the music
    }

    // Free the music
    Mix_FreeMusic(music);
}

void Game::showPlayerSelectionScreen() {
    // Load the player selection screen image
    SDL_Surface* image = IMG_Load("path_to_player_selection_screen_image");
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

    // Render the texture
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    // Wait for a click on one of the player number buttons
    SDL_Event event;
    int numPlayers = 0;
    while (SDL_WaitEvent(&event)) {
        if (event.type == SDL_QUIT) {
            break;
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";
            // TODO: Check if the click was on one of the player number buttons
            // and set numPlayers accordingly
        }
    }

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);

    startGame(numPlayers);
}

void Game::startGame(int numPlayers) {
    // Create the players
    std::string colors[] = {"red", "green", "blue", "yellow"};
    for (int i = 0; i < numPlayers; ++i) {
        players.push_back(new Player("Player " + std::to_string(i+1), colors[i]));
    }

    // Load the board image
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

    // Render the texture
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    // TODO: Place the tokens on the board
    void Game::placeTokens() {
    // TODO: Load the token images
    SDL_Surface* tokenImages[4];
    tokenImages[0] = IMG_Load("path_to_red_token_image");
    tokenImages[1] = IMG_Load("path_to_green_token_image");
    tokenImages[2] = IMG_Load("path_to_blue_token_image");
    tokenImages[3] = IMG_Load("path_to_yellow_token_image");

    // TODO: Create textures from the images
    SDL_Texture* tokenTextures[4];
    for (int i = 0; i < 4; ++i) {
        tokenTextures[i] = SDL_CreateTextureFromSurface(renderer, tokenImages[i]);
        SDL_FreeSurface(tokenImages[i]);
    }

    // TODO: Place the tokens on the board
    for (int i = 0; i < players.size(); ++i) {
        for (int j = 0; j < 4; ++j) {
            // Calculate the position of the token
            SDL_Rect dst;
            dst.x = /* TODO: Calculate the x position based on the player and token number */;
            dst.y = /* TODO: Calculate the y position based on the player and token number */;
            dst.w = /* TODO: Set the width of the token */;
            dst.h = /* TODO: Set the height of the token */;

            // Render the token
            SDL_RenderCopy(renderer, tokenTextures[i], NULL, &dst);
        }
    }

    // TODO: Present the renderer
    SDL_RenderPresent(renderer);

    // TODO: Destroy the textures
    for (int i = 0; i < 4; ++i) {
        SDL_DestroyTexture(tokenTextures[i]);
    }
}
}





//------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------//

























































//---------------------------------------------------------------------------------------------------------------------------
/*                                    WANIA         CODE*/                                                                 //
//---------------------------------------------------------------------------------------------------------------------------
// // Include the necessary header files
// #include "game.hpp"
// #include <iostream>

// // Constructor for the Game class
// Game::Game() 
//     : startGame(false) {  // Initialize startGame to false
//     // Initialize SDL
//     if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//         // If SDL could not initialize, print an error message
//         std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
//         return;
//     }

//     // Create a window
//     window = SDL_CreateWindow("OOP Project Team 09", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 600, SDL_WINDOW_SHOWN);
//     if (!window) {
//         // If the window could not be created, print an error message
//         std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
//         return;
//     }

//     // Create a renderer
//     renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//     if (!renderer) {
//         // If the renderer could not be created, print an error message
//         std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
//         return;
//     }
// }

// // Destructor for the Game class
// Game::~Game() {
//     // Clean up
//     SDL_DestroyRenderer(renderer);  // Destroy the renderer
//     SDL_DestroyWindow(window);  // Destroy the window
//     SDL_Quit();  // Quit SDL
// }

// // Method to run the game
// void Game::run() {
//     showWelcomeScreen();  // Show the welcome screen
//     if (startGame) {  // If the user clicked "Start" on the welcome screen...
//         showPlayerSelectionScreen();  // ...show the player selection screen
//     }
//     // Run the rest of the game
//     // Continue
// }

// // Method to show the welcome screen
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

//     // Rectangles for "Start" and "Rules" buttons
//     SDL_Rect startButtonRect = {197, 194, 277, 48}; // Top-left corner, width, height
//     SDL_Rect rulesButtonRect = {188, 348, 284, 47}; // Top-left corner, width, height

//     // Number of blinks
//     const int blinkCount = 3;

//     // Blinking effect
//     for (int i = 0; i < blinkCount; ++i) {
//         // Render the texture
//         SDL_RenderClear(renderer);
//         SDL_RenderCopy(renderer, texture, NULL, NULL);

//         // Draw the rectangular box around the "Start" button during the blink
//         SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
//         SDL_RenderDrawRect(renderer, &startButtonRect);

//         // Draw the rectangular box around the "Rules" button during the blink
//         SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue color
//         SDL_RenderDrawRect(renderer, &rulesButtonRect);

//         SDL_RenderPresent(renderer);

//         // Introduce a delay for the blinking effect
//         SDL_Delay(500); // Adjust the delay duration as needed
//     }

//     // Wait for a click on the "Start" or "Rules" button
//     SDL_Event event;
//     while (SDL_WaitEvent(&event)) {
//         if (event.type == SDL_QUIT) {
//             break;
//         } else if (event.type == SDL_MOUSEBUTTONDOWN) {
//             int x, y;
//             SDL_GetMouseState(&x, &y);
//             std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";

//             // Check if the click was within the "Start" button's area
//             if (x >= startButtonRect.x && x <= startButtonRect.x + startButtonRect.w &&
//                 y >= startButtonRect.y && y <= startButtonRect.y + startButtonRect.h) {
//                 startGame = true;
//                 std::cout << "Start button clicked!\n";
//                 break;
//             }

//             // Check if the click was within the "Rules" button's area
//             if (x >= rulesButtonRect.x && x <= rulesButtonRect.x + rulesButtonRect.w &&
//                 y >= rulesButtonRect.y && y <= rulesButtonRect.y + rulesButtonRect.h) {
//                 // Handle transitioning to the "Rules" screen
//                 // Add your logic here
//                 std::cout << "Rules button clicked!\n";
//                 break;
//             }
//         }
//     }

//     // Destroy the texture
//     SDL_DestroyTexture(texture);
// }

// // void Game::showWelcomeScreen() {
// //     // Load the image
// //     SDL_Surface* image = IMG_Load("E:\\Users\\hp\\Documents\\GitHub\\OOP_Project_Group9\\assets\\screen1.png");
// //     if (!image) {
// //         std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
// //         return;
// //     }

// //     // Create a texture from the image
// //     SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
// //     if (!texture) {
// //         std::cout << "Unable to create texture from image! SDL_Error: " << SDL_GetError() << std::endl;
// //         return;
// //     }

// //     // Free the image surface
// //     SDL_FreeSurface(image);

// //     // Rectangles for "Start" and "Rules" buttons
// //     SDL_Rect startButtonRect = {181, 199, 482, 240}; // Replace with actual values
// //     SDL_Rect rulesButtonRect = {190, 350, 477, 390}; // Replace with actual values

// //     // Number of blinks
// //     const int blinkCount = 3;

// //     // Blinking effect
// //     for (int i = 0; i < blinkCount; ++i) {
// //         // Render the texture
// //         SDL_RenderClear(renderer);
// //         SDL_RenderCopy(renderer, texture, NULL, NULL);

// //         // Draw the rectangular box around the "Start" button during the blink
// //         SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
// //         SDL_RenderDrawRect(renderer, &startButtonRect);

// //         // Draw the rectangular box around the "Rules" button during the blink
// //         SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue color
// //         SDL_RenderDrawRect(renderer, &rulesButtonRect);

// //         SDL_RenderPresent(renderer);

// //         // Introduce a delay for the blinking effect
// //         SDL_Delay(500); // Adjust the delay duration as needed
// //     }

// //     // Wait for a click on the "Start" or "Rules" button
// //     SDL_Event event;
// //     while (SDL_WaitEvent(&event)) {
// //         if (event.type == SDL_QUIT) {
// //             break;
// //         } else if (event.type == SDL_MOUSEBUTTONDOWN) {
// //             int x, y;
// //             SDL_GetMouseState(&x, &y);
// //             std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";

// //             // Check if the click was within the "Start" button's area
// //             if (x >= startButtonRect.x && x <= startButtonRect.x + startButtonRect.w &&
// //                 y >= startButtonRect.y && y <= startButtonRect.y + startButtonRect.h) {
// //                 startGame = true;
// //                 break;
// //             }

// //             // Check if the click was within the "Rules" button's area
// //             if (x >= rulesButtonRect.x && x <= rulesButtonRect.x + rulesButtonRect.w &&
// //                 y >= rulesButtonRect.y && y <= rulesButtonRect.y + rulesButtonRect.h) {
// //                 // Handle transitioning to the "Rules" screen
// //                 // Add your logic here
// //                 break;
// //             }
// //         }
// //     }

// //     // Destroy the texture
// //     SDL_DestroyTexture(texture);
// // }

// // void Game::showWelcomeScreen() {
// //     // Load the image
// //     SDL_Surface* image = IMG_Load("E:\\Users\\hp\\Documents\\GitHub\\OOP_Project_Group9\\assets\\screen1.png");
// //     if (!image) {
// //         // If the image could not be loaded, print an error message
// //         std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
// //         return;
// //     }

// //     // Create a texture from the image
// //     SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
// //     if (!texture) {
// //         // If the texture could not be created, print an error message
// //         std::cout << "Unable to create texture from image! SDL_Error: " << SDL_GetError() << std::endl;
// //         return;
// //     }

// //     // Free the image surface
// //     SDL_FreeSurface(image);

// //     // Render the texture
// //     SDL_RenderClear(renderer);  // Clear the current rendering target with the drawing color
// //     SDL_RenderCopy(renderer, texture, NULL, NULL);  // Copy a portion of the texture to the current rendering target
// //     SDL_RenderPresent(renderer);  // Update the screen with any rendering performed since the previous call

// //     // Wait for a click on the "Start" button
// //     SDL_Event event;
// //     while (SDL_WaitEvent(&event)) {  // Wait for an event
// //         if (event.type == SDL_QUIT) {  // If the event is a quit event (like closing the window)...
// //             break;  // ...break the loop
// //         } else if (event.type == SDL_MOUSEBUTTONDOWN) {  // If the event is a mouse button down event...
// //             int x, y;
// //             SDL_GetMouseState(&x, &y);  // Get the current state of the mouse
// //             std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";  // Print the mouse coordinates
            
// //             // Check if the click was within the "Start" button's area
// //             // Will be replaced these values with the actual position and size of our "Start" button and screen resolution
// //             if (x >= 186 && x <= 479 && y >= 198 && y <= 239) {
// //                 startGame = true;  // Set startGame to true
// //                 break;  // Break the loop
// //             }
// //         }
// //     }

// //     // Destroy the texture
// //     SDL_DestroyTexture(texture);
// // }







