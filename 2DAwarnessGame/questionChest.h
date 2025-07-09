#include "Entity.h"
#include "player.h"
#include "Interact.h"
#include "questionMenu.h"

class QuestionChest : public EntityClass, public Interact {
public:
	QuestionChest() {}; // Default constructor
	void draw(sf::RenderWindow& window) override;
	void update(float dt, sf::RenderWindow& window) override;

	// Constructor to initialize the chest with a texture, position, and hitbox
	// Parameters: texturePath for the closed chesr - path to the open chest texture, x, y - position, hitboxX, hitboxY - size of the hitbox, player reference, int reperesenting the info in the chest, int repersenting where the info is located in the player inventory
	QuestionChest(std::string texturePath, std::string texturePathOpen, int x, int y, float hitboxX, float hitboxY, int xTexture, int yTexture, PlayerClass* playerRef, int info, int pInfo);

	EntityClass* player = nullptr; // Pointer to the player object  

	bool detectPlayer(EntityClass& player) override; // Move this to public to make it accessible  

	//int getInfo() const { return info; } // Getter for the info in the chest
	void setOpen(bool open) { isOpen = open; } // Setter for the chest state

private:
	sf::Texture texture;
	sf::Texture textureOpen; // Texture for the open chest
	sf::Sprite sprite;
	Hitbox hitbox;
	bool isOpen = false; // State of the chest, whether it's open or closed
	bool isColliding = false; // State of collection
	sf::Font font; // Font for text rendering
	sf::Text text; // Text to display when player is near the chest

	int info; // Information in the chest
	int pInfo; // Player info, used to check if the player has already interacted with this chest

	QuestionMenu questionMenu; // Question menu to display when the chest is opened

};


#pragma once
