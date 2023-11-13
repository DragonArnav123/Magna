#include "../../Engine/include/Engine.hpp" 

#include <iostream>

using namespace Magna;

int main(int argc, const char **argv) {
	Window::Window::initialize(4, 2);
	Window::Window window(800, 600, "Sandbox");	
	Log("Created Window!");
	Window::Window::terminate();

	return (0);
}
