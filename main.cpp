#include "game_calls.h"
#include <iostream>

int main()
{
	Code toGuess;
	toGuess.UpdateGuess();
	std::vector<int> guess;
	std::cout << "Enter a guess of the form, xxxx, where x is [0-9]:\n";
	
	do
	{
		guess = GetGuess();
	} while (!CheckGuess(guess, toGuess.code));
	return 0;
}