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
    // Add necessary member variables for surfaces and texturess
    bool startGame;  // Add this line
};

// Update the PlayerSelectionScreen class
class PlayerSelectionScreen : public Screen {
public:
    virtual void show(SDL_Renderer* renderer, ScreenType& nextScreen) override;
    ~PlayerSelectionScreen();

private:
    SDL_Texture* loadTexture(const std::string& path, SDL_Renderer* renderer);
    void renderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y);
    Dice dice1;
    Dice dice2;
};
// class PlayerSelectionScreen : public Screen {
// public:
//     virtual void show(SDL_Renderer* renderer, ScreenType& nextScreen) override;
//     ~PlayerSelectionScreen();

// private:
//     SDL_Texture* loadTexture(const std::string& path, SDL_Renderer* renderer);
//     void renderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y);
// };

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
    Mix_Music* music;
    void playMusic();
};




