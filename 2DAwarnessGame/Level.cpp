#include "Level.h"

// Constructor to initialize the world and load textures
PlayWorld::PlayWorld(int world_num) {
	switch (world_num) {
	case 1:
	{
		// Load textures for area 1 (City Park: Day)
		mapFiles = {
			"Assets/Backgrounds/AG_BackgroundSky.png",
			"Assets/Backgrounds/Park/AG_Ground_Park.png",
			"Assets/Backgrounds/Park/AG_Background_Park1.png",
			"Assets/Backgrounds/Park/AG_Background_Park2.png",
			"Assets/Backgrounds/Park/AG_Background_Park3.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_1.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_2.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_3.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_4.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_5.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_6.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_7.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_8.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_9.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_10.png",
			"Assets/Backgrounds/Park/AG_Background_Park5.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_1.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_2.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_3.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_4.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_5.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_6.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_7.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_8.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_9.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_10.png",
		};
		break;
	}
	case 2:
	{
		// Load textures for area 2 (City Park: Night)
		mapFiles = {
			"Assets/Backgrounds/AG_BackgroundSkyNight.png",
			"Assets/Backgrounds/Park/AG_Ground_Park.png",
			"Assets/Backgrounds/Park/AG_Background_Park1.png",
			"Assets/Backgrounds/Park/AG_Background_Park2_Night.png",
			"Assets/Backgrounds/Park/AG_Background_Park3_Night.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_Night_1.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_Night_2.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_Night_3.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_Night_4.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_Night_5.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_Night_6.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_Night_7.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_Night_8.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_Night_9.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_Night_10.png",
			"Assets/Backgrounds/Park/AG_Background_Park5.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_Night_1.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_Night_2.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_Night_3.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_Night_4.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_Night_5.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_Night_6.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_Night_7.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_Night_8.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_Night_9.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_Night_10.png",

		};
		break;
	}
	case 3:
	{
		// Load textures for area 3 (Bridge: Day)
		mapFiles = {
			"Assets/Backgrounds/AG_BackgroundSky.png",
		"Assets/Backgrounds/Bridge/AG_Ground_Bridge.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day1.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day2.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day3.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day4_1.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day4_2.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day4_3.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day4_4.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day4_5.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day4_6.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day4_7.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day4_8.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day4_9.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day4_10.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day5.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_DayForeground_1.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_DayForeground_2.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_DayForeground_3.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_DayForeground_4.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_DayForeground_5.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_DayForeground_6.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_DayForeground_7.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_DayForeground_8.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_DayForeground_9.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_DayForeground_10.png",
		};
		break;
	}
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
	if (!background4Texture.loadFromFile(textureFiles[5 + currentFrame])) {
		std::cerr << "Error loading background 4 texture!" << std::endl;
	}
	if (!background5Texture.loadFromFile(textureFiles[15])) {
		std::cerr << "Error loading background 5 texture!" << std::endl;
	}
	if (!groundTexture.loadFromFile(textureFiles[1])) {
		std::cerr << "Error loading ground texture!" << std::endl;
	}
	if (!foregroundTexture.loadFromFile(textureFiles[16 + currentFrame])) {
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

void PlayWorld::update(PlayerClass player, sf::RenderWindow& window, float dt) {
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

	// Manage background animations
	updateAnimation(dt);

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
	{
		// Load textures for area 1 (City Park: Day)
		mapFiles = {
			"Assets/Backgrounds/AG_BackgroundSky.png",
			"Assets/Backgrounds/Park/AG_Ground_Park.png",
			"Assets/Backgrounds/Park/AG_Background_Park1.png",
			"Assets/Backgrounds/Park/AG_Background_Park2.png",
			"Assets/Backgrounds/Park/AG_Background_Park3.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_1.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_2.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_3.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_4.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_5.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_6.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_7.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_8.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_9.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_10.png",
			"Assets/Backgrounds/Park/AG_Background_Park5.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_1.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_2.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_3.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_4.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_5.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_6.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_7.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_8.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_9.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_10.png",
		};
		break;
	}
	case 2:
	{
		// Load textures for area 2 (City Park: Night)
		mapFiles = {
			"Assets/Backgrounds/AG_BackgroundSkyNight.png",
			"Assets/Backgrounds/Park/AG_Ground_Park.png",
			"Assets/Backgrounds/Park/AG_Background_Park1.png",
			"Assets/Backgrounds/Park/AG_Background_Park2_Night.png",
			"Assets/Backgrounds/Park/AG_Background_Park3_Night.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_Night_1.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_Night_2.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_Night_3.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_Night_4.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_Night_5.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_Night_6.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_Night_7.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_Night_8.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_Night_9.png",
			"Assets/Backgrounds/Park/AG_Background_Park4_Night_10.png",
			"Assets/Backgrounds/Park/AG_Background_Park5.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_Night_1.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_Night_2.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_Night_3.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_Night_4.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_Night_5.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_Night_6.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_Night_7.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_Night_8.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_Night_9.png",
			"Assets/Backgrounds/Park/AG_Background_ParkForeground_Night_10.png",

		};
		break;
	}
	case 3:
	{
		// Load textures for area 3 (Bridge: Day)
		mapFiles = {
			"Assets/Backgrounds/AG_BackgroundSky.png",
		"Assets/Backgrounds/Bridge/AG_Ground_Bridge.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day1.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day2.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day3.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day4_1.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day4_2.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day4_3.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day4_4.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day4_5.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day4_6.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day4_7.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day4_8.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day4_9.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day4_10.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_Day5.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_DayForeground_1.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_DayForeground_2.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_DayForeground_3.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_DayForeground_4.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_DayForeground_5.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_DayForeground_6.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_DayForeground_7.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_DayForeground_8.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_DayForeground_9.png",
		"Assets/Backgrounds/Bridge/AG_Background_Bridge_DayForeground_10.png",
		};
		break;
	}
	}
	// Load the textures
	loadTextures(mapFiles);
};

void PlayWorld::updateAnimation(float dt) {
	// Update the animation frame based on the time delta
	frameTimer += (dt * 1000); // Convert dt to milliseconds
	if (frameTimer >= 10000) { // Change frame
		if (currentFrame >= frameCount - 1) {
			currentFrame = 0; // Reset to first frame if at the end
		}
		else {
			currentFrame = (currentFrame + 1); // Loop through frames
		}
		frameTimer = 0; // Reset timer
		std::cout << "frame update" << currentFrame << std::endl;

		// Set the current texture for the sprite based on the current frame
		if (!background4Texture.loadFromFile(mapFiles[5 + currentFrame])) {
			std::cerr << "Error loading background 4 texture!" << std::endl;
		};
		if (!foregroundTexture.loadFromFile(mapFiles[16 + currentFrame])) {
			std::cerr << "Error loading foreground texture!" << std::endl;
		};

		foregroundSprite.setTexture(foregroundTexture);
		background4Sprite.setTexture(background4Texture);
	}

}
