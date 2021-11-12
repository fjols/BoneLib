#include "application.h"
#include "engine.h"
#include "SFMLInputPoller.h"

namespace Engine
{
	InputPoller* InputPoller::s_pInstance = new SFMLInputPoller;

	bool SFMLInputPoller::isKeyPressedImpl(int keycode)
	{
		sf::RenderWindow* window = static_cast<sf::RenderWindow*>(Application::getInstance().getWindow().getNativeWindow());
		int result = sf::Event::KeyPressed;
		return result;
	}
	bool SFMLInputPoller::isMouseButtonPressedImpl(sf::Mouse::Button button)
	{
		int result = sf::Mouse::isButtonPressed(button);
		return result;
	}
	sf::Vector2i SFMLInputPoller::getMousePosImpl()
	{
		sf::RenderWindow* window = static_cast<sf::RenderWindow*>(Application::getInstance().getWindow().getNativeWindow());
		double x, y;
		sf::Vector2i pos = sf::Mouse::getPosition(*window);
		return pos;
	}
	float SFMLInputPoller::getMouseXImpl()
	{
		sf::Vector2i pos = getMousePosImpl();
		return pos.x;
	}
	float SFMLInputPoller::getMouseYImpl()
	{
		sf::Vector2i pos = getMousePosImpl();
		return pos.y;
	}
}