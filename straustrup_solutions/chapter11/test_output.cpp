#include "std_lib_facilities.h"

struct phonebook_record
{
	string firstName;
	string lastName;
	string phone;
	string email;
};

int main()
{
	unsigned birth_year = 1977;
	cout << "Dec\tHex\tOcd\n";
	cout << showbase << birth_year << '\t' << hex << birth_year << '\t' << oct << birth_year << endl;

	cout << dec << "My age is " << 2016 - birth_year << endl;

	/*
	int a, b, c, d;
	cin >> a >> oct >> b >> hex >> c >> d;
	cout << a << '\t' << b << '\t' << c << '\t' << d << endl;
	*/

	const double a = 1234567.89;
	std::cout << defaultfloat << "default float:\t" << a << endl;
	std::cout << fixed << "fixed:\t" << a << endl;
	std::cout << scientific << "scientific:\t" << a << endl;

	

	vector<phonebook_record> phonebook =
	{
		{"Diana", "Tarnavskaya", "067-565-33-33", "Diana_tarn@mail.ru"},
		{"Yaroslav", "Tarnavskiy", "097-566-44-22", "yaroslav.tarnavskiy@incom.ua"}
	};

	cout << "Phone book:\n";

	cout << setw(10) << "First Name" << setw(16) << "Last Name" << setw(16) << "Phone" << setw(32) << "E-mail" << endl;
	for (auto &record : phonebook)
	{
		cout << setw(10) << record.firstName << setw(16) << record.lastName << setw(16) << record.phone << setw(32) << record.email << endl;
	}
	keep_window_open();
}