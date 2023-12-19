// // GameTimer.cpp
// #include <SDL_timer.h>
// #include <ctime>
// #include <SDL.h>
// #include "time.h"
// #include <iostream>


// GameTimer::GameTimer() : startTime(0), currentTime(0) {}

// GameTimer::~GameTimer() {}

// void GameTimer::start() {
//     startTime = SDL_GetTicks();
// }

// void GameTimer::update() {
//     currentTime = SDL_GetTicks() - startTime;
// }

// // Assuming you have TTF_Font* font; and SDL_Color textColor; as members in your GameTimer class

// void GameTimer::render(SDL_Renderer* renderer) {
//     // Assuming you have loaded a font before calling render (e.g., in the constructor)
//     textColor = {255,0,0};
//     // Convert time to seconds for simplicity
//     Uint32 seconds = currentTime / 1000;

//     // Convert seconds to a string (you may need to use std::to_string or sprintf depending on your compiler)
//     std::stringstream timeText;
//     timeText << "Time: " << seconds;

//     // Create an SDL_Surface from the text
//     SDL_Surface* textSurface = TTF_RenderText_Solid(font, timeText.str().c_str(), textColor);
//     if (!textSurface) {
//         // Handle error (e.g., unable to render text)
//         return;
//     }

//     // Create an SDL_Texture from the surface
//     SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
//     if (!textTexture) {
//         // Handle error (e.g., unable to create texture)
//         SDL_FreeSurface(textSurface);
//         return;
//     }

//     // Get the width and height of the text
//     int textWidth = textSurface->w;
//     int textHeight = textSurface->h;

//     // Set the destination rectangle for rendering (centered on the screen)
//     SDL_Rect destRect = { 455,455, textWidth, textHeight };

//     // Render the text
//     SDL_RenderCopy(renderer, textTexture, nullptr, &destRect);

//     // Clean up resources
//     SDL_FreeSurface(textSurface);
//     SDL_DestroyTexture(textTexture);
// }

