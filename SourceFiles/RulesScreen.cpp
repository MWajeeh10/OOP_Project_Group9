#include "RulesScreen.hpp"
#include <SDL_image.h>


RulesScreen::RulesScreen(SDL_Renderer* renderer): renderer(renderer){
    // Initialize SDL and TTF here
    loadRulesTexture(); //loads the rules image
}

RulesScreen::~RulesScreen(){
    SDL_DestroyTexture(rulesTexture);  //frees memory allocated for rulesTexture
}

void RulesScreen::handleEvents(SDL_Events& event) {
    // Handle mouse events, implement navigation
    if(event.type == SDL_MOUSEBUTTONDOWN){
        //check if the click is within the back button's rectangle
        int mouseX, mouseY;  //current coordinates of mouse pointer on screen
        SDL_GetMouseState(&mouseX, &mouseY); //retrieve the above values

        if (mouseX >= backButtonRect.x && mouseX <= backButtonRect.x + backButtonRect.w 
            && mouseY >= backButtonRect.y && mouseY <= backButtonRect.y + backButtonRect.h)
            {
                handleBackButtonClick();
            }
    }
}

void RulesScreen::update() {
    // will have to update or implement any logic if required. otherwise no need to modify it
}

void RulesScreen::render() {
    // Render rules text and back button
    SDL_RenderCopy(renderer, rulesTexture, nullptr, nullptr);
    renderBackButton();
}