/************************************************************************/
/* Stroustrup Chapter 10. Exercise 9.                                   */
/* Concatenate two files with ordered words in third ordered file       */
/************************************************************************/


#include "..\std_lib_facilities.h"

int main()
{
	string iname1;
	string iname2;
	string oname;
	cout << "Enter first file name:";
	cin >> iname1;
	ifstream ifs1{ iname1 };
	if (!ifs1)
		error("Unable to open file ", iname1);

	cout << "Enter second file name:";
	cin >> iname2;
	ifstream ifs2{ iname2 };
	if (!ifs2)
		error("Unable to open file ", iname2);

	cout << "Enter output file name:";
	cin >> oname;
	ofstream ofs{ oname };
	if (!ofs)
		error("Unable to open file ", oname);

	string str1, str2;

	ifs1 >> str1;
	ifs2 >> str2;
	while (ifs1 || ifs2) // while one of stream is good
	{	
		// Compare if both strings not empty
		if (ifs1 && ifs2) 
		{
			if (str1 < str2)
			{
				ofs << str1 << ' ';
				ifs1 >> str1;
			}
			else
			{
				ofs << str2 << ' ';
				ifs2 >> str2;
			}
		} 
		else // some or both stream fail
		{
			if (ifs1)
			{
				ofs << str1 << ' ';
				ifs1 >> str1;
			}
			if (str2 != "")
			{
				ofs << str2 << ' ';
				ifs2 >> str2;
			}
		}
	}
	return 0;
}