//main game file for execution
// main.cpp

#include "game.hpp"

int main() {
    Game game;

    game.init("LUDO Game", 800, 600);

    while (game.isRunning()) {
        game.handleEvents();
        game.update();
        game.render();
    }

    game.clean();

    return 0;
}
