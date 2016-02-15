#include "Name_pairs.h"
#include "..\std_lib_facilities.h"


Name_pairs::Name_pairs() : name{}, age{}
{
}


Name_pairs::~Name_pairs()
{
}

/** Quick sort by name and according age*/
void Name_pairs::sort()
{
	quick_sort(0, name.size() - 1);
	// Implement non STL quicksort for vector<string>
}

void Name_pairs::read_names()
{
	const string exitString = "quit";
	cout << "Enter name or type '" << exitString << "' to stop:\n";
	string newName;
	while (cin >> newName && newName != "" && newName != exitString)
	{
		name.push_back(newName);
		cout << '\'' << newName + "' was added. Enter new name or '" << exitString << "' to stop.\n";
	}
	cout << "You have added " << name.size() << " names.\n";
}

void Name_pairs::read_ages()
{
	cout << "Enter ages for " << name.size() << " names\n";
	int newAge;
	int i = 0;
	while (i < name.size())
	{
		cout << "Enter age for '" << name[i] << "'\n";
		cin >> newAge;
		if (!cin || newAge < 0 || newAge > 150)
		{
			cout << "Please enter correct age.\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			++i;
			age.push_back(newAge);
		}
	}
}

int Name_pairs::partition(int p, int r)
{
	string s = name[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; ++j)
	{
		if (name[j] <= s)
		{
			++i;
			swap(name[i], name[j]);
			swap(age[i], age[j]);
		}
	}
	swap(name[r], name[i + 1]);
	swap(age[r], age[i + 1]);
	return i + 1;
}

void Name_pairs::quick_sort(int p, int r)
{
	int q;
	if (p < r)
	{
		q = partition(p, r);
		quick_sort(p, q - 1);
		quick_sort(q, r);
	}
}

std::ostream & operator<<(std::ostream & outs, Name_pairs & namePairs)
{
	for (int i = 0; i < namePairs.name.size(); ++i)
		outs << '(' << namePairs.name[i] << ',' << namePairs.age[i] << ')' << std::endl;

	return outs;
}
