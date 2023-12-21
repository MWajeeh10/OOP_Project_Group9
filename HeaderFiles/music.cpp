#include "music.hpp"

MusicPlayer::MusicPlayer(const char* filePath) {
    music = Mix_LoadMUS("C:\\Users\\hp\\Downloads\\oop project assets\\audio1.mp3");
}

MusicPlayer::~MusicPlayer() {
    Mix_FreeMusic(music);
}

void MusicPlayer::play() {
    if (music) {
        // Play music only if it's not already playing
        if (Mix_PlayingMusic() == 0) {
            Mix_PlayMusic(music, -1);
        }
    }
}

void MusicPlayer::stop() {
    Mix_HaltMusic();
}