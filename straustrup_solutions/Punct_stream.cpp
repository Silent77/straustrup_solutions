#include "stdafx.h"
#include "Punct_stream.h"


bool Punct_stream::is_whitespace(char c)
{
	for (char ch : white)
		if (c == ch)
			return true;

	return false;
}

Punct_stream & Punct_stream::operator>>(string & s)
{
	while (!(buffer >> s))
	{
		if (buffer.bad() || !source.good())
			return *this;
		buffer.clear();

		string line;
		getline(source, line);

		for (char& ch : line)
			if (is_whitespace(ch))
				ch = ' ';
			else if (!sensitive)
				ch = tolower(ch);

		buffer.str(line);
	}
	return *this;
}

Punct_stream::operator bool()
{
	return !(source.bad() || source.fail()) && source.good();
}

Punct_stream::~Punct_stream()
{
}


