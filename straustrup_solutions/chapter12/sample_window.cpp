#include "Graph.h"
#include "Simple_window.h"

int main()
{
	Point p1(100,100);
	Simple_window win(p1, 800, 600, "Simple window");
	
	win.wait_for_button();
}