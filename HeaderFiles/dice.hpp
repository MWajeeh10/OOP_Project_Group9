#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <vector>


class Dice {
    private:
        std::vector<SDL_Texture*> faceTextures; // Textures for each face of the dice
        int xPosition; // X-coordinate position of the dice
        int yPosition; // Y-coordinate position of the dice
        bool rolling;   // Flag to indicate if the dice is currently rolling
        int score;      // Current score of the dice

        // Load a texture from an image file
        void loadTexture(const std::string& imagePath, SDL_Renderer* renderer, SDL_Texture*& texture);
        
        // Method to roll the dice
        // void roll(SDL_Renderer* renderer); 

        // Method to get the current dice value
        int getValue() const;

    public:
        // Constructor for the Dice class
        Dice(SDL_Renderer* renderer, const std::vector<std::string>& facePaths, int x, int y);

        // Destructor for the Dice class
        ~Dice();

        // Render the current face of the dice
        void render(SDL_Renderer* renderer);

        // Simulate the rolling of the dice
        void roll(SDL_Renderer* renderer);

        // Get the current dice score
        int diceScore() const {
            return score;
        }

        std::vector<SDL_Texture*> faces;  // Vector to store the textures for each face
        int currentValue;  // Variable to store the current dice value


};
