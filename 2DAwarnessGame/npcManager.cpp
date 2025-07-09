#include "npcManager.h"
#include "chest.h"
#include "questionChest.h"

NpcManager::NpcManager(PlayerClass* player) {
	// Initialize the NPC manager
	npcs = {

		// Level 1 NPCs
		{new Chest("","", 600, 665, 150.f, 150.f, 50, 50, player, 0),
		new Chest("Assets/NPCs/Chests/AG_Trash1.png","Assets/NPCs/Chests/AG_Trash2.png", 3200, 665, 150.f, 150.f, 50, 50, player, 1),
		new Chest("","", 1500, 665, 150.f, 150.f, 50, 50, player, 2),
		new Chest("Assets/NPCs/Chests/AG_Kid1.png","Assets/NPCs/Chests/AG_Kid2.png", 2800, 680, 150.f, 150.f, 50, 50, player, 3),
		new Chest("","", 2000, 665, 150.f, 150.f, 50, 50, player, 4),
		},

		// Level 2 NPCs
		{new QuestionChest("Assets/NPCs/Chests/Chest1.png", "Assets/NPCs/Chests/Chest2.png", 600, 665, 150.f, 150.f, 50, 50, player, 0, 5),
		new QuestionChest("Assets/NPCs/Chests/Chest1.png", "Assets/NPCs/Chests/Chest2.png", 2200, 665, 150.f, 150.f, 50, 50, player, 1, 6),
		new QuestionChest("Assets/NPCs/Chests/Chest1.png", "Assets/NPCs/Chests/Chest2.png", 3200, 665, 150.f, 150.f, 50, 50, player, 2, 7),
		},

		// Level 3 NPCs
		{
			new Chest("", "", 600, 665, 150.f, 150.f, 50, 50, player, 8),
		},
		
	};
};

void NpcManager::npcUpdate(float dt, sf::RenderWindow& window, int levelNum) {
	for (auto& npc : npcs[levelNum - 1]) {
		npc->update(dt, window);
	}
};

void NpcManager::npcDraw(sf::RenderWindow& window, int levelNum) {
	for (auto& npc : npcs[levelNum - 1]) {
		npc->draw(window);
	}
};

// Make Chest npcs load
void NpcManager::loadChest(int infoNum,bool open) {
	for (auto& npc : npcs[0]) {
		Chest* chestCast = dynamic_cast<Chest*>(npc);
		if (chestCast && chestCast->getInfo() == infoNum) {
			chestCast -> setOpen(open);
			break;
		}
		else {
			std::cerr << "Error: npc is not of type Chest!" << std::endl;
		}
	}
};

