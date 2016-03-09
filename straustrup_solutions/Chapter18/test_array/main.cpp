#include <iostream>

int ga[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(int[], int);

int main()
{
	f(ga, 10);
	int aa[10]{1, 1*2, 1*2*3, 1*2*3*4, 1*2*3*4*5, 1*2*3*4*5*6, 1 * 2 * 3 * 4 * 5 * 6 * 7, 1 * 2 * 3 * 4 * 5 * 6 * 7* 8,
		1 * 2 * 3 * 4 * 5 * 6 *7 *8 * 9, 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10};
	f(aa, 10);

	std::cin.get();
}

void f(int ar[], int n)
{
	int la[10];
	for (int i = 0; i < 10; ++i)
		la[i] = ga[i];


	std::cout << "Local array:\n";
	for (int i = 0; i < 10; ++i)
	{
		std::cout << la[i];
		if (i < 9)
			std::cout << ',';
	}
	std::cout << "\n";

	int * p = new int[n];
	for (int i = 0; i < n; ++i)
	{
		p[i] = ar[i];
	}

	std::cout << "Dynamic array:\n";
	for (int i = 0; i < 10; ++i)
	{
		std::cout << p[i];
		if (i < 9)
			std::cout << ',';
	}
	std::cout << "\n";
	delete[] p;
}