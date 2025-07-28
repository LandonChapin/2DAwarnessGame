#include <SFML/Graphics.hpp>  
#include <vector>  
#include "Player.h"
#include <iostream>
#include <string>
#include <fstream>
#include "s_Button.h"

class MainMenuClass {
public:
	MainMenuClass();
	void initialize(); // Initialize the main menu
	void draw(sf::RenderWindow& window);
	int update(sf::RenderWindow& window);

	int getSaveSlot() const { return saveSlot; } // Getter for the save slot
	std::string getPlayerNameInput() const { return playerNameInput; }

private:
	std::string fontString = "Assets/Fonts/Seagram_tfb/Seagram tfb.ttf"; // Path to the font file
	sf::Font mainMenuFont; // Font for the main menu

	std::vector<s_button> mainMenuButtonArray{
		s_button{std::string("NEW GAME"), sf::Text(), Hitbox()},
		s_button{std::string("LOAD GAME"), sf::Text(), Hitbox()},
		//s_button{std::string("SETTINGS"), sf::Text(), Hitbox()},
		s_button{std::string("QUIT"), sf::Text(), Hitbox()}
	};

	std::vector<s_button> loadMenuButtonArray{
		s_button{std::string("LOAD SLOT 1"), sf::Text(), Hitbox()},
		s_button{std::string("LOAD SLOT 2"), sf::Text(), Hitbox()},
		s_button{std::string("LOAD SLOT 3"), sf::Text(), Hitbox()},
	};

	std::vector<s_button> namingMenuButtonArray{
		s_button{std::string("ENTER"), sf::Text(), Hitbox()},
	};
	
    // Add a text box for player input
        sf::RectangleShape nameInputBox; // Visual box for text input
        sf::Text nameInputText;          // Text entered by the player
        std::string playerNameInput = "";     // Stores the actual input string
        bool isNameInputActive = false;  // Is the text box currently active for typing?
        void handleTextInput(sf::RenderWindow& window);

	int inputDelay = 0; // Delay for input

	int menuNumber = 0; // Variable to track the current menu number
	int interMenuNumber = 0; // Variable

	void setupButton(sf::Text& button, const std::string& text, int charSize, sf::Color color, float x, float y);
	void updateButtonHover(sf::Text& button, Hitbox& hitbox, const sf::Vector2f& mousePos);

	void handleNewGameButtonClicked();
	void handleLoadGameButtonClicked();
	void handleSettingsButtonClicked();
	void handleQuitButtonClicked(sf::RenderWindow& window);
	
	void handleLoad1ButtonClicked();
	void handleLoad2ButtonClicked();
	void handleLoad3ButtonClicked();

	void updateButtonPositions();

	int saveSlot = 0; // Variable to track the save slot

	bool isSaving = false;

	sf::Sprite background; // Background sprite for the main menu
	sf::Texture backgroundTexture; // Texture for the background sprite


};

#pragma once
