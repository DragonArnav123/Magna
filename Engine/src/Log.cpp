/* Implementation for Log struct */

#include "common.hpp"
#include <spdlog/sinks/stdout_color_sinks.h>
#include "Log.hpp"

namespace Magna {

void MAGNA_API Log::Init() {
	string s = "%^";
// if build mode is debug, prepend "DEBUG" to log
#ifdef DEBUG_BUILD	
	s += "(DEBUG)";
// if build mode is not debug, prepend "REL|DIST" to log
#elif defined(RELEASE_BUILD) || defined(DISTRIBUTION_BUILD)
	s += "(REL|DIST)";
#else
#error [LOGGER] INVALID BUILD TYPE!!
#endif
	string format = s;

	// set the format for log
	format += "(%c)(%g)(%!:%#) [%n:%l] -> %v%$";

	// instantiating the loggers
	Log::core_logger = spdlog::stdout_color_mt("Magna");
	Log::core_logger->set_level(spdlog::level::level_enum::trace);
	Log::client_logger= spdlog::stdout_color_mt("App");
	Log::client_logger->set_level(spdlog::level::level_enum::trace);
}

}
