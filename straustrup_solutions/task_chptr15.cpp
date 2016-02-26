#include "Simple_window.h"
#include "Graph.h"
#include "GUI.h"
#include <sstream>

// Convert Local to Window coordinate for axis according scale 
struct Scale
{
	Scale(int width_, double value_min_, double value_max_) :
		width(width_), value_min(value_min_), value_max(value_max_) {};
	int operator() (double v) const
	{
		return static_cast<int>(  (v - value_min) * width / (value_max - value_min) );
	}
private:
	double value_min;
	double value_max;
	int width;
};



int main()
{
	Simple_window win { Point{100,100}, 600, 600, "Functions graphs" };

	constexpr double min_value = -10;
	constexpr double max_value = 11;
	constexpr int xsize = 400;
	constexpr int ysize = 400;
	constexpr int xnotches = 20;
	constexpr int ynotches = 20;
	constexpr int xstep = (max_value - min_value)  / xnotches;
	constexpr int ystep = (max_value - min_value)  / ynotches;

	std::ostringstream ss;
	ss << "| == " << xstep << " value";
	Graph_lib::Axis axisx(Graph_lib::Axis::x, Point{int(300 - xsize * 0.5), 300}, xsize, xnotches, ss.str());
	Graph_lib::Axis axisy(Graph_lib::Axis::y, Point{300, int(300 + ysize * 0.5) }, ysize, ynotches, ss.str());
	axisx.set_color(Graph_lib::Color::red);
	axisy.set_color(Graph_lib::Color::red);
	win.attach(axisx);
	win.attach(axisy);

	Scale scalex(300, -10,11);
	Scale scaley(300, -10, 11);

	Graph_lib::Function fn1([](double v) { return v /2.; }, min_value, max_value, Point{300, 300}, 400, 20, 20);
	Graph_lib::Function fn2([](double v) { return 2.; }, -10, 11, Point{ 300, 300 }, 400, 20, 20);
	Graph_lib::Function fn3([](double v) { return v*v; }, -10, 11, Point{ 300, 300 }, 400, 20, 20);
	Graph_lib::Function fn4([](double v) { return v / 2. + cos(v); }, -10, 11, Point{ 300, 300 }, 400, 20, 20);
	Graph_lib::Function fn5(cos, -10, 11, Point{ 300, 300 }, 400, 20, 20);
	Graph_lib::Text fn2_label(Point{150,520}, "x/2");
	win.attach(fn4);
	fn4.set_color(Graph_lib::Color::blue);
	win.attach(fn5);
	fn5.set_color(Graph_lib::Color::green);

	win.attach(fn2);
	win.attach(fn3);
	win.attach(fn2_label);

	Graph_lib::gui_main();
}