#include "CalculatorUI.h"

CalculatorUI::CalculatorUI(sf::RenderWindow& window)
	: window(window), displayPanel(sf::Vector2f(465, 130), sf::Vector2f(0, 150), &window),
	button0(sf::Vector2f(110, 70), sf::Vector2f(120, 625), &window, "0"),
	button1(sf::Vector2f(110, 70), sf::Vector2f(5, 550), &window, "1"),
	button2(sf::Vector2f(110, 70), sf::Vector2f(120, 550), &window, "2"),
	button3(sf::Vector2f(110, 70), sf::Vector2f(235, 550), &window, "3"),
	button4(sf::Vector2f(110, 70), sf::Vector2f(5, 475), &window, "4"),
	button5(sf::Vector2f(110, 70), sf::Vector2f(120, 475), &window, "5"),
	button6(sf::Vector2f(110, 70), sf::Vector2f(235, 475), &window, "6"),
	button7(sf::Vector2f(110, 70), sf::Vector2f(5, 400), &window, "7"),
	button8(sf::Vector2f(110, 70), sf::Vector2f(120, 400), &window, "8"),
	button9(sf::Vector2f(110, 70), sf::Vector2f(235, 400), &window, "9"),
	buttonPlus(sf::Vector2f(110, 70), sf::Vector2f(350, 550), &window, "+"),
	buttonMinus(sf::Vector2f(110, 70), sf::Vector2f(350, 475), &window, "-"),
	buttonMultiply(sf::Vector2f(110, 70), sf::Vector2f(350, 400), &window, "x"),
	buttonDivide(sf::Vector2f(110, 70), sf::Vector2f(350, 325), &window, "/"),
	buttonCE(sf::Vector2f(110, 70), sf::Vector2f(5, 325), &window, "CE"),
	buttonC(sf::Vector2f(110, 70), sf::Vector2f(120, 325), &window, "C"),
	buttonComma(sf::Vector2f(110, 70), sf::Vector2f(235, 625), &window, ","),
	buttonEquals(sf::Vector2f(110, 70), sf::Vector2f(350, 625), &window, "="),
	buttonBackspace(sf::Vector2f(110, 70), sf::Vector2f(235, 325), &window, "DEL"),
	buttonPlusMinus(sf::Vector2f(110, 70), sf::Vector2f(5, 625), &window, "+/-")
{
	buttonPointers = {
		&button0,
		&button1,
		&button2,
		&button3,
		&button4,
		&button5,
		&button6,
		&button7,
		&button8,
		&button9,
		&buttonPlus,
		&buttonMinus,
		&buttonMultiply,
		&buttonDivide,
		&buttonCE,
		&buttonC,
		&buttonComma,
		&buttonEquals,
		&buttonBackspace,
		&buttonPlusMinus
	};
	SetupButtons();
}



void CalculatorUI::Update()
{
	for (auto* button : buttonPointers)
	{
		button->Update();
	}

	displayPanel.Update();

	// since SetText() is expensive to call, only call it when it actually changes.
	if (currentEntryText != calculatorBrain.GetCurrentEntry())
	{
		currentEntryText = calculatorBrain.GetCurrentEntry();
		displayPanel.SetText(currentEntryText);
	}

	if (currentExpressionText != calculatorBrain.GetExpression())
	{
		currentExpressionText = calculatorBrain.GetExpression();
		displayPanel.SetExpressionText(currentExpressionText);
	}

}

void CalculatorUI::SetupButtons()
{
	button0.AddAction([this]() {calculatorBrain.AddDigit("0"); });
	button1.AddAction([this]() {calculatorBrain.AddDigit("1"); });
	button2.AddAction([this]() {calculatorBrain.AddDigit("2"); });
	button3.AddAction([this]() {calculatorBrain.AddDigit("3"); });
	button4.AddAction([this]() {calculatorBrain.AddDigit("4"); });
	button5.AddAction([this]() {calculatorBrain.AddDigit("5"); });
	button6.AddAction([this]() {calculatorBrain.AddDigit("6"); });
	button7.AddAction([this]() {calculatorBrain.AddDigit("7"); });
	button8.AddAction([this]() {calculatorBrain.AddDigit("8"); });
	button9.AddAction([this]() {calculatorBrain.AddDigit("9"); });
	buttonPlus.AddAction([this]() {calculatorBrain.SetOperator("+"); });
	buttonMinus.AddAction([this]() {calculatorBrain.SetOperator("-"); });
	buttonMultiply.AddAction([this]() {calculatorBrain.SetOperator("*"); });
	buttonDivide.AddAction([this]() {calculatorBrain.SetOperator("/"); });
	buttonCE.AddAction([this]() {calculatorBrain.ClearEntry(); });
	buttonC.AddAction([this]() {calculatorBrain.ClearAll(); });
	buttonComma.AddAction([this]() {calculatorBrain.AddComma(); });
	buttonEquals.AddAction([this]() {calculatorBrain.CalculateExpression(); });
	buttonBackspace.AddAction([this]() {calculatorBrain.Backspace(); });
	buttonPlusMinus.AddAction([this]() {calculatorBrain.MakePositiveNegative(); });


	buttonPlus.SetColor(sf::Color(199, 135, 54));
	buttonMultiply.SetColor(sf::Color(199, 135, 54));
	buttonDivide.SetColor(sf::Color(199, 135, 54));
	buttonMinus.SetColor(sf::Color(199, 135, 54));
	buttonEquals.SetColor(sf::Color(199, 135, 54));

	button0.SetColor(sf::Color(81, 61 ,43));
	button1.SetColor(sf::Color(81, 61, 43));
	button2.SetColor(sf::Color(81, 61, 43));
	button3.SetColor(sf::Color(81, 61, 43));
	button4.SetColor(sf::Color(81, 61, 43));
	button5.SetColor(sf::Color(81, 61, 43));
	button6.SetColor(sf::Color(81, 61, 43));
	button7.SetColor(sf::Color(81, 61, 43));
	button8.SetColor(sf::Color(81, 61, 43));
	button9.SetColor(sf::Color(81, 61, 43));
	buttonComma.SetColor(sf::Color(81, 61, 43));
	buttonPlusMinus.SetColor(sf::Color(81, 61, 43));

	buttonCE.SetColor(sf::Color(134, 125, 108));
	buttonC.SetColor(sf::Color(134, 125, 108));
	buttonBackspace.SetColor(sf::Color(134, 125, 108));

}	
