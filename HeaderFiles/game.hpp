#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>

class Game {
public:
    Game();
    ~Game();
    void run();
    void showWelcomeScreen();
    void showPlayerSelectionScreen();
    void showRulesScreen1(); // Add a function to show the rules screen

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool startGame;  // Set to true when the user clicks "Start"
};

// #include <SDL.h>
// #include <SDL_image.h>
// #include <SDL_mixer.h>
// #include <iostream>

// class Game {
// public:
//     Game();
//     ~Game();
//     void run();

// private:
//     SDL_Window* window;
//     SDL_Renderer* renderer;
//     bool quit;
//     enum GameState { WELCOME, PLAYER_SELECTION, RULES };
//     GameState gameState;

//     void showWelcomeScreen();
//     void showPlayerSelectionScreen();
//     void showRulesScreen();
// };
