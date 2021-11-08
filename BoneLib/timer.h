#pragma once
#include "system.h"
#include "chrono"
#include "log.h"
#include<map>
#include<string>

namespace Engine
{
	class Timer : public System
	{
	private:
		static bool m_bInstance;
		static std::shared_ptr<Timer> s_pThis;
		static std::chrono::high_resolution_clock::time_point s_startFrame;
		static std::chrono::high_resolution_clock::time_point s_endFrame;
		static std::chrono::duration<float> s_frameDuration;
		static std::map<std::string, std::pair<std::chrono::high_resolution_clock::time_point, std::chrono::high_resolution_clock::time_point>> s_sectionTime;
		static std::chrono::duration<float> s_sectionTimeDuration;
		static bool s_bWorking;
	public:
		static std::shared_ptr<Timer> getInstance();
		void start(SystemSignal init = SystemSignal::None, ...) override;
		void stop(SystemSignal close = SystemSignal::None, ...) override;
		static float newFrame();
		inline static float timestep() { return s_frameDuration.count(); }
		static void startTimer(std::string tag);
		static float endTimer(std::string tag);
	};
}

#define TIMER_NEWFRAME Engine::Timer::newFrame()
#define TIMER_TIMESTEP Engine::Timer::timestep()
#define TIMER_END(...) Engine::Timer::endTimer(__VA_ARGS__)
#define TIMER_START(...) Engine::Timer::startTimer