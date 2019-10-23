#include <algorithm>
#include <iostream>
#include <limits>
#include <ctime>
#include "game_calls.h"

Code::Code()
{
	// Easier to write! Arguments: number of elements, value of each element
	code = std::vector<int>(4, 0);
}

Code::~Code() = default;		// .clear() will be called by ~vector()

void Code::UpdateGuess()
{
	// Try using std::random instead
	//srand(time(NULL));		// Compiler throws a warning here; so explicitly cast it
	srand(static_cast<unsigned int>(time(NULL)));
	for (size_t i = 0; i < code.size(); ++i)
	{
		code[i] = rand() % 10;	// This is a flawed approach BTW
	}
}

std::vector<int> GetGuess()
{
	int guess = 0;
	std::cin >> guess;

	while (!std::cin || guess / 10000 > 0)
	{
		std::cout << "Wrong Format!\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> guess;
	}

	int divider = 1000;
	std::vector<int> result;

	while (divider > 0)
	{
		result.push_back(guess / divider);
		guess = guess % divider;
		divider /= 10;
	}
	return result;
}

bool CheckGuess(const std::vector<int>& guess, const std::vector<int>& code)
{
	if (guess.empty() || code.empty())
	{
		std::cout << "Error: Guess or Code was empty!\n";
		return false;
	}

	// A for loop seems to make sense here; not sure why `while` is better?
	size_t i = 0;
	bool status = true;
	while (i < guess.size() && i < code.size())
	{
		if (code[i] == guess[i])
		{
			std::cout << "B";
		}
		else if (ContainedIn(guess[i], code))
		{
			std::cout << "C";
			status = false;
		}
		else
		{
			std::cout << "X";
			status = false;
		}
		++i;
	}
	std::cout << std::endl;
	return status;
}

bool ContainedIn(int current, const std::vector<int>& code)
{
	// Let STL do the searching
	return std::find(code.begin(), code.end(), current) != code.end();
}