// token.cpp
#include "tokens.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>

std::vector<SDL_Point> Token::boardMovement = {
    {305, 655}, {305, 605}, {305, 555}, {305, 505}, 
    {305, 455}, {255, 405}, {205, 405}, {155, 405}, 
    {105, 405}, {55, 405 }, {5, 405  }, {5, 355  }, 
    {5, 305  }, {55, 305 }, {105, 305}, {155, 305}, 
    {205, 305}, {255, 305}, {305, 255}, {305, 205}, 
    {305, 155}, {305, 105}, {305, 55 }, {305, 5  }, 
    {355, 5  }, {405, 5  }, {405, 55 }, {405, 105}, 
    {405, 155}, {405, 205}, {405, 255}, {455, 305}, 
    {505, 305}, {555, 305}, {605, 305}, {655, 305}, 
    {705, 305}, {705, 355}, {705, 405}, {655, 405}, 
    {605, 405}, {555, 405}, {505, 405}, {455, 405}, 
    {405, 455}, {405, 505}, {405, 555}, {405, 605}, 
    {405, 655}, {405, 705}, {355, 705}, {305, 705}
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

void Token::moveToNextPosition(int diceScore) {
    // Assuming a standard Ludo board
    const int homeX = 5;
    const int homeY = 5;
    const int mainTrackStartX = 55;
    const int mainTrackStartY = 305;
    const int mainTrackLength = 50;
    const int destinationX = 5;
    const int destinationY = 305;

    // Calculate the current position within the main track
    int currentPositionIndex = -1;

    // If the token is in the home area
    if (position.x == homeX && position.y == homeY && diceScore > 0) {
        // Move along the vertical path to the starting point of the main track
        position.y -= diceScore * mainTrackLength; // Adjust TOKEN_STEP_SIZE according to your needs
        if (position.y < mainTrackStartY) {
            position.y = mainTrackStartY;
        }
    } else {
        // Calculate the current position within the main track based on the board movement array
        for (size_t i = 0; i < boardMovement.size(); ++i) {
            if (position.x == boardMovement[i].x && position.y == boardMovement[i].y) {
                currentPositionIndex = i;
                break;
            }
        }

        // If the token is still on the board and needs to move
        if (currentPositionIndex >= 0 && currentPositionIndex < boardMovement.size() && diceScore > 0) {
            currentPositionIndex += diceScore;

            // If the token reaches the end of the board positions
            if (currentPositionIndex >= boardMovement.size()) {
                // Implement logic for reaching the destination area
                // You may want to handle special actions or conditions when the token reaches the destination
                position.x = destinationX;
                position.y = destinationY;
            } else {
                // Move the token along the predefined board positions
                position.x = boardMovement[currentPositionIndex].x;
                position.y = boardMovement[currentPositionIndex].y;
            }
        }
    }
}


SDL_Rect Token::getPosition() const {
    return position;
}
