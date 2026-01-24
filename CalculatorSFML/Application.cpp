#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"
#include "DisplayPanel.h"
#include "CalculatorModel.h"
#include "CalculatorBrain.h"    
#include "CalculatorUI.h"

int main()
{
    unsigned int resolution[2] = {465, 700};
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode({ resolution[0], resolution[1] }), "Phuc's Calculator", sf::Style::Close);
    
    sf::RectangleShape Backround(sf::Vector2f({ (float)resolution[0], (float)resolution[1] }));
    Backround.setFillColor(sf::Color(32, 32, 32, 255));

    CalculatorUI* calculatorUI = new CalculatorUI(*window);
    auto mouse_position = sf::Vector2f(sf::Mouse::getPosition(*window));

    while (window->isOpen())
    {
        mouse_position = sf::Vector2f(sf::Mouse::getPosition(*window));

        while (const std::optional event = window->pollEvent())
        {
            if (event -> is<sf::Event::Closed>())
                window->close();
        }

        window->clear();
        window->draw(Backround);
        calculatorUI->Update();
        window->display();
    }
}

