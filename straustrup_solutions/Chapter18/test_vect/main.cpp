#include <iostream>
#include <vector>

std::vector<int> gv{1,2,4,8,16,32,64,128,256,512,1024};

void f(std::vector<int>&);

int main()
{
	f(gv);
	std::vector<int> vv { 1, 1 * 2, 1 * 2 * 3, 1 * 2 * 3 * 4, 1 * 2 * 3 * 4 * 5, 1 * 2 * 3 * 4 * 5 * 6, 1 * 2 * 3 * 4 * 5 * 6 * 7, 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8,
		1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9, 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 }; 
	f(vv);

	std::cin.get();
}

void f(std::vector<int>& v)
{
	std::vector<int> lv(v);

	std::cout << "Local vector:\n";
	for (auto it = lv.begin(); it != lv.end(); ++it)
	{
		std::cout << *it;
		if (it != lv.end() - 1)
			std::cout << ',';
		else
			std::cout << '\n';
	}

}