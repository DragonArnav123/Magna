#pragma once

#include "../include/std.hpp"
#include "../include/gllibs.hpp"
#include "Keys.hpp"

namespace Magna { namespace Window {

class Window {
public:
	explicit Window(uint16 width, uint16 height, string title);
	~Window();

	inline uint16 get_width() const { return _width; }
	inline uint16 get_height() const { return _height; }
	inline string get_title() const { return _title; }
	inline void set_clear_color(glm::vec3 color) { _clr_color = color; }
	inline glm::vec2 get_mouse_pos() const { return _mouse_pos; }
	inline glm::vec2 get_screen_pos() const { return _screen_pos; }
	inline bool is_current_context() const { return _is_current_ctx; }

	static void initialize();
	void resize(uint16 width, uint16 height);
	void poll_events();
	void clear();
	void set_mouse_pos(glm::vec2 pos);
	void toggle_full_screen(bool value);
	void set_title(string title);
	void set_cursor_visibility(bool value);
	void close();
	void open();
	void center_window_on_screen();
	void set_cursor_mode();
	void update_window_pos(glm::vec2 pos)

private:
	uint16 _width;
	uint16 _height;
	string _title;
	GLFWwindow *_win;
	glm::vec2 _screen_pos;
	glm::vec2 _mouse_pos;
	bool _is_full_screen;
	bool _is_current_ctx;
	glm::vec3 _clr_color;
	
	/* HWND _window_handle; */
	/* Event listener : WindowEvent */
	/* Event dispatcher: KeyEvent */
	/* Event dispatcher: MouseEvent */
};

} }
