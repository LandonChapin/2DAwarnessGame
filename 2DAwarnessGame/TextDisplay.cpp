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
		case 0:
			time += dt * 1000;
			if (time >= 3000000) {
				visible = false; // Hide the text
				canMoveOn = true; // Allow the player to move on
				time = 0; // Reset the time
			}
			else {
				visible = true; // Ensure the text is visible for level 0
			}

			break;

		case 1:
			time += dt * 1000;
			if (this->variable != variable) {
				this->variable = variable; // Update the variable if it has changed
				initializeText(currentLevel, window); // Reinitialize the text if the variable has changed
			}
			if (time >= 1000000) {
				this->variable = variable;
				visible = false; // Ensure the text is visible for level 1
				canMoveOn = true; // Reset the canMoveOn flag for level 1
			}
			else {
				visible = true; 
				canMoveOn = false; // Allow the player to move on
				
			}
			break;
		case 2:
			time += dt * 1000;
			if (time >= 1000000) {
				this->variable = variable;
				visible = false; // Ensure the text is visible for level 1
				canMoveOn = true; // Reset the canMoveOn flag for level 1
			}
			else {
				visible = true;
				canMoveOn = false; // Allow the player to move on

			}

			break;
		case 3:
			time += dt * 1000;
			if (time >= 1000000) {
				this->variable = variable;
				visible = false; // Ensure the text is visible for level 1
				canMoveOn = true; // Reset the canMoveOn flag for level 1
			}
			else {
				visible = true;
				canMoveOn = false; // Allow the player to move on

			}

			break;
		case 4:
			this->variable = variable;
			if (visible) {

				time += dt * 1000;
				if (time >= 1000000 || variable != 0) {
					visible = false; // Hide the text after 100 seconds
					time = 0; // Reset the time
					if (variable >= 10) {
						canMoveOn = true; // Allow the player to move on if variable is 10 or more
						time = 0; // Reset the time
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
			time += dt * 1000;
			if (time >= 500000 && !canMoveOn) {
				canMoveOn = true;
				initializeText(currentLevel, window); // Reinitialize the text to display the level 5 information
				time = 0; // Reset the time
			}
			else if (canMoveOn) {

			}
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
	case 0:
	{
		text.setString("Welcome to Air, We Breathe\nWe are going to spend a few minutes of our lives playing this game,\n and through that, we want to rediscover and\n become aware of one of the significant issues of modern life : air pollution.\nWe hope to remember what we observed during the game and apply the best practices in the future.");
		sf::View view = window.getView();
		sf::Vector2f viewCenter = view.getCenter();
		sf::Vector2f viewSize = view.getSize();
		sf::FloatRect textBounds = text.getLocalBounds();
		float textX = viewCenter.x - textBounds.width / 2.f;
		float textY = viewCenter.y - 100.f - textBounds.height / 2.f;
		text.setPosition(textX, textY);
		
		break;
		}
	case 1:
		{
		canMoveOn = false; // Reset the canMoveOn flag for level 1
		time = 0; // Reset the time for level 1
		visible = true; // Ensure the text is visible for level 1
		if (variable == 0) {
			text.setString("Level 01: Information Gathering\n\nIn this episode, we will walk around a park and gather clues.\nThe clues are scattered along the walkway, hidden within clickable objects.\nThe clues become visible when we inspect the object hiding the clues.\nWe have a notebook / cluebook that will automatically store the clues as they are discovered.\nThese clues may help us in the next level.");
		}
		else if (variable == 1) {
			text.setString("Thanks for collecting all the clues. You are ready for the next level.");
		}
		
		sf::View view = window.getView();
		sf::Vector2f viewCenter = view.getCenter();
		sf::Vector2f viewSize = view.getSize();
		sf::FloatRect textBounds = text.getLocalBounds();
		float textX = viewCenter.x - textBounds.width / 2.f;
		float textY = viewCenter.y - 100.f - textBounds.height / 2.f;
		text.setPosition(textX, textY);
		
		break;
	}
	case 2:
	{
		canMoveOn = false; // Reset the canMoveOn flag for level 2
		time = 0; // Reset the time for level 2
		visible = true; // Ensure the text is visible for level 2
		text.setString("Level 02: Park, Night:\nIn this episode, we will walk around a park and\n answer some questions using the knowledge\n we gathered from the previous level.");
		sf::View view = window.getView();
		sf::Vector2f viewCenter = view.getCenter();
		sf::Vector2f viewSize = view.getSize();
		sf::FloatRect textBounds = text.getLocalBounds();
		float textX = viewCenter.x - textBounds.width / 2.f;
		float textY = viewCenter.y - 100.f - textBounds.height / 2.f;
		text.setPosition(textX, textY);
		break;
	}
	case 3:
	{
		canMoveOn = false; // Reset the canMoveOn flag for level 3
		time = 0; // Reset the time for level 3
		visible = true; // Ensure the text is visible for level 3
		text.setString("Level 03: Bridge Day:\nIn this episode, we will walk by a bridge,\n gather clues, and observe the surrounding causes of air pollution.\nWe have a notebook / cluebook that will automatically store the clues as they\n are discovered.These clues may help us in the next level.");
		sf::View view = window.getView();
		sf::Vector2f viewCenter = view.getCenter();
		sf::Vector2f viewSize = view.getSize();
		sf::FloatRect textBounds = text.getLocalBounds();
		float textX = viewCenter.x - textBounds.width / 2.f;
		float textY = viewCenter.y - 100.f - textBounds.height / 2.f;
		text.setPosition(textX, textY);
		break;
	}
	case 4:
	{
		variable = 0; // Reset the variable for level 4
		time = 0; // Reset the time for level 4
		canMoveOn = false; // Reset the canMoveOn flag for level 4
		visible = true; // Ensure the text is visible for level 4
		text.setString("Level 04: Bridge, Night:\nIn this episode, we will walk around a bridge and\n inspect passing cars,\n and identify the ones releasing harmful gas into the air.");
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
		if (time == 0) {
		text.setString("Thank you for playing");
		sf::View view = window.getView();
		sf::Vector2f viewCenter = view.getCenter();
		sf::Vector2f viewSize = view.getSize();
		sf::FloatRect textBounds = text.getLocalBounds();
		float textX = viewCenter.x - textBounds.width / 2.f;
		float textY = viewCenter.y - 100.f - textBounds.height / 2.f;
		text.setPosition(textX, textY);
		canMoveOn = false;
		}
		else if (canMoveOn){
			text.setString("Air pollution is contamination of the indoor\n or outdoor environment by any chemical, physical,\n or biological agent that modifies the natural characteristics of the atmosphere.\nWorld Health Organisation data show that almost the entire global population(99 %)\n breathes air that exceeds WHO guideline limits and contains high levels of pollutants,\n with low - and middle - income countries suffering the highest exposures.\nAir quality is closely linked to the Earth’s climate and ecosystems globally.\nWe must all work together to reduce air pollution to save the Earth and our future.\nWe only aimed to provide you with an idea and thus increase awareness of this issue through this game.\n\n\n* The data is collected from https ://www.who.int/HEALTH-TOPICS/AIR-POLLUTION");
			sf::View view = window.getView();
			sf::Vector2f viewCenter = view.getCenter();
			sf::Vector2f viewSize = view.getSize();
			sf::FloatRect textBounds = text.getLocalBounds();
			float textX = viewCenter.x - textBounds.width / 2.f;
			float textY = viewCenter.y - 100.f - textBounds.height / 2.f;
			text.setPosition(textX, textY);
			canMoveOn = false;
		}

		break;
	}
	default:
		text.setString("");
		break;
	}
};