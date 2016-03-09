#include <iostream>
#include <string>

void testMemLocation(int fst, double scnd);

int main()
{
	testMemLocation(0,0.);

	std::cin.get();
	return 0;
}

void testMemLocation(int fst, double scnd)
{
	int * pInt = new int{5};
	double * pDbl = new double{3.1415};

	std::cout << "Check the stack and heap memory location:\n";
	std::cout << std::string( 20,'=' ) << " Stack " << std::string( 20,'=' ) << std::endl;
	std::cout << "1st (int)\t" << (void*)&fst << "\n";
	std::cout << "2nd (double)\t" << (void*)&scnd << "\n";
	std::cout << std::string( 20,'=' ) << " Heap " << std::string( 20,'=' ) << std::endl;
	std::cout << "1st (int)\t" << (void*)pInt << "\n";
	std::cout << "2nd (double)\t" << (void*)pDbl << "\n";

}
