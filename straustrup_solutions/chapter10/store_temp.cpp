#include "temps.h"
#include "../common/std_lib_facilities.h"

int main()
{
	const string oname = "raw_temps.txt";
	ofstream ofs{ oname };
	if (!ofs)
		error("Unable open file for output ", oname);

	vector<Reading> raw_temps;
	cout << "Enter temp data: <day> <hour> <temp> or any char to stop:\n";
	Reading r;
	while (cin >> r.day >> r.hour >> r.temperature)
	{
		raw_temps.push_back(r);
		cout << "Enter next data\n";
	}
	std::cout << "You have enter " << raw_temps.size() << " records.\n";

	for (Reading & r : raw_temps)
		ofs << r.day << ' ' << r.hour << ' ' << r.temperature << std::endl;
	return 0;
}