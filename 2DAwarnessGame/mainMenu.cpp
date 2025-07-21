#include "MainMenu.h"

MainMenuClass::MainMenuClass() {

};

void MainMenuClass::initialize() {
	// Load the font
	if (!mainMenuFont.loadFromFile(fontString)) {
		std::cerr << "Error loading font!" << std::endl;
	}

	// Set up the buttons
	for (auto& button : mainMenuButtonArray) {
		setupButton(button.buttonText, button.buttonName, 35, sf::Color::Black, 600, 200 + (&button - &mainMenuButtonArray[0]) * 100);
	}


	for (auto& button : mainMenuButtonArray) {
		button.buttonHitbox.setSize({ button.buttonText.getGlobalBounds().width, button.buttonText.getGlobalBounds().height });
		button.buttonHitbox.setPosition(button.buttonText.getPosition());
		button.buttonHitbox.setColor(sf::Color(0, 2, 0, 100));
	}
}

void MainMenuClass::draw(sf::RenderWindow& window) {
	// Draw the buttons
	for (const auto& button : mainMenuButtonArray) {
		window.draw(button.buttonText);
	}
}

int MainMenuClass::update(sf::RenderWindow& window) {
	// Check for mouse hover and clicks on buttons
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f mousePosF = window.mapPixelToCoords(mousePos);
	for (auto& button : mainMenuButtonArray) {
		updateButtonHover(button.buttonText, button.buttonHitbox, mousePosF);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && button.buttonHitbox.getBounds().contains(mousePosF)) {
			if (button.buttonName == "NEW GAME" && inputDelay == 0) {
				handleNewGameButtonClicked();
				inputDelay = 300; // Delay to prevent multiple clicks
			}
			else if (button.buttonName == "LOAD GAME" && inputDelay == 0) {
				handleLoadGameButtonClicked();
				inputDelay = 300; // Delay to prevent multiple clicks
			}
			else if (button.buttonName == "SETTINGS" && inputDelay == 0) {
				handleSettingsButtonClicked();
				inputDelay = 300; // Delay to prevent multiple clicks
			}
			else if (button.buttonName == "QUIT" && inputDelay == 0) {
				handleQuitButtonClicked(window);
				inputDelay = 300; // Delay to prevent multiple clicks
			}
		}
	}
	if (inputDelay > 0) {
		inputDelay--;
	}
	// Update button positions
	updateButtonPositions();

	return menuNumber; // Return the current menu number
}

void MainMenuClass::setupButton(sf::Text& button, const std::string& text, int charSize, sf::Color color, float x, float y) {
	button.setFont(mainMenuFont);
	button.setString(text);
	button.setCharacterSize(charSize);
	button.setFillColor(color);
	// Adjust the origin to the center of the text
	sf::FloatRect textBounds = button.getLocalBounds();
	button.setOrigin(textBounds.left + textBounds.width / 2.0f,
		textBounds.top + textBounds.height / 2.0f);
	button.setPosition(x, y);
}

void MainMenuClass::updateButtonHover(sf::Text& button, Hitbox& hitbox, const sf::Vector2f& mousePos) {
	if (hitbox.getBounds().contains(mousePos)) {
		button.setFillColor(sf::Color::Yellow); // Highlight on hover
	} else {
		button.setFillColor(sf::Color::White); // Default color
	}
}

void MainMenuClass::handleNewGameButtonClicked() {
	std::cout << "New Game button clicked!" << std::endl;
	// Logic to start a new game
	menuNumber = 1; // Set menu number to indicate new game started
}
void MainMenuClass::handleLoadGameButtonClicked() {
	std::cout << "Load Game button clicked!" << std::endl;
	// Logic to load a game
}
void MainMenuClass::handleSettingsButtonClicked() {
	std::cout << "Settings button clicked!" << std::endl;
	// Logic to open settings menu
}
void MainMenuClass::handleQuitButtonClicked(sf::RenderWindow& window) {
	std::cout << "Quit button clicked!" << std::endl;
	window.close(); // Close the window
}

void MainMenuClass::updateButtonPositions() {
	// Update the positions of the buttons based on the current window size
	for (size_t i = 0; i < mainMenuButtonArray.size(); ++i) {
		mainMenuButtonArray[i].buttonText.setPosition(600, 200 + i * 100);
		mainMenuButtonArray[i].buttonHitbox.setPosition(mainMenuButtonArray[i].buttonText.getPosition());
	}
}