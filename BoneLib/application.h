#pragma once
#include "engine.h"

namespace Engine
{
	class Application
	{
	public:
		Application(); //!< Application constructor.
	private:
		static Application* s_instance; //!< Application instance.
		bool m_bIsRunning;
		Engine::Window window;
		Engine::WindowProps properties;
	public:
		//virtual ~Application();
		inline static Application& getInstance() { return *s_instance; } //!< Return the instance.
		void run(); //!< Run the application.
	};
}