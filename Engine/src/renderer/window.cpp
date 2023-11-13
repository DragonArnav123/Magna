#define MAGNA_IMPLEMENTATION
#include "window.hpp"

#include <gllibs.hpp>
#include <std.hpp>
#include <GLFW/glfw3.h>

void __declspec(__dllexport__) Log(const char *a) {
	spdlog::log(spdlog::level::info, a);
}

namespace Magna { namespace Window {

__declspec(__dllexport__) Window::Window(uint16 width, uint16 height, string title)
	: width(width), height(height), title(title) {
	
	_win = 
		glfwCreateWindow(
				(int32) width,
				(int32) height,
				title.c_str(), NULL, NULL);
	spdlog::log(spdlog::level::debug, "In WINDOW!");
	glfwSetWindowUserPointer(_win, this);
}

__declspec(__dllexport__) Window::~Window() {
	glfwSetWindowShouldClose(_win, GLFW_TRUE);
	glfwDestroyWindow(_win);
}

void API Window::initialize(
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

void API Window::resize(uint16 width, uint16 height) {
	auto win_ptr =
		glfwGetWindowMonitor(_win);

	auto lambda = [this](GLFWwindow *window, int32 width, int32 height) {
	};
	std::cerr << "[window] [todo]";

}

void API Window::clear() {
	glClearColor(
		_clr_color.x, _clr_color.y, _clr_color.z, _clr_color.w);
	glClear(GL_COLOR_BUFFER_BIT);
}

void API Window::close() {
	glfwSetWindowShouldClose(_win, GLFW_TRUE);
}

void API Window::open() {
	glfwSetWindowShouldClose(_win, GLFW_FALSE);
}

void API Window::set_title(string title) {
	this->title = title;
	glfwSetWindowTitle(_win, title.c_str());
}

void API Window::update_window_pos(ivec2 pos) {
	glfwSetWindowPos(_win, pos.x, pos.y);
}

void API Window::center_window_on_screen() {
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

void API Window::set_current_context() {
	glfwMakeContextCurrent(_win);
}

} }
