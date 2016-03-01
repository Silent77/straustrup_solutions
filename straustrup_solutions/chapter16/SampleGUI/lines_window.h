#pragma once
#include "GUI.h"

struct Lines_window : Graph_lib::Window 
{
	Lines_window(Point xy, int w, int h, const string& title);
	Graph_lib::Open_polyline lines;
	Graph_lib::Menu color_menu;

private:
	Graph_lib::Button next_button;
	Graph_lib::Button quit_button;
	Graph_lib::In_box next_x;
	Graph_lib::In_box next_y;
	Graph_lib::Out_box xy_out;
	void next();
	void quit();

	void red_pressed() { change_color(Graph_lib::Color::red); };
	void blue_pressed() { change_color(Graph_lib::Color::blue); };
	void black_pressed() { change_color(Graph_lib::Color::black); };
	void change_color(Graph_lib::Color cl) { 
		lines.set_color(cl); 
		this->draw();
		
	}
};