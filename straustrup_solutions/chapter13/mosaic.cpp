#include "Graph.h"
#include "Simple_window.h"
#include "Graph_add.h"
#include <sstream>

int main()
{
	constexpr int width = 800;
	constexpr int height = 600;
	Simple_window win{ Point{ 100, 100 }, width, height, "Chapter 13. Exercise 16-17. Mosaic" };

	constexpr double radius = 10;
	
	Vector_ref<Regular_Polygon> mosaic;
	Point start = { 120, 120};
	Point end = {width - 150, height - 150};

	int x = start.x;
	int y = start.y;
	int row_num = 1;
	while (y <= end.y + radius * 0.5 * sqrt(3))
	{
		while (x <= end.x + radius)
		{
			mosaic.push_back(new Regular_Polygon(Point{ x, y }, 6, radius));
			x += 3 * radius;
		}
		if (row_num % 2)
			x = start.x + 1.5 * radius;
		else
			x = start.x;
		y += radius * 0.5 * sqrt(3);
		++row_num;
	}

	for (int i = 0; i < mosaic.size(); ++i)
	{
		mosaic[i].set_fill_color(randint(255));
		win.attach(mosaic[i]);
	}

	Graph_lib::Rectangle rect{start, end};
	rect.set_style( Line_style{ Line_style::dot, 4} );
	rect.set_color( Color::dark_magenta );
	win.attach(rect);
	std::ostringstream ss;
	ss << "Tiles = " << mosaic.size();
	Text t{ Point {10, 20}, ss.str()};
	t.set_color(Color::black);
	win.attach(t);
	win.put_on_top(t);

	win.wait_for_button();
}