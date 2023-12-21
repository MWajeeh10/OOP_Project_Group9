#pragma once


#include <SDL_mixer.h>
#include <string>
#include "screen.hpp"
#include "iostream"

class MusicPlayer {
private:
    Mix_Music* music;

public:
    MusicPlayer();
    ~MusicPlayer();

    void loadMusic(const std::string& filePath);
    void play();
    void stop();
};
