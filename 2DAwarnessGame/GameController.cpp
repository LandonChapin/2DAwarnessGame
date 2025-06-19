#include "GameController.h"


GameController::GameController(){
	// Initialize the game controller
	currentLevel = 1;
	window.create(sf::VideoMode(1600, 900), "2D Awareness Game");
	isPaused = false;
	dt = 0.1f;
	player = PlayerClass("Assets/Player/AG_Player.png", 10); // Assuming Player is a class that handles player logic
	pauseMenu.setCurrentMenu(0); // Set the current menu to 0 (Main Menu)
	
	background = sf::RectangleShape(sf::Vector2f(5000, 1500));
	background.setFillColor(sf::Color::Blue);
	ground = sf::RectangleShape(sf::Vector2f(5000, 800));
	ground.setFillColor(sf::Color::Green);
	ground.setPosition(0, 0);
	world = PlayWorld();
	world.initialize(1);
	


	
}

void GameController::playGame() {
	player.initializeFont(); // Load a font for the player
	NpcManager npcManager(&player); // Initialize the NPC manager
	

	// Start the game loop
	while (true) {
		//close the window  
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::I || event.key.code == sf::Keyboard::Escape) {  //pause game  
					isPaused = !isPaused;

				}
			}
		}
		if (isPaused) {
			runPauseMenu();
			continue; // Skip the rest of the loop while paused
		}
		else { initializeLevel(currentLevel, &npcManager); }
	}
}

void GameController::initializeLevel(int level, NpcManager* npcManager) {


	switch (level) {
		case 0:
			// Logic for initializing level 0
			std::cout << "Running Main Menu" << std::endl;
			break;
		case 1:
			// Logic for initializing level 1
			window.clear(sf::Color::Black);
			
			world.update(player, window); // Update the game world
			player.update(dt, window);

			world.draw(window); // Draw the game world
			
			npcManager ->npcUpdate(dt, window); // Update the entities
			npcManager->npcDraw(window); // Draw the entities

			
			player.draw(window);

			world.drawForeground(window); // Draw the foreground elements of the world

			window.display();
			break;
		default:
			std::cout << "No more levels to initialize." << std::endl;
			break;
	}
}

void GameController::runPauseMenu() {
	// Display pause menu
	window.clear(sf::Color::White);
	isPaused = pauseMenu.update(window, player);
	if (!isPaused) {
		pauseMenu.setCurrentMenu(0);
	}
	
	
	pauseMenu.draw(window); // Draw the pause menu
	window.display();
};