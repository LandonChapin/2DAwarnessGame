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

	for (auto& button : loadMenuButtonArray) {
		setupButton(button.buttonText, button.buttonName, 35, sf::Color::Black, 900, 200 + (&button - &loadMenuButtonArray[0]) * 100);
	}

	for (auto& button : namingMenuButtonArray) {
		setupButton(button.buttonText, button.buttonName, 35, sf::Color::Black, 600, 400 + (&button - &namingMenuButtonArray[0]) * 100);
	}

	for (auto& button : mainMenuButtonArray) {
		button.buttonHitbox.setSize({ button.buttonText.getGlobalBounds().width, button.buttonText.getGlobalBounds().height });
		button.buttonHitbox.setPosition(button.buttonText.getPosition());
		button.buttonHitbox.setColor(sf::Color(0, 2, 0, 100));
	}
	for (auto& button : loadMenuButtonArray) {
		button.buttonHitbox.setSize({ button.buttonText.getGlobalBounds().width, button.buttonText.getGlobalBounds().height });
		button.buttonHitbox.setPosition(button.buttonText.getPosition());
		button.buttonHitbox.setColor(sf::Color(0, 2, 0, 100));
	}

	// Set up the naming menu button
	for (auto& button : namingMenuButtonArray) {
		button.buttonHitbox.setSize({ button.buttonText.getGlobalBounds().width, button.buttonText.getGlobalBounds().height });
		button.buttonHitbox.setPosition(button.buttonText.getPosition());
		button.buttonHitbox.setColor(sf::Color(0, 2, 0, 100));
	}
	nameInputBox.setSize(sf::Vector2f(400, 50)); // Set the size of the input box
	nameInputBox.setFillColor(sf::Color(255, 255, 255, 150)); // Set the color of the input box
	nameInputBox.setPosition(600, 300); // Set the position of the input box
	nameInputText.setFont(mainMenuFont); // Set the font for the input text
	nameInputText.setCharacterSize(24); // Set the character size for the input text
	nameInputText.setFillColor(sf::Color::Black); // Set the color for the input text
	nameInputText.setPosition(610, 310); // Set the position of the input text

	// Load the background texture
	if (!backgroundTexture.loadFromFile("Assets/Backgrounds/AG_Background_MainMenu.png")) {
		std::cerr << "Error loading background texture!" << std::endl;
	}
	background.setTexture(backgroundTexture);
	background.setPosition(0, 0); // Set the position of the background
	background.setScale(5.0f, 5.0f); // Scale the background to fit the window

}

void MainMenuClass::draw(sf::RenderWindow& window) {
	// Draw the background
	window.draw(background);
	// Draw the buttons
	switch (interMenuNumber) {
	case 0:
	{
		for (const auto& button : mainMenuButtonArray) {
			window.draw(button.buttonText);
		}
		break;
	}
	case 1: {
		for (const auto& button : loadMenuButtonArray) {
			window.draw(button.buttonText);
		}
		break;
	}
	case 2: 
	{
		for (const auto& button : namingMenuButtonArray) {
			window.draw(button.buttonText);
		}
		// Draw the name input box and text
		window.draw(nameInputBox);
		window.draw(nameInputText);
		break;
	}
	}
}

int MainMenuClass::update(sf::RenderWindow& window) {
	// Check for mouse hover and clicks on buttons
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f mousePosF = window.mapPixelToCoords(mousePos);

	switch (interMenuNumber) {
	case 0:
		for (auto& button : mainMenuButtonArray) {
			updateButtonHover(button.buttonText, button.buttonHitbox, mousePosF);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && button.buttonHitbox.getBounds().contains(mousePosF)) {
				if (button.buttonName == "NEW GAME" && inputDelay == 0) {
					handleNewGameButtonClicked();
					inputDelay = 700; // Delay to prevent multiple clicks
				}
				else if (button.buttonName == "LOAD GAME" && inputDelay == 0) {
					handleLoadGameButtonClicked();
					inputDelay = 700; // Delay to prevent multiple clicks
				}
				else if (button.buttonName == "SETTINGS" && inputDelay == 0) {
					handleSettingsButtonClicked();
					inputDelay = 700; // Delay to prevent multiple clicks
				}
				else if (button.buttonName == "QUIT" && inputDelay == 0) {
					handleQuitButtonClicked(window);
					inputDelay = 700; // Delay to prevent multiple clicks
				}
			}
		};
		break;
	
	case 1: {
		for (auto& button : loadMenuButtonArray) {
			updateButtonHover(button.buttonText, button.buttonHitbox, mousePosF);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && button.buttonHitbox.getBounds().contains(mousePosF)) {
				if (button.buttonName == "LOAD SLOT 1" && inputDelay == 0) {
					handleLoad1ButtonClicked();
					inputDelay = 300; // Delay to prevent multiple clicks
				}
				else if (button.buttonName == "LOAD SLOT 2" && inputDelay == 0) {
					handleLoad2ButtonClicked();
					inputDelay = 300; // Delay to prevent multiple clicks
				}
				else if (button.buttonName == "LOAD SLOT 3" && inputDelay == 0) {
					handleLoad3ButtonClicked();
					inputDelay = 300; // Delay to prevent multiple clicks
				}
			}
		}
		break;
	}
	case 2: {
		for (auto& button : namingMenuButtonArray) {
			updateButtonHover(button.buttonText, button.buttonHitbox, mousePosF);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && button.buttonHitbox.getBounds().contains(mousePosF)) {
				if (button.buttonName == "ENTER" && inputDelay == 0) {
					// Handle the enter button click
					std::cout << "Player Name Entered: " << playerNameInput << std::endl;
					menuNumber = 1; // Go to level 1
					inputDelay = 300; // Delay to prevent multiple clicks
				}
			}
		}
		// Handle text input for player name
		isNameInputActive = true; // Set the input active state to true
		handleTextInput(window);

		break;
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
	//menuNumber = 1; // Set menu number to indicate new game started
	interMenuNumber = 2;
}
void MainMenuClass::handleLoadGameButtonClicked() {
	std::cout << "Load Game button clicked!" << std::endl;
	isSaving = true; // Set the saving state to true
	interMenuNumber = 1;
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
	if (!isSaving) {
		for (size_t i = 0; i < mainMenuButtonArray.size(); ++i) {
			mainMenuButtonArray[i].buttonText.setPosition(600, 200 + i * 100);
			mainMenuButtonArray[i].buttonHitbox.setPosition(mainMenuButtonArray[i].buttonText.getPosition());
		}
	}
	else {
		for (size_t i = 0; i < loadMenuButtonArray.size(); ++i) {
			loadMenuButtonArray[i].buttonText.setPosition(900, 200 + i * 100);
			loadMenuButtonArray[i].buttonHitbox.setPosition(loadMenuButtonArray[i].buttonText.getPosition());
		}
	}
}

void MainMenuClass::handleLoad1ButtonClicked() {
	std::cout << "Load Slot 1 button clicked!" << std::endl;
	saveSlot = 1; // Set the save slot to 1
	isSaving = false; // Exit the saving state
	menuNumber = 10; // Set menu number to indicate loading game
}
void MainMenuClass::handleLoad2ButtonClicked() {
	std::cout << "Load Slot 2 button clicked!" << std::endl;
	saveSlot = 2; // Set the save slot to 2
	isSaving = false; // Exit the saving state
	menuNumber = 10; // Set menu number to indicate loading game
}
void MainMenuClass::handleLoad3ButtonClicked() {
	std::cout << "Load Slot 3 button clicked!" << std::endl;
	saveSlot = 3; // Set the save slot to 3
	isSaving = false; // Exit the saving state
	menuNumber = 10; // Set menu number to indicate loading game
}

void MainMenuClass::handleTextInput(sf::RenderWindow& window) {
	// Handle text input for player name
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::TextEntered) {
				if (isNameInputActive && inputDelay == 0) {
					if (event.text.unicode < 128) { // ASCII only
						char entered = static_cast<char>(event.text.unicode);
						if (std::isalnum(entered) || entered == ' ') {
							playerNameInput += entered;
							inputDelay = 100;

							nameInputText.setString(playerNameInput); // Update the text displayed in the input box
						}
					}
				}
			}
		}
		nameInputText.setPosition(nameInputBox.getPosition().x + 10, nameInputBox.getPosition().y + 10); // Adjust position inside the box
	}
