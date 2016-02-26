#include "Graph.h"
#include "Simple_window.h"

int main()
{
	Point p1(100, 100);
	Simple_window win(p1, 600, 400, "My window");

	Graph_lib::Polygon poly;
	poly.add(Point(100, 100));
	poly.add(Point(200, 100));
	poly.add(Point(200, 150));
	poly.add(Point(100, 150));

	win.attach(poly);
	poly.set_color(Color::red);

	Graph_lib::Rectangle rect(Point{100, 250}, 100, 50);
	rect.set_color(Color::blue);
	win.attach(rect);

	Text t(Point(130,280), "Howdy!");
	win.attach(t);

	Text yt1(Point(300, 300), "Y");
	yt1.set_font_size(150);
	yt1.set_color(Color::dark_green);
	yt1.set_style({ Line_style::solid, 5 });
	win.attach(yt1);

	Text yt2(Point(400, 300), "T");
	yt2.set_font_size(150);
	yt2.set_color(Color::dark_cyan);
	yt2.set_style({ Line_style::solid, 5 });
	win.attach(yt2);

	win.wait_for_button();
}