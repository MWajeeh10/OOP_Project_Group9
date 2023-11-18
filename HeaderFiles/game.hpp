
#include <SDL.h>
#include <SDL_image.h>
#include <vector>

class Game {
public:
    Game();
    ~Game();
    void run();
    void showWelcomeScreen();
    void showPlayerSelectionScreen();
    void showRules1Screen() ;
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool startGame; 
};


