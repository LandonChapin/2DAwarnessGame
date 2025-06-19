#include <SFML/Graphics.hpp>  
#include <vector>  
#include "Player.h"  
#include <iostream>
#include <string>
#include <fstream>

// Structure for Buttons
struct s_button {
	std::string buttonName;
	sf::Text buttonText;
	Hitbox buttonHitbox;
};

// Menu For Saving and Loading the game
class savingMenuClass {

public:
	savingMenuClass();
	~savingMenuClass();
	void draw(sf::RenderWindow window);
	void update();

};

class cluesMenuClass {
public:
	cluesMenuClass();
	~cluesMenuClass() = default;

	void drawCluesMenu(sf::RenderWindow& window);
	void updateCluesMenu(PlayerClass& player, sf::RenderWindow& window);

private:
	sf::Font font;
	sf::Text itemNameText;
	sf::Text itemDescriptionText;

	int inputDelay = 0;

	int currentItemIndex = 0;

	s_Item* selectedItem = nullptr;

	void setupButton(sf::Text& button, const std::string& text, int charSize, sf::Color color, float x, float y);
	void setupText(sf::Text& text, const std::string& str, int size, sf::Color color, float x, float y);
	void updateButtonHover(sf::Text& button, Hitbox& hitbox, const sf::Vector2f& mousePos);

	std::vector <s_button> pauseMenuButtonArray{
		s_button{std::string("NEXT"),sf::Text(), Hitbox()},
		s_button{std::string("BACK"),sf::Text(), Hitbox()},
	};

	void handleNextButtonClicked(PlayerClass& player) {
		if (currentItemIndex < player.getPlayerInventory().size() - 1) {
			currentItemIndex++;
			selectedItem = &player.getPlayerInventory()[currentItemIndex];
		}
	}
	void handleBackButtonClicked(PlayerClass& player) {
		if (currentItemIndex > 0) {
			currentItemIndex--;
			selectedItem = &player.getPlayerInventory()[currentItemIndex];
		}
	}
};


class PauseMenuClass {
public:
	PauseMenuClass();
	void draw(sf::RenderWindow& window);
	bool update(sf::RenderWindow& window, PlayerClass& player);
	void setCurrentMenu(int menuNum) { this->currentMenu = menuNum; };
	int checkSaving();
	void setSaving(bool saving) {
		this->saving = saving;
	}
	void setLoading(bool loading) {
		this->loading = loading;
	}

private:
	// Variables
	std::string fontString = "Assets/Fonts/Seagram_tfb/Seagram tfb.ttf";
	int currentMenu = 0; // 0 for main menu, 1 for settings, 2 for save/load, 3 for clues, 4 for , 5 for none, 6 for 
	sf::Font pauseMenuFont;
	sf::Text pauseMenuText;
	sf::Text settingsMenuText;
	sf::Text questMenuText;
	cluesMenuClass cluesMenu;

	// Background for Pause Menu
	std::string pauseMenuBackgroundString = "Assets/Backgrounds/AG_NotebookBackground.png";
	sf::Texture pauseMenuBackgroundTexture;
	sf::Sprite pauseMenuBackgroundSprite;

	bool saving = false;
	bool loading = false;
	// Array of Pause Menu Buttons
	std::vector <s_button> pauseMenuButtonArray{
		s_button{std::string("RESUME"),sf::Text(), Hitbox()},
		s_button{std::string("QUIT"),sf::Text(), Hitbox()},
		//s_button{std::string("SAVE"),sf::Text(), Hitbox()},
		//s_button{std::string("LOAD"),sf::Text(), Hitbox()},
		s_button{std::string("SETTINGS"),sf::Text(), Hitbox()}

	};
	// Array For side menu buttons
	std::vector <s_button> pauseMenuSideButtonArray{
		s_button{std::string("PAUSE"),sf::Text(), Hitbox()},
		s_button{std::string("CLUES"),sf::Text(), Hitbox()},
		//s_button{std::string("QUESTS"), sf::Text(), Hitbox()}
	};


	void setupButton(sf::Text& button, const std::string& text, int charSize, sf::Color color, float x, float y);
	void updateButtonHover(sf::Text& button, Hitbox& hitbox, const sf::Vector2f& mousePos);

	void handleResumeButtonClicked();
	void handleQuitButtonClicked(sf::RenderWindow& window);
	void handleSaveButtonClicked();
	void handleLoadButtonClicked();
	void handleSettingsButtonClicked();
	void handlePauseButtonClicked();
	void handleInventoryButtonClicked();
	void handleQuestButtonClicked();

	void updateButtonPositions(PlayerClass& player);

};

#pragma once
