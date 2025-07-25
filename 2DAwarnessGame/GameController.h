#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.h"
#include "chest.h"
#include "entity.h"
#include "npcManager.h"
#include "pauseMenu.h"
#include "MainMenu.h"
#include "Level.h"
#include "musicPlayer.h"
#include "TextDisplay.h"

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
	PlayWorld world; // Instance of the PlayWorld class

	PauseMenuClass pauseMenu; // Instance of the pause menu class
	MainMenuClass mainMenu; // Instance of the main menu class
	TextDisplayClass textDisplay; // Instance of the text display class


	MusicPlayer musicPlayer; // Instance of the music player class

	void runPauseMenu(NpcManager* npcManager);
	void initializeLevel(int level, NpcManager* npcManager);
};

#pragma once
