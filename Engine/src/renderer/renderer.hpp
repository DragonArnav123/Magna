#pragma once

#include "../macros.hpp"
#include "window.hpp"

namespace Magna {

struct Renderer
{
	Renderer() = default;
	~Renderer();

	/* initialize all renderer and window processes */
	inline static void init() {
		// initialize window
		Window::Window::initialize(4, 2);
	}

	inline static void terminate() {
		// terminate window
		Window::Window::terminate();
	}
};

}
