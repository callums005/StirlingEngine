#pragma once

#include <string>
#include <vector>
#include <functional>
#include <memory>

#include "WindowEvent.h"
#include "KeyboardEvent.h"
#include "MouseEvent.h"

namespace StirlingEngine
{
	const enum EventType {
		OnApplicationStart = 1,
		OnApplicationUpdate,
		OnApplicationExit,
		OnWindowClose,
		OnWindowResize,
		OnWindowMove,
		OnMouseDown,
		OnMouseUp,
		OnMouseMove,
		OnMouseScroll,
		OnKeyDown,
		OnKeyUp,
		UserDefined
	};

	class Event
	{
	public:
		Event(const unsigned int id, const std::string eventName, const EventType eventType)
			: m_Id(id), m_EventName(eventName), m_EventType(eventType)
		{
		}

		// Pass in the function to be called when the event is triggered (functions takes the event called as a param)
		void operator+=(const std::function<void(Event &)> func)
		{
			m_Callbacks.push_back(func);
		}

		std::unique_ptr<WindowMoveEvent> WindowMoveEvent;
		std::unique_ptr<WindowResizeEvent> WindowResizeEvent;
		std::unique_ptr<KeyEvent> KeyEvent;
		std::unique_ptr<MouseMoveEvent> MouseMoveEvent;
		std::unique_ptr<MouseButtonEvent> MouseButtonEvent;
		std::unique_ptr<MouseSctrollEvent> MouseScrollEvent;

	private:
		unsigned int m_Id;
		std::string m_EventName;
		EventType m_EventType;
		bool m_Handled = false;

		std::vector<std::function<void(Event &)>> m_Callbacks;
	};
}