// GameTimer.h
#pragma once

#include <SDL.h>

class GameTimer {
public:
    GameTimer();
    ~GameTimer();

    void start(); // Start the timer
    void update(); // Update the timer (call this in your game loop)
    void render(SDL_Renderer* renderer); // Render the timer

private:
    Uint32 startTime; // Time when the timer started
    Uint32 currentTime; // Current time
};
