#include <iostream>

void exercise7(char stopChar);
void exercise8(char);
void exercise10(char);

int main()
{
	try
	{
		exercise7('!');
		exercise8('!');

		exercise10('#');
	}
	catch (std::out_of_range& e_range)
	{
		std::cout << "Range error: " << e_range.what();
	}
	catch (...)
	{
		std::cout << "Other error";
	}
	
	std::cin.get();
	return 0;
}

void exercise7(char stopChar)
{
	char* chars = new char[256] {};
	std::cout << "Exercise 7. Enter chars. [" << stopChar << "] - stop\n";
	int i = 0;
	for (char ch; std::cin >> ch && ch != stopChar; ++i)
	{
		chars[i] = ch;
	}
	
	std::cout << "You have entered " << i << " chars:\n";
	for (int i = 0; chars[i]; ++i)
		std::cout << chars[i];
	std::cout << std::endl;

	delete[] chars;
}

void exercise8(char stopChar)
{
	std::string chars;

	std::cout << "Exercise 8. Enter chars. [" << stopChar << "] - stop\n";
	int i = 0;
	for (char ch; std::cin >> ch && ch != stopChar; ++i)
	{
		chars.push_back(ch);
	}

	std::cout << "You have entered " << i << " chars:\n";
	for (int i = 0; i < chars.size(); ++i)
		std::cout << chars[i];
	std::cout << std::endl;
}

void exercise10(char stopChar)
{
	constexpr int maxChars = 8;
	char* chars = new char[maxChars]{};
	std::cout << "Exercise 10. Enter chars. [" << stopChar << "] - stop\n";
	int i = 0;
	for (char ch; std::cin >> ch && ch != stopChar; ++i)
	{
		if (i >= maxChars)
			throw(std::out_of_range("Number of entered char exceeds limit."));
		chars[i] = ch;
	}

	std::cout << "You have entered " << i << " chars:\n";
	for (int i = 0; chars[i]; ++i)
		std::cout << chars[i];
	std::cout << std::endl;

	delete[] chars;

}