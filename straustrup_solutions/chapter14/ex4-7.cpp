#include "gui.h"
#include "../chapter13/graph_add.h"

int main()
{
	Graph_lib::Window win{ Point{ 100,100 }, 800, 600, "Exercises 4-7" };

	Graph_lib::Circle c1(Point{100,100}, 50);
	Graph_lib::Immobile_Circle c2(Point{ 300,100 }, 50);
	c1.move(10, 10);

	Graph_lib::Striped_Rectangle rect1(Point{ 100, 200 }, Point{400,500});
	rect1.set_fill_color(Graph_lib::Color::blue);
	win.attach(rect1);

	win.attach(c1);
	win.attach(c2);

	Graph_lib::Striped_Circle c3(Point{ 500,300 }, 150);
	c3.set_fill_color(Graph_lib::Color::yellow);
	win.attach(c3);

	Graph_lib::gui_main();

}

