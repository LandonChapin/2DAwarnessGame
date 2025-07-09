#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>




class MusicPlayer {
public:
	MusicPlayer();
	void playMusic(const std::string& filePath);
	void stopMusic();
	void setVolume(float volume);
	void setLoop(bool loop);
	void update(float dt, int songNumber);
private:
	sf::Music music;
	float volume;
	bool isLooping;
};

