#include "Button.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "DisplayPanel.h"

Button::Button(sf::Vector2f size, sf::Vector2f position, sf::RenderWindow* window, std::string p_text)
    : position(position), size(size) , window(window), text(font, p_text, 30)
{
    button.setFillColor(colorDefault);
    button.setSize(size);
    button.setPosition(position);
    pivotPoint = sf::Vector2f(button.getSize().x / 2.0f + button.getPosition().x, button.getSize().y / 2.0f + button.getPosition().y);
    font.openFromFile("ARIAL.TTF");
    SetText(p_text);

    // DEBUG
    //positionShower.setRadius(5.0f);
    //positionShower.setFillColor(sf::Color::Red);
    //positionShower.setPointCount(50);
    //positionShower.setOrigin(sf::Vector2(positionShower.getRadius(), positionShower.getRadius()));

    // Use this to check the position of a object.
    //positionShower.setPosition(pivotPoint);
}

void Button::SetColor(sf::Color color)
{
    colorDefault = sf::Color(color);
    colorHover = sf::Color(colorDefault.r - 20, colorDefault.g - 20, colorDefault.b - 20);
    colorClick = sf::Color(colorDefault.r - 40, colorDefault.g - 40, colorDefault.b - 40);
}

void Button::SetText(std::string string)
{

    text = sf::Text(font, string, 30);
    //text.setFillColor(sf::Color::Black);
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(sf::Vector2f(bounds.getCenter().x, bounds.getCenter().y));
    text.setPosition(pivotPoint);
}

void Button::SetSize(sf::Vector2f p_size)
{
    button.setSize(p_size);
    pivotPoint = sf::Vector2f(button.getSize().x / 2.0f + button.getPosition().x, button.getSize().y / 2.0f + button.getPosition().y);
}

void Button::Update()
{
    mousePosition = sf::Vector2f(sf::Mouse::getPosition(*window));
    mouseIsOverButton = button.getGlobalBounds().contains(mousePosition);
    mousePressed = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);

    window->draw(button);
    window->draw(text);
    //window->draw(positionShower);

    // Checks if Mouse entered
    if (mouseIsOverButton && !isOver)
    {
        //std::cout << "Entered" << std::endl;
    }
    else if (!mouseIsOverButton && isOver)
    {
        //std::cout << "Left" << std::endl;
    }
    isOver = mouseIsOverButton;

    // Checks if Mouse got pressed
    if (mouseIsOverButton && mousePressed)
    {
        button.setFillColor(colorClick);
        if (!isCurrentlyPressing)
        {
            onButtonClick();
        }
        isCurrentlyPressing = true;
    }
    else if (mouseIsOverButton) // hover 
    {
        button.setFillColor(colorHover);
    }
    else // default
    {
        button.setFillColor(colorDefault);
    }

    // Checks if button got released
    if (!mousePressed && isCurrentlyPressing)
    {
        //std::cout << "Released" << std::endl;
        isCurrentlyPressing = false;
    }
}

void Button::onButtonClick()
{
    //std::cout << "Clicked" << std::endl;
    // call the function whatever the onButtonPressedFunction is set to
    if (onButtonPressedFunction)
    {
        onButtonPressedFunction();
    }
}

void Button::AddAction(std::function<void()> function)
{
    onButtonPressedFunction = function;
}
