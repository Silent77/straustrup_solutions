#include "Graph.h"
#include "Simple_window.h"

int main()
{
	Point p1(100, 100);
	Simple_window win(p1, 600, 400, "My window");

	Axis xa(Axis::x, Point(20, 300), 280, 10, "x axis");
	win.attach(xa);

	Axis ya(Axis::y, Point(20, 300), 280, 10, "y axis");
	win.attach(ya);

	xa.set_color(Color::dark_cyan);
	ya.set_color(Color::dark_green);

	Function sine(cos, 0, 100, Point(20, 150), 1000, 50, 50);
	sine.set_color(Color::red);
	win.attach(sine);

	Graph_lib::Polygon poly;
	poly.add(Point(300, 200));
	poly.add(Point(350, 100));
	poly.add(Point(450, 150));
	poly.add(Point(400, 200));

	poly.set_fill_color(Color::yellow);
	poly.set_style(Line_style{ Line_style::dash , 4 });
	win.attach(poly);

	Graph_lib::Rectangle r{ Point(200,200), 100, 50 };
	win.attach(r);
	r.set_fill_color(Color::dark_green);

	Text t(Point(150, 32), "Hello, graphics world!");
	t.set_font(Font::helvetica_bold);
	t.set_font_size(22);
	win.attach(t);


	Image pic1(Point(100, 50), "chapter12/logo.gif");
	pic1.set_mask(Point{ 0,0 }, 300, 80);

	win.attach(pic1);
	pic1.move(100, 100);
	

	win.wait_for_button();
}