#include "Car.h"

Car::Car(int x, int y, float hitboxX, float hitboxY,PlayerClass* playerReference, int type, bool poluting, float speed) 
	: EntityClass("Assets/NPCs/Cars/AG_Car_1_1.png", speed), hitbox(sf::Vector2f(hitboxX, hitboxY), sf::Color::White) {
	// Load the texture from the file
	if (!texture.loadFromFile("Assets/NPCs/Cars/AG_Car_1_1.png")) {
		std::cerr << "Error loading car texture!" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 70, 30));
	sprite.setPosition(x, y);
	sprite.setScale(10.0f * direction, 10.0f);
	sprite.setOrigin(70 / 2.0f, 30 / 2.0f);
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

	this->type = type; // Store the info value
	this->poluting = poluting; // Store whether the car is poluting or not
}



bool Car::detectPlayer(EntityClass& player) {
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

void Car::update(float dt, sf::RenderWindow& window) {
	// Update the hitbox position to match the sprite position  
	hitbox.setPosition(sf::Vector2f(sprite.getPosition()));
	if (player) {
		if (detectPlayer(*player)) {
			isColliding = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && !isOpen) {
				// Interact
				isOpen = true;
				// Logic for whatever happens when they click a car
				if (player) {
					PlayerClass* playerCast = dynamic_cast<PlayerClass*>(player);
					if (playerCast) {
						// Add to the score if the car is poluting and subtract if it is not
						if (poluting) {
							//
						}
						else {
							//
						}
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

	// Update the car position and animation
	updatePosition(dt); // Update the car position based on its speed and direction
	updateAnimation(dt); // Update the car texture animation

}

void Car::draw(sf::RenderWindow& window) {
	// Draw the car
	window.draw(sprite);
	// Draw the hitbox
		//hitbox.draw(window);
	// Draw the text
	if (isColliding) {
		window.draw(text);
	}
}

void Car::updateAnimation(float dt) {
	

	if (frameDelay >= 10000) {
		if (poluting) {
			texture.loadFromFile(carTextures[currentFrame]);
			if (currentFrame != 2) {
				currentFrame++;
			}
			else {
				currentFrame = 0; // Reset to the first frame after the last one
			}

		}
		else {
			// If the car is not poluting, then there is no animation
			currentFrame = 3;
			texture.loadFromFile(carTextures[currentFrame]);
		}
		// Reset the frame delay
		frameDelay = 0;
	}
	

	// Update the frame delay
	frameDelay += dt * 1000; // Convert dt to milliseconds for frame delay
}

void Car::updatePosition(float dt) {
	// Update the car position based on its speed and direction
	sprite.move(speed * direction * dt, 0);
	hitbox.setPosition(sprite.getPosition());
	text.setPosition(sprite.getPosition().x - 75, sprite.getPosition().y - 100);
}

void Car::setCarTextures(const std::array<std::string, 4>& textures) {
	carTextures = textures; // Set the car textures
	texture.loadFromFile(carTextures[0]); // Load the first texture as default
	sprite.setTexture(texture); // Set the texture to the sprite
};