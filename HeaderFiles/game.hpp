/*
-------------------------------------------------------------------------------------------------
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
----------------------------------------------------------------------------------------------
*/


// game.hpp

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>

// Enumeration to represent different screens
enum ScreenType {
    WELCOME,
    PLAYER_SELECTION,
    RULES,
    EXIT
    // Add more screen types as needed
};

// Base class for screens
class Screen {
public:
    virtual ~Screen() {}
    virtual void show(SDL_Renderer* renderer, ScreenType& nextScreen) = 0;
};

// Update the WelcomeScreen class
class WelcomeScreen : public Screen {
public:
    WelcomeScreen() : startGame(false) {}
    virtual void show(SDL_Renderer* renderer, ScreenType& nextScreen) override;
    ~WelcomeScreen();

private:
    // Add necessary member variables for surfaces and textures
    bool startGame;  // Add this line
};

// Update the PlayerSelectionScreen class
class PlayerSelectionScreen : public Screen {
public:
    virtual void show(SDL_Renderer* renderer, ScreenType& nextScreen) override;
    ~PlayerSelectionScreen();

private:
    // Add necessary member variables for surfaces and textures
};

// Update the RulesScreen class
class RulesScreen : public Screen {
public:
    virtual void show(SDL_Renderer* renderer, ScreenType& nextScreen) override;
    ~RulesScreen();

private:
    // Add necessary member variables for surfaces and textures
};

// Update the ScreenManager class
class ScreenManager {
public:
    ScreenManager();
    ~ScreenManager();
    void run();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    ScreenType currentScreen;
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
