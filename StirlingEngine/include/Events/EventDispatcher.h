#pragma once

#include <map>

#include "../Events.h"

namespace StirlingEngine
{
	class EventDispatcher
	{
	public:
#define Subscribe(func) [this](StirlingEngine::Event &e) { this->func(e); }

		/// @brief Generates a new event
		/// @param name The name of the event
		/// @param type The type of the event
		/// @return Event ID
		static unsigned int GenerateEvent(std::string name, EventType type);

		/// @brief This function is called to dispatch the event
		/// @param dispatchType The event type to be dispatched
		/// @param eventName The name of the event to dispatch (only if user-defined event)
		/// @param markAsHandled Whether or not to mark the event has handled
		/// @return Returns true if the event dispatches correctly
		static bool DispatchEvent(EventType dispatchType, std::string eventName = std::string(""), bool markAsHandled = false);

		/// @brief Get the event by Id
		/// @param eventId The id of the event you want to get
		/// @return Reference of the event you got by id
		static Event &GetEventFromId(unsigned int eventId);

		/// @brief Get the event by name
		/// @param eventName The name of the event you want to get
		/// @return Reference of the event you got by name
		static Event &GetEventByName(std::string eventName);

		/// @brief Get the event's id by name
		/// @param eventName The name of the event you want to get the id of
		/// @return Id of the event you got by name
		static unsigned int GetEventIdByName(std::string eventName);

	private:
		static std::map<unsigned int, Event *> m_Events;
		static unsigned int m_EventCount;
	};
}