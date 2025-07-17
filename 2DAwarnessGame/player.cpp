#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "Player.h"
#include "Hitbox.h"


PlayerClass::PlayerClass(std::string texturePath, float speed) : EntityClass(texturePath , speed)
{
	// Load the texture from the file
	if (!texture.loadFromFile(texturePath))
	{
		std::cerr << "Error loading texture!" << std::endl;
	}

	// Set the texture to the sprite
	sprite.setTexture(texture);
	
	// Set the texture rect to the single base sprite
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 64));

	// Set the position of the player
	sprite.setPosition(400, 800);
	// makesure that the players "Center" is the center of the sprite
	//was 32 32
	sprite.setOrigin(16, 32);
	// Set the scale of the player to make it look better
	sprite.setScale(3.0f * direction, 3.0f);

	hitbox.setPosition(sf::Vector2f(getPosition().x - 100.f, getPosition().y + 100.f)); // Adjusted position to be lower and more to the left  
	hitbox.setSize(sf::Vector2f(64.f, 128.f)); // Set the size of the hitbox  
	hitbox.setColor(sf::Color(0, 255, 0, 100)); // Set the color of the hitbox

	
	initializeFont(); // Initialize the font for the player name text
	setPlayerName("Default Name"); // Set the default player name

	// Set the speed of the player
	this->speed = speed;
};





void PlayerClass::draw(sf::RenderWindow& window)
{
	// Draw the player
	window.draw(sprite);
	//draw the hitbox
	//hitbox.draw(window);
	//draw the text
	window.draw(nameText);

}

// The direction the player is facing
int direction = 1;




// Function to handle all the things the player needs to update
void PlayerClass::update(float dt, sf::RenderWindow& window)
{
	handleInput(dt);
	// Update the hitbox position to match the sprite position
	hitbox.setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y));
	nameText.setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y - 60.f));
	
	// Create a view that follows the player
	sf::View view = window.getView();
	view.setCenter(sprite.getPosition()); // Center the view on the player's position
	window.setView(view); // Apply the updated view to the window
}

void PlayerClass::handleInput(float dt)
{
	// Handle the input
	// Out movement vector
	sf::Vector2f movement(0, 0);


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && getPosition().x > 300) {

		direction = -1; // Move left
		movement.x -= speed * dt; // Move left
		moved = true; // Set the moved flag to true
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && getPosition().x < 3695 ) {
		direction = 1; // Move right
		movement.x += speed * dt; // Move right
		moved = true; // Set the moved flag to true
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !jumping && !falling && onGround) {
		movement.y -= speed * dt * 10; // Move up
		jumping = true; // Set the moved flag to true
		onGround = false; // Set the onGround flag to false
		playerGravity = -115; // Reset the player gravity
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
		// Interact
	}


	// Move the player
	if (jumping && !falling && !onGround || !jumping && falling && !onGround) {
		playerGravity += 1; // Increase the gravity
		movement.y += playerGravity * dt; // Move down
		if (playerGravity > 0) {
			jumping = false; // Set the jumping flag to false
			falling = true; // Set the falling flag to true
		}
	}
	if (onGround && !jumping && !falling) {
		playerGravity = 0; // Reset the player gravity
	}
	if (sprite.getPosition().y >= 647) {
		onGround = true; // Set the onGround flag to true
		jumping = false; // Set the jumping flag to false
		falling = false; // Set the falling flag to false
		playerGravity = 0; // Reset the player gravity
		movement.y = 0; // Reset the movement
		sprite.setPosition(sprite.getPosition().x, 645); // Set the position of the player
	}

	sprite.move(movement * speed * dt);

	// Handle the animation
	handleAnimation(direction, dt);
}


// Function to handle the animation of the player
void PlayerClass::handleAnimation(int direction, float dt)
{
	// Increment the elapsed time
	timeSinceLastFrame += dt;

	// Set The texture for the frame
	

	if (moved && !jumping) {
		texture.loadFromFile(walkArray[curentFrame % 3]);
		timePerFrame = 12.0f;
		FrameEnd = 3;
		SleepCounter = 0;
	}
	else if (jumping) {
		texture.loadFromFile("");
		SleepCounter = 0;
	}
	else if (falling) {
		texture.loadFromFile("");
		SleepCounter = 0;
	}
	
	else {
		texture.loadFromFile(idleArray[curentFrame % 2]);
		timePerFrame = 24.0f; // 1/10 of a second
		FrameEnd = 2;
		SleepCounter = SleepCounter + 1;
	}

	// If the elapsed time is greater than the time per frame
	if (timeSinceLastFrame > timePerFrame)
	{
		if (curentFrame == FrameEnd)
		{
			curentFrame = 0;
		}
		// and -1 being moving left. (To make the flipping easier)
		sprite.setScale(3.0f * direction, 3.0f);

		// Increment the current frame
		curentFrame++;

		// Reset the elapsed time
		timeSinceLastFrame = 0;
	}

	moved = false; // Reset the moved flag
	sprite.setTexture(texture); // Set the texture of the sprite to the current frame
}



void PlayerClass::setPlayerName(const std::string name) {
	displayName = name;
	nameText.setString(displayName);
	nameText.setOrigin(nameText.getLocalBounds().width / 2, nameText.getLocalBounds().height / 2); // Set the origin to the center of the text
};

void PlayerClass::initializeFont() {
	// Initialize display name
	if (!nameFont.loadFromFile("Assets/Fonts/Seagram_tfb/Seagram tfb.ttf")) {
		std::cerr << "Failed to load font!" << std::endl;
	}
	nameText.setFont(nameFont); // Set the font for the display name

	nameText.setCharacterSize(24); // Set the character size for the display name
	nameText.setFillColor(sf::Color::White); // Set the color for the display name
	nameText.setOrigin(nameText.getLocalBounds().width / 2, nameText.getLocalBounds().height / 2); // Set the origin to the center of the text

};