#pragma once

#include <SDL_mixer.h>

class MusicPlayer {
private:
    Mix_Music* music; //pointer that represented music loaded by Mix_Music(SDL Library)

public:
    MusicPlayer(const char* filePath);//constructor
    ~MusicPlayer();//destructor

    void play();
    void stop();
};

class SoundEffect {
private:
    Mix_Chunk* soundEffect;

public:
    SoundEffect(const char* filePath);//constructor
    ~SoundEffect();//destructor

    void play();
};