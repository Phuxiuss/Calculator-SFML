#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class CalculatorModel
{
public:

	CalculatorModel();
	~CalculatorModel();

	void EnterCharacter(char character);
	void Clear();
	void ClearAll();
	double ConvertStringToDouble(std::string& p_string);
	void ConvertDoubleToString();
	std::optional<double> GetResult() const;
	double ApplyOperator(double a, double b, std::string p_operator);

private:

	bool IsACharOperator(char c);
	bool IsANumber(const std::string& string);
	double StringToDouble(const std::string string);
	void PerformPendingOperaton();
	void TrimSpaces();

	std::string DoubleToString(const double p_double);
	std::string CalculateResult();


	std::string currentEntry;
};

