#include "PauseMenu.h"

savingClass::savingClass() {
    // Constructor implementation
}

savingClass::~savingClass() {
    // Destructor implementation
}

void savingClass::saveGame(int saveFileNum, int mapNumber, PlayerClass& player) {
    std::ofstream saveFile(saveFilePaths[saveFileNum]);
    if (saveFile.is_open()) {
        // Save map number
        saveFile << "MapNumber: " << mapNumber << std::endl;

        // Save player position from hitbox
        sf::Vector2f position = player.getPosition(); // Assuming getPosition() exists
        saveFile << "PlayerX: " << position.x << std::endl;
        saveFile << "PlayerY: " << position.y << std::endl;

        // Save inventory
        const auto& inventory = player.getPlayerInventory();
        saveFile << "InventorySize: " << inventory.size() << std::endl;

        for (const auto& item : inventory) {
            saveFile << "ItemQuestion: " << item.Question << std::endl;
            saveFile << "ItemDescription: " << item.Decription << std::endl;
            saveFile << "ItemCollected: " << (item.isCollected ? "true" : "false") << std::endl;
        }

        // Save any additional data
        for (const auto& data : saveData) {
            saveFile << data << std::endl;
        }

        saveFile.close();
        std::cout << "Game saved successfully!" << std::endl;
    }
    else {
        std::cerr << "Error opening save file for writing." << std::endl;
    }
}

void savingClass::loadGame(int saveFileNum, int& mapNumber, PlayerClass& player, NpcManager& npcManager) {
    std::ifstream loadFile(saveFilePaths[saveFileNum]);
    if (loadFile.is_open()) {
        std::string line;
        loadData.clear(); // Clear previous data

        sf::Vector2f position;
        std::vector<s_Item> loadedInventory;
        int inventorySize = 0;

        while (std::getline(loadFile, line)) {
            loadData.push_back(line); // Optional: keep for debugging or other use

            if (line.find("MapNumber: ") == 0) {
                mapNumber = std::stoi(line.substr(11));
            }
            else if (line.find("PlayerX: ") == 0) {
                position.x = std::stof(line.substr(9));
            }
            else if (line.find("PlayerY: ") == 0) {
                position.y = std::stof(line.substr(9));
            }
            else if (line.find("InventorySize: ") == 0) {
                inventorySize = std::stoi(line.substr(15));
            }
            else if (line.find("ItemQuestion: ") == 0) {
                s_Item item;
                item.Question = line.substr(14);

                std::getline(loadFile, line);
                item.Decription = line.substr(17);

                std::getline(loadFile, line);
                item.isCollected = (line.substr(15) == "true");

                loadedInventory.push_back(item);
            }
        }

        // Set player position
        player.setPosition(position);

        // Set player inventory
        player.playerInventory = loadedInventory;

        for (int i = 0; i < inventorySize; ++i) {
            if (i < loadedInventory.size()) {
                if (player.playerInventory[i].isCollected) {
                    npcManager.loadChest(i, true);
                }
                else {
					npcManager.loadChest(i, false);
                }
            }
		}

        loadFile.close();
        std::cout << "Game loaded successfully!" << std::endl;
    }
    else {
        std::cerr << "Error opening save file for reading." << std::endl;
    }
}
