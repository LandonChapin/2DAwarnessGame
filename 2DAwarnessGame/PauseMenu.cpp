#include "PauseMenu.h"

PauseMenuClass::PauseMenuClass() {
    // Load the font
    if (!pauseMenuFont.loadFromFile("Assets/Fonts/Seagram_tfb/Seagram tfb.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    }

    // Set up the buttons
    setupButton(pauseMenuText, "PAUSE MENU", 35, sf::Color::Black, 600, 100);
    setupButton(settingsMenuText, "", 35, sf::Color::Magenta, 600, 100);
    setupButton(questMenuText, "", 35, sf::Color::Black, 600, 100);
    float yOffset = 200;
    for (auto& button : pauseMenuButtonArray) {
        setupButton(button.buttonText, button.buttonName, 30, sf::Color::Black, 600, yOffset);
        button.buttonHitbox.setSize({ button.buttonText.getGlobalBounds().width, button.buttonText.getGlobalBounds().height });
        button.buttonHitbox.setPosition(button.buttonText.getPosition());
        button.buttonHitbox.setColor(sf::Color(0, 2, 0, 100));
        yOffset += 100;
    }
    yOffset = 200;
    for (auto& button : pauseMenuSideButtonArray) {
        setupButton(button.buttonText, button.buttonName, 30, sf::Color::Black, 200, yOffset);
        button.buttonHitbox.setSize({ button.buttonText.getGlobalBounds().width, button.buttonText.getGlobalBounds().height });
        button.buttonHitbox.setPosition(button.buttonText.getPosition());
        button.buttonHitbox.setColor(sf::Color(0, 2, 0, 100));
        yOffset += 100;
    }

    // Set up background
	pauseMenuBackgroundSprite.setTextureRect(sf::IntRect(0, 0, 160, 90));
    if (!pauseMenuBackgroundTexture.loadFromFile(pauseMenuBackgroundString)) {
        std::cerr << "Error loading pause menu background texture!" << std::endl;
    }
    pauseMenuBackgroundSprite.setTexture(pauseMenuBackgroundTexture);
	pauseMenuBackgroundSprite.setScale(10.0f, 10.0f); // Scale the background to fit the window
    
}

void PauseMenuClass::setupButton(sf::Text& button, const std::string& text, int charSize, sf::Color color, float x, float y) {
    button.setFont(pauseMenuFont);
    button.setString(text);
    button.setCharacterSize(charSize);
    button.setFillColor(color);

    // Adjust the origin to the center of the text
    sf::FloatRect textBounds = button.getLocalBounds();
    button.setOrigin(textBounds.left + textBounds.width / 2.0f,
        textBounds.top + textBounds.height / 2.0f);

    button.setPosition(x, y);
}

bool PauseMenuClass::update(sf::RenderWindow& window, PlayerClass& player) {
    // Check for mouse hover and clicks on buttons
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF = window.mapPixelToCoords(mousePos);

    // Update button positions
    updateButtonPositions(player);
    switch (currentMenu) {
    case 0:
    {

        for (auto& button : pauseMenuButtonArray) {
            updateButtonHover(button.buttonText, button.buttonHitbox, mousePosF);


            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && button.buttonHitbox.getBounds().contains(mousePosF)) {
                if (button.buttonName == "RESUME" && currentMenu != 5) {
                    std::cout << "Resume button clicked!" << std::endl;
                    handleResumeButtonClicked();
                }
                else if (button.buttonName == "QUIT") {
                    std::cout << "Quit button clicked!" << std::endl;
                    handleQuitButtonClicked(window);
                }
                else if (button.buttonName == "SAVE" && !saving) {
                    std::cout << "Save button clicked!" << std::endl;
                    handleSaveButtonClicked();
                }
                else if (button.buttonName == "LOAD" && !loading) {
                    std::cout << "Load button clicked!" << std::endl;
                    handleLoadButtonClicked();
                }
                else if (button.buttonName == "SETTINGS") {
                    std::cout << "Settings button clicked!" << std::endl;
                    handleSettingsButtonClicked();
                }
            }
        }
        break;
    }
    case 2: // Save Menu
    {
        saving = savingMenu.update(player, window, 1);
        break;
    }

    case 3: // Clues Menu
    {
        cluesMenu.updateCluesMenu(player, window);
        break;

    }
    case 4: // Load Menu
    { 
        loading = savingMenu.update(player, window, 2);
        break;

    }
    }


    for (auto& button : pauseMenuSideButtonArray) {
        updateButtonHover(button.buttonText, button.buttonHitbox, mousePosF);


        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && button.buttonHitbox.getBounds().contains(mousePosF)) {

            if (button.buttonName == "PAUSE" && currentMenu != 0) {
                std::cout << "Pause button clicked!" << std::endl;
                handlePauseButtonClicked();
            }
            else if (button.buttonName == "CLUES" && currentMenu != 3) {
                std::cout << "Inventory button clicked!" << std::endl;
                handleInventoryButtonClicked();
            }
            else if (button.buttonName == "QUESTS" && currentMenu != 6) {
                std::cout << "Quests button clicked!" << std::endl;
                handleQuestButtonClicked();
            }
        }
    }

    return currentMenu != 5;
}


void PauseMenuClass::updateButtonHover(sf::Text& button, Hitbox& hitbox, const sf::Vector2f& mousePos) {
    if (hitbox.getBounds().contains(mousePos)) {
        button.setFillColor(sf::Color::Yellow); // Highlight on hover
    }
    else {
        button.setFillColor(sf::Color::Black); // Default color
    }
}

void PauseMenuClass::draw(sf::RenderWindow& window) {


    switch (currentMenu) {

    case 0:
    {
        window.draw(pauseMenuBackgroundSprite);

        window.draw(pauseMenuText);
        for (auto& button : pauseMenuButtonArray) {
            window.draw(button.buttonText);
            //button.buttonHitbox.draw(window);
        }
        break;
    }
    case 1:
    {
        window.draw(pauseMenuBackgroundSprite);

        window.draw(settingsMenuText);
        break;
    }
    case 2:
    {
        savingMenu.draw(window);

        break;
    }

    case 3:
        window.draw(pauseMenuBackgroundSprite);

        cluesMenu.drawCluesMenu(window);
        break;

    case 4:
    {
        savingMenu.draw(window);

        break;
    }
    case 6:
        window.draw(questMenuText);
        break;
    }


    for (auto& button : pauseMenuSideButtonArray) {
        window.draw(button.buttonText);
        //button.buttonHitbox.draw(window);
    }

	

}

void PauseMenuClass::updateButtonPositions(PlayerClass& player) {
    // Get the player's position (assumed to be the center of the screen)
    sf::Vector2f playerPosition = player.getPosition();

    // Calculate the center of the screen based on the player's position
    float centerX = playerPosition.x;
    float centerY = playerPosition.y;

    switch (currentMenu) {
    case 0: {
        pauseMenuText.setPosition(centerX - pauseMenuText.getGlobalBounds().width / 2 + 150, centerY - pauseMenuText.getGlobalBounds().height / 2 - 350);
        float yOffset = -210;
        for (auto& button : pauseMenuButtonArray) {
            button.buttonText.setPosition(centerX - button.buttonText.getGlobalBounds().width / 2 + 650, centerY + yOffset);
            button.buttonHitbox.setPosition(button.buttonText.getPosition());
            yOffset += 65;
        }
    }
    case 1:
        settingsMenuText.setPosition(centerX - pauseMenuText.getGlobalBounds().width / 2 + 150, centerY - pauseMenuText.getGlobalBounds().height / 2 - 250);
        break;
    case 6:
        questMenuText.setPosition(centerX - pauseMenuText.getGlobalBounds().width / 2 + 150, centerY - pauseMenuText.getGlobalBounds().height / 2 - 250);
        break;
    }
    float yOffset = -200;
    for (auto& button : pauseMenuSideButtonArray) {
        button.buttonText.setPosition(centerX - button.buttonText.getGlobalBounds().width / 2 + -500, centerY + yOffset);
        button.buttonHitbox.setPosition(button.buttonText.getPosition());
        yOffset += 100;
    }

	pauseMenuBackgroundSprite.setPosition(centerX - pauseMenuBackgroundSprite.getGlobalBounds().width / 2, centerY - pauseMenuBackgroundSprite.getGlobalBounds().height / 2);
}


void PauseMenuClass::handleResumeButtonClicked() {
    currentMenu = 5;
    std::cout << "Resuming\n";
};
void PauseMenuClass::handleQuitButtonClicked(sf::RenderWindow& window) {
    window.close();
};
void PauseMenuClass::handleSaveButtonClicked() {
    currentMenu = 2;
};
void PauseMenuClass::handleLoadButtonClicked() {
    currentMenu = 4;
};
void PauseMenuClass::handleSettingsButtonClicked() {
    // Opening Settings
    currentMenu = 1;
};
void PauseMenuClass::handlePauseButtonClicked() {
    // Opening Pause Menu
    currentMenu = 0;
};
void PauseMenuClass::handleInventoryButtonClicked() {
    // Opening Inventory Menu
    currentMenu = 3;
};
void PauseMenuClass::handleQuestButtonClicked() {
    // Opening Quest Menu
    currentMenu = 6;
}

// Finction to get current saving of pause menu, 0 = Niether, 1 = Saving, 2 = Loading
int PauseMenuClass::checkSaving() {
    if (saving) {
        return 1;
    }
    else if (loading) {
        return 2;
    }
    else {
        return 0;
    }
};

// Function to reset save menu
void PauseMenuClass::finishSave() {
    currentMenu = 0;
    savingMenu.resetSaveMenu();
}
