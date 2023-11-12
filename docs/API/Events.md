# Events
The event system allows you to interface with core events from the Stirling Engine along with custom user-defined events.

## Core Events

| Event ID | Event Name | Event Description |
| -------- | ---------- | ----------- |
| 1 | OnApplicationStart | Dispatched when the application starts |
| 2 | OnApplicationUpdate | Dispatched when the application updates each frame |
| 3 | OnApplicationExit | Dispatched when the application ends (after the window is closed) |
| 4 | OnWindowClose | Dispatched when the window requests to close |
| 5 | OnWindowResize | Dispatched when the window is resized
| ~~6~~ | ~~OnWindowMove~~ | ~~UNUSED~~ |
| 7 | OnMouseDown | Dispatched when a mouse button is pressed |
| 8 | OnMouseUp | Dispatched when a mouse button is released |
| 9 | OnMouseMove | Dispatched when the mouse is moved |
| 10 | OnMouseScroll | Dispatched when the mouse wheel is moved |
| 11 | OnKeyDown | Dispatched when a key is pressed |
| 12 | OnKeyUp | Dispatched when a key is released |

## User Defined

### Generate an Event

You are able to define your own events using the `GenerateEvent` function:
```cpp
StirlingEngine::EventDispatcher::GenerateEvent("MyCustomEvent");
```
Or;
```cpp
StirlingEngine::EventDispatcher::GenerateEvent("MyCustomEvent", StirlingEngine::EventType::UserDefined);
```

You must set the `EventType` to `EventType::UserDefined`, for the dispatcher to dispatch by event name instead of type.

## Subscribing to Events

To call user defined functions when an event is triggered you must subscribe a function to an event.

To subscribe to an event you can use the `+=` operator paired with the `Subscribe` macro. 

All callback functions must be defined the same way:

```cpp
void ExampleCallback(StirlingEngine::Event &event)
{
	StirlingEngine::Debug::Log("Hello World!: %s", event.GetName().c_str());
}
```
Finally, to subscribe to the callback you can use this code snippet:

```cpp
StirlingEngine::EventDispatcher::GetEventByName("MyCustomEvent") += Subscribe(ExampleCallback);
```

### Dispatching an Event

To trigger an event you have to use the `DispatchEvent` function:
```cpp
StirlingEngine::EventDispatcher::DispatchEvent(StirlingEngine::EventType::UserDefined, "MyCustomEvent", false);
```

