#pragma once
#include "std_lib_facilities.h"

void end_of_loop(istream & ist, char term, const string & message)
{
	if (ist.fail())
	{
		ist.clear();
		char ch;
		if (ist >> ch && ch == term)
			return;
		error(message);
	}
}