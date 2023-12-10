// token.cpp
#include "tokens.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>


/*
VECTORS FOR DEFINING PATH OF EACH TOKEN ON THE BOARD.
THE PATHS DO NOT INCLUDE THE FINAL GAME WINNING PATH
*/

//PATH FOR RED TOKEN
std::vector<SDL_Point> Token::boardMovementRed = {
    {55, 305 }, {105, 305}, {155, 305}, 
    {205, 305}, {255, 305}, {305, 255}, {305, 205}, 
    {305, 155}, {305, 105}, {305, 55 }, {305, 5  }, 
    {355, 5  }, {405, 5  }, {405, 55 }, {405, 105}, 
    {405, 155}, {405, 205}, {405, 255}, {455, 305}, 
    {505, 305}, {555, 305}, {605, 305}, {655, 305}, 
    {705, 305}, {705, 355}, {705, 405}, {655, 405}, 
    {605, 405}, {555, 405}, {505, 405}, {455, 405}, 
    {405, 455}, {405, 505}, {405, 555}, {405, 605}, 
    {405, 655}, {405, 705}, {355, 705}, {305, 705},
    {305, 655}, {305, 605}, {305, 555}, {305, 505}, 
    {305, 455}, {255, 405}, {205, 405}, {155, 405}, 
    {105, 405}, {55, 405 }, {5, 405  }, {5, 355  }, 
};


//PATH FOR GREEN TOKEN
std::vector<SDL_Point> Token::boardMovementGreen= {
    {405, 55 }, {405, 105}, {405, 155}, {405, 205}, 
    {405, 255}, {455, 305}, {505, 305}, {555, 305}, 
    {605, 305}, {655, 305}, {705, 305}, {705, 355}, 
    {705, 405}, {655, 405}, {605, 405}, {555, 405}, 
    {505, 405}, {455, 405}, {405, 455}, {405, 505},
    {405, 555}, {405, 605}, {405, 655}, {405, 705}, 
    {355, 705}, {305, 705},{305, 655}, {305, 605}, 
    {305, 555}, {305, 505}, {305, 455}, {255, 405}, 
    {205, 405}, {155, 405}, {105, 405}, {55, 405 }, 
    {5, 405  }, {5, 355  }, {55, 305 }, {105, 305},  
    {155, 305},{205, 305}, {255, 305}, {305, 255}, 
    {305, 205}, {305, 155}, {305, 105}, {305, 55 }, 
    {305, 5  },{355,5}
};


//PATH FOR YELLOW TOKEN
std::vector<SDL_Point> Token::boardMovementYellow= {
    {655, 405}, {605, 405}, {555, 405}, 
    {505, 405}, {455, 405}, {405, 455}, {405, 505},
    {405, 555}, {405, 605}, {405, 655}, {405, 705}, 
    {355, 705}, {305, 705},{305, 655}, {305, 605}, 
    {305, 555}, {305, 505}, {305, 455}, {255, 405}, 
    {205, 405}, {155, 405}, {105, 405}, {55, 405 }, 
    {5, 405  }, {5, 355  }, {55, 305 }, {105, 305},  
    {155, 305},{205, 305}, {255, 305}, {305, 255}, 
    {305, 205}, {305, 155}, {305, 105}, {305, 55 }, 
    {305, 5  },{355,5},{405, 55 }, {405, 105}, 
    {405, 155}, {405, 205}, {405, 255}, {455, 305}, 
    {505, 305}, {555, 305}, {605, 305}, {655, 305}, 
    {705, 305}, {705, 355}
};


//PATH FOR BLUE TOKEN
std::vector<SDL_Point> Token::boardMovementBlue= {
    {305, 655}, {305, 605}, 
    {305, 555}, {305, 505}, {305, 455}, {255, 405}, 
    {205, 405}, {155, 405}, {105, 405}, {55, 405 }, 
    {5, 405  }, {5, 355  }, {55, 305 }, {105, 305},  
    {155, 305},{205, 305}, {255, 305}, {305, 255}, 
    {305, 205}, {305, 155}, {305, 105}, {305, 55 }, 
    {305, 5  },{355,5},{405, 55 }, {405, 105},
    {405, 155}, {405, 205}, {405, 255}, {455, 305}, 
    {505, 305}, {555, 305}, {605, 305}, {655, 305}, 
    {705, 305}, {705, 355}, {705, 405}, {655, 405}, 
    {605, 405}, {555, 405}, {505, 405}, {455, 405}, 
    {405, 655}, {405, 705}, {355, 705}
};








Token::Token(SDL_Renderer* renderer, SDL_Texture* texture)
    : texture(texture), currentX(0), currentY(0) {
    SDL_QueryTexture(texture, nullptr, nullptr, &position.w, &position.h);
}

Token::~Token() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

void Token::render(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, texture, nullptr, &position);
}

void Token::setStartPosition(int startX, int startY) {
    currentX = startX;
    currentY = startY;
    position.x = startX;
    position.y = startY;
}



//movement for Red
void Token::moveToNextPositionRed(int diceScore) {
    // Assuming a standard Ludo board
    const int homeX = 5;
    const int homeY = 5;
    const int mainTrackStartX = 55;
    const int mainTrackStartY = 305;
    const int mainTrackLength = 50;
    const int destinationX = 5;
    const int destinationY = 355;

    // Check if the token is in the home area
    if (position.x == homeX && position.y == homeY && diceScore > 0) {
        // Move along the vertical path to the starting point of the main track
        position.y -= diceScore * mainTrackLength; // Adjust TOKEN_STEP_SIZE according to your needs
        if (position.y < mainTrackStartY) {
            position.y = mainTrackStartY;
        }
    } else {
        // Calculate the current position within the main track based on the board movement array
        for (size_t i = 0; i < boardMovementRed.size(); ++i) {
            if (position.x == boardMovementRed[i].x && position.y == boardMovementRed[i].y) {
                int newPositionIndex = i + diceScore;

                // If the new position index exceeds the boardMovement size, set it to the destination
                if (newPositionIndex >= boardMovementRed.size()) {
                    newPositionIndex = boardMovementRed.size() - 1;
                    // newPositionIndex = (i + diceScore) % boardMovement.size();

                }

                // Move the token along the predefined board positions
                position.x = boardMovementRed[newPositionIndex].x;
                position.y = boardMovementRed[newPositionIndex].y;

                // Check if the token has reached the destination
                if (position.x == destinationX && position.y == destinationY) {
                    // You may want to add additional logic or handle reaching the destination here
                    // For now, let's set the position to the destination to stop the token
                    position.x = destinationX;
                    position.y = destinationY;
                }

                break;  // Exit the loop once the new position is set
            }
        }
    }
}




//movement for green
void Token::moveToNextPositionGreen(int diceScore) {
    // Assuming a standard Ludo board
    const int homeX = 450;
    const int homeY = 0;
    const int mainTrackStartX = 605;
    const int mainTrackStartY = 405;
    const int mainTrackLength = 50;
    const int destinationX = 355;
    const int destinationY = 5;

    // Check if the token is in the home area
    if (position.x == homeX && position.y == homeY && diceScore > 0) {
        // Move along the vertical path to the starting point of the main track
        position.y -= diceScore * mainTrackLength; // Adjust TOKEN_STEP_SIZE according to your needs
        if (position.y < mainTrackStartY) {
            position.y = mainTrackStartY;
        }
    } else {
        // Calculate the current position within the main track based on the board movement array
        for (size_t i = 0; i < boardMovementGreen.size(); ++i) {
            if (position.x == boardMovementGreen[i].x && position.y == boardMovementGreen[i].y) {
                int newPositionIndex = i + diceScore;

                // If the new position index exceeds the boardMovement size, set it to the destination
                if (newPositionIndex >= boardMovementGreen.size()) {
                    newPositionIndex = boardMovementGreen.size() - 1;
                    // newPositionIndex = (i + diceScore) % boardMovement.size();

                }

                // Move the token along the predefined board positions
                position.x = boardMovementGreen[newPositionIndex].x;
                position.y = boardMovementGreen[newPositionIndex].y;

                // Check if the token has reached the destination
                if (position.x == destinationX && position.y == destinationY) {
                    // You may want to add additional logic or handle reaching the destination here
                    // For now, let's set the position to the destination to stop the token
                    position.x = destinationX;
                    position.y = destinationY;
                }

                break;  // Exit the loop once the new position is set
            }
        }
    }
}





//movement for Yellow
void Token::moveToNextPositionYellow(int diceScore) {
    // Assuming a standard Ludo board
    const int homeX = 660;
    const int homeY = 450;
    const int mainTrackStartX = 655;
    const int mainTrackStartY = 405;
    const int mainTrackLength = 50;
    const int destinationX = 705;
    const int destinationY = 355;

    // Check if the token is in the home area
    if (position.x == homeX && position.y == homeY && diceScore > 0) {
        // Move along the vertical path to the starting point of the main track
        position.y -= diceScore * mainTrackLength; // Adjust TOKEN_STEP_SIZE according to your needs
        if (position.y < mainTrackStartY) {
            position.y = mainTrackStartY;
        }
    } else {
        // Calculate the current position within the main track based on the board movement array
        for (size_t i = 0; i < boardMovementYellow.size(); ++i) {
            if (position.x == boardMovementYellow[i].x && position.y == boardMovementYellow[i].y) {
                int newPositionIndex = i + diceScore;

                // If the new position index exceeds the boardMovement size, set it to the destination
                if (newPositionIndex >= boardMovementYellow.size()) {
                    newPositionIndex = boardMovementYellow.size() - 1;
                    // newPositionIndex = (i + diceScore) % boardMovement.size();

                }

                // Move the token along the predefined board positions
                position.x = boardMovementYellow[newPositionIndex].x;
                position.y = boardMovementYellow[newPositionIndex].y;

                // Check if the token has reached the destination
                if (position.x == destinationX && position.y == destinationY) {
                    // You may want to add additional logic or handle reaching the destination here
                    // For now, let's set the position to the destination to stop the token
                    position.x = destinationX;
                    position.y = destinationY;
                }

                break;  // Exit the loop once the new position is set
            }
        }
    }
}

SDL_Rect Token::getPosition() const {
    return position;
}


//movement for Blue
void Token::moveToNextPositionBlue(int diceScore) {
    // Assuming a standard Ludo board
    const int homeX = 260;
    const int homeY = 710;
    const int mainTrackStartX = 305;
    const int mainTrackStartY = 655;
    const int mainTrackLength = 50;
    const int destinationX = 355;
    const int destinationY = 705;

    // Check if the token is in the home area
    if (position.x == homeX && position.y == homeY && diceScore > 0) {
        // Move along the vertical path to the starting point of the main track
        position.y -= diceScore * mainTrackLength; // Adjust TOKEN_STEP_SIZE according to your needs
        if (position.y < mainTrackStartY) {
            position.y = mainTrackStartY;
        }
    } else {
        // Calculate the current position within the main track based on the board movement array
        for (size_t i = 0; i < boardMovementBlue.size(); ++i) {
            if (position.x == boardMovementBlue[i].x && position.y == boardMovementBlue[i].y) {
                int newPositionIndex = i + diceScore;

                // If the new position index exceeds the boardMovement size, set it to the destination
                if (newPositionIndex >= boardMovementBlue.size()) {
                    newPositionIndex = boardMovementBlue.size() - 1;
                    // newPositionIndex = (i + diceScore) % boardMovement.size();

                }

                // Move the token along the predefined board positions
                position.x = boardMovementBlue[newPositionIndex].x;
                position.y = boardMovementBlue[newPositionIndex].y;

                // Check if the token has reached the destination
                if (position.x == destinationX && position.y == destinationY) {
                    // You may want to add additional logic or handle reaching the destination here
                    // For now, let's set the position to the destination to stop the token
                    position.x = destinationX;
                    position.y = destinationY;
                }

                break;  // Exit the loop once the new position is set
            }
        }
    }
}






// void Token::moveToNextPosition(int diceScore) {
//     // Assuming a standard Ludo board
//     const int homeX = 5;
//     const int homeY = 5;
//     const int mainTrackStartX = 55;
//     const int mainTrackStartY = 305;
//     const int mainTrackLength = 50;
//     const int destinationX = 5;
//     const int destinationY = 355;

//     // Calculate the current position within the main track
//     int currentPositionIndex = -1;

//     // If the token is in the home area
//     // If the token is in the home area
//     if (position.x == homeX && position.y == homeY && diceScore > 0) {
//         // Move along the vertical path to the starting point of the main track
//         position.y -= diceScore * mainTrackLength; // Adjust TOKEN_STEP_SIZE according to your needs
//         if (position.y < mainTrackStartY) {
//             position.y = mainTrackStartY;
//         }
//     } else {
//         // Calculate the current position within the main track based on the board movement array
//         for (size_t i = 0; i < boardMovement.size(); ++i) {
//             if (position.x == boardMovement[i].x && position.y == boardMovement[i].y) {
//                 currentPositionIndex = i;
//                 break;
//             }
//         }

//         // If the token is still on the board and needs to move
//         if (currentPositionIndex >= 0 && currentPositionIndex < boardMovement.size() && diceScore > 0) {
//             int newPositionIndex = currentPositionIndex + diceScore;

//             // If the new position index exceeds the boardMovement size, adjust the index
//             if (newPositionIndex >= boardMovement.size()) {
//                 newPositionIndex = boardMovement.size() - 1;
//             }

//             // Move the token along the predefined board positions
//             position.x = boardMovement[newPositionIndex].x;
//             position.y = boardMovement[newPositionIndex].y;
//         }
//     }
//     }











// // token.cpp
// #include "tokens.hpp"
// #include <SDL.h>
// #include <SDL_image.h>
// #include <iostream>
// #include <vector>

// std::vector<SDL_Point> Token::boardMovement = {
//     {55, 305 }, {105, 305}, {155, 305}, 
//     {205, 305}, {255, 305}, {305, 255}, {305, 205}, 
//     {305, 155}, {305, 105}, {305, 55 }, {305, 5  }, 
//     {355, 5  }, {405, 5  }, {405, 55 }, {405, 105}, 
//     {405, 155}, {405, 205}, {405, 255}, {455, 305}, 
//     {505, 305}, {555, 305}, {605, 305}, {655, 305}, 
//     {705, 305}, {705, 355}, {705, 405}, {655, 405}, 
//     {605, 405}, {555, 405}, {505, 405}, {455, 405}, 
//     {405, 455}, {405, 505}, {405, 555}, {405, 605}, 
//     {405, 655}, {405, 705}, {355, 705}, {305, 705},
//     {305, 655}, {305, 605}, {305, 555}, {305, 505}, 
//     {305, 455}, {255, 405}, {205, 405}, {155, 405}, 
//     {105, 405}, {55, 405 }, {5, 405  }, {5, 355  }, 
// };

// Token::Token(SDL_Renderer* renderer, SDL_Texture* texture)
//     : texture(texture), currentX(0), currentY(0) {
//     SDL_QueryTexture(texture, nullptr, nullptr, &position.w, &position.h);
// }

// Token::~Token() {
//     if (texture) {
//         SDL_DestroyTexture(texture);
//     }
// }

// void Token::render(SDL_Renderer* renderer) {
//     SDL_RenderCopy(renderer, texture, nullptr, &position);
// }

// void Token::setStartPosition(int startX, int startY) {
//     currentX = startX;
//     currentY = startY;
//     position.x = startX;
//     position.y = startY;
// }


// void Token::moveToNextPosition(int diceScore) {
//     // Assuming a standard Ludo board
//     const int homeX = 5;
//     const int homeY = 5;
//     const int mainTrackStartX = 55;
//     const int mainTrackStartY = 305;
//     const int mainTrackLength = 50;
//     const int destinationX = 5;
//     const int destinationY = 355;

//     // Check if the token is in the home area
//     if (position.x == homeX && position.y == homeY && diceScore > 0) {
//         // Move along the vertical path to the starting point of the main track
//         position.y -= diceScore * mainTrackLength; // Adjust TOKEN_STEP_SIZE according to your needs
//         if (position.y < mainTrackStartY) {
//             position.y = mainTrackStartY;
//         }
//     } else {
//         // Calculate the current position within the main track based on the board movement array
//         for (size_t i = 0; i < boardMovement.size(); ++i) {
//             if (position.x == boardMovement[i].x && position.y == boardMovement[i].y) {
//                 int newPositionIndex = i + diceScore;

//                 // If the new position index exceeds the boardMovement size, set it to the destination
//                 if (newPositionIndex >= boardMovement.size()) {
//                     newPositionIndex = boardMovement.size() - 1;
//                     // newPositionIndex = (i + diceScore) % boardMovement.size();

//                 }

//                 // Move the token along the predefined board positions
//                 position.x = boardMovement[newPositionIndex].x;
//                 position.y = boardMovement[newPositionIndex].y;

//                 // Check if the token has reached the destination
//                 if (position.x == destinationX && position.y == destinationY) {
//                     // You may want to add additional logic or handle reaching the destination here
//                     // For now, let's set the position to the destination to stop the token
//                     position.x = destinationX;
//                     position.y = destinationY;
//                 }

//                 break;  // Exit the loop once the new position is set
//             }
//         }
//     }
// }

