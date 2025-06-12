#include "GameController.h"


GameController::GameController(){
	// Initialize the game controller
	currentLevel = 1;
	window.create(sf::VideoMode(1600, 900), "2D Awareness Game");
	isPaused = false;
	dt = 0.1f;
	player = PlayerClass("", 10); // Assuming Player is a class that handles player logic
	
	background = sf::RectangleShape(sf::Vector2f(8000, 6000));
	background.setFillColor(sf::Color::Blue);
	ground = sf::RectangleShape(sf::Vector2f(8000, 100));
	ground.setFillColor(sf::Color::Green);
	ground.setPosition(0, 650);
	chest = Chest("", 600, 670, 100.f, 100.f, 50, 50, &player);
	
}

void GameController::playGame() {
	player.initializeFont(); // Load a font for the player
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
		else { initializeLevel(currentLevel); }
	}
}

void GameController::initializeLevel(int level) {
	// Set the current level
	currentLevel = level;
	switch (level) {
		case 0:
			// Logic for initializing level 0
			std::cout << "Running Main Menu" << std::endl;
			break;
		case 1:
			// Logic for initializing level 1
			window.clear(sf::Color::Black);
			

			window.draw(background); // Draw the background
			window.draw(ground); // Draw the ground
			chest.update(dt, window); // Update the chest state
			chest.draw(window); // Draw the chest

			player.update(dt, window);
			player.draw(window);
			window.display();
			break;
		default:
			std::cout << "No more levels to initialize." << std::endl;
			break;
	}
}

void GameController::runPauseMenu() {
	// Display pause menu
	window.clear(sf::Color::Black);
	sf::Font font;
	font.loadFromFile("Assets/Fonts/Seagram_tfb/Seagram tfb.ttf"); // Load a font file

	sf::Text pauseText;
	pauseText.setPosition(player.getPosition().x - 300, player.getPosition().y);
	pauseText.setString("Game Paused. Press 'I' or 'Escape' to resume.");
	pauseText.setCharacterSize(35);
	pauseText.setFillColor(sf::Color::White);
	pauseText.setFont(font);
	window.draw(pauseText);
	window.display();
	
};