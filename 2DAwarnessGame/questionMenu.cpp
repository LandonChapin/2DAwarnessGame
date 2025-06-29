#include "questionMenu.h"

void QuestionMenu::draw(sf::RenderWindow& window) {
	if (isActive) {
		// Draw the question text
		window.draw(questionText);
		
		// Draw the answer buttons
		for (auto& button : answerButtons) {
			if (button.buttonText.getString() == "n") {
				continue; // Skip buttons with "n" as the text
			}
			window.draw(button.buttonText);
		}
	}
}

bool QuestionMenu::update(sf::RenderWindow& window, sf::Vector2f owner) { // Returns true if the correct answer is selected, false otherwise
	if (isActive) {
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		sf::Vector2f mousePosF = window.mapPixelToCoords(mousePos);
		// Check for mouse hover and clicks on answer buttons

		for (auto& button : answerButtons) {
			button.buttonHitbox.setPosition(button.buttonText.getPosition());
			if (button.buttonHitbox.getBounds().contains(mousePosF)) {
				updateButtonHover(button.buttonText, button.buttonHitbox, mousePosF);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					// Handle button click
					std::cout << "Clicked: " << button.buttonName << std::endl;
					if (button.buttonName == "Answer 1") {
						return handleAnswer1ButtonClicked();
					} else if (button.buttonName == "Answer 2") {
						return handleAnswer2ButtonClicked();
					} else if (button.buttonName == "Answer 3") {
						return handleAnswer3ButtonClicked();
					} else if (button.buttonName == "Answer 4") {
						return handleAnswer4ButtonClicked();
					}
					
				}
			} else {
				button.buttonText.setFillColor(sf::Color::White); // Default color

			}
		}
	}
	// Update the position of the question text and buttons based on the owner's position
	updateButtonPositions(owner);

	return false; // No answer selected yet
}

void QuestionMenu::initializeMenu(int questionNumber, sf::Vector2f owner) {
	currentQuestionIndex = questionNumber;

	if (!font.loadFromFile("Assets/Fonts/Seagram_tfb/Seagram tfb.ttf")) {
		std::cerr << "Error loading font!" << std::endl;
	}

	// Load the question text
	questionText.setFont(font);
	questionText.setString(questionArray[questionNumber].question);
	questionText.setCharacterSize(24);
	questionText.setFillColor(sf::Color::White);
	questionText.setPosition(owner.x - 200, owner.y - 250); // Position above the entity

	// Set up answer buttons
	setupButton(answerButtons[0].buttonText, questionArray[questionNumber].answer1, 20, sf::Color::White, owner.x + 300, owner.y + 0);
	setupButton(answerButtons[1].buttonText, questionArray[questionNumber].answer2, 20, sf::Color::White, owner.x + 300, owner.y + 50);
	setupButton(answerButtons[2].buttonText, questionArray[questionNumber].answer3, 20, sf::Color::White, owner.x + 300, owner.y + 100);
	setupButton(answerButtons[3].buttonText, questionArray[questionNumber].answer4, 20, sf::Color::White, owner.x + 300, owner.y + 150);
	
}

void QuestionMenu::setupButton(sf::Text& button, const std::string& text, int charSize, sf::Color color, float x, float y) {
	button.setFont(font);
	button.setString(text);
	button.setCharacterSize(charSize);
	button.setFillColor(color);

	// Adjust the origin to the center of the text
	sf::FloatRect textBounds = button.getLocalBounds();
	button.setOrigin(textBounds.left + textBounds.width / 2.0f,
		textBounds.top + textBounds.height / 2.0f);

	button.setPosition(x, y);
};

void QuestionMenu::updateButtonHover(sf::Text& button, Hitbox& hitbox, const sf::Vector2f& mousePos) {
	if (hitbox.getBounds().contains(mousePos)) {
		button.setFillColor(sf::Color::Yellow); // Highlight on hover
	} else {
		button.setFillColor(sf::Color::White); // Default color
	}
}

void QuestionMenu::updateButtonPositions(sf::Vector2f owner) {
	// Update the position of the question text
	questionText.setPosition(owner.x - 200, owner.y - 250);
	// Update the positions of the answer buttons
	for (size_t i = 0; i < answerButtons.size(); ++i) {
		answerButtons[i].buttonText.setPosition(owner.x + 300, owner.y + i * 50);
		answerButtons[i].buttonHitbox.setPosition(answerButtons[i].buttonText.getPosition());
	}
}

bool QuestionMenu::handleAnswer1ButtonClicked() {
	if (currentQuestionIndex < questionArray.size() && questionArray[currentQuestionIndex].correctAnswer == 1) {
		std::cout << "Correct answer selected!" << std::endl;
		return true; // Correct answer
	}
	std::cout << "Incorrect answer selected!" << std::endl;
	return false; // Incorrect answer
}

bool QuestionMenu::handleAnswer2ButtonClicked() {
	if (currentQuestionIndex < questionArray.size() && questionArray[currentQuestionIndex].correctAnswer == 2) {
		std::cout << "Correct answer selected!" << std::endl;
		return true; // Correct answer
	}
	std::cout << "Incorrect answer selected!" << std::endl;
	return false; // Incorrect answer
}

bool QuestionMenu::handleAnswer3ButtonClicked() {
	if (currentQuestionIndex < questionArray.size() && questionArray[currentQuestionIndex].correctAnswer == 3) {
		std::cout << "Correct answer selected!" << std::endl;
		return true; // Correct answer
	}
	std::cout << "Incorrect answer selected!" << std::endl;
	return false; // Incorrect answer
}

bool QuestionMenu::handleAnswer4ButtonClicked() {
	if (currentQuestionIndex < questionArray.size() && questionArray[currentQuestionIndex].correctAnswer == 4) {
		std::cout << "Correct answer selected!" << std::endl;
		return true; // Correct answer
	}
	std::cout << "Incorrect answer selected!" << std::endl;
	return false; // Incorrect answer
}