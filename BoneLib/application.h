#pragma once
#include "engine.h"
#include "log.h"
#include "SFMLWindow.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "timer.h"
#include "event.h"
#include "windowEvents.h"

namespace Engine
{
	class Application
	{
	public:
		Application(); //!< Application constructor.
	private:
		static Application* s_instance; //!< Application instance.
		bool m_bIsRunning;
		std::shared_ptr<Engine::Window> window;
		Engine::WindowProps properties;
		std::shared_ptr<Engine::Log> m_log;
		float m_fTimeElapsed;
		float m_fTimestep;
		sf::Event ev;
	public:
		virtual ~Application();
		inline static Application& getInstance() { return *s_instance; } //!< Return the instance.
		void run(); //!< Run the application.
		void onEvent(Event& e);
		bool onClose(WindowCloseEvent& e);
		bool onResize(WindowResizeEvent& e);
		inline Engine::Window& getWindow() { return *window; }
	};
}