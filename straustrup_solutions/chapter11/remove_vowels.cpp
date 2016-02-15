/***************************************************************************/
/* remove_vowels.cpp by Yaroslav Tarnavskiy, 2016                          */
/* Remove vowels from file                                                 */
/***************************************************************************/


#include "..\std_lib_facilities.h"

bool is_vowel(char ch)
{
	const string vowels = "aeyuio";
	for (auto c : vowels)
	{
		if (c == ch)
			return true;
	}
	return false;
}
int main()
{
	cout << "Enter file name:\n";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs)
		error("Unable to open file ", iname);

	string oname;
	cout << "Enter destination file name:\n";
	cin >> oname;
	ofstream ofs{ oname };
	if (!ofs)
	{
		error("Unable to open file " + oname + " for writing");
	}

	// Read file and output only non vowel characters
	for (char ch; ifs.get(ch);)
		if (!is_vowel(tolower(ch)))
			ofs << ch;

	cout << "Done!\n";

	keep_window_open();
}