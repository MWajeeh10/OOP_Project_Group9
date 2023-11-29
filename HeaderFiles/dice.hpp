// Dice.hpp

#ifndef DICE_HPP
#define DICE_HPP

#include <SDL.h>
#include <string>
#include <vector>

class Dice {
public:
    Dice(const std::string& color, int x, int y, SDL_Renderer* renderer);
    ~Dice();

    // Render the current face of the dice at its position
    void render(SDL_Renderer* renderer);

    // Check if a point (x, y) is inside the boundaries of the dice
    bool isPointInside(int x, int y);

    // Handle a click on the dice, updating the face to a random value
    void handleClick();

private:
    std::string color;
    int x;
    int y;
    SDL_Texture* currentFace;
    std::vector<SDL_Texture*> faces;

    // Load dice images for a specific color
    std::vector<SDL_Texture*> loadDiceFaces(const std::string& color, SDL_Renderer* renderer);

    // Render a face of the dice at its position
    void renderFace(SDL_Renderer* renderer);
};

#endif // DICE_HPP
