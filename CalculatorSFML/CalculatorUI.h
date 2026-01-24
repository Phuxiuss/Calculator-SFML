#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"
#include "DisplayPanel.h"
#include "CalculatorBrain.h"    
#include <vector>

class CalculatorUI
{
public:

	CalculatorUI(sf::RenderWindow& window);
	void Update();

private:

	void SetupButtons();

	Button button0;
	Button button1;
	Button button2;
	Button button3;
	Button button4;
	Button button5;
	Button button6;
	Button button7;
	Button button8;
	Button button9;
	Button buttonPlus;
	Button buttonMinus;
	Button buttonMultiply;
	Button buttonDivide;
	Button buttonCE;
	Button buttonC;
	Button buttonComma;
	Button buttonEquals;
	Button buttonBackspace;
	Button buttonPlusMinus;

	std::string currentExpressionText;
	std::string currentEntryText;

	std::vector<Button*> buttonPointers;
	DisplayPanel displayPanel;
	sf::RenderWindow& window;
	CalculatorBrain calculatorBrain;
};

