#include <SFML/Graphics.hpp>
#include "s_Button.h"
#include <iostream>
#include "Entity.h"

struct s_Conversation {
	std::string statment1; // First statment from the NPC
	std::string statment2; // Statment from player, input "n" for the answer to be ignored
	std::string statment3; // Statment from player, input "n" for the answer to be ignored
	std::string statment4; // Statment from player, input "n" for the answer to be ignored
	std::string statment5; // Answer to statment 2, input "n" for the answer to be ignored
	std::string statment6; // Answer to statment 3, input "n" for the answer to be ignored
	std::string statment7; // Answer to statment 4, input "n" for the answer to be ignored
	std::string statment8; // Closing Statment from player, input "n" for the answer to be ignored
	std::string statment9; // Closing Statment from MPC, input "n" for the answer to be ignored
	

};



class ConversationMenu {
public:
	ConversationMenu() {};
	void draw(sf::RenderWindow& window);
	int update(sf::RenderWindow& window, sf::Vector2f owner);
	void initializeMenu(int questionNumber, sf::Vector2f owner); // Move this method to public access
	void setActive(bool active) { isActive = active; } // Method to set the active state of the question menu
	bool getActive() const { return isActive; } // Method to get the active state of the question menu

private:
	sf::Font font; // Font for the question menu
	sf::Text questionText; // Text to display the question

	// Vector of buttons for the answers
	std::vector<s_button> answerButtons{
		s_button{std::string("Answer 1"), sf::Text(), Hitbox()},
		s_button{std::string("Answer 2"), sf::Text(), Hitbox()},
		s_button{std::string("Answer 3"), sf::Text(), Hitbox()},
		s_button{std::string("Answer 4"), sf::Text(), Hitbox()}
	};

	bool isActive = false; // State of the question menu, whether it's active or not
	int currentQuestionIndex = 0; // Index of the current question being displayed

	void setupButton(sf::Text& button, const std::string& text, int charSize, sf::Color color, float x, float y);
	void updateButtonHover(sf::Text& button, Hitbox& hitbox, const sf::Vector2f& mousePos);
	void updateButtonPositions(sf::Vector2f owner);

	int handleAnswer1ButtonClicked();
	int handleAnswer2ButtonClicked();
	int handleAnswer3ButtonClicked();
	int handleAnswer4ButtonClicked();

	std::vector <s_Conversation> conversationArray = {
	s_Conversation{	
				// First statement from the NPC
				std::string("I used to visit Dreamland Park (now located here) in my childhood.\n After many years, I decided to stop by this park again.\n But today, while I was walking in the park for around 30 minutes,\n I started coughing; my eyes and throat were irritated,\n and I felt shortness of breath.\n I wonder why."),
				// Responses by player
				std::string("It's nothing, just my delusion"),
				std::string("The air is polluted"),
				std::string("n"),
				// Response by NPC for each player input
				std::string("n"),
				std::string("n"),
				std::string("n"),
				// Closing statment player
				std::string("n"),
				// Closing statment NPC
				std::string("n"),
				
				
	},
	s_Conversation{	
				// First statement from the NPC
				std::string("I used to visit Dreamland Park (now located here) in my childhood.\n After many years, I decided to stop by this park again.\n But today, while I was walking in the park for around 30 minutes,\n I started coughing; my eyes and throat were irritated,\n and I felt shortness of breath.\n I wonder why."),
				// Responses by player
				std::string("It's nothing, just my delusion"),
				std::string("The air is polluted"),
				std::string("n"),
				// Response by NPC for each player input
				std::string("n"),
				std::string("n"),
				std::string("n"),
				// Closing statment player
				std::string("n"),
				// Closing statment NPC
				std::string("n"),
	},
	s_Conversation{	
				// First statement from the NPC
				std::string("I used to visit Dreamland Park (now located here) in my childhood.\n After many years, I decided to stop by this park again.\n But today, while I was walking in the park for around 30 minutes,\n I started coughing; my eyes and throat were irritated,\n and I felt shortness of breath.\n I wonder why."),
				// Responses by player
				std::string("It's nothing, just my delusion"),
				std::string("The air is polluted"),
				std::string("n"),
				// Response by NPC for each player input
				std::string("n"),
				std::string("n"),
				std::string("n"),
				// Closing statment player
				std::string("n"),
				// Closing statment NPC
				std::string("n"),
	},
	};
};



#pragma once
