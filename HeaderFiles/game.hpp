
// #include <SDL.h>
// #include <SDL_image.h>
// #include <stdio.h>
// #include <iostream>
// #include <string>
// #include <stdlib.h>
// #include <time.h>

// class Game{
//     //constant screen dimensions
//     const int SCREEN_WIDTH = 1000;
//     const int SCREEN_HEIGHT = 600;

//     //The window we'll be rendering on to
//     SDL_Window* gWindow = NULL;

//     //The window renderer
//     SDL_Renderer* gRenderer = NULL;

//     //Current displayed texture
//     SDL_Texture* gTexture = NULL;

//     //global reference to png image sheets(assets file)
//     SDL_Texture* assets=NULL;
    

// public:

//     bool init();//Initializes SDL
//     bool loadMedia();//Textures(images) are loaded
//     void close();//SDL closes
//     SDL_Texture* loadTexture( std::string path );//Converts the image in the assets to format SDL can use for rendering on the screen
//     void run();//Handles the SDL events
// };

// game.hpp

// game.hpp

#ifndef GAME_HPP
#define GAME_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <thread>  // Include this header for sleep functionality

class Game {
public:
    Game();
    ~Game();

    void init(const char* title, int width, int height);
    void handleEvents();
    void update();
    void render();
    void clean();

    bool isRunning() const { return running; }

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;

    SDL_Texture* welcomeScreenTexture;  // Add a texture for the welcome screen
    int welcomeScreenTimer;  // Add a timer for the welcome screen

    // Load image function
    SDL_Texture* loadTexture(const char* path);

    // Add more member variables and functions as needed
};

#endif // GAME_HPP

