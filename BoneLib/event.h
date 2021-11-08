#pragma once
#include<functional>
namespace Engine
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryWindow = 1 << 0,
		EventCategoryInput = 1 << 1,
		EventCategoryKeyboard = 1 << 2,
		EventCategoryMouse = 1 << 3,
		EventCategoryMouseButton = 1 << 4
	};

	class Event
	{
	private:
		bool m_bHandled = false;
	public:
		virtual EventType getEventType() const = 0;
		virtual int getCategoryFlags() const = 0;
		inline bool handled() const { return m_bHandled; }
		inline void handle(bool isHandled) { m_bHandled = isHandled; }
		inline bool isInCategory(EventCategory category) { return getCategoryFlags() & category; }

	};

	class EventDispatcher
	{
		template<typename T>
		using EventFunc = std::function<bool(T&)>;
	private:
		Event& m_event;
	public:
		EventDispatcher(Event& event) : m_event(event) {}
		template<typename T>
		bool dispatch(EventFunc<T> func)
		{
			if (m_event.getEventType() == T::getStaticType())
			{
				m_event.handle(func(*((T*)&m_event)));
				return true;
			}
			return false;
		}
	};

}