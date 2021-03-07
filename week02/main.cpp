/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
try{
    using namespace Graph_lib;

    Point tl{100, 100};

    Simple_window win {tl, 600, 400, "Canvas"};

	Axis xa {Axis::x, Point{20, 300}, 280, 10, "x"};
	Axis ya {Axis::y, Point{20, 300}, 280, 10, "y"};
	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_red);

	Function sine(sin, 0, 100, Point(20,150),1000,50,50);
	sine.set_color(Color::blue);

	Polygon poly;
	poly.add(Point(300,200));
	poly.add(Point(350,100));
	poly.add(Point(400,200));

	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);

	Rectangle r(Point(200,200), 100, 50);

	Closed_polyline poly_rect;
	poly_rect.add(Point(100,50));
	poly_rect.add(Point(200,50));
	poly_rect.add(Point(200,100));
	poly_rect.add(Point(100,100));
	poly_rect.add(Point(50,75));

	r.set_fill_color(Color::yellow);
	poly.set_style(Line_style(Line_style::dash,4));
	poly_rect.set_style(Line_style(Line_style::dash,2));

	Text t(Point(150,150), "Hello, graphical world!");

	t.set_font(Font::times_bold);
	t.set_font_size(20);

	Image ii{Point{100,50}, "badge.jpg"};

	//ii.move(100,200);

	Circle c(Point(100,200),50);
	c.set_style(Line_style(Line_style::dash,3));
	Mark m(Point(100,200),'x');
	
	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max();
	Text sizes(Point(100,20),oss.str());

	Image cal(Point(225,225), "earth.gif");
	cal.set_mask(Point(40,40),400,400);

	win.attach(ii);
	win.attach(c);
	win.attach(m);
	win.attach(sizes);
	win.attach(cal);
	win.attach(t);
	win.attach(poly_rect);
	win.attach(r);
	win.attach(poly);
	win.attach(sine);
	win.attach(xa);
	win.attach(ya);

    win.wait_for_button();

}
catch(exception& e){
	cerr << "Error" << endl;
	return 1;
}
catch(...){
	cerr << "Error" << endl;
	return 2;
}
