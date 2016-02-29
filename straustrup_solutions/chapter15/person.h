#pragma once

#include <string>
#include "../common/std_lib_facilities.h"
#include <iostream>

class Person
{
public:
	Person(int age_ = 0, std::string firstname_ = "", std::string lastname_ = "");
	Person(const Person& p);
	Person & operator=(const Person &p);
	int getAge() const { return age; };
	std::string getName() const { return firstname + ' ' + lastname; };
	friend std::ostream & operator<<(std::ostream & ost, const Person & p);
	friend std::istream & operator>>(std::istream & ist, Person & p);
private:
	const std::string bad_chars = ";:\"'{}[]@-+^$!~`#%";
	int age;
	std::string firstname;
	std::string lastname;
};