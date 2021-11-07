#include "application.h"

namespace Engine
{
	Application* Application::s_instance = nullptr;
	Application::Application()
	{
		if (s_instance == nullptr)
			s_instance = this;
		m_bIsRunning = true;
		window.initialise(properties);
	}

	void Application::run()
	{
		while (m_bIsRunning)
		{
			std::cout << "running" << std::endl;
		}
	}
}