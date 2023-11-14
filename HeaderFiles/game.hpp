// #include <SDL2/SDL.h>
// #include <SDL2/SDL_image.h>

// #ifndef GAME_HPP
// #define GAME_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <vector>

class Game {
public:
    Game();
    ~Game();
    void run();
    void showWelcomeScreen();
    void showPlayerSelectionScreen();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};

