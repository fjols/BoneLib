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
		window.reset(Window::createWindow());
		LOG_MSG("WINDOWS SYSTEM INITIALISED");
		TIMER_NEWFRAME;
	}

	void Application::run()
	{
		while (m_bIsRunning)
		{
			m_fTimestep = TIMER_NEWFRAME;
			window->onUpdate(m_fTimestep);
		}
	}

	void Application::onEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
	}

	void Application::onClose()
	{

	}

	Application::~Application()
	{
		m_log->stop();
		window->close();
	}
}