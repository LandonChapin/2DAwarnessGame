#include "Entity.h"
#include "Interact.h"
#include "player.h"

class Chest : public EntityClass, public Interact {
public:
    Chest() {}; // Default constructor
    void draw(sf::RenderWindow& window) override;
    void update(float dt, sf::RenderWindow& window) override;
	// Constructor to initialize the chest with a texture, position, and hitbox
	// Parameters: texturePath for the closed chesr - path to the open chest texture, x, y - position, hitboxX, hitboxY - size of the hitbox, player reference, int reperesenting the info in the chest
    Chest(std::string texturePath, std::string texturePathOpen, int x, int y, float hitboxX, float hitboxY, int xTexture, int yTexture, PlayerClass* playerRef, int info);

    EntityClass* player = nullptr; // Pointer to the player object  

    bool detectPlayer(EntityClass& player) override; // Move this to public to make it accessible  
    
    
private:
    sf::Texture texture;
	sf::Texture textureOpen; // Texture for the open chest
    sf::Sprite sprite;
    Hitbox hitbox;
	bool isOpen = false; // State of the chest, whether it's open or closed
    bool isColliding = false; // State of collection
	sf::Font font; // Font for text rendering
	sf::Text text; // Text to display when player is near the chest

    int info; // Iformation in the chest

};
#pragma once
