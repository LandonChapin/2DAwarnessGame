#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"

//declarations
class PlayWorld {
public:
	PlayWorld(int world_num);
	PlayWorld() {};
	void loadTextures(const std::vector<std::string>& textureFiles);
	void scaleTextures(sf::RenderWindow& window);
	void update(PlayerClass player, sf::RenderWindow& window, float dt);
	void draw(sf::RenderWindow& window);
	void drawForeground(sf::RenderWindow& window);
	void initialize(int episodeNum);

private:
	sf::Texture skyTexture;
	sf::Texture background1Texture;
	sf::Texture background2Texture;
	sf::Texture background3Texture;
	sf::Texture background4Texture;
	sf::Texture background5Texture;
	sf::Texture groundTexture;
	sf::Texture foregroundTexture;

	sf::Sprite skySprite;
	sf::Sprite background1Sprite;
	sf::Sprite background2Sprite;
	sf::Sprite background3Sprite;
	sf::Sprite background4Sprite;
	sf::Sprite background5Sprite;
	sf::Sprite groundSprite;
	sf::Sprite foregroundSprite;

	std::vector<std::string> mapFiles;
	int world_num = 1; // The current world number

	float PARALLAX_FACTORS[5] = { 0.8f, 0.65f, 0.5f, 0.35f, 0.2f };

	int currentFrame = 0; // Current frame for animation
	int frameCount = 9; // Total number of frames in the animation
	float frameTimer = 0; // Delay between frames

	void updateAnimation(float dt);
};
#pragma once
