#include <SFML/Graphics.hpp>  
#include <vector>  
#include "Player.h"  
#include "npcManager.h"
#include <iostream>
#include <string>
#include <fstream>
#include "s_Button.h"



// Menu For Saving and Loading the game
class savingMenuClass {

public:
	savingMenuClass();
	
	void draw(sf::RenderWindow& window);
	bool update(PlayerClass& player, sf::RenderWindow& window, int i);
	void resetSaveMenu();

	int getSaveSlot() const { return saveSlot; }

private:
	sf::Font font;
	sf::Text saveText;
	sf::Text loadText;

	int saveSlot = 1;

	int saving = 0; // 1 for saving, 2 for loading

	int inputDelay = 0;

	void setupButton(sf::Text& button, const std::string& text, int charSize, sf::Color color, float x, float y);
	void setupText(sf::Text& text, const std::string& str, int size, sf::Color color, float x, float y);
	void updateButtonHover(sf::Text& button, Hitbox& hitbox, const sf::Vector2f& mousePos);

	std::vector <s_button> savingMenuButtonArray{
		s_button{std::string("SAVE SLOT 1"),sf::Text(), Hitbox()},
		s_button{std::string("SAVE SLOT 2"),sf::Text(), Hitbox()},
		s_button{std::string("SAVE SLOT 3"),sf::Text(), Hitbox()}
	};

	std::vector <s_button> loadingMenuButtonArray{
		s_button{std::string("LOAD SLOT 1"),sf::Text(), Hitbox()},
		s_button{std::string("LOAD SLOT 2"),sf::Text(), Hitbox()},
		s_button{std::string("LOAD SLOT 3"),sf::Text(), Hitbox()}
	};

	void handleSaveSlot1Clicked();
	void handleSaveSlot2Clicked();
	void handleSaveSlot3Clicked();
	void handleLoadSlot1Clicked();
	void handleLoadSlot2Clicked();
	void handleLoadSlot3Clicked();

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

	void handleNextButtonClicked(PlayerClass& player);
	void handleBackButtonClicked(PlayerClass& player);
};

class LevelSelectorMenuClass {
public:
	LevelSelectorMenuClass();

	void draw(sf::RenderWindow& window);
	void update(sf::RenderWindow& window, PlayerClass& player);

	void resetLevelSelectorMenu() { selectedLevel = 0; };
	int getSelectedLevel() const { return selectedLevel; };
	
private:
	sf::Font font;

	int inputDelay = 0;

	int selectedLevel = 0; // Index of the currently selected level

	void setupButton(sf::Text& button, const std::string& text, int charSize, sf::Color color, float x, float y);
	void setupText(sf::Text& text, const std::string& str, int size, sf::Color color, float x, float y);
	void updateButtonHover(sf::Text& button, Hitbox& hitbox, const sf::Vector2f& mousePos);

	std::vector <s_button> pauseMenuButtonArray{
		s_button{std::string("PARK: DAY"),sf::Text(), Hitbox()},
		s_button{std::string("PARK: NIGHT"),sf::Text(), Hitbox()},
		s_button{std::string("BRIDGE: DAY"),sf::Text(), Hitbox()},
		s_button{std::string("BRIDGE: NIGHT"),sf::Text(), Hitbox()},
	};

	void handleParkDayButtonClicked();
	void handleParkNightButtonClicked();
	void handleBridgeDayButtonClicked();
	void handleBridgeNightButtonClicked();

};

class PauseMenuClass {
public:
	PauseMenuClass();
	void draw(sf::RenderWindow& window);
	bool update(sf::RenderWindow& window, PlayerClass& player);
	void setCurrentMenu(int menuNum) { this->currentMenu = menuNum; };
	int getCurrentMenu() const { return currentMenu; };
	int checkSaving();
	void setSaving(bool saving) {
		this->saving = saving;
	}
	void setLoading(bool loading) {
		this->loading = loading;
	}

	int getSaveSlot() const { return savingMenu.getSaveSlot(); };
	void finishSave();

	int getLevelSelectorLevel();


private:
	// Variables
	std::string fontString = "Assets/Fonts/Seagram_tfb/Seagram tfb.ttf";
	int currentMenu = 0; // 0 for main menu, 1 for settings, 2 for save, 3 for inventory, 4 for load, 5 for none, 6 for level selector
	sf::Font pauseMenuFont;
	sf::Text pauseMenuText;
	sf::Text settingsMenuText;
	sf::Text questMenuText;

	// Different Menus
	cluesMenuClass cluesMenu;
	savingMenuClass savingMenu;
	LevelSelectorMenuClass levelSelectorMenu;

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
		s_button{std::string("SAVE"),sf::Text(), Hitbox()},
		s_button{std::string("LOAD"),sf::Text(), Hitbox()},
		s_button{std::string("SETTINGS"),sf::Text(), Hitbox()}

	};
	// Array For side menu buttons
	std::vector <s_button> pauseMenuSideButtonArray{
		s_button{std::string("PAUSE"),sf::Text(), Hitbox()},
		s_button{std::string("CLUES"),sf::Text(), Hitbox()},
		s_button{std::string("LEVEL"), sf::Text(), Hitbox()}
	};

	int inputDelay = 0; // Delay for input

	void setupButton(sf::Text& button, const std::string& text, int charSize, sf::Color color, float x, float y);
	void updateButtonHover(sf::Text& button, Hitbox& hitbox, const sf::Vector2f& mousePos);

	void handleResumeButtonClicked();
	void handleQuitButtonClicked(sf::RenderWindow& window);
	void handleSaveButtonClicked();
	void handleLoadButtonClicked();
	void handleSettingsButtonClicked();
	void handlePauseButtonClicked();
	void handleInventoryButtonClicked();
	void handleLevelButtonClicked();

	void updateButtonPositions(PlayerClass& player);

};

class savingClass {


public:
	savingClass();
	~savingClass();
	void saveGame(int salveFileNum, int mapNumber, PlayerClass& player);
	void loadGame(int saveFileNum, int& mapnumber, PlayerClass& player, NpcManager& npcManager);
private:
	// File paths for saving and loading
	std::vector<std::string> saveFilePaths = {
		"SaveFiles/SaveFile1.txt",
		"SaveFiles/SaveFile2.txt",
		"SaveFiles/SaveFile3.txt"
	};
	std::vector<std::string> saveData;
	std::vector<std::string> loadData;
};


#pragma once
