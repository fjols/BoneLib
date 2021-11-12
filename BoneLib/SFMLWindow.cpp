#include "engine.h"
#include "SFMLWindow.h"

namespace Engine
{
	Window* Window::createWindow(const WindowProps& props)
	{
		LOG_MSG("CREATE RAN");
		return new SFMLWindowImpl(props);
	}

	SFMLWindowImpl::SFMLWindowImpl(const WindowProps& props)
	{
		initialise(props);
	}

	SFMLWindowImpl::~SFMLWindowImpl()
	{

	}

	void SFMLWindowImpl::initialise(const WindowProps& props)
	{
		m_properties.m_sName = props.m_sName;
		m_properties.x = props.x;
		m_properties.y = props.y;
		LOG_MSG("CREATING WINDOW: {0} ({1}, {2})", m_properties.m_sName, m_properties.x, m_properties.y);
	}

	void SFMLWindowImpl::close()
	{
		LOG_MSG("WINDOWING CLOSING");
		m_nativeWindow->close();
	}

	void SFMLWindowImpl::onUpdate(float timestep)
	{
		sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Green);
		while (m_nativeWindow->pollEvent(e))
		{

			if (e.type == sf::Event::Closed)
				close();
		}
		m_nativeWindow->clear();
		m_nativeWindow->draw(shape);
		m_nativeWindow->display();
	}

	void SFMLWindowImpl::setEventCallback(const std::function<void(Event&)>& callback)
	{
		m_callback = callback;
	}

	void SFMLWindowImpl::resize(int x, int y)
	{
		m_properties.x = x;
		m_properties.y = y;
	}

}