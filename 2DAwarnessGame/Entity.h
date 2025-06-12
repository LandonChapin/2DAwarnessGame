//all include statements for Entity.cpp
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Hitbox.h"
#include <iostream>
#include <string>
#include "s_Item.h"


class EntityClass {
public:
	EntityClass(std::string texturePath, float speed);
	EntityClass() {};

	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void update(float dt,sf::RenderWindow& window) = 0;
	sf::Vector2f getPosition();
	sf::FloatRect getGlobalBounds();
	Hitbox& getHitbox();
	int getDirection() const { return direction; }
	void setPosition(sf::Vector2f newPosition) { sprite.setPosition(newPosition); };
	sf::Texture texture;
	sf::Sprite sprite;
	Hitbox hitbox;
protected:
	int direction = 1; // The direction the entity is facing
	
	float speed = 100.f;
	bool moved = false; // Flag to check if the player has moved this frame
	bool jumping = false; // Flag to check if the player is jumping
	bool falling = false; // Flag to check if the player is falling
	bool onGround = true; // Flag to check if the player is on the ground
	bool playerDead = false; //check if the player is dead
	int entityGravity = 0; // Number of frames the player has been jumping
	bool invincible = false;
	
};

