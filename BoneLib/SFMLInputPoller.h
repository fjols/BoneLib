#pragma once
#include "inputPoller.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
namespace Engine
{
	class SFMLInputPoller : public InputPoller
	{
	private:
		bool isKeyPressedImpl(int keycode) override;
		bool isMouseButtonPressedImpl(sf::Mouse::Button button) override;
		sf::Vector2i getMousePosImpl() override;
		float getMouseXImpl() override;
		float getMouseYImpl() override;
	};
}