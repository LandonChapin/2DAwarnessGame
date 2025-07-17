#include "CarSpawner.h"

CarSpawner::CarSpawner(int x, int y, int spawnRate, PlayerClass* playerReference) 
	: EntityClass("Assets/NPCs/Cars/AG_Car_1_1.png", 1.f), hitbox(sf::Vector2f(0, 0), sf::Color::White) {

	sprite.setPosition(x, y);
	hitbox.setPosition(sprite.getPosition());

	this->spawnRate = spawnRate;

	player = playerReference; // Initialize the player reference
	
	// Initialize the car textures
	cartextures = {
		{{
		"Assets/NPCs/Cars/AG_Car_1_1.png",
		"Assets/NPCs/Cars/AG_Car_1_2.png",
		"Assets/NPCs/Cars/AG_Car_1_3.png",
		"Assets/NPCs/Cars/AG_Car_1_N.png"
		}},
		{{
		"Assets/NPCs/Cars/AG_Car_2_1.png",
		"Assets/NPCs/Cars/AG_Car_2_2.png",
		"Assets/NPCs/Cars/AG_Car_2_3.png",
		"Assets/NPCs/Cars/AG_Car_2_N.png"
		}},
		{{
		"Assets/NPCs/Cars/AG_Car_3_1.png",
		"Assets/NPCs/Cars/AG_Car_3_2.png",
		"Assets/NPCs/Cars/AG_Car_3_3.png",
		"Assets/NPCs/Cars/AG_Car_3_N.png"
		}}
	};

	spawnCar(); // Spawn the first car immediately
	spawnCar(); // Spawn a second car immediately
}

void CarSpawner::update(float dt, sf::RenderWindow& window) {
	// Update the hitbox position to match the sprite position
	hitbox.setPosition(sprite.getPosition());
	
	for (auto car : cars) {
		car->update(dt, window);
	}

	manageCars(dt, window);
}

void CarSpawner::draw(sf::RenderWindow& window) {
	// Draw the hitbox
	//hitbox.draw(window);
	
	for (auto car : cars) {
		car->draw(window);
	}
}

void CarSpawner::manageCars(float dt, sf::RenderWindow& window) {
	// Spawn new cars based on the spawn rate
	if (spawnTimer >= spawnRate) {
		spawnCar();
		spawnTimer = 0; // Reset the timer after spawning
	} else {
		spawnTimer += dt; // Increment the timer
	}
	// Remove cars that are out of bounds
	for (auto i = cars.begin(); i != cars.end(); ) {
		if ((*i)->getPosition().x < -100) {
			delete *i;
			i = cars.erase(i); // Removes the correct car and returns the next iterator
		}
		else {
			++i;
		}
	}
}

void CarSpawner::spawnCar() {
	// Create a new car with a random position and add it to the vector
	int x = rand() % 5000 + 4000; // Random x position within a range
	int y = 590;
	int type = rand() % 3; // Random type between 0 and 2
	int poluting = rand() % 2; // Randomly decide if the car is polluting or not
	float speed = static_cast<float>(rand() % 5 + 1); // Random speed between 5 and 5 (should be fixed if you want a range)
	Car* newCar = new Car(x, y, 700.f, 300.f, static_cast<PlayerClass*>(player), 0, poluting, speed);
	newCar->setCarTextures(cartextures[type ]);
	cars.push_back(newCar);
	std::cout << "Car spawned at position: " << x << ", " << y << " with speed: " << speed << std::endl;
}