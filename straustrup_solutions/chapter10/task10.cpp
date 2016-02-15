#pragma once

#include <fstream>
#include <iostream>
#include <vector>
#include "../std_lib_facilities.h"

struct Point
{
	int x;
	int y;
};

int main()
{
	constexpr int num_points = 7;
	Point p;
	int entered_points = 0, x, y;
	std::cout << "Enter " << num_points << " points.\n";
	Vector<Point> original_points;

	while (entered_points < num_points)
	{
		std::cout << num_points - entered_points << " left\n";
		std::cout << "Enter next point:";

		cin >> x >> y;
		if (!cin)
		{
			if (cin.fail())
			{
				cout << "Wrong input. Enter point as pair of integer: \n";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
			if (cin.eof())
				error("End of file.");
		}
		// good input
		else
		{
			original_points.push_back(Point{ x,y });
			++entered_points;
		}
	}

	std::cout << "You have enter points:\n";
	for (auto point : original_points)
		std::cout << '(' << point.x << ',' << point.y << ')' << std::endl;

	{
		std::ofstream fout{ "mydata.txt" };
		for (auto point : original_points)
			fout << point.x << ' ' << point.y << std::endl;
	}

	vector<Point> processed_points;
	{
		std:ifstream fin{ "mydata.txt" };
		if (!fin)
			error("Unable to open file for reading!");

		for (int x,  y; fin >> x >> y;)
			processed_points.push_back(Point{ x,y });
	}

	try
	{
		for (int i = 0; i < original_points.size(); ++i)
		{
			if ((original_points[i].x != processed_points[i].x) || (original_points[i].y != processed_points[i].y))
				error("Something wrong");
			std::cout << '(' << original_points[i].x << ',' << original_points[i].y << ')' << "  ";
			std::cout << '(' << processed_points[i].x << ',' << processed_points[i].y << ')' << std::endl;
		}
	}
	catch (exception e)
	{
		std::cout << e.what();
	}

	keep_window_open();
	return 0;
}