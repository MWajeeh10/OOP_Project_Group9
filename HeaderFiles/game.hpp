
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

class Game{
    //constant screen dimensions
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 600;

    //The window we'll be rendering on to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;

    //global reference to png image sheets(assets file)
    SDL_Texture* assets=NULL;
    

public:

    bool init();//Initializes SDL
    bool loadMedia();//Textures(images) are loaded
    void close();//SDL closes
    SDL_Texture* loadTexture( std::string path );//Converts the image in the assets to format SDL can use for rendering on the screen
    void run();//Handles the SDL events
};

