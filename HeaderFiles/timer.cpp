// GameTimer.cpp
#include "time.h"

GameTimer::GameTimer() : startTime(0), currentTime(0) {}

GameTimer::~GameTimer() {}

void GameTimer::start() {
    startTime = SDL_GetTicks();
}

void GameTimer::update() {
    currentTime = SDL_GetTicks() - startTime;
}

void GameTimer::render(SDL_Renderer* renderer) {
    // Implement rendering logic (e.g., render text with the current time)
    // You can use SDL_ttf or other libraries for rendering text
}
