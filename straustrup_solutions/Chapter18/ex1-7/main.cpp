#include <iostream>
#include <string>

namespace Straustrup
{
	// Length of string
	int strlen(const char *);

	// Duplicate string
	char * strdup(const char * s);
	
	// Find first occurrence x in s. Not use indexing and STD
	// Return nullptr if x is not found
	char * findx(const char * s, const char * x);

	// Compare 2 strings. Return -1 if s1 > s2, 0 if s1 == s2, or 1 if s2 > s1
	int strcmp(const char * s1, const char * s2);

	std::string cat_dot(const std::string & s1, const std::string & s2, const std::string s_cat= ".")
	{
		return s1 + s_cat + s2;
	}

	char * cat_dot(const char *, const char *, const char * s_cat = ".");
}

int main()
{
	const char * s = "Hello, world!";
	std::cout << "Local string:\n";
	std::cout << s << std::endl;

	char * s1 = Straustrup::strdup(s);
	std::cout << "Copied string:\n";
	std::cout << s1 << std::endl;
	delete[] s1;

	const char * sx = "world";
	char * s2 = Straustrup::findx(s, sx);
	if (s2 != nullptr)
	{
		std::cout << "Found substring :\n";
		std::cout << s2 << std::endl;
		delete[] s2;
	}

	const char * s3 = "Hello, world!!";
	const char * s4 = "Cello, world!";
	const char * s5 = "Hello, world!";

	std::cout << "Compare strings:\n";
	switch (Straustrup::strcmp(s, s3))
	{
		case -1:
			std::cout << "The '" << s << "' is greater than '" << s3 << "'\n";
			break;
		case 1:
			std::cout << "The '" << s << "' is smaller than '" << s3 << "'\n";
			break;
		case 0:
			std::cout << "The '" << s << "' is equal '" << s3 << "'\n";
			break;
	}

	switch (Straustrup::strcmp(s, s4))
	{
	case -1:
		std::cout << "The '" << s << "' is greater than '" << s4 << "'\n";
		break;
	case 1:
		std::cout << "The '" << s << "' is smaller than '" << s4 << "'\n";
		break;
	case 0:
		std::cout << "The '" << s << "' is equal '" << s4 << "'\n";
		break;
	}

	switch (Straustrup::strcmp(s, s5))
	{
	case -1:
		std::cout << "The '" << s << "' is greater than '" << s5 << "'\n";
		break;
	case 1:
		std::cout << "The '" << s << "' is smaller than '" << s5 << "'\n";
		break;
	case 0:
		std::cout << "The '" << s << "' is equal '" << s5 << "'\n";
		break;
	}

	std::cout << "Concatenate strings:\n";
	std::cout << Straustrup::cat_dot("Niels", "Bor") << std::endl;
	std::cout << Straustrup::cat_dot("Niels", "Bor",",") << std::endl;

	char * s6 = "Hello";
	char * s7 = "World!";
	char * s8 = Straustrup::cat_dot(s6, s7);
	char * s9 = Straustrup::cat_dot(s6, s7, ", Mighty ");
	std::cout << "Concatenate C-strings:\n";
	std::cout << s8 << std::endl;
	std::cout << s9 << std::endl;
	delete[] s8;
	delete[] s9;

std::cin.get();
	
}

int Straustrup::strlen(const char * str)
{
	int size = 0;
	for (const char * s = str; *s; ++s, ++size); // get size
	return size;
}

// Not using std and indexing
char * Straustrup::strdup(const char * str)
{
	int size = Straustrup::strlen(str);
	
	char * ss = new char[size+1];
	const char * it_str = str;
	for (char * it = ss; it != ss + size + 1; ++it)
	{
		*it = *it_str;	// Copy string
		++it_str;
	};
	//ss[size] = '\0';
	return ss;
}

char * Straustrup::findx(const char * s, const char * x)
{
	bool found;
	for (const char * it = s; *s; ++it)
	{
		found = true;
		const char * it_s = it;
		for (const char * it_x = x; *it_x; ++it_x)
		{
			if ((*it_x != *it_s) || !*it_s)
			{
				found = false;
				break;
			}
			++it_s;
		}
		if (found)
			return strdup(x);
	}
	return nullptr;
}

int Straustrup::strcmp(const char * s1, const char * s2)
{
	const char * it_s1 = s1;
	const char * it_s2 = s2;

	for (; *it_s1 && *it_s2; ++it_s1, ++it_s2)
	{
		if (*it_s1 < *it_s2)
			return 1;
		if (*it_s2 < *it_s1)
			return -1;
	}
	
	// Equal
	if (!*it_s1 && !*it_s2)
		return 0;

	// If one of the strings have chars, than this string is greater
	if (!*it_s1)
		return 1;
	if (!it_s2)
		return -1;	
}

char * Straustrup::cat_dot(const char * s1, const char * s2, const char * s_cat)
{
	int s1_len = Straustrup::strlen(s1);
	int s2_len = Straustrup::strlen(s2);
	int s_cat_len = Straustrup::strlen(s_cat);
	char * s = new char[s1_len + s2_len + s_cat_len + 1];
	char * it_s = s;
	for (const char * it = s1; *it; ++it, ++it_s)
		*it_s = *it;
	for (const char * it = s_cat; *it; ++it, ++it_s)
		*it_s = *it;

	for (const char * it = s2; *it; ++it, ++it_s)
		*it_s = *it;

	*(it_s) = '\0';
	return s;
}