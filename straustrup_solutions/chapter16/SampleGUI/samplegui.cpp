#include "lines_window.h"

int main()
{
	try
	{
		Lines_window win{ Point{ 100 , 100 } , 600 , 400 , "lines " };
		return Graph_lib::gui_main();
	}
	catch (exception& å) 
	{
		cerr << "Exeption : " << å.what() << ' \n ';
		return 1;
	}
	catch (...) {
		cerr << "Other exeption\n";
		return 2;
	}
}