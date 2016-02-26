#pragma once

#include <string>
#include "../common/std_lib_facilities.h"
#include <iostream>

class Person
{
public:
	Person(int age_, string name_);
	friend std::ostream & operator<<()

private:
	const std::string bad_chars = ";:\"'{}[]@-+^$!~`#%";
	int age;
	std::string name;
};