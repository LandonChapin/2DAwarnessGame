#include "GameController.h"


GameController::GameController(){
	// Initialize the game controller
	currentLevel = 0;
	window.create(sf::VideoMode(1600, 900), "2D Awareness Game");
	isPaused = false;
	dt = 0.1f;
	player = PlayerClass("Assets/Player/AG_Player.png", 10); // Assuming Player is a class that handles player logic
	pauseMenu.setCurrentMenu(0); // Set the current menu to 0 (Main Menu)
	mainMenu.initialize(); // Set the current menu to 0 (Main Menu)
	
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
				if (event.key.code == sf::Keyboard::Num1) { // Reset the game
					currentLevel = 1;
					world.initialize(1); // Initialize the world for level 1
				}
				if (event.key.code == sf::Keyboard::Num2) { // Go to level 2
					currentLevel = 2;
					world.initialize(2); // Initialize the world for level 2
				}
				if (event.key.code == sf::Keyboard::Num3) { // Go to level 3
					currentLevel = 3;
					world.initialize(3); // Initialize the world for level 3
				}
			}
		}
		if (isPaused) {
			runPauseMenu(&npcManager);
			continue; // Skip the rest of the loop while paused
		}
		else { initializeLevel(currentLevel, &npcManager); }
	}
}

void GameController::initializeLevel(int level, NpcManager* npcManager) {


	switch (level) {
		case 0:
			// Logic for initializing level 0
			window.clear(sf::Color::Black);

			currentLevel = mainMenu.update(window); // Update the main menu
			

			mainMenu.draw(window); // Draw the main menu

			musicPlayer.update(dt, currentLevel); // Update the music player based on the current level

			window.display(); // Display the main menu
			break;

		case 1:
			// Logic for initializing level 1
			
			window.clear(sf::Color::Black);
			
			
			world.update(player, window, dt); // Update the game world
			player.update(dt, window);

			world.draw(window); // Draw the game world
			
			npcManager ->npcUpdate(dt, window, level); // Update the entities
			npcManager->npcDraw(window, level); // Draw the entities

			
			player.draw(window);

			world.drawForeground(window); // Draw the foreground elements of the world

			musicPlayer.update(dt, currentLevel); // Update the music player based on the current level

			window.display();
			break;

		case 2:
			// Logic for initializing level 2
			
			window.clear(sf::Color::Black);

			
			world.update(player, window, dt); // Update the game world
			player.update(dt, window);

			world.draw(window); // Draw the game world

			npcManager->npcUpdate(dt, window, level); // Update the entities
			


			player.draw(window);

			world.drawForeground(window); // Draw the foreground elements of the world
			npcManager->npcDraw(window, level); // Draw the entities

			musicPlayer.update(dt, currentLevel); // Update the music player based on the current level

			window.display();
			break;

		case 3:
			// Logic for initializing level 3
			
			window.clear(sf::Color::Black);
			
			world.update(player, window, dt); // Update the game world
			player.update(dt, window);

			npcManager->npcUpdate(dt, window, level); // Update the entities

			world.draw(window); // Draw the game world
			player.draw(window);

			npcManager->npcDraw(window, level); // Draw the entities
			world.drawForeground(window); // Draw the foreground elements of the world

			musicPlayer.update(dt, currentLevel); // Update the music player based on the current level
			
			window.display(); // Display the game world

			break;

		case 4:
			// Logic for initializing level 4

			window.clear(sf::Color::Black);

			world.update(player, window, dt); // Update the game world
			player.update(dt, window);

			npcManager->npcUpdate(dt, window, level); // Update the entities


			world.draw(window); // Draw the game world

			npcManager->npcDraw(window, level); // Draw the entities
			
			player.draw(window);
			
			world.drawForeground(window); // Draw the foreground elements of the world

			musicPlayer.update(dt, currentLevel); // Update the music player based on the current level

			window.display(); // Display the game world

			break;

		default:
			std::cout << "No more levels to initialize." << std::endl;
			break;
	}
}

void GameController::runPauseMenu(NpcManager* npcManager) {
	// Display pause menu
	window.clear(sf::Color::White);
	isPaused = pauseMenu.update(window, player);
	if (!isPaused) {
		pauseMenu.setCurrentMenu(0);
	}

	int pauseState = pauseMenu.checkSaving();
	if (pauseState == 1) {
		savingClass save;
		save.saveGame(pauseMenu.getSaveSlot(), currentLevel, player);
		pauseMenu.setSaving(false);
		pauseMenu.finishSave();
	}
	else if (pauseState == 2) {
		savingClass save;
		save.loadGame(pauseMenu.getSaveSlot(), currentLevel, player, *npcManager);
		world.initialize(currentLevel); // <-- Add this line
		pauseMenu.setLoading(false);
		pauseMenu.finishSave();
	}

	pauseState = pauseMenu.getCurrentMenu();
	if (pauseState == 6) {
		int selectedLevel = pauseMenu.getLevelSelectorLevel();
		if (selectedLevel > 0) {
			currentLevel = selectedLevel;
			std::cout << "Selected Level: " << currentLevel << std::endl;
			world.initialize(currentLevel); // Reinitialize the world for the selected level
			pauseMenu.setCurrentMenu(0); // Go back to the main menu
		}
	};
	
	pauseMenu.draw(window); // Draw the pause menu
	window.display();
};