#pragma once
#include "Screen.hpp"
#include <SDL_ttf.h>

class RulesScreen : public Screen {
    public:
        RulesScreen(SDL_Renderer* renderer);
        ~RulesScreen();

        void handleEvents(SDL_Events& event) override;
        void update() override;
        void render() override;


    private:
        SDL_Renderer* render;
        SDL_Texture* rulesTexture;  //Texture for the rules image
        SDL_Rect backButtonRect;
        // bool backButtonHovered;

        void loadRulesTexture();
        void renderBackButton();
        void handleBackButtonClick();

};