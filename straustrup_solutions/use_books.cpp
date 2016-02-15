#include "Book.h"
#include "std_lib_facilities.h"

int main()
{
	Book myBook;
	myBook.getBookData();
	std::cout << myBook;

	keep_window_open();
	return 0;

}