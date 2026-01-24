#include "DisplayPanel.h"
#include "CalculatorModel.h"
#include <iostream>


DisplayPanel::DisplayPanel(sf::Vector2f size, sf::Vector2f position, sf::RenderWindow* window)
	: currentSize(size), currentPosition(position), window(window)
{
	background.setSize(currentSize);
	background.setPosition(currentPosition);
	background.setFillColor(sf::Color(20, 20, 20));
	font.openFromFile("ARIAL.TTF");
	text.setPosition(sf::Vector2f(background.getPosition().x + 20, background.getPosition().y));
	textExpression.setPosition(sf::Vector2f(background.getPosition().x + 10, background.getPosition().y - 50));
	textExpression.setFillColor(sf::Color(180, 180, 180));
}

void DisplayPanel::SetText(const std::string& string)
{
    text.setString(string);

    const unsigned int MIN_SIZE = 20;
    const unsigned int MAX_SIZE = 100;
    const float padding = 30.f;

    float boxWidth = background.getSize().x - padding;
    if (boxWidth <= 0.f)
    {
        text.setCharacterSize(MIN_SIZE);
        return;
    }

    unsigned int size = text.getCharacterSize();
    if (size < MIN_SIZE) size = MIN_SIZE;
    if (size > MAX_SIZE) size = MAX_SIZE;
    text.setCharacterSize(size);

    sf::FloatRect bounds = text.getLocalBounds();

    while (bounds.size.x > boxWidth && size > MIN_SIZE)
    {
        --size;
        text.setCharacterSize(size);
        bounds = text.getLocalBounds();
    }

    
    while (size < MAX_SIZE)
    {
        unsigned int nextSize = size + 1;
        text.setCharacterSize(nextSize);
        sf::FloatRect nextBounds = text.getLocalBounds();
        if (nextBounds.size.x > boxWidth)
        {
            text.setCharacterSize(size);
            break;
        }

        size = nextSize;
        bounds = nextBounds;
    }

}

void DisplayPanel::SetExpressionText(const std::string &string)
{
    textExpression.setString(string);

    const unsigned int MIN_SIZE = 5;
    const unsigned int MAX_SIZE = 40;
    const float padding = 30.f;

    float boxWidth = background.getSize().x - padding;
    if (boxWidth <= 0.f)
    {
        textExpression.setCharacterSize(MIN_SIZE);
        return;
    }

    unsigned int size = textExpression.getCharacterSize();
    if (size < MIN_SIZE) size = MIN_SIZE;
    if (size > MAX_SIZE) size = MAX_SIZE;
    textExpression.setCharacterSize(size);

    sf::FloatRect bounds = textExpression.getLocalBounds();

    while (bounds.size.x > boxWidth && size > MIN_SIZE)
    {
        --size;
        textExpression.setCharacterSize(size);
        bounds = textExpression.getLocalBounds();
    }

    while (size < MAX_SIZE)
    {
        unsigned int nextSize = size + 1;
        textExpression.setCharacterSize(nextSize);
        sf::FloatRect nextBounds = textExpression.getLocalBounds();
        if (nextBounds.size.x > boxWidth)
        {
            textExpression.setCharacterSize(size);
            break;
        }

        size = nextSize;
        bounds = nextBounds;
    }
}

void DisplayPanel::Update()
{
	window->draw(background);
	window->draw(text);
	window->draw(textExpression);
}