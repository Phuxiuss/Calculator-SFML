#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class DisplayPanel
{

public:
	DisplayPanel(sf::Vector2f size, sf::Vector2f position, sf::RenderWindow* window);

	void SetText(const std::string& string);
	void SetExpressionText(const std::string& string);
	void Update();

private:
	sf::RenderWindow* window;
	sf::Vector2f currentPosition;
	sf::Vector2f currentSize;
	std::string currentErrorMessage = "SYNTAX ERROR";
	sf::RectangleShape background;
	sf::Font font;
	sf::Text text = sf::Text(font, "", 60);
	sf::Text textExpression = sf::Text(font, "", 30);
};

