#include "chapter15\person.h"

Person::Person(int age_, string name_)
	:age{ age_ }, name{name_}
{
	if (age < 0 || age > 150)
		error("Age must be in (0, 150) scope");

	for (char ch : bad_chars)
		for (char str_ch : name)
			if (ch == str_ch)
				error("Name contains incorrect char");
}
