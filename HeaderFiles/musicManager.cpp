// #include "music.hpp"

// MusicManager::MusicManager() {}

// MusicManager::~MusicManager() {
//     stopMusic();
// }

// void MusicManager::loadScreenMusic(ScreenType screen, const std::string& musicFilePath) {
//     screenMusicPaths[screen] = musicFilePath;
// }

// void MusicManager::playScreenMusic(ScreenType screen) {
//     const auto& it = screenMusicPaths.find(screen);
//     if (it != screenMusicPaths.end()) {
//         musicPlayer.loadMusic(it->second);
//         musicPlayer.play();
//     }
// }

// void MusicManager::stopMusic() {
//     musicPlayer.stop();
// }
