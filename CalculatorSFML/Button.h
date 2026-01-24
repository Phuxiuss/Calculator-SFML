#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <string>

class Button : sf::RectangleShape
{
public:

	Button(sf::Vector2f size, sf::Vector2f position, sf::RenderWindow* window, std::string p_text = "");

	void Update();
	void SetColor(sf::Color color);
	void SetText(std::string string);
	void SetSize(sf::Vector2f p_size);
	void onButtonClick();
	void AddAction(std::function<void()> function);

private:

	sf::Color colorDefault = sf::Color(100,100,100);
	sf::Color colorHover = sf::Color(colorDefault.r - 20, colorDefault.g - 20, colorDefault.b - 20);
	sf::Color colorClick = sf::Color(colorDefault.r - 40, colorDefault.g - 40, colorDefault.b - 40);

	sf::Vector2f mousePosition;
	sf::RectangleShape button;
	sf::Vector2f position;
	sf::Vector2f size;
	sf::RenderWindow* window;
	sf::Vector2f pivotPoint;

	sf::Font font;
	sf::Text text;
	//sf::CircleShape positionShower;

	std::function<void()> onButtonPressedFunction;

	bool isOver = false;
	bool isCurrentlyPressing = false;
	bool mousePressed = false;
	bool mouseIsOverButton = false;
};

