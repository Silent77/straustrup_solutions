#include "Graph.h"
#include "Simple_window.h"

int main()
{
	

	const int cell_size = 100;
	const int cells_hor_count = 8;
	const int cells_vert_count = 8;
	const Point cells_origin = Point{10, 10};

	Simple_window win
	{ 
		Point{ 100,100 }, 
		cells_hor_count * cell_size + 2 * cells_origin.x, 
		cells_vert_count * cell_size + 2 * cells_origin.y, 
		"Chess" 
	};

	vector<Graph_lib::Rectangle*> cells(cells_hor_count * cells_vert_count);
	for (int i = 0; i < cells_hor_count; ++i)
		for (int j = 0; j < cells_vert_count; ++j)
		{
			cells[i*j] = new Graph_lib::Rectangle(Point{ cells_origin.x + cell_size * i, cells_origin.y + cell_size * j }, cell_size, cell_size);
			if ((i+j)%2)
				cells[i*j]->set_fill_color(Color::black);
			else
				cells[i*j]->set_fill_color(Color::white);
			win.attach(*cells[i*j]);
		}


	win.wait_for_button();
}