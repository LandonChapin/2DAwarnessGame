#include "pauseMenu.h"

savingMenuClass::savingMenuClass() {
	if (!font.loadFromFile("Assets/Fonts/ikan-besar_tfb/IkanBesar tfb.ttf")) {
		std::cerr << "Failed to load inventory font!" << std::endl;
	}

	setupText(saveText, "Save Game", 50, sf::Color::Black, 100, 100);
	setupText(loadText, "Load Game", 50, sf::Color::Black, 100, 200);

	setupButton(savingMenuButtonArray[0].buttonText, "SAVE SLOT 1", 30, sf::Color::Black, 100, 300);
	setupButton(savingMenuButtonArray[1].buttonText, "SAVE SLOT 2", 30, sf::Color::Black, 100, 350);
	setupButton(savingMenuButtonArray[2].buttonText, "SAVE SLOT 3", 30, sf::Color::Black, 100, 400);

	setupButton(loadingMenuButtonArray[0].buttonText, "LOAD SLOT 1", 30, sf::Color::Black, 100, 500);
	setupButton(loadingMenuButtonArray[1].buttonText, "LOAD SLOT 2", 30, sf::Color::Black, 100, 550);
	setupButton(loadingMenuButtonArray[2].buttonText, "LOAD SLOT 3", 30, sf::Color::Black, 100, 600);

};

void savingMenuClass::setupText(sf::Text& text, const std::string& str, int size, sf::Color color, float x, float y) {
	text.setFont(font);
	text.setString(str);
	text.setCharacterSize(size);
	text.setFillColor(color);
	text.setPosition(x, y);
	text.setLineSpacing(1.75f);
}

void savingMenuClass::updateButtonHover(sf::Text& button, Hitbox& hitbox, const sf::Vector2f& mousePos) {
	if (hitbox.getBounds().contains(mousePos)) {
		button.setFillColor(sf::Color::Yellow); // Highlight on hover
	}
	else {
		button.setFillColor(sf::Color::Black); // Default color
	}
}

void savingMenuClass::draw(sf::RenderWindow& window) {

	if (saving == 1) {
		window.draw(saveText);

		for (auto& button : savingMenuButtonArray) {
			window.draw(button.buttonText);
		}
	}
	else if (saving == 2) {
		window.draw(loadText);

		for (auto& button : loadingMenuButtonArray) {
			window.draw(button.buttonText);
		}
	}

};

bool savingMenuClass::update(PlayerClass& player, sf::RenderWindow& window, int i) {
	saving = i;

	// Update Button Positions
	int bp = 0; // Int for button positiononing
	if (saving == 1) {
		for (auto& button : savingMenuButtonArray) {
			button.buttonText.setPosition(player.getPosition().x + 50, player.getPosition().y - 200 + bp);
			button.buttonHitbox.setPosition(button.buttonText.getPosition());

			bp += 65;
		}

		saveText.setPosition(player.getPosition().x + 50, player.getPosition().y - 450);
	}
	else if (saving == 2) {
		for (auto& button : loadingMenuButtonArray) {
			button.buttonText.setPosition(player.getPosition().x + 50, player.getPosition().y - 200 + bp);
			button.buttonHitbox.setPosition(button.buttonText.getPosition());

			bp += 65;
		}

		loadText.setPosition(player.getPosition().x + 50, player.getPosition().y - 450);
	}

	// Handling Inputs
	sf::Vector2f mousePosF = window.mapPixelToCoords(sf::Mouse::getPosition(window));

	float x = player.getPosition().x + 100, y = player.getPosition().y + 150;
	if (saving == 1) {

	for (auto& button : savingMenuButtonArray) {
		updateButtonHover(button.buttonText, button.buttonHitbox, mousePosF);


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && button.buttonHitbox.getBounds().contains(mousePosF)) {
			if (button.buttonName == "SAVE SLOT 1" && inputDelay == 0) {
				std::cout << "Save Slot 1 button clicked!" << std::endl;
				handleSaveSlot1Clicked();
				inputDelay = 300; // Delay to prevent multiple clicks
				return false;
			}
			else if (button.buttonName == "SAVE SLOT 2" && inputDelay == 0) {
				std::cout << "Save Slot 2 button clicked!" << std::endl;
				handleSaveSlot2Clicked();
				inputDelay = 300; // Delay to prevent multiple clicks
				return false;
			}
			else if (button.buttonName == "SAVE SLOT 3" && inputDelay == 0) {
				std::cout << "Save Slot 3 button clicked!" << std::endl;
				handleSaveSlot3Clicked();
				inputDelay = 300; // Delay to prevent multiple clicks
				return false;
			}
		}
	}
}
	else if (saving == 2) {
		for (auto& button : loadingMenuButtonArray) {
			updateButtonHover(button.buttonText, button.buttonHitbox, mousePosF);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && button.buttonHitbox.getBounds().contains(mousePosF)) {
				if (button.buttonName == "LOAD SLOT 1" && inputDelay == 0) {
					std::cout << "Load Slot 1 button clicked!" << std::endl;
					handleLoadSlot1Clicked();
					inputDelay = 300; // Delay to prevent multiple clicks
					return false;
				}
				else if (button.buttonName == "LOAD SLOT 2" && inputDelay == 0) {
					std::cout << "Load Slot 2 button clicked!" << std::endl;
					handleLoadSlot2Clicked();
					inputDelay = 300; // Delay to prevent multiple clicks
					return false;
				}
				else if (button.buttonName == "LOAD SLOT 3" && inputDelay == 0) {
					std::cout << "Load Slot 3 button clicked!" << std::endl;
					handleLoadSlot3Clicked();
					inputDelay = 300; // Delay to prevent multiple clicks
					return false;
				}
			}
		}
	}
	else {
		// Reset Input Delay
		if (inputDelay > 0) {
			inputDelay--;
		}
		return false;
	}
	

}

void savingMenuClass::setupButton(sf::Text& button, const std::string& text, int charSize, sf::Color color, float x, float y) {
	button.setFont(font);
	button.setString(text);
	button.setCharacterSize(charSize);
	button.setFillColor(color);

	// Adjust the origin to the center of the text
	sf::FloatRect textBounds = button.getLocalBounds();
	button.setOrigin(textBounds.left + textBounds.width / 2.0f,
		textBounds.top + textBounds.height / 2.0f);

	button.setPosition(x, y);
}

void savingMenuClass::handleSaveSlot1Clicked() {
	saveSlot = 1;
}
void savingMenuClass::handleSaveSlot2Clicked() {
	saveSlot = 2;
}
void savingMenuClass::handleSaveSlot3Clicked() {
	saveSlot = 3;
}
void savingMenuClass::handleLoadSlot1Clicked() {
	saveSlot = 1;
}
void savingMenuClass::handleLoadSlot2Clicked() {
	saveSlot = 2;
}
void savingMenuClass::handleLoadSlot3Clicked() {
	saveSlot = 3;
}

void savingMenuClass::resetSaveMenu() {
#include <iostream>
	// anything we need to do to reset the save menu
	saveSlot = 0;

	std::cout << "Save menu reset." << std::endl;
}
