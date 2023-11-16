#define MAGNA_DLL_BUILD

#include "window.hpp"
#include "../Log.hpp"
#include <gllibs.hpp>
#include <std.hpp>
#include <GLFW/glfw3.h>


namespace Magna { namespace Window {
using namespace Math;

MAGNA_API Window::Window(uint16 width, uint16 height, string title)
	: width(width), height(height), title(title) {
	
	_win = 
		glfwCreateWindow(
				(int32) width,
				(int32) height,
				title.c_str(), NULL, NULL);
	MG_CLIENT_DEBUG("Created Window at {0}", (void*)_win)
	glfwSetWindowUserPointer(_win, this);
}

MAGNA_API Window::~Window() {
	glfwSetWindowShouldClose(_win, GLFW_TRUE);
	glfwDestroyWindow(_win);
}

void MAGNA_API Window::initialize(
		int32 opengl_major, int32 opengl_minor) {

	if (!glfwInit()) {
		std::cerr << "(ERROR)(window): glfw could not be initialized!";
		exit (-1);
	}
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, opengl_major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, opengl_minor);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void MAGNA_API Window::terminate() {
	glfwTerminate();
}

void MAGNA_API Window::resize(uint16 width, uint16 height) {
	auto win_ptr =
		glfwGetWindowMonitor(_win);

	auto lambda = [this](GLFWwindow *window, int32 width, int32 height) {
	};
	std::cerr << "[window] [todo]";

}

void MAGNA_API Window::clear() {
	glClearColor(
		_clr_color.x, _clr_color.y, _clr_color.z, _clr_color.w);
	glClear(GL_COLOR_BUFFER_BIT);
}

void MAGNA_API Window::close() {
	glfwSetWindowShouldClose(_win, GLFW_TRUE);
}

void MAGNA_API Window::open() {
	glfwSetWindowShouldClose(_win, GLFW_FALSE);
}

void MAGNA_API Window::set_title(string title) {
	this->title = title;
	glfwSetWindowTitle(_win, title.c_str());
}

void MAGNA_API Window::update_window_pos(ivec2 pos) {
	glfwSetWindowPos(_win, pos.x, pos.y);
}

void MAGNA_API Window::center_window_on_screen() {
	auto monitor = 
		glfwGetWindowMonitor(_win);

	int32 monitor_x, monitor_y, monitor_width, monitor_height;
	glfwGetMonitorWorkarea(
			monitor, &monitor_x, &monitor_y,
			&monitor_width, &monitor_height);

	int32 
		x_pos = (int)(monitor_x / 2 - width / 2),
		y_pos = (int)(monitor_y / 2 - height / 2);
	glfwSetWindowPos(_win, x_pos, y_pos);
}

void MAGNA_API Window::set_current_context() {
	glfwMakeContextCurrent(_win);
}

} }
