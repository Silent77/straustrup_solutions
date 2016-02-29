#include "chapter15\person.h"

Person::Person(int age_, std::string firstname_, std::string lastname_)
:age{ age_ }, firstname{ firstname_ }, lastname{lastname_}
{
	if (age < 0 || age > 150)
		error("Age must be in (0, 150) scope");

	for (char ch : bad_chars)
		for (char str_ch : getName())
			if (ch == str_ch)
				error("Name contains incorrect char");
}


Person::Person(const Person & p):
	firstname{ p.firstname }, lastname{p.lastname}, age {p.age}
{
	if (age < 0 || age > 150)
		error("Age must be in (0, 150) scope");

	for (char ch : bad_chars)
		for (char str_ch : getName())
			if (ch == str_ch)
				error("Name contains incorrect char");
}

Person & Person::operator=(const Person & p)
{
	if (&p == this)
		return *this;

	age = p.age;
	firstname = p.firstname;
	lastname = p.lastname;
	return *this;
}

std::ostream & operator<<(std::ostream & ost, const Person & p) 
{
	ost << p.getName() << ", age " << p.age << std::endl;
	return ost;
}

std::istream & operator>>(std::istream & ist, Person & p)
{
	Person p_temp;
	if (!(ist >> p_temp.firstname >> p_temp.lastname >> p_temp.age))
		return ist;								// failed input

	// good input
	p = p_temp;		// Correct input also checked by copy ctor
	return ist;
}
