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
	enum EventType
	{
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
		/// @brief Constructor called when a new instance of Event is created
		/// @param id The ID generated by the Event Dispatcher
		/// @param eventName The name of the event (user/engine defined)
		/// @param eventType The type of event (user/engine defined)
		Event(const unsigned int id, const std::string eventName, const EventType eventType)
			: m_Id(id), m_EventName(eventName), m_EventType(eventType)
		{
		}

		/// @brief += operator overloading allowing you to subscribe functions to the event
		/// @param func The function to be called when the event is dispatched
		void operator+=(const std::function<void(Event &)> func)
		{
			m_Callbacks.push_back(func);
		}

		std::unique_ptr<WindowMoveEvent> OnWindowMoveEvent;
		std::unique_ptr<WindowResizeEvent> OnWindowResizeEvent;
		std::unique_ptr<KeyEvent> OnKeyEvent;
		std::unique_ptr<MouseMoveEvent> OnMouseMoveEvent;
		std::unique_ptr<MouseButtonEvent> OnMouseButtonEvent;
		std::unique_ptr<MouseSctrollEvent> OnMouseScrollEvent;

		/// @brief Set the value of the handled flag
		/// @param value What to set the handled flag to
		void SetHandled(bool value)
		{
			m_Handled = value;
		}

		/// @brief Get the event id
		/// @return Returns the event id
		unsigned int GetId()
		{
			return m_Id;
		}

		/// @brief Get the name of the event
		/// @return Returns the name of the event
		std::string GetName()
		{
			return m_EventName;
		}

		/// @brief Get the handled flag
		/// @return Returns the value of the handled flag
		bool GetHandled()
		{
			return m_Handled;
		}

		/// @brief Get the type of event
		/// @return Returns the type of event
		EventType GetType()
		{
			return m_EventType;
		}

		/// @brief Get the callbacks subscribed to the event
		/// @return Returns the callbacks
		std::vector<std::function<void(Event &)>> GetCallbacks()
		{
			return m_Callbacks;
		}

	private:
		unsigned int m_Id;
		std::string m_EventName;
		EventType m_EventType;
		bool m_Handled = false;
		std::vector<std::function<void(Event &)>> m_Callbacks;
	};
}