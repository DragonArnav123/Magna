#pragma once

/* Macros / Definitions */
#include "../src/macros.hpp"

/* Logging */
#include "../src/Log.hpp"

/* Renderer */
#include "../src/renderer/renderer.hpp"

/* math */
#include "../src/math.hpp"

/* Initialize */
namespace Magna {
inline void init() {
	Renderer::init();
	Log::Init();
}

inline void terminate() {
	Renderer::terminate();
}
}
