#include "Entity.h"

// Constructor for the Entity class
EntityClass::EntityClass(std::string texturePath, float speed) : hitbox(sf::Vector2f(50.f, 50.f), sf::Color::Green) {
	// Load the texture from the file
	if (!texture.loadFromFile(texturePath)) {
		std::cerr << "Error loading texture from " << texturePath << std::endl;
	}
	sf::Texture texture = sf::Texture(); // Placeholder for texture loading
	sprite.setTexture(texture);
	this->speed = speed;
}
// Get the position of the entity
sf::Vector2f EntityClass::getPosition() {
	return sprite.getPosition();
}
// Get the global bounds of the entity
sf::FloatRect EntityClass::getGlobalBounds() {
	return sprite.getGlobalBounds();
}
// Get the hitbox of the entity
Hitbox& EntityClass::getHitbox() {
	return hitbox;
}

