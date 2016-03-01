#include "lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title) 
	: Graph_lib::Window{ xy, w, h, title },
	next_button{ Point {x_max() - 150, 0 }, 70, 20, "Next point", [](void*, void* pw) {Graph_lib::reference_to<Lines_window>(pw).next();  } },
	quit_button{ Point {x_max() - 70 , 0}, 70, 20, "Quit", [](void*, void* pw) { Graph_lib::reference_to<Lines_window>(pw).quit();  } },	
	next_x{ Point{ x_max() - 310 , 0 } , 50 , 20 , "next x : " } ,
	next_y{ Point{ x_max() - 210 , 0 } , 50 , 20 , "next y: " } ,
	xy_out{ Point{ 100 , 0 } , 100 , 20 , " current (x,y) : " },
	color_menu{ Point {x_max() - 70, 40}, 70, 20, Graph_lib::Menu::vertical, "colors" }
{
	attach(next_button);
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	attach(lines);
	color_menu.attach(new Graph_lib::Button(Point{ 0,0 }, 0, 0, "red", [](void*, void* rw) { Graph_lib::reference_to<Lines_window>(rw).red_pressed(); }));
	color_menu.attach(new Graph_lib::Button(Point{ 0,0 }, 0, 0, "blue", [](void*, void* rw) { Graph_lib::reference_to<Lines_window>(rw).blue_pressed(); }));
	color_menu.attach(new Graph_lib::Button(Point{ 0,0 }, 0, 0, "black", [](void*, void* rw) { Graph_lib::reference_to<Lines_window>(rw).black_pressed(); }));
	attach(color_menu);
}



void Lines_window::next()
{
	int x = next_x.get_int();
	int y = next_y.get_int();
	lines.add(Point{x,y});
	ostringstream ss;
	ss << '(' << x << ',' << y << ')';
	xy_out.put(ss.str());
	redraw();
}

void Lines_window::quit()
{
	hide();	
}
