#include "graph_add.h"

namespace Graph_lib
{
	Point Arc::center() const
	{
		return Point(point(0).x + r1, point(0).y + r2);
	}

	//------------------------------------------------------------------------------

	void Arc::draw_lines() const
	{
		if (fill_color().visibility()) {	// fill
			fl_color(fill_color().as_int());
			fl_pie(point(0).x, point(0).y, r1 + r1 - 1, r2 + r2 - 1, start, end);
			fl_color(color().as_int());	// reset color
		}

		if (color().visibility()) {
			fl_color(color().as_int());
			fl_arc(point(0).x, point(0).y, r1 + r1, r2 + r2, start, end);
		}
	}
//------------------------------------------------------------------------------
Arrow::Arrow(Point p1, Point p2, int size, double ang, bool two_sides)
	: a_size{ size }, lines{}, angle{ ang }, double_arrow{two_sides}
{
	lines.add(p1, p2);
	Point l_arrow;
	Point r_arrow;
	ang = 2 * PI * ang / 360;		// ang to rad
	double phi = atan2((p2.y - p1.y) , (p2.x - p1.x));
	
	l_arrow.x = p2.x + a_size * cos(PI + ang) * cos(phi) - a_size * sin(PI + ang) * sin(phi);
	l_arrow.y = p2.y + a_size * cos(PI + ang) * sin(phi) + a_size * sin(PI + ang) * cos(phi);
	lines.add(l_arrow, p2);

	r_arrow.x = p2.x + a_size * cos(PI - ang) * cos(phi) - a_size * sin(PI - ang) * sin(phi);
	r_arrow.y = p2.y + a_size * cos(PI - ang) * sin(phi) + a_size * sin(PI - ang) * cos(phi);
	lines.add(p2, r_arrow);

	if (double_arrow)
	{
		Point l_arrow;
		Point r_arrow;
		l_arrow.x = p1.x + a_size * cos(ang) * cos(phi) - a_size * sin(ang) * sin(phi);
		l_arrow.y = p1.y + a_size * cos(ang) * sin(phi) + a_size * sin(ang) * cos(phi);
		lines.add(l_arrow, p1);

		r_arrow.x = p1.x + a_size * cos(- ang) * cos(phi) - a_size * sin(- ang) * sin(phi);
		r_arrow.y = p1.y + a_size * cos(- ang) * sin(phi) + a_size * sin(- ang) * cos(phi);
		lines.add(p1, r_arrow);
	}
}

void Arrow::draw_lines() const
{
	lines.draw_lines();
}

Regular_Polygon::Regular_Polygon(Point p, int n, int x)
	: center(p), size(x), sides(n)
{
	if (n < 3)
		error("Wrong polygon sides count. Minimum 3 is allowed.");

	double angle = 2. * PI / sides;

	for (int i = 0; i <  n; ++i)
	{
		Closed_polyline::add( Point{static_cast<int>(center.x  + size * cos(i * angle)), static_cast<int>(center.y + size * sin(i * angle))});
	}
}

void Smiley::set_color(Color c)
{
	Circle::set_color(c);
	leye.set_color(c);
	reye.set_color(c);
	smile.set_color(c);
}

void Smiley::draw_lines() const
{
	Circle::draw_lines();
	leye.draw_lines();
	reye.draw_lines();
	smile.draw_lines();
}

void Frowny::set_color(Color c)
{
	Circle::set_color(c);
	leye.set_color(c);
	reye.set_color(c);
	smile.set_color(c);
}

void Frowny::draw_lines() const
{
	Circle::draw_lines();
	leye.draw_lines();
	reye.draw_lines();
	smile.draw_lines();
}

void SmileyHat::draw_lines() const
{
	Smiley::draw_lines();
	hat_top.draw_lines();
	hat_bottom.draw();
	
}

void SmileyHat::set_color(Color c)
{
	Smiley::set_color(c);
	hat_bottom.set_color(c);
	hat_top.set_color(c);
}

void Immobile_Circle::move(int dx, int dy)
{
}

void Striped_Rectangle::draw_lines() const
{
	if (fill_color().visibility()) {    // fill
		fl_color(fill_color().as_int());
		// Draw horizontal lines with fill color
		for (int i = 2; i < h; i += 5)
			fl_line(point(0).x,point(0).y + i, point(0).x + w, point(0).y + i);
		
		fl_color(color().as_int());    // reset color
	}

	if (color().visibility()) {    // lines on top of fill
		fl_color(color().as_int());
		fl_rect(point(0).x, point(0).y, w, h);
	}
}

void Striped_Circle::draw_lines() const
{
	if (fill_color().visibility()) {	// fill
		fl_color(fill_color().as_int());

		// draw horizontal lines with fill color
		for (int y = 0; y < r; y += 5)
		{
			float x = sqrt( r * r - y * y);
			fl_line(point(0).x - x + r, point(0).y - y + r, point(0).x + x + r, point(0).y - y + r);
			fl_line(point(0).x - x + r, point(0).y + y + r, point(0).x + x + r, point(0).y + y + r);
		}
		fl_color(color().as_int());	// reset color
	}

	if (color().visibility()) {
		fl_color(color().as_int());
		fl_arc(point(0).x, point(0).y, r + r, r + r, 0, 360);
	}
}

} // namespace
