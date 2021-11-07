#include "engine.h"
#include "SFMLWindow.h"

namespace Engine
{
	Window* Window::create(const WindowProps& props)
	{
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
		sf::RenderWindow m_nativeWindow(sf::VideoMode(m_properties.x, m_properties.y), m_properties.m_sName);
	}

	void SFMLWindowImpl::close()
	{
		m_nativeWindow.close();
	}

	void SFMLWindowImpl::onUpdate(float timestep)
	{
		sf::Event e;
		while (m_nativeWindow.pollEvent(e))
		{

			if (e.type == sf::Event::Closed)
				close();
		}
	}

}