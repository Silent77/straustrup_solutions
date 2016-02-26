#include "std_lib_facilities.h"

int main()
{
	int num;

	cout << "Enter numbers:\n";

	cin.setf(ios::hex);
	while ((cin >> num))
		cout << dec << "Decimal: " << num << endl;

	keep_window_open();
	return 0;
}