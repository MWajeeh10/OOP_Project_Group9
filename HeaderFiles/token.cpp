#include <SDL.h>
#include <iostream>
#include <cstdlib>
void PlayerSelectionScreen::token_move(SDL_Renderer* renderer) {
    int token_movement_array[][2] = {
        {305, 655}, {305, 605}, {305, 555}, {305, 505},
        {305, 455}, {255, 405}, {205, 405}, {155, 405},
        {105, 405}, {55, 405}, {5, 405}, {5, 355},
        {5, 305}, {55, 305}, {105, 305}, {155, 305},
        {205, 305}, {255, 305}, {305, 255}, {305, 205},
        {305, 155}, {305, 105}, {305, 55}, {305, 5},
        {355, 5}, {405, 5}, {405, 55}, {405, 105},
        {405, 155}, {405, 205}, {405, 255}, {405, 305},
        {505, 305}, {555, 305}, {605, 305}, {655, 305},
        {705, 305}, {705, 355}, {705, 405}, {655, 405},
        {605, 405}, {555, 405}, {505, 405}, {455, 405},
        {405, 455}, {405, 505}, {405, 555}, {405, 605},
        {405, 655}, {405, 705}, {355, 705}, {305, 705}
    }}
class Coin {
private:
    int _x, _y, _x2, _y2, _x3, _y3, _x4, _y4;
    // Other member variables...

public:
    // Existing member functions...

    void moveToken(int coinIndex);

    void pollEvent();
    int Get_X1();
    int Get_X2();
    int Get_X3();
    int Get_X4();
    int Get_Y1();
    int Get_Y2();
    int Get_Y3();
    int Get_Y4();

    void Set_x1(int newx);
    void Set_x2(int newx);
    void Set_x3(int newx);
    void Set_x4(int newx);
    void Set_y1(int newy);
    void Set_y2(int newy);
    void Set_y3(int newy);
    void Set_y4(int newy);
};

void Coin::moveToken(int coinIndex) {
    // Movement logic for each coin based on the coinIndex
    // Update _x, _y, rect[coinIndex], etc.
    // Use similar logic as before
    // ...

//     // Example:
//     if (!coinIn[1] && diceRoll == 6) {
//         switch (coinIndex) {
//             case 0:
//                 _x = 370;
//                 rect[0].x = _x;
//                 _y = 825;
//                 rect[0].y = _y;
//                 coinIn[0] = true;
//                 break;
//             case 1:
//                 // Similar logic for other coins...
//                 break;
//             // Additional cases for more coins...
//         }
//     }

//     startCheck[coinIndex]++;
//     if (startCheck[coinIndex] > 1) {
//         // Your existing loop and movement conditions here...
//         // ...
//     }
// }

void Coin::pollEvent() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                // Your existing cases...

                case SDLK_1:
                    checkTurn = 's';
                    moveCoin(0);
                    break;
                case SDLK_2:
                    checkTurn = 's';
                    moveCoin(1);
                    break;
                case SDLK_3:
                    checkTurn = 's';
                    moveCoin(2);
                    break;
                case SDLK_4:
                    checkTurn = 's';
                    moveCoin(3);
                    break;
                // Additional cases for more coins...
            }
        }
    }
}

// Your existing accessor and mutator functions...
// ...

int main() {
    // Your existing main function...
    // ...
    return 0;
}
