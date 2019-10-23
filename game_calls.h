#pragma once
#include <vector>

class Code
{
public:
	std::vector<int> code;
	void UpdateGuess();
	Code()
	{
		for (int i = 0; i < 4; ++i)
		{
			code.push_back(0);
		}
	}
	~Code()
	{
		code.clear();
	}

};

// Asks the user for their input and will try to filter out poor inputs
std::vector<int> GetGuess();

// Does the checking of the guess and gives you your result. 
bool CheckGuess(std::vector<int> guess, std::vector<int> code);

// Checks if a digit is contained in code
bool ContainedIn(int current, std::vector<int> code);
