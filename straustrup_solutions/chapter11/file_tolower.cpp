#include "..\std_lib_facilities.h"

int main()
{
	cout << "Enter file name:\n";
	string iname;
	cin >> iname;
	ifstream ifs{iname};
	if (!ifs)
		error("Unable to open file ", iname);

	
	string oname;
	cout << "Enter destination file name:\n";
	cin >> oname;
	ofstream ofs{oname};
	if (!ofs)
	{
		error("Unable to open file " + oname + " for writing");
	}

	// copy to output file
	for (char ch; ifs.get(ch);)
		ofs << static_cast<char>(tolower(ch));
	cout << "Done!\n";

	keep_window_open();
}