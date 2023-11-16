#pragma once

#include "../macros.hpp"
#include "../std.hpp"
#include "../gllibs.hpp"
#include "../math.hpp"
#include "../Keys.hpp"

namespace Magna { namespace Window {

struct MAGNA_API Window {
public:
	uint16 width;
	uint16 height;
	string title;

	explicit Window(uint16 width, uint16 height, string title);
	~Window();

	inline uint16 get_width() const { return width; }
	inline uint16 get_height() const { return height; }
	inline string get_title() const { return title; }
	inline void set_clear_color(Math::vec4 color) { _clr_color = color; }
	inline Math::vec2 get_mouse_pos() const { return _mouse_pos; }
	inline Math::vec2 get_screen_pos() const { return _screen_pos; }
	inline bool is_current_context() const { return _is_current_ctx; }
	inline void set_opactiy(float opacity) const {
		glfwSetWindowOpacity(this->_win, opacity);
	}

	static void initialize(int32 opengl_major, int32 opengl_minor);
	static void terminate(); 
	void resize(uint16 width, uint16 height);
	void poll_events();
	void clear();
	void set_mouse_pos(Math::vec2 pos);
	void toggle_full_screen(bool value);
	void set_title(string title);
	void set_cursor_visibility(bool value);
	void close();
	void open();
	void center_window_on_screen();
	void set_cursor_mode();
	void update_window_pos(Math::ivec2 pos);
	void set_current_context();

private:
	GLFWwindow *_win;
	Math::vec2 _screen_pos;
	Math::vec2 _mouse_pos;
	bool _is_full_screen;
	bool _is_current_ctx;
	Math::vec4 _clr_color;
	
	/* HWND _window_handle; */
	/* Event listener : WindowEvent */
	/* Event dispatcher: KeyEvent */
	/* Event dispatcher: MouseEvent */
};

} } 
