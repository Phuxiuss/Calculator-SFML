#include "CalculatorBrain.h"
#include <sstream>
#include <iomanip>
#include <iostream>

CalculatorBrain::CalculatorBrain()
{
	firstNumber.push_back("0");
	currentEntry = firstNumber[0];
	std::cout << currentEntry << std::endl;
}

void CalculatorBrain::ClearAll()
{
	firstNumber.clear();
	secondNumber.clear();
	firstNumber.push_back("0");
	currentEntry = firstNumber[0];
	currentExpression = "";
	stringOperator = "";
	result = "";
}

void CalculatorBrain::ClearEntry()
{
	if (stringOperator == "" || stringOperator.empty())
	{
		if (firstNumber.size() > 0)
		{
			firstNumber.clear();

			if (firstNumber.size() <= 0)
			{
				firstNumber.push_back("0");
			}

			std::string tempEntry = ConvertStringArrayToString(firstNumber);
			currentEntry = tempEntry;
		}
	}
	else if (secondNumber.size() > 0)
	{
		secondNumber.clear();
		if (secondNumber.size() <= 0)
		{
			secondNumber.push_back("0");
		}
		std::string tempEntry = ConvertStringArrayToString(secondNumber);
		currentEntry = tempEntry;
	}
}

void CalculatorBrain::CalculateExpression()
{
	if (stringOperator == "" || stringOperator.empty()) { return; }

	double tempResult;
	double firstNumber;

	std::string tempFirstNumber = ConvertStringArrayToString(this->firstNumber);
	firstNumber = std::stod(tempFirstNumber);

	// if second Number is empty, second Number = first number
	double secondNumber;
	if (this->secondNumber.size() == 0)
	{
		secondNumber = firstNumber;
		this->secondNumber = this->firstNumber;
	}
	else
	{
		std::string tempSecondNumber = ConvertStringArrayToString(this->secondNumber);
		secondNumber = std::stod(tempSecondNumber);
	}

	tempResult = ApplyOperator(firstNumber, secondNumber, stringOperator);
	

	// make a stream so you round the number up
	std::ostringstream oss;
	oss << std::setprecision(10) << tempResult;  // set precision to 10 since it rounds up to ten digits

	// check if Division by 0
	if ((firstNumber == 0 || secondNumber == 0) && stringOperator == "/")
	{
		result = "Division by 0";
	}
	else
	{
		result = oss.str();
	}

	std::ostringstream ossExpression;
	// a + b = c
	ossExpression << std::setprecision(10) << firstNumber << " " << stringOperator << " " << secondNumber << " = ";
	currentExpression = ossExpression.str();

	currentEntry = result;

	// turn result into first number
	this->firstNumber.clear();
	for (auto character : result) {
		std::string value(1, character);
		this->firstNumber.push_back(value);
	}

}

void CalculatorBrain::AddComma()
{
	if (stringOperator == "" || stringOperator.empty())
	{
		bool commaIsAlreadySet = false;

		for (int i = 0; i < firstNumber.size(); i++)
		{
			if (firstNumber[i] == ".")
			{
				commaIsAlreadySet = true;

			}
		}

		if (!commaIsAlreadySet)
		{
			firstNumber.push_back(".");
			currentEntry = ConvertStringArrayToString(firstNumber);
		}
	}
	else
	{
		bool commaIsAlreadySet = false;

		for (int i = 0; i < secondNumber.size(); i++)
		{
			if (secondNumber[i] == ".")
			{
				commaIsAlreadySet = true;
			}
		}

		if (!commaIsAlreadySet)
		{
			secondNumber.push_back(".");
			currentEntry = ConvertStringArrayToString(secondNumber);
		}
	}
}

void CalculatorBrain::AddDigit(std::string number)
{
	if (firstNumber[0] == "0") firstNumber.erase(firstNumber.begin());
	if (stringOperator == "" || stringOperator.empty())
	{
		firstNumber.push_back(number);
		currentEntry = ConvertStringArrayToString(firstNumber);
	}
	else
	{
		secondNumber.push_back(number);
		currentEntry = ConvertStringArrayToString(secondNumber);
	}
}

void CalculatorBrain::SetOperator(std::string Operator)
{
	stringOperator = Operator;
	secondNumber.clear();

	UpdateExpression();
}

void CalculatorBrain::Backspace()
{
	if (stringOperator == "" || stringOperator.empty())
	{
		if (firstNumber.size() > 0)
		{
			firstNumber.pop_back();
			std::string tempEntry = ConvertStringArrayToString(firstNumber);

			if (firstNumber.size() <= 0)
			{
				firstNumber.push_back("0");
			}
			currentEntry = tempEntry;
		}
	}
	else if (secondNumber.size() > 0)
	{
		secondNumber.pop_back();
		std::string tempEntry = ConvertStringArrayToString(secondNumber);

		if (secondNumber.size() <= 0)
		{
			secondNumber.push_back("0");
		}
		currentEntry = tempEntry;
	}
}

void CalculatorBrain::MakePositiveNegative()
{
	if (stringOperator == "" || stringOperator.empty())
	{
		if (firstNumber.size() > 0)
		{
			if (firstNumber[0] == "-" && firstNumber[0] != "0")
			{
				firstNumber.erase(firstNumber.begin());
				//std::cout << std::to_string(firstNumber.begin()) << std::endl;
				currentEntry = ConvertStringArrayToString(firstNumber);
			}
			else
			{
				firstNumber.insert(firstNumber.begin(), "-");
				currentEntry = ConvertStringArrayToString(firstNumber);

				for (auto string : firstNumber)
				{
					std::cout << string << std::endl;
				}
			}
		}
	}
	else
	{
		if (secondNumber.size() > 0 && secondNumber[0] != "0")
		{
			if (secondNumber[0] == "-")
			{
				secondNumber.erase(secondNumber.begin());
				currentEntry = ConvertStringArrayToString(secondNumber);
			}
			else
			{
				secondNumber.insert(secondNumber.begin(), "-");
				currentEntry = ConvertStringArrayToString(secondNumber);
			}
		}
	}
}

const std::string CalculatorBrain::GetCurrentEntry()
{
	return currentEntry;
}

const std::string CalculatorBrain::GetExpression()
{
	return currentExpression;
}

double CalculatorBrain::ApplyOperator(double a, double b, std::string p_operator)
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
		if (b == 0)
		{
			std::cout << "Division By 0" << std::endl;
			return 0;
		}
		return a / b;
	}
	if (p_operator == "^")
	{
		return std::pow(a,b);
	}

}

void CalculatorBrain::UpdateExpression()
{
	std::string tempExpression = "";
	tempExpression += ConvertStringArrayToString(firstNumber) + " ";

	if (stringOperator != "" || !stringOperator.empty())
	{
		tempExpression += stringOperator;
	}
	currentExpression = tempExpression;
}

std::string CalculatorBrain::ConvertStringArrayToString(std::vector<std::string> stringArray)
{
	if (stringArray.size() == 0) { return "0"; }
	std::string result;

	bool hasUselessZeros = true;

	auto iterator = stringArray.begin();

	while (hasUselessZeros && iterator != stringArray.end() && stringArray.size() > 1)
	{
		if (*iterator == "0")
		{
			iterator = stringArray.erase(iterator);
		}
		else
		{
			hasUselessZeros = false;
		}
	}

	// check if first digit is a comma
	if (stringArray.size() > 0 && stringArray[0] == ".")
	{
		stringArray[0] = "0";
		stringArray.insert(stringArray.begin() + 1, ".");
	}

	for (int i = 0; i < stringArray.size(); i++)
	{
		result += stringArray[i];
	}

	return result;
}


