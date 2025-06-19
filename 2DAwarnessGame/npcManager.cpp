#include "npcManager.h"
#include "chest.h"

NpcManager::NpcManager(PlayerClass* player) {
	// Initialize the NPC manager

	npcs = {
		new Chest("","", 600, 670, 100.f, 100.f, 50, 50, player, 0),
		new Chest("","", 1200, 670, 100.f, 100.f, 50, 50, player, 1),
		new Chest("","", 1500, 670, 100.f, 100.f, 50, 50, player, 2),
		new Chest("","", 1800, 670, 100.f, 100.f, 50, 50, player, 3),
		new Chest("","", 2000, 670, 100.f, 100.f, 50, 50, player, 4),
	};
}

void NpcManager::npcUpdate(float dt, sf::RenderWindow& window) {
	for (auto& npc : npcs) {
		npc->update(dt, window);
	}
}

void NpcManager::npcDraw(sf::RenderWindow& window) {
	for (auto& npc : npcs) {
		npc->draw(window);
	}
}