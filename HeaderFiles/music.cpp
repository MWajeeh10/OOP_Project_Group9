#include "music.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include "screen.hpp"

MusicPlayer::MusicPlayer() : music(nullptr) {}

void MusicPlayer::loadMusic(const std::string& filePath) {
    music = Mix_LoadMUS(filePath.c_str());
}

void MusicPlayer::play() {
    if (music && Mix_PlayingMusic() == 0) {
        Mix_PlayMusic(music, -1);
    }
}

void MusicPlayer::stop() {
    Mix_HaltMusic();
}

MusicPlayer::~MusicPlayer() {
    if (music) {
        Mix_FreeMusic(music);
    }
}
