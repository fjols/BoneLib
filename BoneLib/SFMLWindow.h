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
		std::shared_ptr<sf::RenderWindow> m_nativeWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 800), "hello");
		//sf::RenderWindow m_nativeWindow;
		//void initialise(const Engine::WindowProps& properties) override;
		unsigned int m_uiWindowHeight;
		unsigned int m_uiWindowWidth;
		Engine::WindowProps m_properties;
		sf::Event e;
		std::function<void(Event&)> m_callback;
	public:
		SFMLWindowImpl(const Engine::WindowProps& props);
		~SFMLWindowImpl();
		void initialise(const Engine::WindowProps& properties) override;
		void close() override;
		void resize(int x, int y) override;
		void onUpdate(float timestep) override;
		inline void* getNativeWindow() const override { return static_cast<void*>(m_nativeWindow.get()); }
		void setEventCallback(const std::function<void(Event&)>& callback) override;

	};
}