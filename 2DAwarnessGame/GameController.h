#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.h"
#include "chest.h"
#include "entity.h"

// Header file for the GameController class
class GameController {
public:
	// Constructor
	GameController();
	// Method to start the game
	void playGame();

private:
	int currentLevel; // Variable to track the current level of the game
	float dt; // Delta time for frame rate independent movement
	PlayerClass player; // Create a player instance
	sf::RenderWindow window; // SFML window for rendering the game
	bool isPaused; // Variable to track if the game is paused

	// test variables
	sf::RectangleShape background;
	sf::RectangleShape ground;
	Chest chest;


	void runPauseMenu();
	void initializeLevel(int level);
};

#pragma once
