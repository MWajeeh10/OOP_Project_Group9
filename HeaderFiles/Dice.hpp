#pragma once
#include <SDL.h>


//function to draw the dice on the renderer using provided textures
void drawObjects(SDL_Renderer* diceRenderer, SDL_Texture*assets);

//function to create dice with the given position(width,height)
void createObjects(int x,int y);

//Structure representing a Dice
struct Dice
{

   //The Source Rectangle which indicates area of the dice to be rendered
    SDL_Rect srcRect;
    
    //Dimension Rectangle which indicates the current position of the dice which can be updated when dice is moved 
    SDL_Rect moveRect;
};

//renderer-responsible for drawing shapes and images on the screen
//texture->collection of pixels of the image