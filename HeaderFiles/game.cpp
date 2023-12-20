

// #include "game.hpp"
// #include <SDL_mixer.h>
// #include <iostream>

// // #include "game.hpp"

// // Implementation of WelcomeScreen
// void WelcomeScreen::show(SDL_Renderer* renderer, ScreenType& nextScreen) {
//     Mix_Music* music = Mix_LoadMUS("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\audio2.mp3");
//     if (!music) {
//         std::cout << "Unable to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
//         return;
//     }

//     // Play music
//     Mix_PlayMusic(music, -1);

//     SDL_Surface* image = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\welcome\\screen1.png");
//     SDL_Surface* imageClicked = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\welcome\\screen2.png");
//     SDL_Surface* rulesImage = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\rules\\rulesblink.png");

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

//     SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, texture, NULL, NULL);
//     SDL_RenderPresent(renderer);

//     bool startGame = false;

//     //event handling loop
//     SDL_Event event;
//     while (SDL_PollEvent(&event)) {
//         if (event.type == SDL_QUIT) {
//             nextScreen = ScreenType::EXIT;  // Set nextScreen to EXIT when the window is closed
//             break;
//         } else if (event.type == SDL_MOUSEBUTTONDOWN) {
//             int x, y;
//             SDL_GetMouseState(&x, &y);
//             std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";
//             if (x >= 222 && x <= 560 && y >= 246 && y <= 299) {
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
//             } else if (x >= 222 && x <= 558 && y >= 438 && y <= 490) {
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
//                 nextScreen = ScreenType::RULES;
//                 break;  // Break out of the loop after showing the rules
//             }
//         }
//     }

    

//     SDL_DestroyTexture(texture);
//     SDL_DestroyTexture(textureClicked);
//     SDL_DestroyTexture(rulesTexture);

//     if (startGame) {
//         // Stop the music when transitioning to the player selection screen
//         // Mix_HaltMusic();
//         nextScreen = ScreenType::PLAYER_SELECTION;
//     }

//     // Free the music at the end
//     Mix_FreeMusic(music);
// }

// SDL_Texture* PlayerSelectionScreen::loadTexture(const std::string& path, SDL_Renderer* renderer) {
//     SDL_Surface* surface = IMG_Load(path.c_str());
//     if (!surface) {
//         std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
//         return nullptr;
//     }
//     SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
//     SDL_FreeSurface(surface);
//     return texture;
// }

// void PlayerSelectionScreen::renderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y) {
//     SDL_Rect destination;
//     destination.x = x;
//     destination.y = y;
//     SDL_QueryTexture(texture, nullptr, nullptr, &destination.w, &destination.h);
//     SDL_RenderCopy(renderer, texture, nullptr, &destination);
// }

// PlayerSelectionScreen::PlayerSelectionScreen(SDL_Renderer* renderer) : dice1(nullptr), dice2(nullptr), dice3(nullptr), dice4(nullptr) {
//     // Initialize the Dice object with the path to the dice image and initial position
    
//     dice1 = new Dice(renderer, {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\red\\red1.png", 
//                                "C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\red\\red2.png", 
//                                "C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\red\\red3.png", 
//                                "C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\red\\red4.png",
//                                "C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\red\\red5.png", 
//                                "C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\red\\red6.png"},
//                     82, 80);

//     dice2 = new Dice(renderer, {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\green\\green1.png", 
//                                "C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\green\\green2.png", 
//                                "C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\green\\green3.png", 
//                                "C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\green\\green4.png",
//                                "C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\green\\green5.png", 
//                                "C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\green\\green6.png"},
//                     530, 80);

//     dice3 = new Dice(renderer, {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\yellow\\yellow1.png", 
//                                "C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\yellow\\yellow2.png", 
//                                "C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\yellow\\yellow3.png", 
//                                "C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\yellow\\yellow4.png",
//                                "C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\yellow\\yellow5.png", 
//                                "C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\yellow\\yellow6.png"},
//                     530, 530);

//     dice4 = new Dice(renderer, {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\blue\\blue1.png", 
//                                "C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\blue\\blue2.png", 
//                                "C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\blue\\blue3.png", 
//                                "C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\blue\\blue4.png",
//                                "C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\blue\\blue5.png", 
//                                "C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\blue\\blue6.png"},
//                     80, 530);

// }



// // PlayerSelectionScreen class
// void PlayerSelectionScreen::show(SDL_Renderer* renderer, ScreenType& nextScreen) {
//     Mix_Music* music = Mix_LoadMUS("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\audio1.mp3");
//     if (!music) {
//         std::cout << "Unable to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
//         return;
//     }
//     Mix_PlayMusic(music, -1);

//     // Load the board image
//     SDL_Surface* boardImage = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\board.png");
//     if (!boardImage) {
//         std::cout << "Unable to load board image! SDL_image Error: " << IMG_GetError() << std::endl;
//         return;
//     }

//     SDL_Texture* boardTexture = SDL_CreateTextureFromSurface(renderer, boardImage);
//     if (!boardTexture) {
//         std::cout << "Unable to create texture from board image! SDL_Error: " << SDL_GetError() << std::endl;
//         SDL_FreeSurface(boardImage);
//         return;
//     }


//     //TOKEN:
//     // Load textures for different colored tokens
//     SDL_Texture* redTokenTexture = loadTexture("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\tokens\\red1.png", renderer);
//     SDL_Texture* greenTokenTexture = loadTexture("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\tokens\\green1.png", renderer);
//     SDL_Texture* yellowTokenTexture = loadTexture("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\tokens\\yellow1.png", renderer);
//     SDL_Texture* blueTokenTexture = loadTexture("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\tokens\\blue1.png", renderer);
    

//     // Check if loading any texture failed
//     if (!redTokenTexture) {
//         // Handle error
//         SDL_DestroyTexture(boardTexture);
//         return;
//     }

//     if (!greenTokenTexture) {
//         // Handle error
//         SDL_DestroyTexture(boardTexture);
//         return;
//     }

    
//     if (!yellowTokenTexture) {
//         // Handle error
//         SDL_DestroyTexture(boardTexture);
//         return;
//     }

    
//     if (!blueTokenTexture) {
//         // Handle error
//         SDL_DestroyTexture(boardTexture);
//         return;
//     }

//     // Create tokens based on dice colorS
//     redToken = new Token(renderer, redTokenTexture);
//     redToken->setStartPosition(55, 305);

//     greenToken = new Token(renderer, greenTokenTexture);
//     greenToken->setStartPosition(405, 55);

//     yellowToken = new Token(renderer, yellowTokenTexture);
//     yellowToken->setStartPosition(655,405);

//     blueToken = new Token(renderer, blueTokenTexture);
//     blueToken -> setStartPosition(305,655);


//     SDL_FreeSurface(boardImage);

//     // Render the board
//     SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, boardTexture, NULL, NULL);

//     redToken->render(renderer);
//     greenToken->render(renderer);
//     yellowToken->render(renderer);
//     blueToken->render(renderer);

//     SDL_RenderPresent(renderer);
    


//     if (dice1) {
//         dice1->render(renderer);  // Pass the renderer here
//     }

//     if (dice2) {
//         dice2->render(renderer);  // Pass the renderer here
//     }

//     if (dice3) {
//         dice3->render(renderer);  // Pass the renderer here
//     }

//     if (dice4) {
//         dice4->render(renderer);  // Pass the renderer here
//     }

    

//     bool running = true;
//     SDL_Event event;
//     while (running) {
//         // Handle events
//         while (SDL_PollEvent(&event)) {
//             if (event.type == SDL_QUIT) {
//                 running = false;
//                 nextScreen = ScreenType::EXIT;
//             } else if (event.type == SDL_MOUSEBUTTONDOWN) {
//                 int x, y;
//                 SDL_GetMouseState(&x, &y);
//                 std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";

//                 // Handle dice rolling logic based on mouse click
//                 if (x >= 80 && x <= 212 && y >= 80 && y <= 212) {
//                     if (dice1) {
//                         dice1->roll(renderer);
//                         int diceScore = dice1->diceScore();
//                         std::cout << "Dice Score for Red is: " << diceScore << std::endl;
//                         redToken->moveToNextPositionRed(diceScore);
//                     }
//                 } else if (x >= 530 && x <= 662 && y >= 80 && y <= 212) {
//                     if (dice2) {
//                         dice2->roll(renderer);
//                         int diceScore = dice2->diceScore();
//                         std::cout << "Dice Score for Green is: " << diceScore << std::endl;
//                         greenToken->moveToNextPositionGreen(diceScore);
//                     }
//                 } else if (x >= 530 && x <= 662 && y >= 530 && y <= 662) {
//                     if (dice3) {
//                         dice3->roll(renderer);
//                         int diceScore = dice3->diceScore();
//                         std::cout << "Dice Score for Yellow is: " << diceScore << std::endl;
//                         yellowToken->moveToNextPositionYellow(diceScore);
//                     }
//                 } else if (x >= 80 && x <= 530 && y >= 530 && y <= 662) {
//                     if (dice4) {
//                         dice4->roll(renderer);
//                         int diceScore = dice4->diceScore();
//                         std::cout << "Dice Score for Blue is: " << diceScore << std::endl;
//                         blueToken->moveToNextPositionBlue(diceScore);
//                     }
//                 }
//             }
//         }

//         // Clear the renderer
//         SDL_RenderClear(renderer);

//         // Render the board
//         SDL_RenderCopy(renderer, boardTexture, NULL, NULL);

//         // Render the tokens
//         redToken->render(renderer);
//         greenToken->render(renderer);
//         yellowToken->render(renderer);
//         blueToken->render(renderer);

//         // Render the dice
//         if (dice1) {
//             dice1->render(renderer);
//         }

//         if (dice2) {
//             dice2->render(renderer);
//         }

//         if (dice3) {
//             dice3->render(renderer);
//         }

//         if (dice4) {
//             dice4->render(renderer);
//         }

//         // Present the renderer
//         SDL_RenderPresent(renderer);

//         // Add a slight delay to control the frame rate
//         SDL_Delay(16);
//     }



//     SDL_DestroyTexture(boardTexture);
//     Mix_FreeMusic(music);
// }



// // RulesScreen class
// void RulesScreen::show(SDL_Renderer* renderer, ScreenType& nextScreen) {
//     SDL_Surface* rules1 = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\rules\\rules1.png");
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

//     // Wait for a quit event or a mouse click
//     SDL_Event event;
//     while (SDL_PollEvent(&event)) {
//         if (event.type == SDL_QUIT) {
//             nextScreen = ScreenType::EXIT;  // Update nextScreen if the user quits
//             break;
//         } else if (event.type == SDL_MOUSEBUTTONDOWN) {
//             int x, y;
//             SDL_GetMouseState(&x, &y);
//             std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";

//             // Check if the BACK button is clicked
//             if (x >= 504 && x <= 700 && y >= 700 && y <= 735) {
//                 nextScreen = ScreenType::WELCOME;
//                 return;  // Return to the previous screen (Welcome screen)
//             }
//         }
//     }

//     SDL_DestroyTexture(rules1Texture);
// }


// // Implementation of ScreenManager
// ScreenManager::ScreenManager()
//     : currentScreen(ScreenType::WELCOME), music(nullptr) {
//     // Initialize SDL
//     if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
//         std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
//         // Handle initialization failure as needed
//     }

//     // Initialize SDL_mixer
//     if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
//         std::cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
//         // Handle initialization failure as needed
//     }

//     window = SDL_CreateWindow("Ludo Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 750, 750, SDL_WINDOW_SHOWN);
//     if (!window) {
//         std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
//         // Handle window creation failure as needed
//     }

//     renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//     if (!renderer) {
//         std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
//         // Handle renderer creation failure as needed
//     }

//     // Load music
//     music = Mix_LoadMUS("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\audio2.mp3");
//     if (!music) {
//         std::cout << "Unable to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
//     }

//     // Play music only if it's not already playing
//     playMusic();
// }

// ScreenManager::~ScreenManager() {
//     // Free music
//     if (music) {
//         Mix_FreeMusic(music);
//     }

//     SDL_DestroyRenderer(renderer);
//     SDL_DestroyWindow(window);
//     Mix_Quit();
//     SDL_Quit();
// }

// void ScreenManager::playMusic() {
//     if (music) {
//         // Play music only if it's not already playing
//         if (Mix_PlayingMusic() == 0) {
//             Mix_PlayMusic(music, -1);
//         }
//     }
// }

// void ScreenManager::run() {
//     while (currentScreen != ScreenType::EXIT) {
//         switch (currentScreen) {
//             case ScreenType::WELCOME: {
//                 WelcomeScreen welcomeScreen;
//                 welcomeScreen.show(renderer, currentScreen);
//                 break;
//             }
//             case ScreenType::PLAYER_SELECTION: {
//                 PlayerSelectionScreen playerSelectionScreen(renderer);  // Pass renderer here
//                 playerSelectionScreen.show(renderer, currentScreen);
//                 break;
//             }
//             case ScreenType::RULES: {
//                 RulesScreen rulesScreen;
//                 rulesScreen.show(renderer, currentScreen);
//                 break;
//             }
//             // Add more cases for other screens as needed
//             default:
//                 // Handle unknown screen type
//                 break;
//         }
//     }
// }



// WelcomeScreen::~WelcomeScreen() {
//     // Add any cleanup code if needed
// }


// // PlayerSelectionScreen destructor
// PlayerSelectionScreen::~PlayerSelectionScreen() {
//     // Cleanup the first Dice object
//     if (dice1) {
//         delete dice1;
//     }

//     // Cleanup the second Dice object
//     if (dice2) {
//         delete dice2;
//     }

//     if (dice3) {
//         delete dice3;
//     }

//     // Cleanup the second Dice object
//     if (dice4) {
//         delete dice4;
//     }

//     if (redToken) {
//         delete redToken;
//     }

//     if(greenToken){
//         delete greenToken;
//     }

//     if (yellowToken) {
//         delete yellowToken;
//     }

//     if(blueToken){
//         delete blueToken;
//     }

// }

// // RulesScreen destructor
// RulesScreen::~RulesScreen() {
//     // Add any cleanup code if needed
// }







//header files
#include "game.hpp"
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>
#include "kill.hpp"


void WelcomeScreen::show(SDL_Renderer* renderer, ScreenType& nextScreen) {
    SDL_Surface* image = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\welcome\\screen1.png");
    SDL_Surface* imageClicked = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\welcome\\screen2.png");
    SDL_Surface* rulesImage = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\rules\\rulesblink.png");
    
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

SDL_Texture* PlayerSelectionScreen::loadTexture(const std::string& path, SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load(path.c_str());
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

PlayerSelectionScreen::PlayerSelectionScreen(SDL_Renderer* renderer) : dice1(nullptr), dice2(nullptr), dice3(nullptr), dice4(nullptr),currentTurn(Turn::DICE1) {
    // Initialize the Dice object with the path to the dice image and initial position
    
    dice1 = new Dice(renderer, {{"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\red\\red1.png",1},
                               {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\red\\red2.png",2},
                               {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\red\\red3.png",3},
                               {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\red\\red4.png",4},
                               {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\red\\red5.png",5 },
                               {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\red\\red6.png",6}},
                    82, 80);

    dice2 = new Dice(renderer,{{"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\green\\green1.png",1}, 
                               {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\green\\green2.png",2}, 
                               {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\green\\green3.png",3}, 
                               {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\green\\green4.png",4},
                               {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\green\\green5.png",5}, 
                               {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\green\\green6.png",6}},
                    530, 80);

    dice3 = new Dice(renderer,{{"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\yellow\\yellow1.png",1}, 
                               {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\yellow\\yellow2.png",2}, 
                               {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\yellow\\yellow3.png",3}, 
                               {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\yellow\\yellow4.png",4},
                               {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\yellow\\yellow5.png",5}, 
                               {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\yellow\\yellow6.png",6}},
                    530, 530);

    dice4 = new Dice(renderer, {{"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\blue\\blue1.png",1}, 
                               {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\blue\\blue2.png",2}, 
                               {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\blue\\blue3.png",3}, 
                               {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\blue\\blue4.png",4},
                               {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\blue\\blue5.png",5}, 
                               {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\blue\\blue6.png",6}},
                    80, 530);

}

// PlayerSelectionScreen class
void PlayerSelectionScreen::show(SDL_Renderer* renderer, ScreenType& nextScreen) {

    //load board image
    SDL_Surface* boardImage = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\board.png");
    SDL_Texture* boardTexture = SDL_CreateTextureFromSurface(renderer, boardImage);
    //TOKEN:
    // Load textures for different colored tokens
    SDL_Texture* redTokenTexture = loadTexture("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\tokens\\red1.png", renderer);
    SDL_Texture* greenTokenTexture = loadTexture("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\tokens\\green1.png", renderer);
    SDL_Texture* yellowTokenTexture = loadTexture("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\tokens\\yellow1.png", renderer);
    SDL_Texture* blueTokenTexture = loadTexture("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\tokens\\blue1.png", renderer);
        // Check if loading any texture failed
    //! this is to endure that the board is destroyed in order to manage the proper clean up
    //! in case the tokens have some problem in loading up
    if (!redTokenTexture) {
        // Handle error
        SDL_DestroyTexture(boardTexture);
        return;
    }

    if (!greenTokenTexture) {
        // Handle error
        SDL_DestroyTexture(boardTexture);
        return;
    }

    if (!yellowTokenTexture) {
        // Handle error
        SDL_DestroyTexture(boardTexture);
        return;
    }
    
    if (!blueTokenTexture) {
        // Handle error
        SDL_DestroyTexture(boardTexture);
        return;
    }

    // Create tokens based on dice colorS 
    redToken = new Token(renderer, redTokenTexture);   //? will have to be deleted later as it is created on heap
    redToken->setStartPosition(0, 0);
    redToken->lock(); //initial state will be locked
    // redToken->notGoIn(); //the token can't inside the winning squares


    greenToken = new Token(renderer, greenTokenTexture);
    greenToken->setStartPosition(450, 0);
    greenToken->lock(); //initial state will be locked
    // greenToken->notGoIn(); //Token can't go in the winning squares

    yellowToken = new Token(renderer, yellowTokenTexture);
    yellowToken->setStartPosition(710, 450);
    yellowToken->lock(); //initial state will be locked
    // yellowToken->notGoIn(); //token can't go in 


    blueToken = new Token(renderer, blueTokenTexture);
    blueToken->setStartPosition(260, 710);
    blueToken->lock(); //initial state will be locked

    SDL_FreeSurface(boardImage);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, boardTexture, NULL, NULL);

    // *rendering the tokens
    redToken->render(renderer);
    greenToken->render(renderer);
    yellowToken->render(renderer);
    blueToken->render(renderer);

    // Render the board
    if (dice1) {
        dice1->render(renderer);  // Pass the renderer here
    }

    if (dice2) {
        dice2->render(renderer);  // Pass the renderer here
    }

    if (dice3) {
        dice3->render(renderer);  // Pass the renderer here
    }

    if (dice4) {
        dice4->render(renderer);  // Pass the renderer here
    }

    SDL_RenderPresent(renderer);
    bool running = true;
    SDL_Event event;
    while (running) {
        // Handle events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                nextScreen = ScreenType::EXIT;
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";
                if (x >= 80 && x <= 212 && y >= 80 && y <= 212 && currentTurn == Turn::DICE1) {
                    if (dice1) {
                        //dice roll will happen and a random face will be generated
                        dice1->roll(renderer);
                        //dice score is stored and displayed
                        int diceScore = dice1->diceScore();
                        std::cout << "Dice Score for Red is: " << diceScore << std::endl;
                        //condition if redToken is not locked, then move to next position based on diceScore
                        if(redToken->getPosition().x == 0 && redToken->getPosition().y == 0 && redToken->isLocked()){
                            if(diceScore==6){
                                redToken->unlock(); //unlock red if dice score is 6
                                redToken->setStartPosition(55,305); //Move token to start position
                                std::cout<<"Player Red unlocked and moved to start location\n"<<std::endl;
                                std::cout<<"Player Red gets another turn\n";

                                continue; //gets another turn
                            }
                            else{
                                currentTurn = Turn::DICE2;
                            }
                        }
                        else{
                            if(diceScore==6){
                                redToken->moveToNextPositionRed(diceScore);
                                currentTurn = Turn::DICE1;
                                std::cout<<"Player Red has another turn!!\n"<<std::endl;
                                continue;
                            }

                            else{
                                redToken->moveToNextPositionRed(diceScore);
                                currentTurn = Turn::DICE2;
                                std::cout<<"Next Player turn is: Player Green!!\n"<<std::endl;
                            }
                        }
                        checkAndMoveBackToHome(redToken, blueToken, greenToken, yellowToken, redToken);

                    }
                } else if (x >= 530 && x <= 662 && y >= 80 && y <= 212 && currentTurn == Turn::DICE2) {
                    if (dice2) {
                        //dice roll will happen and a random face will be generated
                        dice2->roll(renderer);
                        //dice score is stored and displayed
                        int diceScore = dice2->diceScore();
                        std::cout << "Dice Score for Green is: " << diceScore << std::endl;

                        //condition if greenToken is not locked, then move to next position based on diceScore
                        if(greenToken->getPosition().x == 450 && greenToken->getPosition().y == 0 && greenToken->isLocked()){
                            if(diceScore==6){
                                greenToken->unlock(); //unlock green if dice score is 6
                                greenToken->setStartPosition(405,55); //Move token to start position
                                std::cout<<"Player green unlocked and moved to start location"<<std::endl;
                                std::cout<<"Player Green has another turn\n";
                                std::cout<<std::endl;
                                continue; //gets another turn
                            }
                            else{
                                currentTurn = Turn::DICE3;
                            }
                        }
                        else{
                            if(diceScore==6){
                            greenToken->moveToNextPositionGreen(diceScore);
                            currentTurn = Turn::DICE2;
                            std::cout<<"Player Green gets another turn!!\n"<<std::endl;
                            std::cout<<std::endl;
                            continue;
                            }

                            else{
                                greenToken->moveToNextPositionGreen(diceScore);
                                currentTurn = Turn::DICE3;
                                std::cout<<"Next Player's turn is: Player Yellow!!\n"<<std::endl;
                                std::cout<<std::endl;
                                }
                        }
                        checkAndMoveBackToHome(greenToken, redToken, yellowToken, blueToken);
                    }
                } else if (x >= 530 && x <= 662 && y >= 530 && y <= 662 && currentTurn == Turn::DICE3) {
                    if (dice3) {
                        //dice roll will happen and a random face will be generated
                        dice3->roll(renderer);
                        //dice score is stored and displayed
                        int diceScore = dice3->diceScore();
                        std::cout << "Dice Score for Yellow is: " << diceScore << std::endl;

                        //condition if yellowToken is not locked, then move to next position based on diceScore
                        if(yellowToken->getPosition().x == 710 && yellowToken->getPosition().y == 450 && yellowToken->isLocked()){
                            if(diceScore==6){
                                yellowToken->unlock(); //unlock yellow if dice score is 6
                                yellowToken->setStartPosition(655, 405); //Move token to start position
                                std::cout<<"Player Yellow unlocked and moved to start location"<<std::endl;
                                std::cout<<"Player Yellow has another turn!!!\n";
                                std::cout<<std::endl;
                                continue; //gets another turn
                            }
                            else{
                                currentTurn = Turn::DICE4;
                            }
                        }
                        else{
                            if(diceScore==6){
                                yellowToken->moveToNextPositionYellow(diceScore);
                                currentTurn = Turn::DICE3;
                                std::cout<<"Player Yellow gets another turn!!"<<std::endl;
                                std::cout<<std::endl;
                                continue;
                            }

                            else{
                            yellowToken->moveToNextPositionYellow(diceScore);
                            currentTurn = Turn::DICE4;
                            std::cout<<"Next Player's turn: Player Blue!!"<<std::endl;
                            std::cout<<std::endl;
                            }
                        }
                        checkAndMoveBackToHome(yellowToken, greenToken, redToken, blueToken);
    
                    }
                } else if (x >= 80 && x <= 530 && y >= 530 && y <= 662 && currentTurn == Turn::DICE4) {
                    if (dice4) {
                        //dice roll will happen and a random face will be generated
                        dice4->roll(renderer);
                        //dice score is stored and displayed
                        int diceScore = dice4->diceScore();
                        std::cout << "Dice Score for Blue is: " << diceScore << std::endl;
                        //condition if blueToken is not locked, then move to next position based on diceScore
                        if(blueToken->getPosition().x == 260 && blueToken->getPosition().y == 710 && blueToken->isLocked()){
                            if(diceScore==6){
                                blueToken->unlock(); //unlock blue if dice score is 6
                                blueToken->setStartPosition(305,655); //Move token to start position
                                std::cout<<"Player Blue unlocked and moved to start location";
                                std::cout<<"Player Blue has another Turn"<<std::endl;
                                std::cout<<std::endl;
                                continue; //gets another turn
                            }
                            else{
                                currentTurn = Turn::DICE1;
                                std::cout<<"Next Player's turn: Red\n";
                            }
                        }
                        else{
                            if(diceScore==6){
                            blueToken->moveToNextPositionBlue(diceScore);
                            checkAndMoveBackToHome(blueToken, greenToken, yellowToken, redToken);
                            currentTurn = Turn::DICE4;
                            std::cout<<"Player Blue gets another turn!!"<<std::endl;
                            std::cout<<std::endl;
                            }

                            else{
                                blueToken->moveToNextPositionBlue(diceScore);
                                checkAndMoveBackToHome(blueToken, greenToken, yellowToken, redToken);
                                currentTurn = Turn::DICE1;
                                std::cout<<"Next Player's turn: Player Red!!"<<std::endl;
                                std::cout<<std::endl;
                            }
                        }
                    
                    checkAndMoveBackToHome(blueToken, greenToken, yellowToken, redToken);   
                }

            }
        }
        }
        SDL_RenderClear(renderer);
        // Render the board
        SDL_RenderCopy(renderer, boardTexture, NULL, NULL);


        // Render the tokens
        redToken->render(renderer);
        greenToken->render(renderer);
        yellowToken->render(renderer);
        blueToken->render(renderer);
        if (dice1) {
            dice1->render(renderer);
        }

        if (dice2) {
            dice2->render(renderer);
        }

        if (dice3) {
            dice3->render(renderer);
        }

        if (dice4) {
            dice4->render(renderer);
        }

        // Present the renderer
        SDL_RenderPresent(renderer);

        // Add a slight delay to control the frame rate
        SDL_Delay(16);
    }
    SDL_DestroyTexture(boardTexture);
    // Mix_FreeMusic(music);
}


bool checkAndMoveBackToHome(Token* currentToken, Token* token2, Token* token3, Token* token4, ScoreCalculator& scoreCalculator){
        // Check if the new position overlaps with other tokens
         int currentPositionx = currentToken->getPosition().x;
         int currentPositiony = currentToken->getPosition().y;


        // Define your safe zone coordinates here
        std::vector<SDL_Point> safeZoneCoordinates = {
            {305,655}, {105,405}, {55,305}, {305,105}, {405,55}, {605,305}, {655,405}, {405, 605}
        };

        for (auto& safeCoordinate : safeZoneCoordinates) {
            if (currentPositionx == safeCoordinate.x && currentPositiony == safeCoordinate.y) {
                // Token is in the safe zone, no need to check for collision
                return false;
            }
        }

        if (currentToken->getPosition().x == token2->getPosition().x && currentToken->getPosition().y == token2->getPosition().y) {
            if(token2 == redToken){
                redToken->lock();
                redToken->setStartPosition(0,0);
                currentToken->killToken();
                scoreCalculator += currentToken;
                return true;
            }
            else if (token2 == greenToken){
                greenToken->lock();
                greenToken->setStartPosition(450,0);
                currentToken->killToken();
                return true;
            }
            else if(token2 == blueToken){
                blueToken->lock();
                blueToken->setStartPosition(260,710);
                currentToken->killToken();
                return true;
            }
            else if(token2 == yellowToken){
                yellowToken->lock();
                yellowToken->setStartPosition(710,450);
                currentToken->killToken();
                return true;
            }
            
        } else if (currentToken->getPosition().x == token3->getPosition().x && currentToken->getPosition().y == token3->getPosition().y) {
            if(token3 == redToken){
                redToken->lock();
                redToken->setStartPosition(0,0);
                currentToken->killToken();
                return true;
            }
            else if (token3 == greenToken){
                greenToken->lock();
                greenToken->setStartPosition(450,0);
                currentToken->killToken();
                return true;
            }
            else if(token3 == blueToken){
                blueToken->lock();
                blueToken->setStartPosition(260,710);
                currentToken->killToken();
                return true;
            }
            else if(token3 == yellowToken){
                yellowToken->lock();
                yellowToken->setStartPosition(710,450);
                currentToken->killToken();
                return true;
            }
        } else if (currentToken->getPosition().x == token4->getPosition().x && currentToken->getPosition().y == token4->getPosition().y) {
            if(token4 == redToken){
                redToken->lock();
                redToken->setStartPosition(0,0);
                currentToken->killToken();
                return true;
            }
            else if (token4 == greenToken){
                greenToken->lock();
                greenToken->setStartPosition(450,0);
                currentToken->killToken();
                return true;
            }
            else if(token4 == blueToken){
                blueToken->lock();
                blueToken->setStartPosition(260,710);
                currentToken->killToken();
                return true;
            }
            else if(token4 == yellowToken){
                yellowToken->lock();
                yellowToken->setStartPosition(710,450);
                currentToken->killToken();
                return true;
            }
        }
        return false;
}


// RulesScreen class
void RulesScreen::show(SDL_Renderer* renderer, ScreenType& nextScreen) {
    SDL_Surface* rules1 = IMG_Load("C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\rules\\rules1.png");
    SDL_Texture* rules1Texture = SDL_CreateTextureFromSurface(renderer, rules1);
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
                    PlayerSelectionScreen playerSelectionScreen(renderer);
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
    // Cleanup the first Dice object
    if (dice1) {
        delete dice1;
    }

    // Cleanup the second Dice object
    if (dice2) {
        delete dice2;
    }

    if (dice3) {
        delete dice3;
    }

    // Cleanup the second Dice object
    if (dice4) {
        delete dice4;
    }

    if (redToken) {
        delete redToken;
    }

    if(greenToken){
        delete greenToken;
    }

    if (yellowToken) {
        delete yellowToken;
    }

    if(blueToken){
        delete blueToken;
    }

}
// RulesScreen destructor
RulesScreen::~RulesScreen() {
    // Add any cleanup code if needed
}