#include <SFML/Graphics.hpp>
#include "s_Button.h"
#include <iostream>
#include "Entity.h"


struct DialogueOption {
	std::string playerLine;
	std::string npcResponse;
	bool used = false; // Track if already chosen
};

struct s_Conversation {
	std::string openingLine;
	std::vector<DialogueOption> options;
	std::string closingLine;
};




class ConversationMenu {
public:
	ConversationMenu() {};
	void draw(sf::RenderWindow& window);
	int update(sf::RenderWindow& window, sf::Vector2f owner);
	void initializeMenu(int questionNumber, sf::Vector2f owner); // Move this method to public access
	void setActive(bool active) { isActive = active; } // Method to set the active state of the question menu
	bool getActive() const { return isActive; } // Method to get the active state of the question menu
	void updateButtons(sf::Vector2f owner);

private:
	sf::Font font; // Font for the question menu
	sf::Text questionText; // Text to display the question
	sf::Text continueText; // Text to display the continue prompt

	// Vector of buttons for the answers
	std::vector<s_button> answerButtons{
		s_button{std::string("Answer 1"), sf::Text(), Hitbox()},
		s_button{std::string("Answer 2"), sf::Text(), Hitbox()},
		s_button{std::string("Answer 3"), sf::Text(), Hitbox()},
		s_button{std::string("Answer 4"), sf::Text(), Hitbox()}
	};

	bool isActive = false; // State of the question menu, whether it's active or not
	int currentQuestionIndex = 0; // Index of the current question being displayed

	bool mouseWasPressed = false;

	void setupButton(sf::Text& button, const std::string& text, int charSize, sf::Color color, float x, float y);
	void updateButtonHover(sf::Text& button, Hitbox& hitbox, const sf::Vector2f& mousePos);
	void updateButtonPositions(sf::Vector2f owner);

	int handleAnswer1ButtonClicked();
	int handleAnswer2ButtonClicked();
	int handleAnswer3ButtonClicked();
	int handleAnswer4ButtonClicked();


	int currentConversation = 0;
	bool showingResponse = false;
	std::string currentResponse = "";


	std::vector <s_Conversation> conversationArray = {

	s_Conversation{
	"I used to visit Dreamland Park...",
	{
		{ "It's nothing...", "Hmm... I don't think so." },
		{ "The air is polluted.", "That... would explain a lot." },
		{ "Maybe something changed...", "Yes... things don't feel the same." },
		{ "You should leave...", "You're probably right." }
	},
	"Thank you for talking with me."
	},

	s_Conversation{
		"I used to visit Dreamland Park...",
		{
			{ "It's nothing...", "Hmm... I don't think so." },
			{ "The air is polluted.", "That... would explain a lot." },
			{ "Maybe something changed...", "Yes... things don't feel the same." },
			{ "You should leave...", "You're probably right." }
		},
		"Thank you for talking with me."
	},

	s_Conversation{
		"I used to visit Dreamland Park...",
		{
			{ "It's nothing...", "Hmm... I don't think so." },
			{ "The air is polluted.", "That... would explain a lot." },
			{ "Maybe something changed...", "Yes... things don't feel the same." },
			{ "You should leave...", "You're probably right." }
		},
		"Thank you for talking with me."
	},

	};
};



#pragma once
