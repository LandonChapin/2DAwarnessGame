#include <SFML/Graphics.hpp>
#include "s_Button.h"
#include <iostream>
#include "Entity.h"

struct s_Question {
	std::string question;
	std::string answer1; // Possible answer to question, input "n" for the answer to be ignored
	std::string answer2; // Possible answer to question, input "n" for the answer to be ignored
	std::string answer3; // Possible answer to question, input "n" for the answer to be ignored
	std::string answer4; // Possible answer to question, input "n" for the answer to be ignored
	int correctAnswer;

};



class QuestionMenu {
public:
	QuestionMenu() {};
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

	std::vector <s_Question> questionArray = {
	s_Question{	std::string("I used to visit Dreamland Park (now located here) in my childhood.\n After many years, I decided to stop by this park again.\n But today, while I was walking in the park for around 30 minutes,\n I started coughing; my eyes and throat were irritated,\n and I felt shortness of breath.\n I wonder why."),
				std::string("It's nothing, just my delusion"),
				std::string("The air is polluted"),
				std::string("n"),
				std::string("n"),
				2
	},
	s_Question{	std::string("If polluted air is the cause of my discomfort\n, what would be the major reasons causing it in the park ?"),
				std::string("I see some factories built around the park that are releasing gases into the air,\n which may contain solid or liquid contaminants harmful to health"),
				std::string("Some mysterious trees in the park are polluting the air."),
				std::string("The birds in the trees are causing the issue"),
				std::string("n"),
				1
	},
	s_Question{	std::string("What could we (as a society) do to ease the discomfort caused the air pollution?"),
				std::string("Asking factories to adopt recycling and composting instead of emitting polluted air"),
				std::string("Planting more trees"),
				std::string("Supporting policies that encourage clean energy"),
				std::string("All of the above"),
				4
	},
	};
};



#pragma once
