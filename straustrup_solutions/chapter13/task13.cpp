#include "Graph.h"
#include "Simple_window.h"


int main()
{
	Simple_window win(Point{ 10,10 }, 800, 1000, "Chapter 13 task");

	Lines grid;
	for (int i = 0; i <= 800; i += 100)
	{
		grid.add(Point(0, i), Point(800, i));
		grid.add(Point(i, 0), Point(i, 800));
	}
	win.attach(grid);

	Vector_ref<Graph_lib::Rectangle> diag_rects;
	for (int i = 0; i < 800; i+=100)
	{
		diag_rects.push_back(new Graph_lib::Rectangle{ Point(i,i),101, 101 });
		diag_rects[diag_rects.size() - 1].set_fill_color(Color::red);
		win.attach(diag_rects[diag_rects.size() - 1]);
	};
	Image im1{ Point{200,0}, "f35.jpg" };
	win.attach(im1);
	Image im2{ Point{ 500,200 }, "f35.jpg" };
	win.attach(im2);
	Image im3{ Point{ 0,300 }, "f35.jpg" };
	win.attach(im3);

	Image im{ Point{0,0}, "f35.jpg" };
	im.set_mask(Point{50,50}, 100, 100);
	win.attach(im);
	win.put_on_top(im);

	while (true)
	{
		win.wait_for_button();
		int dx = randint(-1, 1) * 100;
		if ( (im.point(0).x + dx) < 0 || (im.point(0).x + dx) >= 800 )
			dx = -dx;
		int dy = randint(-1, 1) * 100;
		if ((im.point(0).y + dy) < 0 || (im.point(0).y + dy) >= 800)
			dy = -dy;

		im.move(dx, dy);
	}
}