
#include "game.hpp"
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>

// #include "game.hpp"

// Implementation of WelcomeScreen
void WelcomeScreen::show(SDL_Renderer* renderer, ScreenType& nextScreen) {
    // Mix_Music* music = Mix_LoadMUS("C:\\Users\\hp\\Downloads\\oop project assets\\audio2.mp3");
    // Play music
    // Mix_PlayMusic(music, -1);

    SDL_Surface* image = IMG_Load("C:\\Users\\hp\\Downloads\\oop project assets\\screen1.png");
    SDL_Surface* imageClicked = IMG_Load("C:\\Users\\hp\\Downloads\\oop project assets\\screen2.png");
    SDL_Surface* rulesImage = IMG_Load("C:\\Users\\hp\\Downloads\\oop project assets\\rulesblink.png");
    
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
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
        // Stop the music when transitioning to the player selection screen
        // Mix_HaltMusic();
        nextScreen = ScreenType::PLAYER_SELECTION;
    }

    // Free the music at the end
    // Mix_FreeMusic(music);
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
    
    dice1 = new Dice(renderer, {"C:\\Users\\hp\\Downloads\\oop project assets\\red dice 1.png", 
                               "C:\\Users\\hp\\Downloads\\oop project assets\\red dice 2.png", 
                               "C:\\Users\\hp\\Downloads\\oop project assets\\red dice 3.png", 
                               "C:\\Users\\hp\\Downloads\\oop project assets\\red dice 4.png",
                               "C:\\Users\\hp\\Downloads\\oop project assets\\red dice 5.png", 
                               "C:\\Users\\hp\\Downloads\\oop project assets\\red dice 6.png"},
                    82, 80);

    dice2 = new Dice(renderer, {"C:\\Users\\hp\\Downloads\\oop project assets\\green dice 1.png", 
                               "C:\\Users\\hp\\Downloads\\oop project assets\\green dice 2.png", 
                               "C:\\Users\\hp\\Downloads\\oop project assets\\green dice 3.png", 
                               "C:\\Users\\hp\\Downloads\\oop project assets\\green dice 4.png",
                               "C:\\Users\\hp\\Downloads\\oop project assets\\green dice 5.png", 
                               "C:\\Users\\hp\\Downloads\\oop project assets\\green dice 6.png"},
                    530, 80);

    dice3 = new Dice(renderer, {"C:\\Users\\hp\\Downloads\\oop project assets\\yellow dice 1.png", 
                               "C:\\Users\\hp\\Downloads\\oop project assets\\yellow dice 2.png", 
                               "C:\\Users\\hp\\Downloads\\oop project assets\\yellow dice 3.png", 
                               "C:\\Users\\hp\\Downloads\\oop project assets\\yellow dice 4.png",
                               "C:\\Users\\hp\\Downloads\\oop project assets\\yellow dice 5.png", 
                               "C:\\Users\\hp\\Downloads\\oop project assets\\yellow dice 6.png"},
                    530, 530);

    dice4 = new Dice(renderer, {"C:\\Users\\hp\\Downloads\\oop project assets\\blue dice 1.png", 
                               "C:\\Users\\hp\\Downloads\\oop project assets\\blue dice 2.png", 
                               "C:\\Users\\hp\\Downloads\\oop project assets\\blue dice 3.png", 
                               "C:\\Users\\hp\\Downloads\\oop project assets\\blue dice 4.png",
                               "C:\\Users\\hp\\Downloads\\oop project assets\\blue dice 5.png", 
                               "C:\\Users\\hp\\Downloads\\oop project assets\\blue dice 6.png"},
                    80, 530);

}

// PlayerSelectionScreen class
void PlayerSelectionScreen::show(SDL_Renderer* renderer, ScreenType& nextScreen) {
    // Mix_Music* music = Mix_LoadMUS("C:\\Users\\hp\\Downloads\\oop project assets\\audio1.mp3");
    // Mix_PlayMusic(music, -1);
    // Load the board image
    SDL_Surface* boardImage = IMG_Load("C:\\Users\\hp\\Downloads\\oop project assets\\board.png");
    SDL_Texture* boardTexture = SDL_CreateTextureFromSurface(renderer, boardImage);
    //TOKEN:
    // Load textures for different colored tokens
    SDL_Texture* redTokenTexture = loadTexture("C:\\Users\\hp\\Downloads\\oop project assets\\red1.png", renderer);
    SDL_Texture* greenTokenTexture = loadTexture("C:\\Users\\hp\\Downloads\\oop project assets\\green1.png", renderer);
    SDL_Texture* yellowTokenTexture = loadTexture("C:\\Users\\hp\\Downloads\\oop project assets\\yellow1.png", renderer);
    SDL_Texture* blueTokenTexture = loadTexture("C:\\Users\\hp\\Downloads\\oop project assets\\blue1.png", renderer);
        // Check if loading any texture failed
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
    redToken = new Token(renderer, redTokenTexture);
    // redToken->setStartPosition(5, 305);
    redToken->setStartPosition(0, 0);
    redToken->lock(); //initial state will be locked


    greenToken = new Token(renderer, greenTokenTexture);
    // greenToken->setStartPosition(405, 55);
    greenToken->setStartPosition(450, 0);
    greenToken->lock(); //initial state will be locked


    yellowToken = new Token(renderer, yellowTokenTexture);
    // yellowToken->setStartPosition(655,405);
    yellowToken->setStartPosition(710, 450);
    yellowToken->lock(); //initial state will be locked



    blueToken = new Token(renderer, blueTokenTexture);
    // blueToken -> setStartPosition(305,655);
    blueToken->setStartPosition(260, 710);
    blueToken->lock(); //initial state will be locked

    SDL_FreeSurface(boardImage);

    // Render the board
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, boardTexture, NULL, NULL);

    redToken->render(renderer);
    greenToken->render(renderer);
    yellowToken->render(renderer);
    blueToken->render(renderer);

    SDL_RenderPresent(renderer);
    
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

                // std::cout<<"Current Turn: Player Red!!!"<<std::endl;
                // Handle dice rolling logic based on mouse click
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
                                // std::endl;

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
                        checkAndMoveBackToHome(redToken, greenToken, yellowToken, blueToken);

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
                            currentTurn = Turn::DICE4;
                            std::cout<<"Player Blue gets another turn!!"<<std::endl;
                            std::cout<<std::endl;
                            }

                            else{
                                blueToken->moveToNextPositionBlue(diceScore);
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
        // Clear the renderer
        SDL_RenderClear(renderer);

        // Render the board
        SDL_RenderCopy(renderer, boardTexture, NULL, NULL);


        // Render the tokens
        redToken->render(renderer);
        greenToken->render(renderer);
        yellowToken->render(renderer);
        blueToken->render(renderer);

        // Render the dice

        // Present the renderer
        SDL_RenderPresent(renderer);

        // Add a slight delay to control the frame rate
        SDL_Delay(16);
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
    }
    SDL_DestroyTexture(boardTexture);
    // Mix_FreeMusic(music);
}


bool PlayerSelectionScreen::checkAndMoveBackToHome(Token* currentToken, Token* token2, Token* token3, Token* token4) {
    // if (currentToken->getPosition().x != currentToken->mainTrackStartX() && currentToken->getPosition().y != currentToken->mainTrackStartY()){
        // Check if the new position overlaps with other tokens
        if (currentToken->getPosition().x == token2->getPosition().x &&currentToken->getPosition().y == token2->getPosition().y) {
            // // token2->moveToHome();
            // token2->lock();
            // bool check = true;
            if(token2 == redToken){
                redToken->lock();
                redToken->setStartPosition(0,0);
                // return true;
            }
            else if (token2 == greenToken){
                greenToken->lock();
                greenToken->setStartPosition(450,0);
                // return true;
            }
            else if(token2 == blueToken){
                blueToken->lock();
                blueToken->setStartPosition(260,710);
                // return true;
            }
            else if(token2 == yellowToken){
                yellowToken->lock();
                yellowToken->setStartPosition(710,450);
                // return true;
            }
            
        } else if (currentToken->getPosition().x == token3->getPosition().x &&currentToken->getPosition().y == token3->getPosition().y) {
            if(token3 == redToken){
                redToken->lock();
                redToken->setStartPosition(0,0);
                return true;
            }
            else if (token3 == greenToken){
                greenToken->lock();
                greenToken->setStartPosition(450,0);
                return true;
            }
            else if(token3 == blueToken){
                blueToken->lock();
                blueToken->setStartPosition(260,710);
                return true;
            }
            else if(token3 == yellowToken){
                yellowToken->lock();
                yellowToken->setStartPosition(710,450);
                return true;
            }
        } else if (currentToken->getPosition().x == token4->getPosition().x &&currentToken->getPosition().y == token4->getPosition().y) {
            if(token4 == redToken){
                redToken->lock();
                redToken->setStartPosition(0,0);
                return true;
            }
            else if (token4 == greenToken){
                greenToken->lock();
                greenToken->setStartPosition(450,0);
                return true;
            }
            else if(token4 == blueToken){
                blueToken->lock();
                blueToken->setStartPosition(260,710);
                return true;
            }
            else if(token4 == yellowToken){
                yellowToken->lock();
                yellowToken->setStartPosition(710,450);
                return true;
            }
        }
        return false;
    // }
}


// RulesScreen class
void RulesScreen::show(SDL_Renderer* renderer, ScreenType& nextScreen) {
    SDL_Surface* rules1 = IMG_Load("C:\\Users\\hp\\Downloads\\oop project assets\\rules1.png");
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
    : currentScreen(ScreenType::WELCOME), music(nullptr) {
    window = SDL_CreateWindow("Ludo Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 750, 750, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        // Initialize SDL Mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        // Handle initialization error
        std::cerr << "SDL Mixer audio initialization failed: " << Mix_GetError() << std::endl;
        // Add appropriate error handling
    }
    // Load music
    // music = Mix_LoadMUS("C:\\Users\\hp\\Downloads\\oop project assets\\audio2.mp3");
    // Create instances of MusicPlayer with different music files
    welcomeMusic = new MusicPlayer("C:\\Users\\hp\\Downloads\\oop project assets\\audio2.mp3");
    playerSelectionMusic = new MusicPlayer("C:\\Users\\hp\\Downloads\\oop project assets\\audio1.mp3");
    rulesMusic = new MusicPlayer("C:\\Users\\hp\\Downloads\\oop project assets\\audio2.mp3");
    // Play music only if it's not already playing
    playMusic();
}

ScreenManager::~ScreenManager() {
    // Free music
    if (welcomeMusic) {
        delete welcomeMusic;
    }

    if (playerSelectionMusic) {
        delete playerSelectionMusic;
    }

    if (rulesMusic) {
        delete rulesMusic;
    }

    // if (music) {
    //     Mix_FreeMusic(music);
    // }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_Quit();
    SDL_Quit();
}

void ScreenManager::playMusic() {
    // Play music based on the current screen
    if (currentScreen == ScreenType::WELCOME && welcomeMusic) {
        welcomeMusic->play();
    } else if (currentScreen == ScreenType::PLAYER_SELECTION && playerSelectionMusic) {
        playerSelectionMusic->play();
    } else if (currentScreen == ScreenType::RULES && rulesMusic) {
        rulesMusic->play();
    }
    // if (music) {
    //     // Play music only if it's not already playing
    //     if (Mix_PlayingMusic() == 0) {
    //         Mix_PlayMusic(music, -1);
    //     }
    // }
}

void ScreenManager::run() {
    while (currentScreen != ScreenType::EXIT) {
        playMusic();
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