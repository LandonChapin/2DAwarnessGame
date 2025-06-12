#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Hitbox.h"
#include <iostream>
#include <string>
#include "s_Item.h"
#include "Entity.h"

class Interact {
public:
	Interact(Hitbox& hitbox);
	Interact() {};

	virtual bool detectPlayer(EntityClass& player) = 0;

protected:
	Hitbox& getHitboxInteract() { return hitboxInteract.getHitbox(); };
	sf::FloatRect getBounds(EntityClass& player) {
		return player.getHitbox().getBounds();  // Access the hitbox directly
	}
	Hitbox hitboxInteract;
	bool playerDetected = false;
};