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
		window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
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
		dispatcher.dispatch<WindowCloseEvent>(std::bind(&Application::onClose, this, std::placeholders::_1)); // Dispatch the window close event 
		dispatcher.dispatch<WindowResizeEvent>(std::bind(&Application::onResize, this, std::placeholders::_1)); // Dispatch the window resize event
	}

	bool Application::onClose(WindowCloseEvent& e)
	{
		LOG_MSG("Window Closing");
		m_bIsRunning = false;
		return true;
	}

	bool Application::onResize(WindowResizeEvent& e)
	{
		if(ev.type == sf::Event::Resized)
			LOG_MSG("WINDOW RESIZE: WIDTH {0}, HEIGHT {1}", e.getWidth(), e.getHeight());
		window->resize(e.getWidth(), e.getHeight());
		return true;
	}

	Application::~Application()
	{
		m_log->stop();
		window->close();
	}
}