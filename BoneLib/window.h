/** \file window.h
* \brief Base class for the window.
*/
#pragma once
#include<string>
#include <SFML/Window.hpp>
#include "maths.h"
#include "engine.h"

namespace Engine
{
	struct WindowProps
	{
		std::string m_sName; //!< Name or titel of the window.
		Maths::Vector2D m_size; //!< Size of the window.
		Maths::Vector2D m_storedSize; //!< Stored size of window. Used when exiting fullscreen.
		bool m_bFullScreen; //!< Is the window fullscreen or not?

		WindowProps(const std::string& name = "game", Maths::Vector2D size = Maths::Vector2D(700, 700)) : m_sName(name), m_size(size) {}
	};

	class Window
	{
	public:
		void initialise(const Engine::WindowProps& props)
		{
			sf::Window window(sf::VideoMode(700, 700), props.m_sName);
			while (window.isOpen())
			{
				sf::Event e;
				while (window.pollEvent(e))
				{

					if (e.type == sf::Event::Closed)
						window.close();
				}
			}
		}
	};
}
