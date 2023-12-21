#include "dice.hpp"
#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>  // Include the algorithm header
#include <map>

// // Constructor for the Dice class
// Dice::Dice(SDL_Renderer* renderer, const std::vector<std::string>& facePaths, int x, int y)
//     : xPosition(x), yPosition(y), rolling(false) {
//     // Assign scores directly based on your preference
//     faceScores = {1, 2, 3, 4, 5, 6};

//     // Load textures for each face of the dice
//     //! auto deduce the type of the variable without typing the return type
//     for (const auto& path : facePaths) {
//         SDL_Texture* texture;
//         loadTexture(path, renderer, texture);
//         faceTextures.push_back(texture);
//     }
// }

// Destructor for the Dice class
Dice::~Dice() {
    // Release memory allocated for textures
    for (auto& texture : faceTextures) {
        if (texture) {
            SDL_DestroyTexture(texture);
        }
    }
}

// Load a texture from an image file
void Dice::loadTexture(const std::string& imagePath, SDL_Renderer* renderer, SDL_Texture*& texture) {
    SDL_Surface* surface = IMG_Load(imagePath.c_str());
    if (!surface) {
        std::cerr << "Unable to load dice image! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture) {
        std::cerr << "Unable to create texture from dice image! SDL_Error: " << SDL_GetError() << std::endl;
    }
}


// dice.cpp

Dice::Dice(SDL_Renderer* renderer, const std::map<std::string, int>& facePathsAndScores, int x, int y)
    : xPosition(x), yPosition(y), rolling(false) {
    for (const auto& pair : facePathsAndScores) {
        SDL_Texture* texture;
        loadTexture(pair.first, renderer, texture);
        faceTextures.push_back(texture);
        faceScores.push_back(pair.second);
    }
}

void Dice::roll(SDL_Renderer* renderer) {
    rolling = true;

    Uint32 startTime = SDL_GetTicks();
    Uint32 currentTime;
    while ((currentTime = SDL_GetTicks()) - startTime < 2000) {
        if ((currentTime - startTime) % 50 == 0) {
            SDL_Delay(50);
            int randomIndex = rand() % faceTextures.size();
            std::rotate(faceTextures.begin(), faceTextures.begin() + randomIndex, faceTextures.end());
            std::rotate(faceScores.begin(), faceScores.begin() + randomIndex, faceScores.end());
            render(renderer);
            SDL_RenderPresent(renderer);
        }

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                rolling = false;
                return;
            }
        }
    }

    rolling = false;
    score = faceScores.front();

    render(renderer);
    SDL_RenderPresent(renderer);
}

void Dice::render(SDL_Renderer* renderer) {
    SDL_Rect destination;
    destination.x = xPosition;
    destination.y = yPosition;

    // Query dimensions of the current face texture
    SDL_QueryTexture(faceTextures.front(), nullptr, nullptr, &destination.w, &destination.h);

    // Render the current face
    SDL_RenderCopy(renderer, faceTextures.front(), nullptr, &destination);
    SDL_RenderPresent(renderer);
}


// // Simulate the rolling of the dice
// void Dice::roll(SDL_Renderer* renderer) {
//     rolling = true;

//     Uint32 startTime = SDL_GetTicks();
//     Uint32 currentTime;

//     // Roll for 2 seconds
//     while ((currentTime = SDL_GetTicks()) - startTime < 2000) {
//         // Update every 50 milliseconds
//         if ((currentTime - startTime) % 50 == 0) {
//             SDL_Delay(50);

//             // Randomly select a face for rolling effect
//             int randomIndex = rand() % faceTextures.size();
//             std::rotate(faceTextures.begin(), faceTextures.begin() + randomIndex, faceTextures.end());

//             // Render and display the current face
//             render(renderer);
//             SDL_RenderPresent(renderer);
//         }

//         // Check for quit event
//         SDL_Event event;
//         while (SDL_PollEvent(&event)) {
//             if (event.type == SDL_QUIT) {
//                 rolling = false;
//                 return;
//             }
//         }
//     }

//     rolling = false;

//     // Update the score based on the final face of the dice
//     int finalFaceIndex = rand() % faceTextures.size();
//     score = finalFaceIndex + 1;

//     // Render and display the final face
//     render(renderer);
//     SDL_RenderPresent(renderer);

//     std::cout << "Dice Score: " << score << std::endl;  // Print the score
// }



// // void Dice::token_move(SDL_Renderer* renderer){
    
// // }
// // Render the current face of the dice
// void Dice::render(SDL_Renderer* renderer) {
//     SDL_Rect destination;
//     destination.x = xPosition;
//     destination.y = yPosition;

//     // Query dimensions of the current face texture
//     SDL_QueryTexture(faceTextures.front(), nullptr, nullptr, &destination.w, &destination.h);

//     // Render the current face
//     SDL_RenderCopy(renderer, faceTextures.front(), nullptr, &destination);
//     SDL_RenderPresent(renderer);
// }


