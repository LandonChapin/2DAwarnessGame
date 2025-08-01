#include "chest.h"


Chest::Chest(std::string texturePath, std::string texturePathOpen, int x, int y, float hitboxX, float hitboxY, int xTexture, int yTexture, PlayerClass* playerReference, int info) {
	// Load the texture from the file
	if (!texture.loadFromFile(texturePath)) {
		std::cerr << "Error loading texture! " << texturePath << std::endl;
	}
	if (!textureOpen.loadFromFile(texturePathOpen)) {
		std::cerr << "Error loading texture! " << texturePathOpen << std::endl;
	}
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, xTexture, yTexture));
	sprite.setPosition(x, y);
	sprite.setScale(3.0f * direction, 3.0f);
	sprite.setOrigin(xTexture / 2.0f, yTexture / 2.0f);
	hitbox.setPosition(sprite.getPosition());
	hitbox.setSize(sf::Vector2f(hitboxX, hitboxY));
	hitbox.setColor(sf::Color::White);

	// initialize font and text for the chest
	if (!font.loadFromFile("Assets/Fonts/Seagram_tfb/Seagram tfb.ttf")) {
		std::cerr << "Error loading font!" << std::endl;
	}
	text.setFont(font);
	text.setString("Press E to Inspect");
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::White);
	text.setPosition(sprite.getPosition().x - 75, sprite.getPosition().y - 100);

	player = playerReference; // Initialize the player reference

	this->info = info; // Store the info value
}

bool Chest::detectPlayer(EntityClass& player) {
	// Check for collision with the player  
	if (hitbox.getBounds().intersects(player.getGlobalBounds())) {
		// Handle collision with the player  
		//std::cout << "Collision detected with player!" << std::endl;
		return true;
	}

	else {
		return false;
	}
}

void Chest::update(float dt, sf::RenderWindow& window) {
	// Update the hitbox position to match the sprite position  
	hitbox.setPosition(sf::Vector2f(sprite.getPosition()));
	if (player) {
		if (detectPlayer(*player)) {
			isColliding = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && !isOpen) {
				// Interact
				std::cout << "Interacting with chest!" << std::endl;
				isOpen = true;
				// Logic for whatever happens when they open a chest
				sprite.setTexture(textureOpen);
				if (player) {
					PlayerClass* playerCast = dynamic_cast<PlayerClass*>(player);
					if (playerCast) {
						playerCast->playerInventory[info].isCollected = true; // Add the item to the player's inventory
					}
					else {
						std::cerr << "Error: player is not of type PlayerClass!" << std::endl;
					}
				}
			}
		}
		else {
			isColliding = false;
		}
	}

}


void Chest::draw(sf::RenderWindow& window) {
	// Draw the object
	window.draw(sprite);
	

	if (isColliding && !isOpen) {
		window.draw(text); // Draw the text when colliding with the player
		// Draw the hitbox
		//hitbox.draw(window);
	}
}