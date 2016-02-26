#include "Graph.h"
#include "Simple_window.h"
#include <cmath>

int sign(double x);

int main()
{
	const double a = 350.;					
	const double b = 350.;
	const double n = 3.;
	const double m = 3.;
	const int canvas_width = 800;
	const int canvas_height = 800;
	const int total_points = 50;
	const double PI = 3.1415926535;
	Simple_window win
	{
		Point{ 100,100 },
		canvas_width ,
		canvas_height,
		"Superellipse"
	};

	Graph_lib::Closed_polyline superellipse;
	for (int i = 1; i <= total_points; ++i)
	{
		double theta = i  * 2 * PI / (total_points);
		double x = pow(abs(cos(theta)), 2.0 / m) * a * sign(cos(theta));
		double y = pow(abs(sin(theta)), 2.0 / n) * b * sign(sin(theta));
		superellipse.add(Point{static_cast<int>(canvas_width/2.0 + x),static_cast<int>(canvas_height / 2.0 + y)});
	}
	superellipse.set_style(Line_style{ Line_style::solid, 4 });
	superellipse.set_color(Color::dark_blue);
	win.attach(superellipse);
	
	const int points_complexity = 1;
	for (int i = 0; i < superellipse.number_of_points(); i += points_complexity)
	for (int point_no = 1; point_no < superellipse.number_of_points(); point_no += points_complexity)
	{
		int point_to = point_no + i;
		if (point_to >= superellipse.number_of_points())
			point_to -= superellipse.number_of_points();
		Line * line = new Line(Point(superellipse.point(i)), Point(superellipse.point(point_to)));
		line->set_color(Color::dark_cyan);
		
		win.attach(*line);
	}

	win.wait_for_button();
}

int sign(double x)
{
	if (x < 0)
		return -1;
	if (x > 0)
		return 1;
	
	return 0;
}