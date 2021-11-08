#include "engine.h"
#include "timer.h"

namespace Engine
{
	bool Timer::m_bInstance = false;
	std::shared_ptr<Timer> Timer::s_pThis = nullptr;
	std::chrono::high_resolution_clock::time_point Timer::s_startFrame;
	std::chrono::high_resolution_clock::time_point Timer::s_endFrame;
	std::chrono::duration<float> Timer::s_frameDuration;

	std::map<std::string, std::pair<std::chrono::high_resolution_clock::time_point, std::chrono::high_resolution_clock::time_point>> Timer::s_sectionTime;
	std::chrono::duration<float> Timer::s_sectionTimeDuration;

	bool Timer::s_bWorking = true;

	std::shared_ptr<Timer> Timer::getInstance()
	{
		if (!m_bInstance)
		{
			s_pThis = std::shared_ptr<Timer>(new Timer());
			m_bInstance = true;
			return s_pThis;
		}
		else
			return s_pThis;
	}

	void Timer::start(SystemSignal init, ...)
	{
		s_startFrame = std::chrono::high_resolution_clock::now();
	}
	
	void Timer::stop(SystemSignal close, ...)
	{
		s_endFrame = std::chrono::high_resolution_clock::now();
	}

	float Timer::newFrame()
	{
		s_endFrame = std::chrono::high_resolution_clock::now();
		s_frameDuration = s_endFrame - s_startFrame;
		s_startFrame = std::chrono::high_resolution_clock::now();
		return s_frameDuration.count();
	}

	void Timer::startTimer(std::string tag)
	{
		if (s_sectionTime.find(tag) == s_sectionTime.end())
			s_sectionTime.insert(std::make_pair(tag, std::make_pair(std::chrono::high_resolution_clock::now(), std::chrono::high_resolution_clock::now())));
		else
		{
			LOG_ERROR("TIMER WITH TAG: '{0}' ALREADY EXISTS, CANNOT HAVE TWO TIMERS WITH THE SAME TAG", tag);
			s_bWorking = false;
		}
	}

	float Timer::endTimer(std::string tag)
	{
		if (s_sectionTime.find(tag) == s_sectionTime.end())
		{
			LOG_ERROR("TIMER WITH TAG : '{0}' NOT FOUND, ENSURE THE SAME TAG IS USED IN START AND END TIMER FUNCTIONS");
			return 0.0f;
		}
		else
		{
			if (!s_bWorking)
				LOG_WARNING("TWO TIMERS WITH THE SAME TAG WERE STARTED. OUTPUT MAY BE INACCURATE.");
			s_sectionTime[tag].second = std::chrono::high_resolution_clock::now();
			s_sectionTimeDuration = s_sectionTime[tag].second - s_sectionTime[tag].first;
			s_sectionTime.erase(tag);
			return s_sectionTimeDuration.count();
		}
	}
}