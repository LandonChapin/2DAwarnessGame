#include "MusicPlayer.h"  
#include <cstdlib> // For std::rand  
#include <ctime>   // For std::time  


std::vector<std::string> musicFiles1 = {
"Assets/Music/Park_Day.mp3",

};
std::vector<std::string> musicFiles2 = {
"Assets/Music/Park_Day.mp3",

};
std::vector<std::string> musicFiles3 = {
"Assets/Music/Park_Night.mp3",

};
std::vector<std::string> musicFiles4 = {
"Assets/Music/Bridge_Day.mp3",

};
std::vector<std::string> musicFiles5 = {
"Assets/Music/Soul Render Song 1.mp3",

};
std::vector<std::vector<std::string>> musicChoiceArray = {
    musicFiles1,
    musicFiles2,
    musicFiles1,
    musicFiles4,
    musicFiles5, 

};

MusicPlayer::MusicPlayer() : volume(100.f), isLooping(false) {
    // Constructor implementation  
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Seed random number generator  
}

void MusicPlayer::playMusic(const std::string& filePath) {
    if (!music.openFromFile(filePath)) {
        std::cerr << "Error loading music file!" << std::endl;
        return;
    }
    music.setVolume(volume);
    music.setLoop(isLooping);
    music.play();
}

void MusicPlayer::stopMusic() {
    music.stop();
}

void MusicPlayer::setVolume(float volume) {
    this->volume = volume;
    music.setVolume(volume);
}

void MusicPlayer::setLoop(bool loop) {
    isLooping = loop;
    music.setLoop(loop);
}

void MusicPlayer::update(float dt, int songNumber) {
    


    // logic to change the music when the music ends  
    if (music.getStatus() == sf::Music::Stopped) {
        // Choose a random track from the musicFiles array  
        if (!musicChoiceArray.empty()) {

            int randomIndex = std::rand() % musicChoiceArray[songNumber].size();
            std::cout << "Music stopped. Playing random track: " << musicChoiceArray[songNumber][randomIndex] << std::endl;
            playMusic(musicChoiceArray[songNumber][randomIndex]);
        }
        else {
            std::cerr << "No music files available to play!" << std::endl;
        }
    }
}
