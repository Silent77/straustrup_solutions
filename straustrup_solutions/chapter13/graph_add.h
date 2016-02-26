#pragma once
#include "Graph.h"

constexpr double PI = 3.14159265358;

namespace Graph_lib
{
	// Return the sign of integer, -1 , 0 ,1
	inline int sign(int n) { if (n < 0) return -1; if (n > 0) return 1; return 0; };

	// Elliptic arc
	struct Arc : Shape {
		Arc(Point p, int rr1, int rr2, double as = 0., double ae = 360.)	// center and radius1, radius2, start and end angles
			:r1(rr1), r2{rr2}, start {as}, end{ ae }
		{
			add(Point(p.x - r1, p.y - r2));
			if (as < 0)
				as = 0;

			if (ae > 360)
				ae = 360;
		}

		void draw_lines() const;

		Point center() const;

//		void set_radius(int rr) { set_point(0, Point(center().x - rr, center().y - rr)); r = rr; }
//		int radius() const { return r; }
	private:
		int r1;
		int r2;
		double start;
		double end;
	};

struct Arrow : Shape
{
	Arrow(Point p1, Point p2, int size = 4, double ang = 30, bool two_sides = false);
	void draw_lines() const;
private:
	int	 a_size;  
	Lines lines;
	double angle;
	bool double_arrow;
};

//------------------------------------------------------------------------------

struct Regular_Polygon : Closed_polyline {    // regular polygon as closed sequence of non-intersecting lines
	Regular_Polygon(Point p, int n, int x);			// Center, number of sides (>2) and size
private:
	Point center;
	double size;
	int sides;
};

class Smiley : public Circle
{
public:
	Smiley(Point p, int rr)
		: Circle(p, rr),	// center and radius
		leye(Point{ static_cast<int>(p.x - rr * 0.25 * sqrt(2.)), static_cast<int>(p.y - rr * 0.25 * sqrt(2.)) }, rr * 0.25),
		reye(Point{ static_cast<int>(p.x + rr * 0.25 * sqrt(2.)), static_cast<int>(p.y - rr * 0.25 * sqrt(2.)) }, rr * 0.25),
		smile(p, rr * 0.5, rr * 0.5, 180, 0) {};
		
	void set_color(Color c);
	void draw_lines() const;
protected:
	Circle leye;
	Circle reye;
	Graph_lib::Arc smile;
};

class Frowny : public Circle
{
public:
	Frowny(Point p, int rr)
		: Circle(p, rr),	// center and radius
		leye(Point{ static_cast<int>(p.x - rr * 0.25 * sqrt(2.)), static_cast<int>(p.y - rr * 0.25 * sqrt(2.)) }, rr * 0.25),
		reye(Point{ static_cast<int>(p.x + rr * 0.25 * sqrt(2.)), static_cast<int>(p.y - rr * 0.25 * sqrt(2.)) }, rr * 0.25),
		smile(Point{p.x, static_cast<int>(p.y + rr * 0.5)}, rr * 0.5, rr * 0.5, 0, 180) {};

	void set_color(Color c);
	void draw_lines() const;
protected:
	Circle leye;
	Circle reye;
	Graph_lib::Arc smile;
};

// Smile with hat
class SmileyHat : public Smiley
{
public:
	SmileyHat(Point p, int rr)
		: Smiley{ p, rr },
		hat_bottom{ Point{p.x - rr, p.y - rr}, Point{p.x + rr, p.y - rr} },
		hat_top{ Point{p.x - rr / 4, p.y - rr - rr / 2 }, rr / 2, rr / 2 }
	{};
	void draw_lines() const;
	void set_color(Color c);
private:
	Line hat_bottom;
	Graph_lib::Rectangle hat_top;
};

// Circle that cannot move
struct Immobile_Circle : Circle
{
	Immobile_Circle(Point p, int rr) : Circle(p, rr) {};

private:
	void move(int dx, int dy);
};

struct Striped_Rectangle : Rectangle
{
	Striped_Rectangle(Point p1, Point p2) : Rectangle(p1, p2) {};
	Striped_Rectangle(Point p, int ww, int hh) : Rectangle(p, ww, hh) {};
	void draw_lines() const;
};

struct Striped_Circle : Circle
{
	Striped_Circle(Point p, int rr) : Circle(p, rr) {};
	void draw_lines() const;
};

}; // namespace