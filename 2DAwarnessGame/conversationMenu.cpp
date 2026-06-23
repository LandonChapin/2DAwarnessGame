#include "conversationMenu.h"



void ConversationMenu::draw(sf::RenderWindow& window) {
	if (!isActive) return;

	window.draw(questionText);

	if (showingResponse) {
		continueText.setPosition(questionText.getPosition().x,
			questionText.getPosition().y + 100);
		window.draw(continueText);
	}
	else {
		for (auto& button : answerButtons) {
			if (button.buttonText.getString() != "n") {
				window.draw(button.buttonText);
			}
		}
	}
}




int ConversationMenu::update(sf::RenderWindow& window, sf::Vector2f owner) {
	updateButtonPositions(owner);
	if (!isActive) return 0;

	sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	auto& convo = conversationArray[currentConversation];
	bool mousePressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	bool mouseClicked = mousePressed && !mouseWasPressed;
	mouseWasPressed = mousePressed;
	// If showing NPC response, wait for click to continue


	if (showingResponse) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {

			showingResponse = false;

			bool allUsed = true;
			for (auto& opt : convo.options) {
				if (!opt.used) {
					allUsed = false;
					break;
				}
			}

			if (allUsed) {
				questionText.setString(convo.closingLine);
				isActive = false;
				return 2;
			}

			questionText.setString(convo.openingLine);
			updateButtons(owner);
		}

		return 0;
	}



	// Handle button clicks

	for (auto& button : answerButtons) {
		if (button.buttonText.getString() == "n") continue;

		button.buttonHitbox.setPosition(button.buttonText.getPosition());

		if (button.buttonHitbox.getBounds().contains(mousePos)) {
			button.buttonText.setFillColor(sf::Color::Yellow);

			if (mouseClicked) {

				if (button.buttonName == "-1") continue;

				int index = std::stoi(button.buttonName);

				if (index < 0 || index >= convo.options.size()) {
					continue;
				}


				// Mark as used
				convo.options[index].used = true;

				// Show NPC response
				questionText.setString(convo.options[index].npcResponse);
				showingResponse = true;

				return 0;
			}
		}
		else {
			button.buttonText.setFillColor(sf::Color::White);
		}
	}


	return 0;
}



void ConversationMenu::initializeMenu(int index, sf::Vector2f owner) {
	currentConversation = index;
	isActive = false;
	showingResponse = false;

	if (!font.loadFromFile("Assets/Fonts/Seagram_tfb/Seagram tfb.ttf")) {
		std::cerr << "Error loading font!" << std::endl;
	}

	questionText.setFont(font);
	questionText.setCharacterSize(24);
	questionText.setFillColor(sf::Color::White);

	questionText.setString(conversationArray[index].openingLine);


	continueText.setFont(font);
	continueText.setCharacterSize(18);
	continueText.setFillColor(sf::Color::Yellow);
	continueText.setString("Press E to continue");


	updateButtons(owner);

}

void ConversationMenu::setupButton(sf::Text& button, const std::string& text, int charSize, sf::Color color, float x, float y) {
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

void ConversationMenu::updateButtonHover(sf::Text& button, Hitbox& hitbox, const sf::Vector2f& mousePos) {
	if (hitbox.getBounds().contains(mousePos)) {
		button.setFillColor(sf::Color::Yellow); // Highlight on hover
	}
	else {
		button.setFillColor(sf::Color::White); // Default color
	}
}

void ConversationMenu::updateButtonPositions(sf::Vector2f owner) {
	// Update the position of the question text
	questionText.setPosition(owner.x - 200, owner.y - 250);
	// Update the positions of the answer buttons
	for (size_t i = 0; i < answerButtons.size(); ++i) {
		answerButtons[i].buttonText.setPosition(owner.x + 300, owner.y + i * 50);
		answerButtons[i].buttonHitbox.setPosition(answerButtons[i].buttonText.getPosition());
	}
}

void ConversationMenu::updateButtons(sf::Vector2f owner) {
	auto& convo = conversationArray[currentConversation];

	int visibleIndex = 0;



	for (size_t i = 0; i < answerButtons.size(); i++) {
		answerButtons[i].buttonText.setString("n");
	}


	for (auto& b : answerButtons) {
		b.buttonName = "-1"; // invalid safe value
	}


	for (size_t i = 0; i < convo.options.size(); i++) {
		if (!convo.options[i].used && visibleIndex < answerButtons.size()) {
			setupButton(
				answerButtons[visibleIndex].buttonText,
				convo.options[i].playerLine,
				20,
				sf::Color::White,
				owner.x + 300,
				owner.y + visibleIndex * 50
			);

			// Store index inside button name
			answerButtons[visibleIndex].buttonName = std::to_string(i);

			visibleIndex++;
		}
	}
}

