/*
    g++ drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main() 
{
	Simple_window win {Point{100,100}, 800, 1000, "Canvas"};

	constexpr int grid_size = 100;
	constexpr int grid_max = 800;

	Lines grid;

	for (int i = grid_size; i <= grid_max; i+=grid_size)
	{
		grid.add(Point{i,0}, Point{i, grid_max});
		grid.add(Point{0,i}, Point{grid_max, i});
	}

	win.attach(grid);

	Vector_ref<Rectangle> squares;

	for (int i = 0; i < 8; ++i)
	{
		squares.push_back(new Rectangle(Point{i*100, i*100}, 100, 100));
		squares[i].set_fill_color(Color::red);
		win.attach(squares[i]);
	}

	Vector_ref<Image> images;

	images.push_back(new Image(Point{0,200}, "badge.jpg"));
	images.push_back(new Image(Point{0,400}, "badge.jpg"));
	images.push_back(new Image(Point{0,600}, "badge.jpg"));

	for (int i = 0; i < images.size(); ++i)
	{
		images[i].set_mask(Point{100,100}, 200, 200);
		win.attach(images[i]);
	}

	Image logo(Point{0,0}, "badge.jpg");
	logo.set_mask(Point{150,150}, 100, 100);

	win.attach(logo);

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			win.wait_for_button();
			if(j < 7) logo.move(100,0);
			else logo.move(-700,100);
		}
	}
}