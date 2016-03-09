#include "Graph.h"
#include "Simple_window.h"
#include "Graph_add.h"

int main()
{
	Simple_window win{ Point{100, 100} ,800, 600, "Exercise 1. Arc" };

	
	Graph_lib::Arc arc(Point{ 200,100 }, 100, 60);
	win.attach(arc);

	Graph_lib::Arc arc1(Point{ 150,300 }, 100, 300, 40, 220);
	arc1.set_color(Color::red);
	win.attach(arc1);

	Graph_lib::Arc arc2(Point{ 400,200 }, 100, 100,180, 320);
	win.attach(arc2);
	arc2.set_color(Color::dark_green);
	
	Arrow ar1(Point{ 50,50 }, Point{300,50}, 50, 15);
	Arrow ar2(Point{ 450,80 }, Point{ 10,90 }, 50);

	Arrow ar3(Point{ 50,300 }, Point{ 700,100 }, 50);
	Arrow ar4(Point{ 750,150 }, Point{ 100,550 } , 20, 15, true);
	ar4.set_color(Color::red);

	Arrow ar5(Point{ 400, 20 }, Point{ 520, 390 }, 60, 60, true);
	ar5.set_style(Line_style{ Line_style::dot, 4 });
	ar5.set_color(Color::dark_green);
	
	win.attach(ar1);
	win.attach(ar2);
	win.attach(ar3);
	win.attach(ar4);
	win.attach(ar5);

	Regular_Polygon poly1(Point{200,200}, 12, 180);
	poly1.set_fill_color(Color::cyan);
	win.attach(poly1);

	win.wait_for_button();
}