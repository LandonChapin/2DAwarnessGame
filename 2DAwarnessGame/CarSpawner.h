#include "Car.h"

class CarSpawner : public EntityClass {
public:
		CarSpawner() {}; // Default constructor
		void draw(sf::RenderWindow& window) override;
		void update(float dt, sf::RenderWindow& window) override;

		// Constructor to initialize the car spawner with a position, and hitbox
		// Parameters: x, y - position, spawn rate - higher number is less frequent spawns, 
		CarSpawner(int x, int y, int spawnRate, PlayerClass* playerReference);

		EntityClass* player = nullptr; // Pointer to the player object  
		
private:

	void spawnCar(); // Spawns a new car
	void manageCars(float dt, sf::RenderWindow& window);

	std::vector<Car*> cars = {}; // Vector to hold the spawned cars
	sf::Texture texture; // Texture for the carSpawner
	sf::Sprite sprite; // Sprite for the carSpawner
	Hitbox hitbox; // Hitbox for the carSpawner

	int spawnRate; // Rate at which cars are spawned, lower number means more frequent spawns
	float spawnTimer = 0; // Timer to track when to spawn a new car

	std::vector<std::array<std::string, 4>> cartextures;
};


#pragma once
