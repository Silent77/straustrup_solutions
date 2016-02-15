#include "temps.h"

int main()
{
	cout << "Enter input file name:";
	string iname;
	cin >> iname;
	ifstream ist{ iname };
	if (!ist)
		error("Unable to open input file ", iname);

	// generate exception on bad file
	ist.exceptions(ist.exceptions() | ios_base::badbit);

	cout << "Enter output file name:";
	string oname;
	cin >> oname;
	ofstream ofs{ oname };
	if (!ofs)
		error("Unable to open output file ", oname);

	vector<Year> ys;
	while (true)
	{
		Year y;
		if (!(ist >> y))
			break;
		ys.push_back(y);
	}
	cout << "Read " << ys.size() << " year records.\n";

	for (Year& y : ys)
	{
		print_year(ofs, y);
		print_year(cout, y);
	}
	keep_window_open();
}