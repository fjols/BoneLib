/** \file window.h
* \brief Base class for the window.
*/
#pragma once
#include<string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "timer.h"
#include "maths.h"
#include "engine.h"

namespace Engine
{
	struct WindowProps
	{
		std::string m_sName; //!< Name or titel of the window.
		int x;
		int y;
		Maths::Vector2D m_storedSize; //!< Stored size of window. Used when exiting fullscreen.
		//bool m_bFullScreen; //!< Is the window fullscreen or not?

		WindowProps(const std::string& name = "game", int x_ = 700, int y_ = 700) : m_sName(name), x(x_), y(y_) {}
	};

	class Window
	{
	public:
		virtual void initialise(const Engine::WindowProps& props) = 0;
		virtual void close() = 0;
		virtual void resize(int x, int y) = 0;
		virtual void onUpdate(float timestep) = 0;

		static Window* createWindow(const WindowProps& props = WindowProps());
	};
}
