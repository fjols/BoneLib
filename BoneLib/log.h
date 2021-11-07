#pragma once
#include "system.h"
#include "spdlog/spdlog.h"

namespace Engine
{
	class Log : public System
	{
	private:
		static bool s_bInstance; //!< Checks to see if system is running.
		static std::shared_ptr<Log> s_pThis; //!< Pointer to the Log object.
		static std::shared_ptr<spdlog::logger> s_pLogger; //!< Pointer to the logger.
	public:
		static std::shared_ptr<Log> getInstance();
		void start(SystemSignal init = SystemSignal::None, ...) override;
		void stop(SystemSignal close = SystemSignal::None, ...) override;
		inline static std::shared_ptr<spdlog::logger> getLogger() { return s_pLogger; }
	};
}

#define LOG_MSG(...)		Engine::Log::getLogger()->info(__VA_ARGS__)
#define LOG_WARNING(...)	Engine::Log::getLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)		Engine::Log::getLogger()->error(__VA_ARGS__)
#define LOG_CRIT_ERROR(...) Engine::Log::getLogger()->critical(__VA_ARGS__)