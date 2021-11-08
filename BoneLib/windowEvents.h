#pragma once
#include "event.h"

namespace Engine
{
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}
		static EventType getStaticType() { return EventType::WindowClose; }
		EventType getEventType() const override { return EventType::WindowClose; }
		int getCategoryFlags() const override { return EventCategoryWindow; }
	};

	class WindowResizeEvent : public Event
	{
	private:
		int m_iWidth;
		int m_iHeight;
	public:
		WindowResizeEvent(int w, int h) : m_iWidth(w), m_iHeight(h){}
		static EventType getStaticType() { return EventType::WindowResize; }
		EventType getEventType() const override { return EventType::WindowResize; }
		int getCategoryFlags() const override { return EventCategoryWindow; }
		inline int getWidth() const { return m_iWidth; }
		inline int getHeight() const { return m_iHeight; }
	};

	class WindowFocusEvent : public Event
	{
	private:
		float m_fX;
		float m_fY;
	public:
		WindowFocusEvent(float x, float y) : m_fX(x), m_fY(y) {}
		static EventType getStaticType() { return EventType::WindowFocus; }
		EventType getEventType() const override { return EventType::WindowFocus; }
		int getCategoryFlags() const override { return EventCategoryWindow; }
		inline float getX() const { return m_fX; }
		inline float getY() const { return m_fY; }
	};

	class WindowLostFocusEvent : public Event
	{
	private:
		float m_fX;
		float m_fY;
	public:
		WindowLostFocusEvent(float x, float y) : m_fX(x), m_fY(y) {}
		static EventType getStaticType() { return EventType::WindowLostFocus; }
		EventType getEventType() const override { return EventType::WindowLostFocus; }
		int getCategoryFlags() const override { return EventCategoryWindow; }
		inline float getX() const { return m_fX; }
		inline float getY() const { return m_fY; }
	};

	class WindowMovedEvent : public Event
	{
	private:
		int m_iX;
		int m_iY;
	public:
		WindowMovedEvent(int x, int y) : m_iX(x), m_iY(y) {}
		static EventType getStaticType() { return EventType::WindowMoved; }
		EventType getEventType() const override { return EventType::WindowMoved; }
		int getCategoryFlags() const override { return EventCategoryWindow; }
		inline int getX() const { return m_iX; }
		inline int getY() const { return m_iY; }
	};
}