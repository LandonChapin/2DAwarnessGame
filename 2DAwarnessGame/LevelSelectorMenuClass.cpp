#include "pauseMenu.h"

#include "PauseMenu.h"


LevelSelectorMenuClass::LevelSelectorMenuClass() {
	if (!font.loadFromFile("Assets/Fonts/ikan-besar_tfb/IkanBesar tfb.ttf")) {
		std::cerr << "Error loading font!" << std::endl;
	}

	

	// Setup buttons
	setupButton(pauseMenuButtonArray[0].buttonText, "PARK: DAY", 30, sf::Color::Black, 1000, 500);
	setupButton(pauseMenuButtonArray[1].buttonText, "PARK: NIGHT", 30, sf::Color::Black, 1000, 550);
	setupButton(pauseMenuButtonArray[2].buttonText, "BRIDGE: DAY", 30, sf::Color::Black, 1000, 600);
	setupButton(pauseMenuButtonArray[3].buttonText, "BRIDGE: NIGHT", 30, sf::Color::Black, 1000, 650);
}


void LevelSelectorMenuClass::setupText(sf::Text& text, const std::string& str, int size, sf::Color color, float x, float y) {
	text.setFont(font);
	text.setString(str);
	text.setCharacterSize(size);
	text.setFillColor(color);
	text.setPosition(x, y);
	text.setLineSpacing(2.2f);
}

void LevelSelectorMenuClass::updateButtonHover(sf::Text& button, Hitbox& hitbox, const sf::Vector2f& mousePos) {
	if (hitbox.getBounds().contains(mousePos)) {
		button.setFillColor(sf::Color::Yellow); // Highlight on hover
	}
	else {
		button.setFillColor(sf::Color::Black); // Default color
	}
}

void LevelSelectorMenuClass::update(sf::RenderWindow& window, PlayerClass& player) {

	sf::Vector2f mousePosF = window.mapPixelToCoords(sf::Mouse::getPosition(window));

	
	float x = player.getPosition().x + 100, y = player.getPosition().y + 150;


	for (auto& button : pauseMenuButtonArray) {
		updateButtonHover(button.buttonText, button.buttonHitbox, mousePosF);


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && button.buttonHitbox.getBounds().contains(mousePosF)) {
			if (button.buttonName == "PARK: DAY" && inputDelay == 0) {
				std::cout << "Park day button clicked!" << std::endl;
				handleParkDayButtonClicked();
				inputDelay = 500; // Delay to prevent multiple clicks
			}
			else if (button.buttonName == "PARK: NIGHT" && inputDelay == 0) {
				std::cout << "Park night button clicked!" << std::endl;
				handleParkNightButtonClicked();
				inputDelay = 500; // Delay to prevent multiple clicks
			}
			else if (button.buttonName == "BRIDGE: DAY" && inputDelay == 0) {
				std::cout << "Bridge day button clicked!" << std::endl;
				handleBridgeDayButtonClicked();
				inputDelay = 500; // Delay to prevent multiple clicks
			}
			else if (button.buttonName == "BRIDGE: NIGHT" && inputDelay == 0) {
				std::cout << "Bridge night button clicked!" << std::endl;
				handleBridgeNightButtonClicked();
				inputDelay = 500; // Delay to prevent multiple clicks
			}

		}
	}
	if (inputDelay > 0) {
		inputDelay--;
	}
	// Update Button Positions
	int i = 0;
	for (auto& button : pauseMenuButtonArray) {
		button.buttonText.setPosition(player.getPosition().x - 50, player.getPosition().y + -275 + (i * 70));
		button.buttonHitbox.setPosition(button.buttonText.getPosition());
		i++;
	}



}

void LevelSelectorMenuClass::draw(sf::RenderWindow& window) {
	// Draw all item buttons
	for (const auto& s_Button : pauseMenuButtonArray) {
		window.draw(s_Button.buttonText);
	}

}

void LevelSelectorMenuClass::setupButton(sf::Text& button, const std::string& text, int charSize, sf::Color color, float x, float y) {
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

void LevelSelectorMenuClass::handleParkDayButtonClicked() {
	selectedLevel = 1; // Set the selected level to Park: Day
};

void LevelSelectorMenuClass::handleParkNightButtonClicked() {
	selectedLevel = 2; // Set the selected level to Park: Night
};

void LevelSelectorMenuClass::handleBridgeDayButtonClicked() {
	selectedLevel = 3; // Set the selected level to Bridge: Day
};

void LevelSelectorMenuClass::handleBridgeNightButtonClicked() {
	selectedLevel = 4; // Set the selected level to Bridge: Night
};

