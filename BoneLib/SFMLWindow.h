#pragma once
#include "engine.h"
#include "window.h"
#include "log.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace Engine
{
	class SFMLWindowImpl : public Window
	{
	private:
		sf::RenderWindow m_nativeWindow;
		void initialise(const Engine::WindowProps& properties) override;
		unsigned int m_uiWindowHeight;
		unsigned int m_uiWindowWidth;
		Engine::WindowProps m_properties;
	public:
		SFMLWindowImpl(const Engine::WindowProps& props);
		~SFMLWindowImpl();

		void close() override;
		void resize() override;
		void onUpdate(float timestep) override;

	};
}