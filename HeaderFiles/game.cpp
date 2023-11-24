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
//     SDL_Surface* rulesImage = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\rulesblink.png");

//     if (!image || !imageClicked || !rulesImage) {
//         std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
//         return;
//     }

//     SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
//     SDL_Texture* textureClicked = SDL_CreateTextureFromSurface(renderer, imageClicked);
//     SDL_Texture* rulesTexture = SDL_CreateTextureFromSurface(renderer, rulesImage);

//     if (!texture || !textureClicked || !rulesTexture) {
//         std::cout << "Unable to create texture from image! SDL_Error: " << SDL_GetError() << std::endl;
//         return;
//     }

//     SDL_FreeSurface(image);
//     SDL_FreeSurface(imageClicked);
//     SDL_FreeSurface(rulesImage);

//     bool startGame = false;

//     SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, texture, NULL, NULL);
//     SDL_RenderPresent(renderer);

//     bool showRulesScreen = false;

//     SDL_Event event;
//     while (SDL_WaitEvent(&event)) {
//         if (event.type == SDL_QUIT) {
//             break;
//         } else if (event.type == SDL_MOUSEBUTTONDOWN) {
//             int x, y;
//             SDL_GetMouseState(&x, &y);
//             std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";
//             if (x >= 187 && x <= 478 && y >= 208 && y <= 253) {
//                 // Create a blinking effect for the "Start" button
//                 for (int i = 0; i < 3; ++i) {
//                     SDL_RenderClear(renderer);
//                     SDL_RenderCopy(renderer, textureClicked, NULL, NULL);
//                     SDL_RenderPresent(renderer);
//                     SDL_Delay(250);

//                     SDL_RenderClear(renderer);
//                     SDL_RenderCopy(renderer, texture, NULL, NULL);
//                     SDL_RenderPresent(renderer);
//                     SDL_Delay(250);
//                 }
//                 startGame = true;
//                 break;
//             } else if (x >= 189 && x <= 476 && y >= 375 && y <= 417) {
//                 // Create a blinking effect for the "Rules" button
//                 for (int i = 0; i < 3; ++i) {
//                     SDL_RenderClear(renderer);
//                     SDL_RenderCopy(renderer, rulesTexture, NULL, NULL);
//                     SDL_RenderPresent(renderer);
//                     SDL_Delay(250);

//                     SDL_RenderClear(renderer);
//                     SDL_RenderCopy(renderer, texture, NULL, NULL);
//                     SDL_RenderPresent(renderer);
//                     SDL_Delay(250);
//                 }

//                 // Set the flag to transition to the rules screen
//                 showRulesScreen = true;
//                 break;  // Break out of the loop after showing the rules
//             }
//         }
//     }

//     SDL_DestroyTexture(texture);
//     SDL_DestroyTexture(textureClicked);
//     SDL_DestroyTexture(rulesTexture);

//     if (startGame) {
//         // Stop the music when transitioning to the player selection screen
//         Mix_HaltMusic();
//         showPlayerSelectionScreen();
//     } else if (showRulesScreen) {
//         // Stop the music before transitioning to the rules screen
//         Mix_HaltMusic();
//         showRulesScreen1();
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

// void Game::showRulesScreen1() {
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

//      SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, rules1Texture, NULL, NULL);
//     SDL_RenderPresent(renderer);

//     // Wait for a quit event or a mouse click
//     SDL_Event event;
//     while (SDL_WaitEvent(&event)) {
//         if (event.type == SDL_QUIT) {
//             break;
//         } else if (event.type == SDL_MOUSEBUTTONDOWN) {
//             int x, y;
//             SDL_GetMouseState(&x, &y);
//             std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";

//             // Check if the BACK button is clicked
//             if (x >= 430 && x <= 600 && y >= 597 && y <= 629) {
//                 showWelcomeScreen();
//                 return;  // Return to the previous screen (Welcome screen)
//             }
//         }
//     }

//     SDL_DestroyTexture(rules1Texture);
// }























#include "game.hpp"
#include <SDL_mixer.h>
#include <iostream>
// #include "game.hpp"

// Implementation of WelcomeScreen
// WelcomeScreen class
void WelcomeScreen::show(SDL_Renderer* renderer, ScreenType& nextScreen) {
    Mix_Music* music = Mix_LoadMUS("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\audio2.mp3");
    if (!music) {
        std::cout << "Unable to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return;
    }

    // Play music
    if (Mix_PlayMusic(music, -1) == -1) {
        std::cout << "Unable to play music! SDL_mixer Error: " << Mix_GetError() << std::endl;
        Mix_FreeMusic(music);  // Free music if playing fails
        return;
    }

    SDL_Surface* image = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\welcome\\screen1.png");
    SDL_Surface* imageClicked = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\welcome\\screen2.png");
    SDL_Surface* rulesImage = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\rules\\rulesblink.png");

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

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    bool startGame = false;

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
        // Stop the music when transitioning to the player selection screen
        Mix_HaltMusic();
        nextScreen = ScreenType::PLAYER_SELECTION;
    }

    // Free the music at the end
    Mix_FreeMusic(music);
}

SDL_Texture* PlayerSelectionScreen::loadTexture(const std::string& path, SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (!surface) {
        std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
        return nullptr;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void PlayerSelectionScreen::renderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y) {
    SDL_Rect destination;
    destination.x = x;
    destination.y = y;
    SDL_QueryTexture(texture, nullptr, nullptr, &destination.w, &destination.h);
    SDL_RenderCopy(renderer, texture, nullptr, &destination);
}

// PlayerSelectionScreen class
void PlayerSelectionScreen::show(SDL_Renderer* renderer, ScreenType& nextScreen) {
    // Load the board image
    SDL_Surface* boardImage = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\board.png");
    if (!boardImage) {
        std::cout << "Unable to load board image! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }

    SDL_Texture* boardTexture = SDL_CreateTextureFromSurface(renderer, boardImage);
    if (!boardTexture) {
        std::cout << "Unable to create texture from board image! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(boardImage);
        return;
    }

    SDL_FreeSurface(boardImage);

    // Load textures for different colored tokens
    SDL_Texture* redTokenTexture = loadTexture("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\tokens\\red.png", renderer);
    SDL_Texture* greenTokenTexture = loadTexture("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\tokens\\green.png", renderer);
    SDL_Texture* blueTokenTexture = loadTexture("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\tokens\\blue.png", renderer);
    SDL_Texture* yellowTokenTexture = loadTexture("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\tokens\\yellow.png", renderer);

    // Check if loading any texture failed
    if (!redTokenTexture || !greenTokenTexture || !blueTokenTexture || !yellowTokenTexture) {
        // Handle error
        SDL_DestroyTexture(boardTexture);
        return;
    }

    // Render the board
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, boardTexture, NULL, NULL);

    // Render red tokens at different positions
    renderTexture(redTokenTexture, renderer, 0, 0);
    renderTexture(redTokenTexture, renderer, 0, 260);
    renderTexture(redTokenTexture, renderer, 260, 260);
    renderTexture(redTokenTexture, renderer, 260, 0);

    // Render green tokens at different positions
    renderTexture(greenTokenTexture, renderer, 450, 0);
    renderTexture(greenTokenTexture, renderer, 710, 0);
    renderTexture(greenTokenTexture, renderer, 450, 260);
    renderTexture(greenTokenTexture, renderer, 710, 260);

    // Render blue tokens at different positions
    renderTexture(blueTokenTexture, renderer, 0, 450);
    renderTexture(blueTokenTexture, renderer, 0, 710);
    renderTexture(blueTokenTexture, renderer, 260, 450);
    renderTexture(blueTokenTexture, renderer, 260, 710);

    // Render yellow tokens at different positions
    renderTexture(yellowTokenTexture, renderer, 450, 450);
    renderTexture(yellowTokenTexture, renderer, 450, 710);
    renderTexture(yellowTokenTexture, renderer, 710, 710);
    renderTexture(yellowTokenTexture, renderer, 710, 450);

    SDL_RenderPresent(renderer);
   

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                nextScreen = ScreenType::EXIT;  // Update nextScreen if the user quits
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";
                // Add logic for player selection if needed
            }
        }
    }
    SDL_DestroyTexture(boardTexture);
    SDL_DestroyTexture(redTokenTexture);
    SDL_DestroyTexture(greenTokenTexture);
    SDL_DestroyTexture(blueTokenTexture);
    SDL_DestroyTexture(yellowTokenTexture);
    // SDL_DestroyTexture(texture);
}

// RulesScreen class
void RulesScreen::show(SDL_Renderer* renderer, ScreenType& nextScreen) {
    SDL_Surface* rules1 = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\rules\\rules1.png");
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


// Implementation of ScreenManager
ScreenManager::ScreenManager()
    : currentScreen(ScreenType::WELCOME), music(nullptr) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        // Handle initialization failure as needed
    }

    // Initialize SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        // Handle initialization failure as needed
    }

    window = SDL_CreateWindow("Ludo Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 750, 750, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        // Handle window creation failure as needed
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        // Handle renderer creation failure as needed
    }

    // Load music
    music = Mix_LoadMUS("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\audio2.mp3");
    if (!music) {
        std::cout << "Unable to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }

    // Play music only if it's not already playing
    playMusic();
}

ScreenManager::~ScreenManager() {
    // Free music
    if (music) {
        Mix_FreeMusic(music);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_Quit();
    SDL_Quit();
}

void ScreenManager::playMusic() {
    if (music) {
        // Play music only if it's not already playing
        if (Mix_PlayingMusic() == 0) {
            Mix_PlayMusic(music, -1);
        }
    }
}

void ScreenManager::run() {
    while (currentScreen != ScreenType::EXIT) {
        switch (currentScreen) {
        case ScreenType::WELCOME: {
            WelcomeScreen welcomeScreen;
            welcomeScreen.show(renderer, currentScreen);
            break;
        }
        case ScreenType::PLAYER_SELECTION: {
            PlayerSelectionScreen playerSelectionScreen;
            playerSelectionScreen.show(renderer, currentScreen);
            break;
        }
        case ScreenType::RULES: {
            RulesScreen rulesScreen;
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


WelcomeScreen::~WelcomeScreen() {
    // Add any cleanup code if needed
}


// PlayerSelectionScreen destructor
PlayerSelectionScreen::~PlayerSelectionScreen() {
    // Add any cleanup code if needed
}

// RulesScreen destructor
RulesScreen::~RulesScreen() {
    // Add any cleanup code if needed
}
