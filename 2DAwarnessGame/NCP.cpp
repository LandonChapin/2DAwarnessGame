#include "NPC.h"


NPC::NPC(std::string texturePath, std::string texturePathOpen, int x, int y, float hitboxX, float hitboxY, int xTexture, int yTexture, PlayerClass* playerReference, int info, int pInfo) {
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
	this->pInfo = pInfo; // Store the player info value

	// Initialize the question menu
	conversationMenu.initializeMenu(info, sprite.getPosition());
}

bool NPC::detectPlayer(EntityClass& player) {
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

void NPC::update(float dt, sf::RenderWindow& window) {
	// Update the hitbox position to match the sprite position  
	hitbox.setPosition(sf::Vector2f(sprite.getPosition()));
	if (player) {

		if (detectPlayer(*player)) {
			isColliding = true;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && !conversationMenu.getActive()) {

				std::cout << "Interacting with person\n";

				conversationMenu.initializeMenu(info, sprite.getPosition());
				conversationMenu.setActive(true);
			}

			if (conversationMenu.getActive()) {
				conversationMenu.update(window, sprite.getPosition());

				if (!conversationMenu.getActive()) {
					sprite.setTexture(textureOpen);
				}
			}
		}
		else {
			isColliding = false;
		}

	}

}


void NPC::draw(sf::RenderWindow& window) {
	// Draw the object
	window.draw(sprite);

	if (isColliding) {
		if (conversationMenu.getActive()) {
			conversationMenu.draw(window);// Update the question menu if it's active
		}
		else {
			window.draw(text); // Draw the text when colliding with the player
		}
	}



}

void NPC::setOpen(bool open) {
	isOpen = open;
	if (!conversationMenu.getActive()) {
		sprite.setTexture(textureOpen); // Change the texture to the open chest
	}
	else {
		sprite.setTexture(texture); // Change the texture back to the closed chest
	}
}