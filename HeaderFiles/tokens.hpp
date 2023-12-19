// // Token.h
// #ifndef TOKEN_H
// #define TOKEN_H

// #include <SDL.h>

// class Token {
// public:
//     Token(int homeX, int homeY);
//     ~Token();

//     void render(SDL_Renderer* renderer);
//     void moveTo(int destinationX, int destinationY);
//     void update();

// private:
//     int currentX;
//     int currentY;
//     int homeX;
//     int homeY;
//     int destinationX;
//     int destinationY;
//     int mainTrackStartX;
//     int mainTrackStartY;
//     int mainTrackLength;
//     // Add any other necessary properties

//     bool moving;
// };

// #endif // TOKEN_H




// token.hpp
#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>

class Token {
public:
    Token(SDL_Renderer* renderer, SDL_Texture* texture);
    ~Token();

    void render(SDL_Renderer* renderer);
    void setStartPosition(int startX, int startY);
    // void move(int steps);
    SDL_Rect getPosition() const;

    // Moving to the next position for each token
    void moveToNextPositionRed(int diceScore);
    void moveToNextPositionGreen(int diceScore);
    void moveToNextPositionYellow(int diceScore);
    void moveToNextPositionBlue(int diceScore);
    bool isLocked() const {
        return locked;
    }
    void unlock() {
        locked = false;
    }

    // Add the lock method
    void lock() {
        locked = true;
    }
    // bool killed;
    // void hasKill();

private:
    SDL_Texture* texture;
    SDL_Rect position;

    int currentX;
    int currentY;
    bool locked;
    
    // Declare boardMovement as a static member variable
    static std::vector<SDL_Point> boardMovementRed;
    static std::vector<SDL_Point> boardMovementGreen;
    static std::vector<SDL_Point> boardMovementYellow;
    static std::vector<SDL_Point> boardMovementBlue;
    

    // virtual ~Token(){}
};
