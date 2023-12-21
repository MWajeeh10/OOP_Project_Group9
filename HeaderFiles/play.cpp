#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <vector>
#include "play.hpp"


SDL_Texture* play::loadTexture(const std::string& path, SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load(path.c_str());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void play::renderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y) {
    SDL_Rect destination;
    destination.x = x;
    destination.y = y;
    SDL_QueryTexture(texture, nullptr, nullptr, &destination.w, &destination.h);
    SDL_RenderCopy(renderer, texture, nullptr, &destination);
}

play::play(SDL_Renderer* renderer) : dice1(nullptr), dice2(nullptr), dice3(nullptr), dice4(nullptr),currentTurn(Turn::DICE1) {
    // Initialize the Dice object with the path to the dice image and initial position
    
    dice1 = new Dice(renderer, {{"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\red\\red1.png",1},
                               {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\red\\red2.png",2},
                               {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\red\\red3.png",3},
                               {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\red\\red4.png",4},
                               {"C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\dices\\red\\red5.png",5},
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

                    // musicManager.loadScreenMusic(ScreenType::PLAYER_SELECTION, "C:\\Users\\USER\\OneDrive\\Documents\\GitHub\\OOP_Project_Group9\\assets\\audio2.mp3");
                    // musicManager.playScreenMusic(ScreenType::PLAYER_SELECTION);


}

// play class
void play::show(SDL_Renderer* renderer, ScreenType& nextScreen) {

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
        while (SDL_PollEvent(&event)) {  //!checks for pending event and retrieves and stores it. continue as long as there are events in queue
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
                                // checkAndMoveBackToHome(redToken,blueToken,greenToken,yellowToken)
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
                                checkAndMoveBackToHome(redToken,blueToken,greenToken,yellowToken);
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
                        checkAndMoveBackToHome(redToken, blueToken, greenToken, yellowToken);

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
                            checkAndMoveBackToHome(greenToken,redToken,yellowToken,blueToken);
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


bool play::checkAndMoveBackToHome(Token* currentToken, Token* token2, Token* token3, Token* token4){
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
                std::cout<<"SOMEONE HAS BEEN KILLLEEEEEDDDDD!!!!!!";
                scoreCalculator += currentToken;
                std::cout<<"score for "<<currentToken<< " is: "<< scoreCalculator[currentToken];
                return true;
            }
            else if (token2 == greenToken){
                greenToken->lock();
                greenToken->setStartPosition(450,0);
                currentToken->killToken();
                scoreCalculator += currentToken;
                std::cout<<"SOMEONE HAS BEEN KILLLEEEEEDDDDD!!!!!!";
                std::cout<<"score for "<<currentToken<< " is: "<< scoreCalculator[currentToken];

                return true;
            }
            else if(token2 == blueToken){
                blueToken->lock();
                blueToken->setStartPosition(260,710);
                currentToken->killToken();
                scoreCalculator += currentToken;
                std::cout<<"SOMEONE HAS BEEN KILLLEEEEEDDDDD!!!!!!";
                std::cout<<"score for "<<currentToken<< " is: "<< scoreCalculator[currentToken];

                return true;
            }
            else if(token2 == yellowToken){
                yellowToken->lock();
                yellowToken->setStartPosition(710,450);
                currentToken->killToken();
                scoreCalculator += currentToken;
                std::cout<<"SOMEONE HAS BEEN KILLLEEEEEDDDDD!!!!!!";
                std::cout<<"score for "<<currentToken<< " is: "<< scoreCalculator[currentToken];

                return true;
            }
            
        } else if (currentToken->getPosition().x == token3->getPosition().x && currentToken->getPosition().y == token3->getPosition().y) {
            if(token3 == redToken){
                redToken->lock();
                redToken->setStartPosition(0,0);
                currentToken->killToken();
                scoreCalculator += currentToken;
                std::cout<<"SOMEONE HAS BEEN KILLLEEEEEDDDDD!!!!!!";
                std::cout<<"score for "<<currentToken<< " is: "<< scoreCalculator[currentToken];
                return true;
            }
            else if (token3 == greenToken){
                greenToken->lock();
                greenToken->setStartPosition(450,0);
                currentToken->killToken();
                scoreCalculator += currentToken;
                std::cout<<"SOMEONE HAS BEEN KILLLEEEEEDDDDD!!!!!!";
                std::cout<<"score for "<<currentToken<< " is: "<< scoreCalculator[currentToken];
                return true;
            }
            else if(token3 == blueToken){
                blueToken->lock();
                blueToken->setStartPosition(260,710);
                currentToken->killToken();
                scoreCalculator += currentToken;
                std::cout<<"SOMEONE HAS BEEN KILLLEEEEEDDDDD!!!!!!";
                std::cout<<"score for "<<currentToken<< " is: "<< scoreCalculator[currentToken];
                return true;
            }
            else if(token3 == yellowToken){
                yellowToken->lock();
                yellowToken->setStartPosition(710,450);
                currentToken->killToken();
                scoreCalculator += currentToken;
                std::cout<<"SOMEONE HAS BEEN KILLLEEEEEDDDDD!!!!!!";
                std::cout<<"score for "<<currentToken<< " is: "<< scoreCalculator[currentToken];
                return true;
            }
        } else if (currentToken->getPosition().x == token4->getPosition().x && currentToken->getPosition().y == token4->getPosition().y) {
            if(token4 == redToken){
                redToken->lock();
                redToken->setStartPosition(0,0);
                currentToken->killToken();
                scoreCalculator += currentToken;
                std::cout<<"SOMEONE HAS BEEN KILLLEEEEEDDDDD!!!!!!";
                std::cout<<"score for "<<currentToken<< " is: "<< scoreCalculator[currentToken];
                return true;
            }
            else if (token4 == greenToken){
                greenToken->lock();
                greenToken->setStartPosition(450,0);
                currentToken->killToken();
                scoreCalculator += currentToken;
                std::cout<<"SOMEONE HAS BEEN KILLLEEEEEDDDDD!!!!!!";
                std::cout<<"score for "<<currentToken<< " is: "<< scoreCalculator[currentToken];
                return true;
            }
            else if(token4 == blueToken){
                blueToken->lock();
                blueToken->setStartPosition(260,710);
                currentToken->killToken();
                scoreCalculator += currentToken;
                std::cout<<"SOMEONE HAS BEEN KILLLEEEEEDDDDD!!!!!!";
                std::cout<<"score for "<<currentToken<< " is: "<< scoreCalculator[currentToken];
                return true;
            }
            else if(token4 == yellowToken){
                yellowToken->lock();
                yellowToken->setStartPosition(710,450);
                currentToken->killToken();
                scoreCalculator += currentToken;
                std::cout<<"SOMEONE HAS BEEN KILLLEEEEEDDDDD!!!!!!"<<std::endl;
                std::cout<<"score for "<<currentToken<< " is: "<< scoreCalculator[currentToken];
                return true;
            }
        }
        return false;
}
//! copy assignment operator, copy constructor   C:\Users\USER\OneDrive\Desktop\Semester 3\OOP\OOP_Project_Group9\HeaderFiles\dice.hpp
play::~play() {
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

    // musicManager.stopMusic();


}