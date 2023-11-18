#define DEBUG_BUILD
#include "../../Engine/include/Engine.hpp" 

#include <iostream>


using namespace Magna;

int main(int argc, const char **argv) {
	Magna::init();

	Window::Window *window = new Window::Window(800, 600, "Sandbox");	

	window->set_current_context();

	window->set_clear_color(Magna::Math::vec4(.45f, .234f, .542f, 1.0f));
	int i = 0;

	while (true) {
		++i;
		MG_CORE_DEBUG("{0}, {1}", i, "Hello, World!");
		window->clear();
	}


	delete window;

	Magna::terminate();
	return (0);
}
