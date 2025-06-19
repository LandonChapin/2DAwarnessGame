#include "Level.h"

// Constructor to initialize the world and load textures
PlayWorld::PlayWorld(int world_num) {
	switch (world_num) {
	case 1:
		// Load textures for area 1 (City in Moths world)
		mapFiles = {
			"Assets/Backgrounds/AG_BackgroundSky.png",
			"Assets/Backgrounds/Park/AG_Ground_Park.png",
			"Assets/Backgrounds/Park/AG_Background_Park1.png",
			"Assets/Backgrounds/Park/AG_Background_Park2.png",
			"Assets/Backgrounds/Park/AG_Background_Park3.png",
			"Assets/Backgrounds/Park/AG_Background_Park4.png",
			"Assets/Backgrounds/Park/AG_Background_Park5.png",
			"Assets/Backgrounds/Park/AG_Background_Park6.png",
		};
		break;

	}
	// Load the textures
	loadTextures(mapFiles);
}

void PlayWorld::loadTextures(const std::vector<std::string>& textureFiles) {
	//to warn against overflow error
	if (textureFiles.size() < 4) {
		std::cerr << "Error: Not enough texture files provided!" << std::endl;
		return;
	}

	if (!skyTexture.loadFromFile(textureFiles[0])) {
		std::cerr << "Error loading sky texture!" << std::endl;
	}
	if (!background1Texture.loadFromFile(textureFiles[2])) {
		std::cerr << "Error loading background texture!" << std::endl;
	}
	if (!background2Texture.loadFromFile(textureFiles[3])) {
		std::cerr << "Error loading background 2 texture!" << std::endl;
	}
	if (!background3Texture.loadFromFile(textureFiles[4])) {
		std::cerr << "Error loading background 3 texture!" << std::endl;
	}
	if (!background4Texture.loadFromFile(textureFiles[5])) {
		std::cerr << "Error loading background 4 texture!" << std::endl;
	}
	if (!background5Texture.loadFromFile(textureFiles[6])) {
		std::cerr << "Error loading background 5 texture!" << std::endl;
	}
	if (!groundTexture.loadFromFile(textureFiles[1])) {
		std::cerr << "Error loading ground texture!" << std::endl;
	}
	if (!foregroundTexture.loadFromFile(textureFiles[7])) {
		std::cerr << "Error loading foreground texture!" << std::endl;
	}


	skySprite.setTexture(skyTexture);
	skySprite.setScale(10, 10);

	background1Sprite.setTexture(background1Texture);
	background1Sprite.setScale(10, 10);
	background2Sprite.setTexture(background2Texture);
	background2Sprite.setScale(10, 10);
	background3Sprite.setTexture(background3Texture);
	background3Sprite.setScale(10, 10);
	background4Sprite.setTexture(background4Texture);
	background4Sprite.setScale(10, 10);
	background5Sprite.setTexture(background5Texture);
	background5Sprite.setScale(10, 10);

	groundSprite.setTexture(groundTexture);
	groundSprite.setScale(10, 10);
	foregroundSprite.setTexture(foregroundTexture);
	foregroundSprite.setScale(10, 10);
}

void PlayWorld::update(PlayerClass player, sf::RenderWindow& window) {
	sf::Vector2f playerPosition = player.getPosition();
	sf::View currentView = window.getView();
	currentView.setCenter(playerPosition);
	window.setView(currentView);

	// Parallax backgrounds
	sf::Vector2f viewCenter = currentView.getCenter();

	// Sky is static
	skySprite.setPosition(-500, -500);

	// Parallax backgrounds
	background1Sprite.setPosition(
		-500 + (viewCenter.x - window.getSize().x / 2) * PARALLAX_FACTORS[0], 0);
	background2Sprite.setPosition(
		-500 + (viewCenter.x - window.getSize().x / 2) * PARALLAX_FACTORS[1], 0);
	background3Sprite.setPosition(
		-500 + (viewCenter.x - window.getSize().x / 2) * PARALLAX_FACTORS[2], 0);
	background4Sprite.setPosition(
		-500 + (viewCenter.x - window.getSize().x / 2) * PARALLAX_FACTORS[3], 0);
	background5Sprite.setPosition(
		-500 + (viewCenter.x - window.getSize().x / 2) * PARALLAX_FACTORS[4], 0);

	// Ground and foreground move with the view (no parallax)
	groundSprite.setPosition(-500, 0);
	foregroundSprite.setPosition(-500, 0);

};

void PlayWorld::scaleTextures(sf::RenderWindow& window) {
	sf::Vector2u windowSize = window.getSize();
	skySprite.setScale(
		static_cast<float>(windowSize.x) / skyTexture.getSize().x,
		static_cast<float>(windowSize.y) / skyTexture.getSize().y
	);

	background1Sprite.setScale(
		static_cast<float>(windowSize.x) / background1Texture.getSize().x,
		static_cast<float>(windowSize.y) / background1Texture.getSize().y
	);
	background2Sprite.setScale(
		static_cast<float>(windowSize.x) / background2Texture.getSize().x,
		static_cast<float>(windowSize.y) / background2Texture.getSize().y
	);
	background3Sprite.setScale(
		static_cast<float>(windowSize.x) / background3Texture.getSize().x,
		static_cast<float>(windowSize.y) / background3Texture.getSize().y
	);
	background4Sprite.setScale(
		static_cast<float>(windowSize.x) / background4Texture.getSize().x,
		static_cast<float>(windowSize.y) / background4Texture.getSize().y
	);
	background5Sprite.setScale(
		static_cast<float>(windowSize.x) / background5Texture.getSize().x,
		static_cast<float>(windowSize.y) / background5Texture.getSize().y
	);

	groundSprite.setScale(
		static_cast<float>(windowSize.x) / background1Texture.getSize().x,
		static_cast<float>(windowSize.y) / background1Texture.getSize().y
	);
	foregroundSprite.setScale(
		static_cast<float>(windowSize.x) / foregroundTexture.getSize().x,
		static_cast<float>(windowSize.y) / foregroundTexture.getSize().y
	);
}

void PlayWorld::draw(sf::RenderWindow& window) {
	window.draw(skySprite);

	window.draw(background1Sprite);
	window.draw(background2Sprite);
	window.draw(background3Sprite);
	window.draw(background4Sprite);
	window.draw(background5Sprite);

	window.draw(groundSprite);
	
}
void PlayWorld::drawForeground(sf::RenderWindow& window) {
	window.draw(foregroundSprite);
}

void PlayWorld::initialize(int episodeNum) {
	switch (episodeNum) {
	case 1:
		// Load textures for area 1 (City in Moths world)
		mapFiles = {
			"Assets/Backgrounds/AG_BackgroundSky.png",
			"Assets/Backgrounds/Park/AG_Ground_Park.png",
			"Assets/Backgrounds/Park/AG_Background_Park1.png",
			"Assets/Backgrounds/Park/AG_Background_Park2.png",
			"Assets/Backgrounds/Park/AG_Background_Park3.png",
			"Assets/Backgrounds/Park/AG_Background_Park4.png",
			"Assets/Backgrounds/Park/AG_Background_Park5.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground.png",
		};
		break;

	}
	// Load the textures
	loadTextures(mapFiles);
};