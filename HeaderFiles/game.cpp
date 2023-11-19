// #include "game.hpp"
// #include <SDL_mixer.h>
// #include <iostream>

// Game::Game() 
//     : startGame(false) {
//     // Initialize SDL
//     if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) { // Add SDL_INIT_AUDIO to initialize the SDL_mixer library
//         std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
//         return;
//     }


//     // Initialize SDL_mixer
//     if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
//         std::cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
//         return;
//     }


//     window = SDL_CreateWindow("Ludo Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 640, SDL_WINDOW_SHOWN);
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
//     Mix_Quit();
//     SDL_Quit();
// }



// void Game::run() {
//     showWelcomeScreen();
//     if (startGame) {
//         showPlayerSelectionScreen();
//     }
// }


// void Game::showWelcomeScreen() {
//     // Load the music
//     //Mix_Music* music = Mix_LoadMUS("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\audio2.mp3");
//     Mix_Music* music = Mix_LoadMUS("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\audio2.mp3");
//     if (!music) {
//         std::cout << "Unable to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
//         return;
//     }

//     // Play the music
//     Mix_PlayMusic(music, -1); // The second argument is the number of loops. -1 means infinite loops.


//     // Load the image
//     SDL_Surface* image = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\screen1.png");

//     SDL_Surface* imageClicked = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\screen2.png");

//     SDL_Surface* rulesblinkimage = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\rulesblink.png");
//     //SDL_Surface* image = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\screen1.png");
//     //SDL_Surface* imageClicked = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\screen2.png"); // Load the image with the differently colored "Start" button
//     if (!image || !imageClicked||!rulesblinkimage) {
//         std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
//         return;
//     }

//     // Create a texture from the image
//     SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
//     SDL_Texture* textureClicked = SDL_CreateTextureFromSurface(renderer, imageClicked); // Create a texture from the image with the differently colored "Start" button
//     SDL_Texture* rulesBlinkTexture = SDL_CreateTextureFromSurface(renderer, rulesblinkimage);// Create a texture from the image with the differently colored "Rules" button
//     if (!texture || !textureClicked|| !rulesBlinkTexture) {
//         std::cout << "Unable to create texture from image! SDL_Error: " << SDL_GetError() << std::endl;
//         return;
//     }

//     SDL_FreeSurface(image);
//     SDL_FreeSurface(imageClicked);
//     SDL_FreeSurface(rulesblinkimage);

//     // Boolean to control the switching effect
//     bool showRulesBlink = false;
//     bool startGame = false;


//     // Render the texture
//     SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, texture, NULL, NULL);
//     SDL_RenderPresent(renderer);

//     // Wait for a click on the "Start" button
//     SDL_Event event;
//     while (SDL_WaitEvent(&event)) {
//         if (event.type == SDL_QUIT) {
//             break;
//         } 
//         else if (event.type == SDL_MOUSEBUTTONDOWN) {
//             int x, y;
//             SDL_GetMouseState(&x, &y);
//             std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";
//             if (x >= 187 && x <= 478 && y >= 208 && y <= 253){
//                 startGame = true;
//                 break;
//             } 
//             else if(x >= 189 && x <= 476 && y >= 375 && y <= 417){
//                 showRulesBlink = true;
//                 break;
//             }         
//         }
//     }
//     if (showRulesBlink) {
//     // Create a blinking effect for the "Rules" button
//     for (int i = 0; i < 3; ++i) {
//         // Render the rules blink screen
//         SDL_RenderClear(renderer);
//         SDL_RenderCopy(renderer, rulesBlinkTexture, NULL, NULL);
//         SDL_RenderPresent(renderer);
//         SDL_Delay(250); // Reduced delay time

//         // Render the original screen
//         SDL_RenderClear(renderer);
//         SDL_RenderCopy(renderer, texture, NULL, NULL);
//         SDL_RenderPresent(renderer);
//         SDL_Delay(250); // Reduced delay time
//     }
//     showRulesBlink = false; // Reset the flag
//     }

//     if (startGame) {
//     // Create a blinking effect for the "Start" button
//     for (int i = 0; i < 3; ++i) {
//         // Render the texture with the differently colored "Start" button
//         SDL_RenderClear(renderer);
//         SDL_RenderCopy(renderer, textureClicked, NULL, NULL);
//         SDL_RenderPresent(renderer);
//         SDL_Delay(250); // Reduced delay time

//         // Render the original texture
//         SDL_RenderClear(renderer);
//         SDL_RenderCopy(renderer, texture, NULL, NULL);
//         SDL_RenderPresent(renderer);
//         SDL_Delay(250); // Reduced delay time
//     }
//     startGame = false; // Reset the flag
//     }

//     SDL_DestroyTexture(texture);
//     SDL_DestroyTexture(textureClicked);
//     SDL_DestroyTexture(rulesBlinkTexture);
//     // Stop the music when the "Start" button is clicked
//     if (startGame||showRulesBlink) {
//         Mix_HaltMusic(); // Stop the music
//     }

//     // Free the music
//     Mix_FreeMusic(music);
// }



// void Game::showPlayerSelectionScreen() {
//     // Load the image
//     SDL_Surface* image = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\board.png");
//     //SDL_Surface* image = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\board.png");
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

// void Game::showRules1Screen() {
//     // Load the image
//     SDL_Surface* rules1 = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\rules1.png");
//     if (!rules1) {
//         std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
//         return;
//     }

//     // Create a texture from the image
//     SDL_Texture* rules1Texture = SDL_CreateTextureFromSurface(renderer, rules1);
//     if (!rules1Texture) {
//         std::cout << "Unable to create texture from image! SDL_Error: " << SDL_GetError() << std::endl;
//         return;
//     }

//     // Free the image surface
//     SDL_FreeSurface(rules1);

//     // Render the texture
//     SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, rules1Texture, NULL, NULL);
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
//     SDL_DestroyTexture(rules1Texture);
// }






// #include "game.hpp"
// #include <SDL_mixer.h>
// #include <iostream>

// Game::Game() 
//     : startGame(false) {
//     // Initialize SDL
//     if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
//         std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
//         return;
//     }

//     // Initialize SDL_mixer
//     if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
//         std::cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
//         return;
//     }

//     window = SDL_CreateWindow("Ludo Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 640, SDL_WINDOW_SHOWN);
//     if (!window) {
//         std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
//         return;
//     }

//     renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//     if (!renderer) {
//         std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
//         return;
//     }
// }

// Game::~Game() {
//     SDL_DestroyRenderer(renderer);
//     SDL_DestroyWindow(window);
//     Mix_Quit();
//     SDL_Quit();
// }

// void Game::run() {
//     showWelcomeScreen();
//     if (startGame) {
//         showPlayerSelectionScreen();
//     }
// }

// void Game::showWelcomeScreen() {
//     Mix_Music* music = Mix_LoadMUS("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\audio2.mp3");
//     if (!music) {
//         std::cout << "Unable to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
//         return;
//     }

//     Mix_PlayMusic(music, -1);

//     SDL_Surface* image = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\screen1.png");
//     SDL_Surface* imageClicked = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\screen2.png");
//     SDL_Surface* rulesBlinkImage = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\rulesblink.png");

//     if (!image || !imageClicked || !rulesBlinkImage) {
//         std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
//         return;
//     }

//     SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
//     SDL_Texture* textureClicked = SDL_CreateTextureFromSurface(renderer, imageClicked);
//     SDL_Texture* rulesBlinkTexture = SDL_CreateTextureFromSurface(renderer, rulesBlinkImage);

//     if (!texture || !textureClicked || !rulesBlinkTexture) {
//         std::cout << "Unable to create texture from image! SDL_Error: " << SDL_GetError() << std::endl;
//         return;
//     }

//     SDL_FreeSurface(image);
//     SDL_FreeSurface(imageClicked);
//     SDL_FreeSurface(rulesBlinkImage);

//     bool showRulesBlink = false;

//     SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, texture, NULL, NULL);
//     SDL_RenderPresent(renderer);

//     SDL_Event event;
//     while (SDL_WaitEvent(&event)) {
//         if (event.type == SDL_QUIT) {
//             break;
//         } else if (event.type == SDL_MOUSEBUTTONDOWN) {
//             int x, y;
//             SDL_GetMouseState(&x, &y);
//             std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";
//             if (x >= 187 && x <= 478 && y >= 208 && y <= 253) {
//                 startGame = true;
//                 break;
//             } else if (x >= 189 && x <= 476 && y >= 375 && y <= 417) {
//                 showRulesBlink = true;
//                 break;
//             }
//         }
//     }

//     if (showRulesBlink) {
//         for (int i = 0; i < 3; ++i) {
//             SDL_RenderClear(renderer);
//             SDL_RenderCopy(renderer, rulesBlinkTexture, NULL, NULL);
//             SDL_RenderPresent(renderer);
//             SDL_Delay(250);

//             SDL_RenderClear(renderer);
//             SDL_RenderCopy(renderer, texture, NULL, NULL);
//             SDL_RenderPresent(renderer);
//             SDL_Delay(250);
//         }
//         showRulesBlink = false;
//     }

//     if (startGame) {
//         for (int i = 0; i < 3; ++i) {
//             SDL_RenderClear(renderer);
//             SDL_RenderCopy(renderer, textureClicked, NULL, NULL);
//             SDL_RenderPresent(renderer);
//             SDL_Delay(250);

//             SDL_RenderClear(renderer);
//             SDL_RenderCopy(renderer, texture, NULL, NULL);
//             SDL_RenderPresent(renderer);
//             SDL_Delay(250);
//         }
//         startGame = false;
//     }

//     SDL_DestroyTexture(texture);
//     SDL_DestroyTexture(textureClicked);
//     SDL_DestroyTexture(rulesBlinkTexture);

//     if (startGame || showRulesBlink) {
//         Mix_HaltMusic();
//     }

//     Mix_FreeMusic(music);
// }

// void Game::showPlayerSelectionScreen() {
//     SDL_Surface* image = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\board.png");
//     if (!image) {
//         std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
//         return;
//     }

//     SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
//     if (!texture) {
//         std::cout << "Unable to create texture from image! SDL_Error: " << SDL_GetError() << std::endl;
//         return;
//     }

//     SDL_FreeSurface(image);

//     SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, texture, NULL, NULL);
//     SDL_RenderPresent(renderer);

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
//                 // Add logic for player selection if needed
//             }
//         }
//     }

//     SDL_DestroyTexture(texture);
// }

// void Game::showRules1Screen() {
//     SDL_Surface* rules1 = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\rules1.png");
//     if (!rules1) {
//         std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
//         return;
//     }

//     SDL_Texture* rules1Texture = SDL_CreateTextureFromSurface(renderer, rules1);
//     if (!rules1Texture) {
//         std::cout << "Unable to create texture from image! SDL_Error: " << SDL_GetError() << std::endl;
//         return;
//     }

//     SDL_FreeSurface(rules1);

//     SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, rules1Texture, NULL, NULL);
//     SDL_RenderPresent(renderer);

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
//                 // Add logic for handling clicks during rules screen if needed
//             }
//         }
//     }

//     SDL_DestroyTexture(rules1Texture);
// }


//


// class Token {
// public:
//     Token(std::string color) : color(color), position(0) {}
//     void move(int squares) { position += squares; }
//     int getPosition() { return position; }
// private:
//     std::string color;
//     int position;
// };

// class Player {
// public:
//     Player(std::string name, std::string color) : name(name), color(color) {
//         for (int i = 0; i < 4; ++i) {
//             tokens[i] = new Token(color);
//         }
//     }
//     ~Player() {
//         for (int i = 0; i < 4; ++i) {
//             delete tokens[i];
//         }
//     }
//     void moveToken(int tokenIndex, int squares) { tokens[tokenIndex]->move(squares); }
// private:
//     std::string name;
//     std::string color;
//     Token* tokens[4];
// };

// class Game {
// public:
//     Game();
//     ~Game();
//     void run();
//     void showWelcomeScreen();
//     void showPlayerSelectionScreen();
//     // void startGame(int numPlayers);
// private:
//     SDL_Window* window;
//     SDL_Renderer* renderer;
//     std::vector<Player*> players;
// };
#include "game.hpp"
#include <SDL_mixer.h>
#include <iostream>

Game::Game() 
    : startGame(false) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
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

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }
}

Game::~Game() {
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
    Mix_Music* music = Mix_LoadMUS("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\audio2.mp3");
    if (!music) {
        std::cout << "Unable to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return;
    }

    Mix_PlayMusic(music, -1);

    SDL_Surface* image = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\screen1.png");
    SDL_Surface* imageClicked = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\screen2.png");
    SDL_Surface* rulesImage = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\rulesblink.png");

    if (!image || !imageClicked || !rulesImage) {
        std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_Texture* textureClicked = SDL_CreateTextureFromSurface(renderer, imageClicked);
    SDL_Texture* rulesTexture = SDL_CreateTextureFromSurface(renderer, rulesImage);

    if (!texture || !textureClicked || !rulesTexture) {
        std::cout << "Unable to create texture from image! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_FreeSurface(image);
    SDL_FreeSurface(imageClicked);
    SDL_FreeSurface(rulesImage);

    bool startGame = false;

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    bool showRulesScreen = false;

    SDL_Event event;
    while (SDL_WaitEvent(&event)) {
        if (event.type == SDL_QUIT) {
            break;
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";
            if (x >= 187 && x <= 478 && y >= 208 && y <= 253) {
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
            } else if (x >= 189 && x <= 476 && y >= 375 && y <= 417) {
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
                showRulesScreen = true;
                break;  // Break out of the loop after showing the rules
            }
        }
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(textureClicked);
    SDL_DestroyTexture(rulesTexture);

    if (startGame) {
        // Stop the music when transitioning to the player selection screen
        Mix_HaltMusic();
        showPlayerSelectionScreen();
    } else if (showRulesScreen) {
        // Stop the music before transitioning to the rules screen
        Mix_HaltMusic();
        showRulesScreen1();
    }

    Mix_FreeMusic(music);
}





void Game::showPlayerSelectionScreen() {
    SDL_Surface* image = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\board.png");
    if (!image) {
        std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
    if (!texture) {
        std::cout << "Unable to create texture from image! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_FreeSurface(image);

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";
                // Add logic for player selection if needed
            }
        }
    }

    SDL_DestroyTexture(texture);
}

void Game::showRulesScreen1() {
    SDL_Surface* rules1 = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\rules1.png");
    if (!rules1) {
        std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }

    SDL_Texture* rules1Texture = SDL_CreateTextureFromSurface(renderer, rules1);
    if (!rules1Texture) {
        std::cout << "Unable to create texture from image! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_FreeSurface(rules1);

     SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, rules1Texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    // Wait for a quit event or a mouse click
    SDL_Event event;
    while (SDL_WaitEvent(&event)) {
        if (event.type == SDL_QUIT) {
            break;
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";

            // Check if the BACK button is clicked
            if (x >= 430 && x <= 600 && y >= 597 && y <= 629) {
                showWelcomeScreen();
                return;  // Return to the previous screen (Welcome screen)
            }
        }
    }

    SDL_DestroyTexture(rules1Texture);
}


// void Game::startGame(int numPlayers) {
//     // Create the players
//     std::string colors[] = {"red", "green", "blue", "yellow"};
//     for (int i = 0; i < numPlayers; ++i) {
//         players.push_back(new Player("Player " + std::to_string(i+1), colors[i]));
//     }

//     // Load the board image
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

//     // Render the texture
//     SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, texture, NULL, NULL);
//     SDL_RenderPresent(renderer);

//     // TODO: Place the tokens on the board
//     void Game::placeTokens() {
//     // TODO: Load the token images
//     SDL_Surface* tokenImages[4];
//     tokenImages[0] = IMG_Load("path_to_red_token_image");
//     tokenImages[1] = IMG_Load("path_to_green_token_image");
//     tokenImages[2] = IMG_Load("path_to_blue_token_image");
//     tokenImages[3] = IMG_Load("path_to_yellow_token_image");

//     // TODO: Create textures from the images
//     SDL_Texture* tokenTextures[4];
//     for (int i = 0; i < 4; ++i) {
//         tokenTextures[i] = SDL_CreateTextureFromSurface(renderer, tokenImages[i]);
//         SDL_FreeSurface(tokenImages[i]);
//     }

//     // TODO: Place the tokens on the board
//     for (int i = 0; i < players.size(); ++i) {
//         for (int j = 0; j < 4; ++j) {
//             // Calculate the position of the token
//             SDL_Rect dst;
//             dst.x = /* TODO: Calculate the x position based on the player and token number */;
//             dst.y = /* TODO: Calculate the y position based on the player and token number */;
//             dst.w = /* TODO: Set the width of the token */;
//             dst.h = /* TODO: Set the height of the token */;

//             // Render the token
//             SDL_RenderCopy(renderer, tokenTextures[i], NULL, &dst);
//         }
//     }

//     // TODO: Present the renderer
//     SDL_RenderPresent(renderer);

//     // TODO: Destroy the textures
//     for (int i = 0; i < 4; ++i) {
//         SDL_DestroyTexture(tokenTextures[i]);
//     }
// }
// }





//------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------//






















































