#include "std_lib_facilities.h"

int main(int argc, char ** argv)
{
	string iname;
	cout << "Enter file name:";
	cin >> iname;
	ifstream ifs{iname};
	if (!ifs)
		error("Unable to open file ", iname);

	string oname;
	cout << "Enter file name for saving:";
	cin >> oname;

	ofstream ofs{ oname, ios_base::binary };
	if (!ofs)
		error("Unable to open file " + oname + " for writing.");

	string s;
	int win_eol = 0x0a0d;
	while (ifs && getline(ifs, s))
	{
		ofs.write(s.c_str(), s.size()) ;
		ofs.write(as_bytes(win_eol), 2);
	}
	return 0;
}