#pragma once

#include <SDL.h>
#include <iostream>
#include <vector>
#include <chrono>

class Dice {
public:
    Dice(SDL_Renderer* renderer, const std::string& color, int x, int y);
    ~Dice();

    void handleDiceClick(int mouseX, int mouseY);
    void update();  // Update the dice state (e.g., animation)
    void render(SDL_Renderer* renderer);

    int getValue() const;

private:
    std::vector<SDL_Texture*> diceFaces;
    int currentValue;
    SDL_Rect position;

    bool isRolling;
    std::chrono::time_point<std::chrono::high_resolution_clock> rollStartTime;

    SDL_Texture* loadTexture(const std::string& path, SDL_Renderer* renderer);
    void startRollAnimation();
};
