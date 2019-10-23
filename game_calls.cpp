#include "game_calls.h"
#include <iostream>
#include <limits>
#include <ctime>

void Code::UpdateGuess()
{
	srand(time(NULL));
	for (size_t i = 0; i < code.size(); ++i)
	{
		code[i] = rand() % 10;
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

bool CheckGuess(std::vector<int> guess, std::vector<int> code)
{
	if (guess.empty() || code.empty())
	{
		std::cout << "Error: Guess or Code was empty!\n";
		return false;
	}

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

bool ContainedIn(int current, std::vector<int> code)
{
	for (auto e : code)
	{
		if (e == current)
		{
			return  true;
		}
	}
	return false;
}