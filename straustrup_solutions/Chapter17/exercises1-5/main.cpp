#include <iostream>

void to_lower(char * s);
char * strdup(char * st1);

int main()
{
	char str1[] = "Hello World!!!! And welCome TO THE magiC :))\0";

	std::cout << str1 << std::endl;
	to_lower(str1);
	std::cout << str1 << std::endl;

	char str2[] = "Hello!\0";
	char * str3 = strdup(str2);
	std::cout << "str2\t=\t" << str2 << std::endl;
	std::cout << "str3\t=\t" << str3 << std::endl;
	std::cout << " address str2\t=\t" << (void*)str2 << std::endl;
	std::cout << " address str3\t=\t" << (void*)str3 << std::endl;

	std::cin.get();
}


void to_lower(char * s)
{
	const char first_capital = 'A';
	const char last_capital = 'Z';
	const char first_small = 'a';
	char * s1 = s;
	while (*s1)
	{
		if ((*s1 >= first_capital) && (*s1 <= last_capital))
			*s1 = *s1 - first_capital + first_small;
		++s1;
	}
}

char * strdup(char * s)
{
	int size = 0;
	char * s1 = s;
	while (*s1)
	{
		++size;
		++s1;
	}
	char * s_dup = new char[size+1];
	char * s1_dup = s_dup;
	// copy string
	while (*s)
		*(s1_dup++) = *(s++);

	*s1_dup = '\0';

	return s_dup;
}
