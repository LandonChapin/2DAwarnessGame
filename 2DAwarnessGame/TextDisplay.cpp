#include "TextDisplay.h"

TextDisplayClass::TextDisplayClass() {
	if (!font.loadFromFile("Assets/Fonts/Seagram_tfb/Seagram tfb.ttf")) {
		std::cerr << "Failed to load font!" << std::endl;
	}
	
	// Initialize the text
	text.setFont(font);
	text.setCharacterSize(35);
	text.setFillColor(sf::Color::White);
}

void TextDisplayClass::draw(sf::RenderWindow& window) {
	// Draw the text on the window
	if (visible) {
		window.draw(text);
	};
	
}

void TextDisplayClass::update(float dt, sf::RenderWindow& window, int levelNum, int variable) {
	if (currentLevel != levelNum) {
		currentLevel = levelNum;
		initializeText(currentLevel, window);
	}
	else {
		switch (currentLevel) {
		case 4:
			this->variable = variable;
			if (visible) {

				time += dt * 1000;
				if (time >= 500000 || variable != 0) {
					visible = false; // Hide the text after 100 seconds
					time = 0; // Reset the time
					if (variable >= 10) {
						canMoveOn = true; // Allow the player to move on if variable is 10 or more
					}
				}
			}
			else if (!visible && variable >= 10) {
				initializeText(currentLevel, window); // Initialize the text again if it is not visible and variable is 10 or more
				visible = true; // Make the text visible again
			}

			break;

		case 5:
		{
			visible = true; // Ensure the text is visible for level 5
			break; // No specific logic for level 5, just display the text
			
		}
		default:
			visible = false; // Hide the text for other levels
			break;
		}
	};

};

void TextDisplayClass::initializeText(int levelNum, sf::RenderWindow& window) {
	if (!font.loadFromFile("Assets/Fonts/Seagram_tfb/Seagram tfb.ttf")) {
		std::cerr << "Failed to load font!" << std::endl;
	}

	// Initialize the text
	text.setFont(font);
	text.setCharacterSize(35);
	text.setFillColor(sf::Color::White);
	
	switch (levelNum) {
	case 4:
	{
		text.setString("TRY YOUR BEST TO FIND ALL THE FACTORS\n CAUSING POLUTION ON THIS BRIDGE");
		sf::View view = window.getView();
		sf::Vector2f viewCenter = view.getCenter();
		sf::Vector2f viewSize = view.getSize();
		sf::FloatRect textBounds = text.getLocalBounds();
		float textX = viewCenter.x - textBounds.width / 2.f;
		float textY = viewCenter.y - 200.f - textBounds.height / 2.f;
		text.setPosition(textX, textY);

		break;
	}
	case 5:
	{
		text.setString("Air pollution is contamination of the indoor\n or outdoor environment by any chemical, physical,\n or biological agent that modifies the natural characteristics of the atmosphere.\nWorld Health Organisation data show that almost the entire global population(99 %)\n breathes air that exceeds WHO guideline limits and contains high levels of pollutants,\n with low - and middle - income countries suffering the highest exposures.\nAir quality is closely linked to the Earth’s climate and ecosystems globally.\nWe must all work together to reduce air pollution to save the Earth and our future.\nWe only aimed to provide you with an idea and thus increase awareness of this issue through this game.\n\n\n* The data is collected from https ://www.who.int/health-topics/air-pollution#tab=tab_1");
		sf::View view = window.getView();
		sf::Vector2f viewCenter = view.getCenter();
		sf::Vector2f viewSize = view.getSize();
		sf::FloatRect textBounds = text.getLocalBounds();
		float textX = viewCenter.x - textBounds.width / 2.f;
		float textY = viewCenter.y - 100.f - textBounds.height / 2.f;
		text.setPosition(textX, textY);

		break;
	}
	default:
		text.setString("");
		break;
	}
}