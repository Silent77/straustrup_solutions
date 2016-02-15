/************************************************************************/
/* Stroustrup Chapter 10. Exercise 1, 11                                */
/* sumint.cpp Calculate sum of integers in file. Ignore other data      */
/************************************************************************/
 
#include "..\std_lib_facilities.h"


int main()
{
	string iname;
	cout << "Enter file name: ";
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs)
		error("Unable to open file ", iname);

	int sum = 0;
	int num;
	while (!ifs.eof())
	{
		ifs >> num;

		if (ifs.fail())
		{
			// try read to next digit
			ifs.clear();
			char ch;
			while (ifs && ifs >> ch)
			{
				if (isdigit(ch) || ch =='-')
				{
					ifs.unget();
					break;
				}
			}
		}
		else
		{
			if (ifs.bad())
				error("File read error!");
			else
				// good
				// Here we got num
				sum += num;
		}
	}

	cout << "sum = " << sum << std::endl;
	keep_window_open();

	return 0;
}