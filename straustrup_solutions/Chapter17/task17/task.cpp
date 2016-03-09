#include <iostream>
#include <vector>
void print_array10(std::ostream & os, int * ar);
void print_array(std::ostream & os, int * ar, int num);

// Part 10
template<typename T>
void print_vector(std::ostream & os, std::vector<T>& v)
{
	auto it = v.begin();
	while (it != v.end())
	{
		std::cout << *it;
		if (++it == v.end())
			std::cout << '\n';
		else
			std::cout << ',';
	}
}

int main()
{
	/**  Part 1-3 */
	int * par1 = new int[10] {1, 2, 3, 8, 9, 10, 11, 12, 13, 14};

	for (int i = 0; i < 10; ++i)
	{
		std::cout << par1[i];
		if (i != 9)
			std::cout << ',';
		else
			std::cout << '\n';
	}
	delete[] par1;

	int* ar2 = new int[10]{ 100, 101, 102, 103, 104, 105, 106, 107, 108, 109 };
	int* ar3 = new int[11]{ 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110 };

	print_array10(std::cout, ar2);
	delete[] ar2;

	// Part 6
	for (int i = 0; i < 11; ++i)
	{
		std::cout << ar3[i];
		if (i != 10)
			std::cout << ',';
		else
			std::cout << '\n';
	}
	delete[] ar3;

	// Part 7-9
	int* ar4 = new int[20]{ 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119 };
	print_array(std::cout, ar4, 20);
	delete[] ar4;

	std::vector<int> ar5({100,101,102,103,104,105,106,107,108,109});
	std::vector<int> ar6({ 100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119});

	print_vector<int>(std::cout, ar5);
	print_vector<int>(std::cout, ar6);

	// Part 2.1-2.9
	{
		std::cout << std::string(20, '-').c_str() << "Part 2.1-2.09" << std::string(20, '-').c_str() << std::endl;
		int * p1 = new int(7);
		std::cout << "int p1\t=\t" << *p1 << std::endl;
		std::cout << "address p1\t=\t" << (void*)p1 << std::endl;

		int * p2 = new int[7]{ 1,2,4,8,16,32,64 };
		std::cout << "address p2\t=\t" << (void*)p2 << std::endl;
		std::cout << "array p2 \t=\t";
		print_array(std::cout, p2, 7);

		int * p3 = p2;
		p2 = p1;
		p1 = p3;
		std::cout << "address p1\t=\t" << (void*)p1 << std::endl;
		std::cout << "address p2\t=\t" << (void*)p2 << std::endl;
		std::cout << "address p3\t=\t" << (void*)p3 << std::endl;
		std::cout << "address &p3\t=\t" << (void*)&p3 << std::endl;
		std::cout << "int p1\t=\t" << *p1 << std::endl;
		std::cout << "int p2\t=\t" << *p2 << std::endl;
		std::cout << "int p3\t=\t" << *p3 << std::endl;
		delete[] p3;
		delete p2;
	}
	
	/** Part 2.10-2.13 */
	{
		std::cout << std::string(20, '-').c_str() << "Part 2.10-2.13" << std::string(20, '-').c_str() << std::endl;
		int * p1 = new int[10]{ 1,2,4,8,16,32,64,128,256,512 };
		int * p2 = new int[10];
		for (int i = 0; i < 10; ++i)
		{
			p2[i] = p1[i];
		}
		std::cout << "address p1\t=\t" << (void*)p1 << std::endl;
		std::cout << "address p2\t=\t" << (void*)p2 << std::endl;
		std::cout << "array p1 \t=\t";
		print_array(std::cout, p1, 10);
		std::cout << "array p2 \t=\t";
		print_array(std::cout, p2, 10);

		std::vector<int> v1({ 1,2,4,8,16,32,64,128,256,512 });
		std::vector<int> v2 = v1;
		std::cout << "address v1\t=\t" << (void*)&v1 << std::endl;
		std::cout << "address v2\t=\t" << (void*)&v2 << std::endl;
		std::cout << "vector v1 \t=\t";
		print_vector(std::cout, v1);
		std::cout << "vector v2 \t=\t";
		print_vector(std::cout, v2);

	}
	std::cin.get();
}

// Print array10
void print_array10(std::ostream & os, int * ar)
{
	constexpr int num = 10;
	for (int i = 0; i < num; ++i)
	{
		std::cout << ar[i];
		if (i != num-1)
			std::cout << ',';
		else
			std::cout << '\n';
	}
}

void print_array(std::ostream & os, int * ar, int num)
{
	for (int i = 0; i < num; ++i)
	{
		std::cout << ar[i];
		if (i != num - 1)
			std::cout << ',';
		else
			std::cout << '\n';
	}

}


