#include "Entity.h"
#include "Interact.h"
#include "player.h"

class Chest : public EntityClass, public Interact {
public:
    Chest(std::string texturePath, int x, int y, float hitboxX, float hitboxY, int xTexture, int yTexture);
    Chest() {}; // Default constructor
    void draw(sf::RenderWindow& window) override;
    void update(float dt, sf::RenderWindow& window) override;
    Chest(std::string texturePath, int x, int y, float hitboxX, float hitboxY, int xTexture, int yTexture, PlayerClass* playerRef);

    EntityClass* player = nullptr; // Pointer to the player object  

    bool detectPlayer(EntityClass& player) override; // Move this to public to make it accessible  

    
private:
    sf::Texture texture;
    sf::Sprite sprite;
    Hitbox hitbox;
	bool isOpen = false; // State of the chest, whether it's open or closed
    bool isColliding = false; // State of collection
	sf::Font font; // Font for text rendering
	sf::Text text; // Text to display when player is near the chest

};
#pragma once
