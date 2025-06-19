#include <string>
#include "Entity.h"
#include "player.h"

class NpcManager {
public:
	NpcManager(PlayerClass* player);
	void npcUpdate(float dt, sf::RenderWindow& window);
	void npcDraw(sf::RenderWindow& window);
private:
	std::vector<EntityClass*> npcs = {};
};


#pragma once
