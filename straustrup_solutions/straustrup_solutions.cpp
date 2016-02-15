// straustrup_solutions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

// Find and print the mode (maximal sequence of equal numbers) of int numbers sequence
void find_int_mode();


int _tmain(int argc, _TCHAR* argv[])
{
	find_int_mode();
	
	while (std::cin.get() == '\n')
		continue;
	std::cin.get();
	return 0;
}

void find_int_mode()
{
	

	int mod_value = 0, max_length = 0, prev_value = -1, mod_length = 0;
	int n;
	
	std::cout << "Enter int number (or break):\n";
	// initial iteration
	std::cin >> n;
	mod_value = n;
	mod_length = 1;
	prev_value = n;
	
	while (std::cin >> n)
	{
		if (n == prev_value)
		{
			++mod_length;
			if (mod_length > max_length)
			{
				max_length = mod_length;
				mod_value = prev_value;
			}
		}
		// The value was changed
		else
		{
			mod_length = 1;
			
		}
		prev_value = n;
	}

	std::cout << "The mode is : " << mod_value << std::endl;
}