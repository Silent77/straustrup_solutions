#include "Graph.h"
#include "Simple_window.h"

int main()
{
	const int ring_size = 300;					// Ring diameter
	const int ring_line_width = ring_size / 8;
	const Point ring_origin { ring_size / 2 + 50, ring_size / 2 + 50 };
	Simple_window win
	{
		Point{ 100,100 },
		ring_size * 3 + ring_size ,
		ring_size * 2  + ring_size,
		"Olympic rings"
	};
	vector<Graph_lib::Color> ring_colors
	{
		Color::cyan,
		Color::black,
		Color::red,
		Color::yellow,
		Color::green
	};

	vector<Graph_lib::Circle*> rings(5);
	
	for (int i = 0; i < 5; ++i)
	{
		int offset_y = ring_origin.y + (i / 3) * ring_size / 2;
		int offset_x = (i / 3) * ring_size / 2;
		if (i < 3)
			rings[i] = new Graph_lib::Circle{ Point{ring_origin.x + offset_x + (ring_size + ring_line_width)*i, offset_y }, ring_size / 2 };
		else
			rings[i] = new Graph_lib::Circle{ Point{ring_origin.x + offset_x + (ring_size + ring_line_width)*(i-3), offset_y }, ring_size / 2 };

		rings[i]->set_color(ring_colors[i]);
		rings[i]->set_style(Line_style{Line_style::solid, ring_line_width});
		win.attach(*rings[i]);
	}


	win.wait_for_button();
}