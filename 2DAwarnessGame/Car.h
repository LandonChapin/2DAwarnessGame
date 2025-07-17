#include "Entity.h"
#include "Interact.h"
#include "player.h"
#include <array>

class Car : public EntityClass, public Interact {
public:
	Car() {}; // Default constructor
	void draw(sf::RenderWindow& window) override;
	void update(float dt, sf::RenderWindow& window) override;
	// Constructor to initialize the car with a position, and hitbox
	// Parameters: x, y - position, hitboxX, hitboxY - size of the hitbox, Player Reference - type, type of the car, poluting - whether the car is poluting or not, speed
	Car(int x, int y, float hitboxX, float hitboxY, PlayerClass* playerRef, int type, bool poluting, float speed);
	EntityClass* player = nullptr; // Pointer to the player object  
	bool detectPlayer(EntityClass& player) override; // Move this to public to make it accessible

	void setCarTextures(const std::array<std::string, 4>& textures);

private:

	void updateAnimation(float dt); // Updates the car texture
	void updatePosition(float dt); // Updates the car position based on its speed and direction

	sf::Texture texture; // Texture for the car
	sf::Sprite sprite; // Sprite for the car
	Hitbox hitbox; // Hitbox for the car
	int type; // Type of the car, 0 = normal, 1 = poluting
	bool poluting; // Whether the car is poluting or not
	bool isOpen = false; // State of the car
	bool isColliding = false; // State of collection
	int direction = -1; // Direction of the car, 1 = right, -1 = left
	sf::Font font; // Font for text rendering
	sf::Text text; // Text to display when player is near the car

	std::array<std::string, 4> carTextures;

	float frameDelay = 0; // Delay between frames for animation
	int currentFrame = 0; // Current frame of the animation
};



#pragma once
