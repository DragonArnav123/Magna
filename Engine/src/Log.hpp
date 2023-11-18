#pragma once

#include "common.hpp"
#include <spdlog/spdlog.h>

namespace Magna {

struct MAGNA_API Log {

	static void Init();

	inline static std::shared_ptr<spdlog::logger> CoreLogger() { return core_logger; }
	inline static std::shared_ptr<spdlog::logger> ClientLogger() { return client_logger; }

private:
	static std::shared_ptr<spdlog::logger> core_logger;
	static std::shared_ptr<spdlog::logger> client_logger;

};

#ifdef DEBUG_BUILD

#define MG_CORE_LOG(...)			Log::CoreLogger()->log(__VA_ARGS__)			;
#define MG_CORE_WARN(...)			Log::CoreLogger()->warn(__VA_ARGS__)		;
#define MG_CORE_ERROR(...)			Log::CoreLogger()->error(__VA_ARGS__)		;
#define MG_CORE_CRITICAL(...)		Log::CoreLogger()->critical(__VA_ARGS__)	;
#define MG_CORE_INFO(...)			Log::CoreLogger()->info(__VA_ARGS__)		;
#define MG_CORE_DEBUG(...)			Log::CoreLogger()->debug(__VA_ARGS__)		;
#define MG_CORE_TRACE(...)			Log::CoreLogger()->trace(__VA_ARGS__)		;

#define MG_CLIENT_LOG(...)			Log::ClientLogger()->log(__VA_ARGS__)		;
#define MG_CLIENT_WARN(...)			Log::ClientLogger()->warn(__VA_ARGS__)		;
#define MG_CLIENT_ERROR(...)		Log::ClientLogger()->error(__VA_ARGS__)		;
#define MG_CLIENT_CRITICAL(...)		Log::ClientLogger()->critical(__VA_ARGS__)	;
#define MG_CLIENT_INFO(...)			Log::ClientLogger()->info(__VA_ARGS__)		;
#define MG_CLIENT_DEBUG(...)		Log::ClientLogger()->debug(__VA_ARGS__)		;
#define MG_CLIENT_TRACE(...)		Log::ClientLogger()->trace(__VA_ARGS__)		;

#elif defined(RELEASE_BUILD) ||  defined(DISTRIBUTION_BUILD)

#define MG_CORE_LOG(...)			
#define MG_CORE_WARN(...)			
#define MG_CORE_ERROR(...)			
#define MG_CORE_CRITICAL(...)		
#define MG_CORE_INFO(...)			
#define MG_CORE_DEBUG(...)			
#define MG_CORE_TRACE(...)			

#define MG_CLIENT_LOG(...)			Log::ClientLogger()->log(__VA_ARGS__)		;
#define MG_CLIENT_WARN(...)			Log::ClientLogger()->warn(__VA_ARGS__)		;
#define MG_CLIENT_ERROR(...)		Log::ClientLogger()->error(__VA_ARGS__)		;
#define MG_CLIENT_CRITICAL(...)		Log::ClientLogger()->critical(__VA_ARGS__)	;
#define MG_CLIENT_INFO(...)			Log::ClientLogger()->info(__VA_ARGS__)		;
#define MG_CLIENT_DEBUG(...)		Log::ClientLogger()->debug(__VA_ARGS__)		;
#define MG_CLIENT_TRACE(...)		Log::ClientLogger()->trace(__VA_ARGS__)		;

#else
#error [LOG] INVALID BUILD TYPE!
#endif

}
