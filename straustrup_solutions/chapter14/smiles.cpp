#include "Graph.h"
#include "Simple_window.h"
#include "../chapter13/graph_add.h"

int main()
{
	Simple_window win(Point{ 100,100 }, 800, 600, "Smiles");
	
	Smiley smile1(Point{ 200, 200 }, 80);
	smile1.set_color(Color::blue);
	smile1.set_fill_color(Color::yellow);
	smile1.set_style(Line_style{Line_style::solid, 4});
	win.attach(smile1);

	Frowny smile2(Point{ 400, 200 }, 80);
	smile2.set_color(Color::dark_blue);
	smile2.set_fill_color(Color::dark_yellow);
	smile2.set_style(Line_style{ Line_style::solid, 4 });
	win.attach(smile2);

	SmileyHat smile3(Point{ 200, 500 }, 80);
	smile3.set_color(Color::blue);
	smile3.set_fill_color(Color::yellow);
	smile3.set_style(Line_style{ Line_style::solid, 4 });
	win.attach(smile3);

	win.wait_for_button();
}
