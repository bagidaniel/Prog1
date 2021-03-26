#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Window {
	Lines_window(Point xy, int w, int h, const string& title);
	Open_polyline lines;

	bool wait_for_button();

private:
	Button next_button;
	Button quit_button;

	In_box next_x;
	In_box next_y;

	Out_box xy_out;

	Menu color_menu;
	void change_color(Color c);
	void red_pressed();
	void blue_pressed();
	void black_pressed();

	Button select_color;
	void select_color_pressed();
	void color_pressed();

	Menu style_menu;
	void change_style(Line_style ls);
	void solid_pressed();
	void dash_pressed();
	void dot_pressed();

	Button select_style;
	void select_style_pressed();
	void style_pressed();

	void next();
	void quit();
};