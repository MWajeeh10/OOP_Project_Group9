

// int main(int argc, char* argv[]) {
//     Game game;
//     game.run();
//     return 0;
// }



// int main(int argc, char* argv[]) {
//     ScreenManager screenManager;
//     SDL_Renderer* renderer = /* obtain the renderer from your SDL initialization code */;
//     screenManager.run(renderer);

//     return 0;
// }
#include <iostream>
// #include "game.hpp"
#include "screenManager.hpp"
#include "screen.hpp"

// #include "musicManager.hpp"
// #include <SDL.h>

int main(int argc, char* argv[]) {
    // MusicManager musicManager;
    // musicManager.playWelcomeScreenMusic();
    ScreenManager screenManager;
    screenManager.run();

    return 0;
}