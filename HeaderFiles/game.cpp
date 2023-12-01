#include "game.hpp"
#include <SDL_mixer.h>
#include <iostream>

// #include "game.hpp"

// Implementation of WelcomeScreen
void WelcomeScreen::show(SDL_Renderer* renderer, ScreenType& nextScreen) {
    Mix_Music* music = Mix_LoadMUS("C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\audio2.mp3");
    if (!music) {
        std::cout << "Unable to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return;
    }

    // Play music
    Mix_PlayMusic(music, -1);

    SDL_Surface* image = IMG_Load("C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\welcome\\screen1.png");
    SDL_Surface* imageClicked = IMG_Load("C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\welcome\\screen2.png");
    SDL_Surface* rulesImage = IMG_Load("C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\rules\\rulesblink.png");

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
        // Stop the music when transitioning to the player selection screen
        // Mix_HaltMusic();
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

PlayerSelectionScreen::PlayerSelectionScreen(SDL_Renderer* renderer) : dice1(nullptr), dice2(nullptr), dice3(nullptr), dice4(nullptr) {
    // Initialize the Dice object with the path to the dice image and initial position
    
    dice1 = new Dice(renderer, {"C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\red\\red1.png", 
                               "C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\red\\red2.png", 
                               "C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\red\\red3.png", 
                               "C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\red\\red4.png",
                               "C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\red\\red5.png", 
                               "C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\red\\red6.png"},
                    82, 80);

    dice2 = new Dice(renderer, {"C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\green\\green1.png", 
                               "C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\green\\green2.png", 
                               "C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\green\\green3.png", 
                               "C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\green\\green4.png",
                               "C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\green\\green5.png", 
                               "C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\green\\green6.png"},
                    530, 80);

    dice3 = new Dice(renderer, {"C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\yellow\\yellow1.png", 
                               "C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\yellow\\yellow2.png", 
                               "C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\yellow\\yellow3.png", 
                               "C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\yellow\\yellow4.png",
                               "C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\yellow\\yellow5.png", 
                               "C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\yellow\\yellow6.png"},
                    530, 530);

    dice4 = new Dice(renderer, {"C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\blue\\blue1.png", 
                               "C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\blue\\blue2.png", 
                               "C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\blue\\blue3.png", 
                               "C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\blue\\blue4.png",
                               "C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\blue\\blue5.png", 
                               "C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\blue\\blue6.png"},
                    80, 530);

}
// PlayerSelectionScreen class
void PlayerSelectionScreen::show(SDL_Renderer* renderer, ScreenType& nextScreen) {

    Mix_Music* music = Mix_LoadMUS("C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\audio1.mp3");
        if (!music) {
            std::cout << "Unable to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
            return;
        }
    Mix_PlayMusic(music, -1);

    // Load the board image
    SDL_Surface* boardImage = IMG_Load("C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\board.png");
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
    SDL_Texture* redTokenTexture = loadTexture("C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\tokens\\red.png", renderer);
    SDL_Texture* greenTokenTexture = loadTexture("C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\tokens\\green.png", renderer);
    SDL_Texture* blueTokenTexture = loadTexture("C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\tokens\\blue.png", renderer);
    SDL_Texture* yellowTokenTexture = loadTexture("C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\tokens\\yellow.png", renderer);

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
    renderTexture(blueTokenTexture, renderer, 305, 655);//0, 450);
    renderTexture(blueTokenTexture, renderer, 0, 710);
    renderTexture(blueTokenTexture, renderer, 260, 450);
    renderTexture(blueTokenTexture, renderer, 260, 710);

    // Render yellow tokens at different positions
    renderTexture(yellowTokenTexture, renderer, 450, 450);
    renderTexture(yellowTokenTexture, renderer, 450, 710);
    renderTexture(yellowTokenTexture, renderer, 710, 710);
    renderTexture(yellowTokenTexture, renderer, 710, 450);

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
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                nextScreen = ScreenType::EXIT;  // Update nextScreen if the user quits
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";

                // Check if the click is on the dice
                if (x >= 80 && x <= 212 && y >= 80 && y <= 212) {
                    // Add logic for rolling effect and random selection of dice value
                    if (dice1) {
                        dice1->roll(renderer);
                    }
                } 
                else if (x >= 530 && x <= 662 && y >= 80 && y <= 212) {
                    // Add logic for rolling effect and random selection of dice value for the second dice
                    if (dice2) {
                        dice2->roll(renderer);
                    }
                }
                else if (x >= 530 && x <= 662 && y >= 530 && y <= 662) {
                    // Add logic for rolling effect and random selection of dice value for the third dice
                    if (dice3) {
                        dice3->roll(renderer);
                    }
                }
                else if (x >= 80 && x <= 530 && y >= 530 && y <= 662) {
                    // Add logic for rolling effect and random selection of dice value for the fourth dice
                    if (dice4) {
                        dice4->roll(renderer);
                    }
                }

                // Add other logic for player selection if needed
            }
        }
    }

    SDL_DestroyTexture(boardTexture);
    SDL_DestroyTexture(redTokenTexture);
    SDL_DestroyTexture(greenTokenTexture);
    SDL_DestroyTexture(blueTokenTexture);
    SDL_DestroyTexture(yellowTokenTexture);
    // SDL_DestroyTexture(texture);
    Mix_FreeMusic(music);
}
// Inside the PlayerSelectionScreen class
void PlayerSelectionScreen::token_move(SDL_Renderer* renderer) {
    int token_movement_array[][2] = {
        {305, 655}, {305, 605}, {305, 555}, {305, 505},
        {305, 455}, {255, 405}, {205, 405}, {155, 405},
        {105, 405}, {55, 405}, {5, 405}, {5, 355},
        {5, 305}, {55, 305}, {105, 305}, {155, 305},
        {205, 305}, {255, 305}, {305, 255}, {305, 205},
        {305, 155}, {305, 105}, {305, 55}, {305, 5},
        {355, 5}, {405, 5}, {405, 55}, {405, 105},
        {405, 155}, {405, 205}, {405, 255}, {405, 305},
        {505, 305}, {555, 305}, {605, 305}, {655, 305},
        {705, 305}, {705, 355}, {705, 405}, {655, 405},
        {605, 405}, {555, 405}, {505, 405}, {455, 405},
        {405, 455}, {405, 505}, {405, 555}, {405, 605},
        {405, 655}, {405, 705}, {355, 705}, {305, 705}
    };

    SDL_Texture* redTokenTexture = loadTexture("C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\tokens\\red.png", renderer);
    if (!redTokenTexture) {
        std::cout<<"Not found!"<<std::endl;
        return;
    }

    for (int i = 0; i < sizeof(token_movement_array) / sizeof(token_movement_array[0]); ++i) {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, boardTexture, NULL, NULL);

        // Render red tokens at different positions
        renderTexture(redTokenTexture, renderer, token_movement_array[i][0], token_movement_array[i][1]);

        SDL_RenderPresent(renderer);
        SDL_Delay(250); // Adjust the delay as needed
    }

    SDL_DestroyTexture(redTokenTexture);
}


// RulesScreen class
void RulesScreen::show(SDL_Renderer* renderer, ScreenType& nextScreen) {
    SDL_Surface* rules1 = IMG_Load("C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\rules\\rules1.png");
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
    music = Mix_LoadMUS("C:\\Users\\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\audio2.mp3");
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
                PlayerSelectionScreen playerSelectionScreen(renderer);  // Pass renderer here
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
}

// RulesScreen destructor
RulesScreen::~RulesScreen() {
    // Add any cleanup code if needed
}

