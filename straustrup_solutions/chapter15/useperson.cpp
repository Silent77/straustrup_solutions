#include "person.h"
#include <vector>

int main()
{
	vector<Person> persons;
	std::cout << "Enter persons data as - firstname lastname age :\n";

	for (Person p; std::cin >> p;)
	{
		if (p.getAge() > 150 || p.getAge() < 0)
			error("Incorrect age");
		persons.push_back(p);
	}

	std::cout << "You have enter data for persons:\n";
	for (auto p : persons)
		std::cout << p << std::endl;

	keep_window_open();
	return 0;
}