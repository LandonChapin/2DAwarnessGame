#include <iostream>
#include <SFML/Graphics.hpp>

class TextDisplayClass {
public:
	TextDisplayClass();

	void draw(sf::RenderWindow& window);

	// method that updates the text display each frame
	// Parameters: dt - delta time, window - the render window, levelNum - the current level number, variable - a variable that can be used to change the text displayed, varies depending on the level that the text is in
	void update(float dt, sf::RenderWindow& window, int levelNum, int variable);

	bool canMoveOnToNextLevel() const { return canMoveOn; } // Getter for the canMoveOn flag

	void initializeText(int levelNum, sf::RenderWindow& window);
private:
	

	sf::Font font; // Font for the text
	sf::Text text; // Text to display
	std::string textContent; // Content of the text to display

	int currentLevel = 0; // Current level number
	int variable = 0; // Variable to change the text displayed
	
	float time = 0; //Tracks the time since the last frame update

	bool visible = true;

	bool canMoveOn = false; // Flag to check if the player can move on to the next level

};


#pragma once
