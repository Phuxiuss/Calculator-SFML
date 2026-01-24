#pragma once
#include <string>
#include <vector>

class CalculatorBrain
{
public:
	CalculatorBrain();

	void ClearAll();
	void ClearEntry();
	void CalculateExpression();
	void AddComma();
	void AddDigit(std::string number);
	void SetOperator(std::string Operator);
	void Backspace();
	void MakePositiveNegative();
	const std::string GetCurrentEntry();
	const std::string GetExpression();

private: 

	double ApplyOperator(double a, double b, std::string p_operator);
	void UpdateExpression();
	std::string ConvertStringArrayToString(std::vector<std::string> stringArray);

	std::vector<std::string> firstNumber;
	std::string stringOperator;
	std::vector<std::string> secondNumber;
	std::string currentExpression;
	std::string currentEntry;
	std::string result;
};

