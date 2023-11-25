#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include<iostream>
#include "dice.hpp"
#include <vector>

using namespace std;

Dice::Dice(Color color) : color(color), state(DiceState::In_home), position(0) {}

void Dice::roll(){
    //Generate random number between 1 and 2
    int roll=rand()%2 +1;

    if(state==DiceState::In_home && roll==2){
        state=DiceState::Out_home;
        position=1;
    }
    else if(state==DiceState::Out_home){
        position+=roll;
        if (position>56){
            position-=56;
        }
        if (color == Color::Yellow && position == 1) {
            // Implement the logic to move the corresponding token out of the home board
            // This part will depend on your specific game logic and token representation
        }

    }
}

DiceState Dice::getState() const { 
    return state; 
    }

int Dice::getPosition() const { 
    return position; 
    }

for(int i=1,i<3,i++){
    if(Dice::getState()==1){

    SDL_Surface* yellowdice2 = IMG_Load("C:\\Users\\hp\\Downloads\\oop project assets\\yellowdice2.png");
    if (!yellowdice2) {
        std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }
    SDL_Texture* yellowdice2 = SDL_CreateTextureFromSurface(renderer, rules1);
    if (!yellowdice2) {
        std::cout << "Unable to create texture from image! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_FreeSurface(yellowdice2);

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, yellowdice2, NULL, NULL);
    SDL_RenderPresent(renderer);

    }
    else if(Dice::getState()==2){
    SDL_Surface* yellowdice3 = IMG_Load("C:\\Users\\hp\\Downloads\\oop project assets\\yellowdice3.png");
    if (!yellowdice3) {
        std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }
    SDL_Texture* yellowdice2 = SDL_CreateTextureFromSurface(renderer, rules1);
    if (!yellowdice3) {
        std::cout << "Unable to create texture from image! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_FreeSurface(yellowdice3);

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, yellowdice3, NULL, NULL);
    SDL_RenderPresent(renderer);


    }
}



