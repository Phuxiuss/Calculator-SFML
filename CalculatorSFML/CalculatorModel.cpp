#include "CalculatorModel.h"
#include <iostream>


CalculatorModel::CalculatorModel()
{


}

CalculatorModel::~CalculatorModel()
{
}

void CalculatorModel::EnterCharacter(char p_char)
{
	if (std::isdigit(p_char) || p_char == '.')
	{
		currentEntry.push_back(p_char);
	}
	else if (IsACharOperator(p_char))
	{
		currentEntry.push_back(' ');
		currentEntry.push_back(p_char);
		currentEntry.push_back(' ');
	}
	else if (p_char == '(' || p_char == ')')
	{
		currentEntry.push_back(p_char);
	}
	else if (p_char == '%')
	{
		currentEntry.push_back(' ');
		currentEntry.push_back(p_char);
		currentEntry.push_back(' ');
	}

	//TrimSpaces();

	std::cout << currentEntry << std::endl;
	double b = ConvertStringToDouble(currentEntry);

	std::cout << b << std::endl;
}


double CalculatorModel::ConvertStringToDouble(std::string &p_string)
{
	try
	{
		double value = std::stod(p_string);
		return value;
	}
	catch (const std::invalid_argument&)
	{
		return 0.0;
	}
	catch (const std::out_of_range&)
	{
		return 0.0;
	}
}

void CalculatorModel::ConvertDoubleToString()
{
}

std::optional<double> CalculatorModel::GetResult() const
{
	return std::optional<double>();
}

double CalculatorModel::ApplyOperator(double a, double b, const std::string p_operator)
{
	if (p_operator == "+")
	{
		return a + b;
	}
	if (p_operator == "-")
	{
		return a - b;
	}
	if (p_operator == "*")
	{
		return a * b;
	}
	if (p_operator == "/")
	{
		return a / b;
	}
	if (p_operator == "^")
	{
		return std::pow(a, b);
	}
}

bool CalculatorModel::IsACharOperator(char c)
{
	return c == '+' || c == '-' || c == '/' || c == '*' || c == '^';
}

bool CalculatorModel::IsANumber(const std::string &string)
{

	return false;
}

double CalculatorModel::StringToDouble(const std::string string)
{
	return 0.0;
}

void CalculatorModel::PerformPendingOperaton()
{
}

void CalculatorModel::TrimSpaces()
{
	std::string result;
	bool lastSpace = false;

	for (char character : currentEntry)
	{
		if (std::isspace((unsigned char)character))
		{
			if (!lastSpace)
			{
				result.push_back(' ');
			}
			lastSpace = true;
		}
		else
		{
			result.push_back(character);
		}
	}
	
	std::cout << result << std::endl;
}

std::string CalculatorModel::DoubleToString(const double p_double)
{
	return std::string();
}

std::string CalculatorModel::CalculateResult()
{
	return std::string();
}
