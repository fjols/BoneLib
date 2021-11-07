#include "application.h"

namespace Engine
{
	Application* Application::s_instance = nullptr;
	Application::Application()
	{
		if (s_instance == nullptr)
			s_instance = this;
		m_bIsRunning = true;
		m_log = Engine::Log::getInstance();
		m_log->start();
		
		window->initialise(properties);
		LOG_MSG("WINDOWS SYSTEM INITIALISED");
	}

	void Application::run()
	{
		while (m_bIsRunning)
		{
			LOG_MSG("hello");
		}
	}

	Application::~Application()
	{
		m_log->stop();
	}
}