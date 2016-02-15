#include "stdafx.h"
#include <iostream>

const double MIN_C_TEMP = -273.15;

double ctok(double c)
{
	double k = c - MIN_C_TEMP;
	if (k < 0)
		std::cout << "Error! The temperature cannot be less than absolute zero.";
	return k;
}

// Print first count_numbers of Fibbonacci sequence. If count_numbers == 0, print all numbers that are in <int> range 
void print_fibonacci( int count_numbers);


int main()
{
	int num;
	std::cout << "Enter number of Fibbonacci numbers:";
	std::cin >> num;
	
	print_fibonacci(num);

	while (std::cin.get() == '\n') 
		continue;
	std::cin.get();
}

void print_fibonacci( int count_numbers)
{
	int first_num = 1;
	int second_num = 1;
	int numF = 0;
	for (int i = 2; i < count_numbers; ++i)
	{
		numF = first_num + second_num;
		if (numF <= 0)
			break;
		first_num = second_num;
		second_num = numF;
		std::cout << numF << " ";
	}
}