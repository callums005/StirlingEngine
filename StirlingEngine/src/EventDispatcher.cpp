#include "Events/EventDispatcher.h"

namespace StirlingEngine
{
	std::map<unsigned int, Event *> EventDispatcher::m_Events;
	unsigned int EventDispatcher::m_EventCount;

	unsigned int EventDispatcher::GenerateEvent(std::string name, EventType type)
	{
		m_EventCount++;

		Event *event = new Event(m_EventCount, name, type);

		switch (type)
		{
		case EventType::OnWindowResize:
			event->WindowResizeEvent = std::unique_ptr<WindowResizeEvent>(new WindowResizeEvent());
			break;
		case EventType::OnWindowMove:
			event->WindowMoveEvent = std::unique_ptr<WindowMoveEvent>(new WindowMoveEvent());
			break;
		case EventType::OnMouseMove:
			event->MouseMoveEvent = std::unique_ptr<MouseMoveEvent>(new MouseMoveEvent());
			break;
		case EventType::OnMouseScroll:
			event->MouseScrollEvent = std::unique_ptr<MouseSctrollEvent>(new MouseSctrollEvent());
			break;
		case EventType::OnMouseDown:
		case EventType::OnMouseUp:
			event->MouseButtonEvent = std::unique_ptr<MouseButtonEvent>(new MouseButtonEvent());
			break;
		case EventType::OnKeyDown:
		case EventType::OnKeyUp:
			event->KeyEvent = std::unique_ptr<KeyEvent>(new KeyEvent());
			break;
		}

		event->SetHandled(false);
		m_Events[event->GetId()] = event;

		return event->GetId();
	}

	bool EventDispatcher::DispatchEvent(EventType dispatchType, std::string eventName = "", bool markAsHandled = false)
	{

		for (auto e : m_Events)
		{
			Event *event = e.second;

			if (event->GetHandled())
				continue;

			if (event->GetType() != dispatchType && dispatchType != EventType::UserDefined)
				continue;

			if (dispatchType == EventType::UserDefined && eventName != event->GetName())
				continue;

			for (auto callback : event->GetCallbacks())
			{
				// Calls the callback with a paramater of the event dispatched
				callback(*event);
			}

			if (markAsHandled)
				event->SetHandled(true);

			return true;
		}

		return false;
	}

	Event &EventDispatcher::GetEventFromId(unsigned int eventId)
	{
		return *m_Events[eventId];
	}

	Event &EventDispatcher::GetEventByName(std::string eventName)
	{
		return *m_Events[GetEventIdByName(eventName)];
	}

	unsigned int EventDispatcher::GetEventIdByName(std::string eventName)
	{
		for (auto e : m_Events)
		{
			Event *event = e.second;

			if (event->GetName() == eventName)
				return event->GetId();
		}

		return NULL;
	}
}
