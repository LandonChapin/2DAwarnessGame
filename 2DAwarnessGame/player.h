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
		{"WHAT IS AIR POLLUTION?", "Air pollution is when harmful gases, dust, \nand other particles are present in the air we breathe.", false},
		{"WHERE DOES AIR POLLUSTION COME FROM?", "Air pollution can originate from various sources,\n including cars, factories, power plants, wildfires, and volcanic eruptions.", false},
		{"WHY IS AIR POLLUTION BAD?", "Air pollution can harm our health, especially for children.\n It can cause respiratory problems, such as asthma and bronchitis,\n as well as eye irritation, headaches, and nausea.", false},
		{"HOW DOES AIR POLUTION AFFECT CHILDREN?", "Children are more vulnerable to the effects of air pollution\n than adults because their lungs are still developing.\n Air pollution can damage their lungs\n and increase their risk of respiratory diseases.", false},
		{"WHAT CAN WE DO ABOUT AIR POLLUTION?", "We can help reduce air pollution by:\nWalking, biking, or taking public transportation instead of driving\nUsing energy - efficient appliances\nRecycling and composting\nPlanting trees\nSupporting policies that promote clean energy", false},
		{"test", "test", false},
		{"test", "test", false},
		{"test", "test", false},
		{"WHAT CAUSES THIS AIR POLUTION IN THE CITY", "Air pollution in cities is primarily caused\n by a combination of human activities, including transportation,\n industrial emissions, and construction,\na as well as natural factors like weather patterns.\n These sources release pollutants like particulate matter,\n nitrogen oxides, and sulfur dioxide,\n which can lead to smog, respiratory problems, and other health issues. ", false}

	};

	int getScore() const {
		return score;
	}
	void setScore(int newScore) {
		score = newScore;
		scoreText.setString("Score: " + std::to_string(score));
	}

	void drawScore(sf::RenderWindow& window) {
		window.draw(scoreText);
	}

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
	bool moved = false; // Flag to check if the player has moved this frame
	bool jumping = false; // Flag to check if the player is jumping
	bool falling = false; // Flag to check if the player is falling
	bool onGround = true; // Flag to check if the player is on the ground
	int playerGravity = 0; // Number of frames the player has been jumping
	int FrameEnd;

	int score = 0; // Player's score

	// variables for display name
	std::string displayName = "Default Name"; // The name of the player
	sf::Text nameText; // The text object for the name
	sf::Font nameFont; // The font for the name text

	sf::Text scoreText; // The text object for the score

	int SleepCounter = 0;
	void handleAnimation(int direction, float dt);
	// Array of walking frames
	std::vector<std::string> walkArray = {
		"Assets/Player/Walk/AG_Player_Walk1.png",
		"Assets/Player/Walk/AG_Player_Walk2.png",
		"Assets/Player/Walk/AG_Player_Walk3.png",
	};
	// Array of Idle frames
	std::vector<std::string> idleArray = {
		"Assets/Player/AG_Player.png",
		"Assets/Player/Idle/AG_Player_Idle2.png",
	};

	
};

#endif
