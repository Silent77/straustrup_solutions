/***************************************************************************/
/* search_word.cpp by Yaroslav Tarnavskiy, 2016                            */
/* Search file for word and print line and position where the word is found*/
/***************************************************************************/

#include "std_lib_facilities.h"

int main()
{
	string iname;
	cout << "Enter file name for search:\n";
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs)
		error("Unable to open file ", iname);

	cout << "Enter search word\n";
	string sword;
	cin >> sword;
	int str_no = 0;
	while (ifs)
	{
		++str_no;
		string str;
		getline(ifs, str);
		int pos = 0;
		while (pos >= 0)
		{
			pos = str.find(sword, pos+1);
			if (pos >=0)
				cout << "line " << str_no << '\t' << "'" << sword << "'" << " found at " << pos << " position" << endl;
		};
	}
	keep_window_open();
	return 0;
}