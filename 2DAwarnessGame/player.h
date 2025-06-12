// This class will handle the players movement, and the input, 
#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Entity.h"


class PlayerClass : public EntityClass {  // The player class is a child of the Entity class, that the user controls
public:
	PlayerClass(std::string texturePath, float speed);
	PlayerClass() {};
	void draw(sf::RenderWindow& window) override;
	void update(float dt, sf::RenderWindow& window) override;
	void handleInput(float dt);
	int getHealth() const;
	void takeDamage(int amount, int direction);
	void setPlayerName(const std::string name);
	void initializeFont();
	Hitbox hitbox;
	std::vector <s_Item> getPlayerInventory() {
		return playerInventory;
	}
	s_Item getPlayerInventoryItem(int index) {
		if (index >= 0 && index < playerInventory.size()) {
			return playerInventory[index];
		}
		else {
			return s_Item(); // Return an empty item if the index is out of bounds
		}
	}

	std::vector <s_Item> playerInventory{
	};
private:
	// Items that the player has

	sf::Texture texture;
	int curentFrame = 0; // The current frame of the animation
	// Time per frame
	float timePerFrame; // 1/10 of a second
	// Time since the last frame of the animation
	float timeSinceLastFrame = 0.0f;
	// Speed of the player
	float speed = 9.f;
	// The health of the player
	int health = 25;
	// Damage management
	float damageCooldown = 0.5f; // seconds
	float timeSinceLastHit = 0.f;
	bool moved = false; // Flag to check if the player has moved this frame
	bool jumping = false; // Flag to check if the player is jumping
	bool falling = false; // Flag to check if the player is falling
	bool onGround = true; // Flag to check if the player is on the ground
	bool playerDead = false; //check if the player is dead
	int playerGravity = 0; // Number of frames the player has been jumping
	int FrameEnd;

	// variables for display name
	std::string displayName = "Default Name"; // The name of the player
	sf::Text nameText; // The text object for the name
	sf::Font nameFont; // The font for the name text

	int SleepCounter = 0;
	void handleAnimation(int direction, float dt);
};

#endif
