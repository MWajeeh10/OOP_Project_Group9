#pragma once

#include <SDL.h>
#include <string>
#include "Screen.hpp"
#include "Dice.hpp"
#include "Tokens.hpp"
// #include "musicManager.hpp"
#include "Score.hpp"

class play : public Screen {
private:
    enum class Turn {
        DICE1,
        DICE2,
        DICE3,
        DICE4
    };

    Turn currentTurn;

    SDL_Texture* loadTexture(const std::string& path, SDL_Renderer* renderer);
    void renderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y);
    Dice* dice1;
    Dice* dice2;
    Dice* dice3;
    Dice* dice4;
    Token* redToken;
    Token* greenToken;
    Token* yellowToken;
    Token* blueToken;
    bool checkAndMoveBackToHome(Token* currentToken, Token* token2, Token* token3, Token* token4);
    // MusicManager musicManager;

public:
    play(SDL_Renderer* renderer);
    virtual void show(SDL_Renderer* renderer, ScreenType& nextScreen) override;
    ~play();
    ScoreCalculator scoreCalculator;
};
