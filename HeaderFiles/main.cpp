

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
#include "game.hpp"
int main(int argc, char* argv[]) {
    ScreenManager screenManager;
    screenManager.run();

    return 0;
}