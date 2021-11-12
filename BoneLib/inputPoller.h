#pragma once
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
namespace Engine
{
	class InputPoller
	{
	private:
		static InputPoller* s_pInstance;
	protected:
		virtual bool isKeyPressedImpl(int keycode) = 0;
		virtual bool isMouseButtonPressedImpl(sf::Mouse::Button button) = 0;
		virtual sf::Vector2i getMousePosImpl() = 0;
		virtual float getMouseXImpl() = 0;
		virtual float getMouseYImpl() = 0;
	public:
		inline static bool isKeyPressed(int keycode) { return s_pInstance->isKeyPressedImpl(keycode); }
		inline static bool isMouseButtonPressed(sf::Mouse::Button button) { return s_pInstance->isMouseButtonPressedImpl(button); }
		inline static sf::Vector2i getMousePos() { return s_pInstance->getMousePosImpl(); }
		inline static float getMouseX() { return s_pInstance->getMouseXImpl(); }
		inline static float getMouseY() { return s_pInstance->getMouseYImpl(); }
	};
}