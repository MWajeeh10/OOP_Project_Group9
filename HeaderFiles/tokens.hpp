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
    void moveToNextPosition(int diceScore);

private:
    SDL_Texture* texture;
    SDL_Rect position;
    int currentX;
    int currentY;

    // Declare boardMovement as a static member variable
    static std::vector<SDL_Point> boardMovement;
};