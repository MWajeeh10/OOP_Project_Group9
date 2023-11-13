#include "RulesScreen.hpp"
#include <SDL_image.h>


RulesScreen::RulesScreen(SDL_Renderer* renderer): renderer(renderer), backButtonHovered(false){
    SDL_Surface* screenSurface = IMG_Load("image.png");//loads the rules image
    if (screenSurface == nullptr){
        //Handling of error statement/action
    }
    SDL_Texture* screenTexture = SDL_CreateTextureFromSurface(renderer, screenSurface);
    if (screenTexture == nullptr){
        //handle error when creating texture --- to be done later
    }

    SDL_FreeSurface(screenSurface);
    rulesScreenTexture = screenTexture; //assigning the loaded texture to a variable

    //setting position and size of back button according to image
    backButtonRect.x = 10;
    backButtonRect.y = 10;
    backButtonRect.w = 100;
    backButtonRect.h = 50;
}


RulesScreen::~RulesScreen(){
    SDL_DestroyTexture(rulesScreenTexture);  //frees memory allocated for rulesTexture
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
    renderBackButton(); //render back button
}

void RulesScreen::loadRuleTexture(){
    // load the rules image as a texture
    SDL_Surface* rulesSurface == IMG_Load("path/to/rules_image.png");
    if(rulesSurface == nullptr){
        //Handle error loading image
        return;
    }

    rulesTexture = SDL_CreateTextureFromSurface(renderer, rulesSurface);
    SDL_FreeSurface(rulesSurface);
}

coid RulesScreen::renderBackButton(){
    //Render the back buttin at a specific position in the image
    //Setting the position and dimensions based on the image
    SDL_Color buttonColor = backButtonHovered ? SDL_Color{255,0,0,255} : SDL_Color{0,255,0,255};
    SDL_SetRenderDrawColor(renderer, buttonColor.r, buttonColor.g, buttonColor.b, buttonColor.a);
    SDL_RenderDrawRect(renderer, &backButtonRect);
}

void RulesScreen::handleBackButtonClick(){
    //allow the user to go back to the welcome screen after pressing back
    //to be implemented later
    //implement logic to the screen revertion

    //printing a message for testing purpose
    std::cout<<"Back button clicked. Revert back to the welcome screen.\n";
}