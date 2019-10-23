#pragma once
#include <vector>

class Code
{
public:
	std::vector<int> code;
	void UpdateGuess();
	Code();
	~Code();

};

// Asks the user for their input and will try to filter out poor inputs
std::vector<int> GetGuess();

// Does the checking of the guess and gives you your result. 
bool CheckGuess(const std::vector<int>& guess,const std::vector<int>& code);

// Checks if a digit is contained in code
bool ContainedIn(int current, const std::vector<int>& code);
