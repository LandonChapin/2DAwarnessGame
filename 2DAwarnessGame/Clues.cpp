#include "PauseMenu.h"


cluesMenuClass::cluesMenuClass() {
	if (!font.loadFromFile("Assets/Fonts/Seagram_tfb/Seagram tfb.ttf")) {
		std::cerr << "Failed to load inventory font!" << std::endl;
	}

	setupText(itemNameText, "", 35, sf::Color::Black, 700, 150);
	setupText(itemDescriptionText, "", 30, sf::Color::Black, 700, 200);

	// Setup buttons
	setupButton(pauseMenuButtonArray[0].buttonText, "NEXT", 30, sf::Color::Black, 1000, 500);
	setupButton(pauseMenuButtonArray[1].buttonText, "BACK", 30, sf::Color::Black, 1000, 550);
}


void cluesMenuClass::setupText(sf::Text& text, const std::string& str, int size, sf::Color color, float x, float y) {
	text.setFont(font);
	text.setString(str);
	text.setCharacterSize(size);
	text.setFillColor(color);
	text.setPosition(x, y);
	text.setLineSpacing(1.75f);
}

void cluesMenuClass::updateButtonHover(sf::Text& button, Hitbox& hitbox, const sf::Vector2f& mousePos) {
	if (hitbox.getBounds().contains(mousePos)) {
		button.setFillColor(sf::Color::Yellow); // Highlight on hover
	}
	else {
		button.setFillColor(sf::Color::Black); // Default color
	}
}

void cluesMenuClass::updateCluesMenu(PlayerClass& player, sf::RenderWindow& window) {
	
	sf::Vector2f mousePosF = window.mapPixelToCoords(sf::Mouse::getPosition(window));

	const auto& inventory = player.getPlayerInventory();
	float x = player.getPosition().x + 100, y = player.getPosition().y + 150;
	

	for (auto& button : pauseMenuButtonArray) {
		updateButtonHover(button.buttonText, button.buttonHitbox, mousePosF);


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && button.buttonHitbox.getBounds().contains(mousePosF)) {
			if (button.buttonName == "NEXT" && inputDelay == 0) {
				std::cout << "Next button clicked!" << std::endl;
				handleNextButtonClicked(player);
				inputDelay = 300; // Delay to prevent multiple clicks
			}
			else if (button.buttonName == "BACK" && inputDelay == 0) {
				std::cout << "Back button clicked!" << std::endl;
				handleBackButtonClicked(player);
				inputDelay = 300; // Delay to prevent multiple clicks
			}
			
		}
	}
	if (inputDelay > 0) {
		inputDelay--;
	}
	// Update Button Positions
	
		pauseMenuButtonArray[0].buttonText.setPosition(player.getPosition().x + 600, player.getPosition().y + 350);
		pauseMenuButtonArray[0].buttonHitbox.setPosition(pauseMenuButtonArray[0].buttonText.getPosition());

		pauseMenuButtonArray[1].buttonText.setPosition(player.getPosition().x - 550, player.getPosition().y + 350);
		pauseMenuButtonArray[1].buttonHitbox.setPosition(pauseMenuButtonArray[1].buttonText.getPosition());

	// Update item name and description text
	itemNameText.setString(inventory[currentItemIndex].Question);
	itemNameText.setPosition(player.getPosition().x + 150 - itemNameText.getLocalBounds().width / 2, player.getPosition().y - 380);

	if (inventory[currentItemIndex].isCollected) {
	
		itemDescriptionText.setString(inventory[currentItemIndex].Decription);
		itemDescriptionText.setPosition(player.getPosition().x + 150 - itemDescriptionText.getLocalBounds().width/2, player.getPosition().y - 290);
	}
	else {
		itemDescriptionText.setString("Clue has not been found");
		itemDescriptionText.setPosition(player.getPosition().x - 100, player.getPosition().y - 290);
	}
	

	
}

void cluesMenuClass::drawCluesMenu(sf::RenderWindow& window) {
	window.draw(itemDescriptionText);
	window.draw(itemNameText);

	// Draw all item buttons
	for (const auto& s_Button : pauseMenuButtonArray) {
		window.draw(s_Button.buttonText);
	}

}

void cluesMenuClass::setupButton(sf::Text& button, const std::string& text, int charSize, sf::Color color, float x, float y) {
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