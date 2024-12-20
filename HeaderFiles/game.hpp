// #include <SDL.h>
// #include <SDL_image.h>
// #include <SDL_mixer.h>
// #include <SDL_ttf.h>
// #include <iostream>
// #include <string>
// #include "dice.hpp"
// #include "tokens.hpp"
// #include "kill.hpp"
// #include "score.hpp"

// // Enumeration to  represent different screens in the game,
// enum ScreenType {
//     WELCOME,
//     PLAYER_SELECTION,
//     RULES,
//     EXIT
// };


// // Base class for screens
// class Screen {
// public:
//     virtual ~Screen() {}  //! allows proper destruction of objects through base class pointers
//     virtual void show(SDL_Renderer* renderer, ScreenType& nextScreen) = 0;  
// };



// // Update the WelcomeScreen class
// class WelcomeScreen : public Screen {
//     private:
//         bool startGame; 
    
//     public:
//         WelcomeScreen() : startGame(false) {}
//         virtual void show(SDL_Renderer* renderer, ScreenType& nextScreen) override;
//         ~WelcomeScreen();


// };

// // class MusicManager;

// // Update the PlayerSelectionScreen class
// class PlayerSelectionScreen : public Screen {

//     private:

//         //for managing the dice turns
//         enum class Turn {
//             DICE1,
//             DICE2,
//             DICE3,
//             DICE4
//         };


//         Turn currentTurn;

//         SDL_Texture* loadTexture(const std::string& path, SDL_Renderer* renderer);
//         void renderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y);
//         Dice* dice1;  // red dice
//         Dice* dice2;  // green dice
//         Dice* dice3;  // yellow dice
//         Dice* dice4;  // blue dice
//         Token* redToken;  // red token
//         Token* greenToken; // green token
//         Token* yellowToken;
//         Token* blueToken;
//         bool checkAndMoveBackToHome(Token* currentToken, Token* token2, Token* token3, Token* token4, ScoreCalculator& scoreCalculator);


//     public:
//         PlayerSelectionScreen(SDL_Renderer* renderer);
//         // virtual void show(SDL_Renderer* renderer, ScreenType& nextScreen) override;
//         void show(SDL_Renderer* renderer, ScreenType& nextScreen);
//         ~PlayerSelectionScreen();
//         ScoreCalculator scoreCalculator;
// };


// // Update the RulesScreen class
// class RulesScreen : public Screen {
//     protected:

//     public:
//         virtual void show(SDL_Renderer* renderer, ScreenType& nextScreen) override;
//         ~RulesScreen();
// };


// // Update the ScreenManager class
// class ScreenManager {
//     private:
//         SDL_Window* window;
//         SDL_Renderer* renderer;
//         ScreenType currentScreen;
//         Mix_Music* music;
//         void playMusic();
        
//     public:
//         ScreenManager();
//         ~ScreenManager();
//         void run();
// };
