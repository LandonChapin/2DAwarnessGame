#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"

//declarations
class PlayWorld {
public:
	PlayWorld(int world_num);
	PlayWorld() {};
	//void loadTextures(const std::vector<std::string>& textureFiles);
	//void scaleTextures(sf::RenderWindow& window);
	void update(PlayerClass player, sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	void drawForeground(sf::RenderWindow& window);
private:
	sf::Texture skyTexture;
	sf::Texture backgroundTexture;
	sf::Texture groundTexture;
	sf::Texture foregroundTexture;

	sf::Sprite skySprite;
	sf::Sprite backgroundSprite;
	sf::Sprite groundSprite;
	sf::Sprite foregroundSprite;

	std::vector<std::string> mapFiles;
	//int world_num = 1; // The current world number
};
#pragma once
