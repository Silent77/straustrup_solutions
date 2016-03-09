#include <iostream>
#include <stdexcept>

struct Buffer
{
	char buf[1024 * 1024];
};

int main()
{
	try
	{
		for (int i = 0; i < 4096; ++i)
		{
			Buffer * myBuf = new Buffer;
			std::cout << "Allocated " << i << "MB\n";
		}
	}
	catch (std::bad_alloc & e)
	{
		std::cerr << "Unable to allocate memory!\n";
		std::cerr << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}

	return 0;
}
