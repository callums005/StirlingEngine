# Event

## Member Objects
`m_Id` stores an unsigned int of the event.
```cpp
unsigned int m_Id;
```
---
`m_EventName` stores a string of the event name.
```cpp
std::string m_EventName;
```
---
`m_EventType` stores the type of event.
```cpp
EventType m_EventType;
```
---
`m_Handled` stores whether the event has been handled or not.
```cpp
bool m_Handled = false;
```
---
`m_Callbacks` stores a vector of the callback functions subscribed to the event.
```cpp
std::vector<std::function<void(Event &)>> m_Callbacks;
```

---
## Constructor
```cpp
Event(const unsigned int id, const std::string eventName, const EventType eventType)
	: m_Id(id), m_EventName(eventName), m_EventType(eventType)
{
}
```

## Member Functions
`operator+=` allows you to subscribe functions to the event.

**Paramaters:** `const std::function<void(Event &)>`

**Returns:** `void` 

```cpp
void operator+=(const std::function<void(Event &)> func);
```
---