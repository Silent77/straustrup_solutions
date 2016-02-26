#include "Name_pairs.h"
#include <iostream>
#include "std_lib_facilities.h"

int main()
{
	Name_pairs names;
	try
	{
		names.read_names();
		names.read_ages();
		std::cout << "Names and ages unordered:\n";
		cout << names;
		names.sort();
		std::cout << "Names and ages sorted by name:\n";
		cout << names;
	}
	catch (exception &e)
	{
		cout << "error: " << e.what() << std::endl;
		keep_window_open();
		return 1;
	}
	catch (...)
	{
		cout << "Unknown exeption!\n";
		keep_window_open();
		return 2;
	}

	keep_window_open();
	return 0;
}