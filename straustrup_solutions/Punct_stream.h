#pragma once

#include "common/std_lib_facilities.h"

class Punct_stream
{
public:
	Punct_stream(istream & is)
		: source(is), sensitive(true) {};
	void whitespace(const string & s) 
		{ white = s; };
	void add_white(char c) 
		{ white += c; };
	bool is_whitespace(char c);
	void case_sensetive(bool b) 
		{ sensitive = b; };
	bool is_case_sensetive() 
		{ return sensitive; };
	Punct_stream & operator >> (string & s);
	operator bool();
	~Punct_stream();
private:
	bool sensitive;
	istream & source;
	istringstream buffer;
	string white;				// whitespaces
};

