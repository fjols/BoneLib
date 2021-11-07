#include "engine.h"
#include "log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Engine
{
	bool Log::s_bInstance = false;
	std::shared_ptr<Log> Log::s_pThis = nullptr;
	std::shared_ptr<spdlog::logger> Log::s_pLogger = nullptr;

	std::shared_ptr<Log> Log::getInstance()
	{
		if (!s_bInstance)
		{
			s_pThis = std::shared_ptr<Log>(new Log());
			s_bInstance = true;
			return s_pThis;
		}
		else
			return s_pThis;
	}

	void Log::start(SystemSignal init, ...)
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_pLogger = spdlog::stderr_color_mt("Log");
		s_pLogger->set_level(spdlog::level::trace);
	}

	void Log::stop(SystemSignal init, ...)
	{
		s_pLogger = nullptr;
		s_bInstance = false;
		s_pThis = nullptr;
	}
}