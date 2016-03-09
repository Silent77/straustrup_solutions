#include <iostream>

void sizes();

class A
{
public:
	A() { std::cout << "A()"; }
	virtual ~A() { std::cout << "~A()"; }
};

class B : public A
{
public:
	B() { std::cout << "B()"; }
	~B() { std::cout << "~B()"; }
};

int main()
{
	sizes();

	{
		A* pB = new B;
		delete pB;
	}
	std::cin.get();
	return 0;
}


void sizes()
{
	bool bIs = false;
	int vi = 0;
	char ch = 0;
	double dbl = 0;
	float fl = 0;
	char * pch = &ch;
	double * pdbl = &dbl;
	std::cout << "Sizes of integrated types:\n";
	std::cout << "sizeof int = " << '\t' << sizeof(vi) << '\t' << &vi << std::endl;
	std::cout << "sizeof bool = " << '\t' << sizeof(bIs) << '\t' << &bIs << std::endl;
	std::cout << "sizeof char = " << '\t' << sizeof(ch) << '\t' << &ch << std::endl;
	std::cout << "sizeof float = " << '\t' << sizeof(fl) << '\t' << &fl << std::endl;
	std::cout << "sizeof double = " << '\t' << sizeof(dbl) << '\t' << &dbl << std::endl;
	std::cout << "sizeof char* = " << '\t' << sizeof(pch) << '\t' << &pch << std::endl;
	std::cout << "sizeof double* = " << '\t'<< sizeof(pdbl) << '\t' << &pdbl << std::endl;
}