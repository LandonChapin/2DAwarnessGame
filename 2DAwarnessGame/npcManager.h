#include <string>
#include "Entity.h"
#include "player.h"

class NpcManager {
public:
	NpcManager(PlayerClass* player);
	void npcUpdate(float dt, sf::RenderWindow& window, int levelNum);
	void npcDraw(sf::RenderWindow& window, int levelNum);

	void loadChest(int infoNum, bool open); // Load a chest with the given info number

private:
	std::vector <std::vector<EntityClass*>> npcs = {};
};


#pragma once
