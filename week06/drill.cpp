/*
    g++ drill.cpp Graph.cpp Window.cpp GUI.cpp Lines_window.cpp -o drill `fltk-config --ldflags --use-images`
*/
#include "Lines_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    Lines_window win(Point(100,100), 1280, 720, "Canvas");

    return gui_main();
}
