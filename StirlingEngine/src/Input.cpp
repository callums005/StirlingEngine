#include "Input.h"

namespace StirlingEngine
{
	InputState Input::m_KeyStates[100];
	InputState Input::m_MouseStates[6];
	int Input::m_MouseX = 0;
	int Input::m_MouseY = 0;
	double Input::m_OffsetX = 0.0;
	double Input::m_OffsetY = 0.0;
	bool Input::m_IsInit = false;

	void Input::Init()
	{
		if (m_IsInit)
			return;

		EventDispatcher::GetEventByName("OnKeyDown") += [](Event &event)
		{ HandleEvent(event); };
		EventDispatcher::GetEventByName("OnKeyUp") += [](Event &event)
		{ HandleEvent(event); };
		EventDispatcher::GetEventByName("OnMouseDown") += [](Event &event)
		{ HandleEvent(event); };
		EventDispatcher::GetEventByName("OnMouseUp") += [](Event &event)
		{ HandleEvent(event); };
		EventDispatcher::GetEventByName("OnMouseMove") += [](Event &event)
		{ HandleEvent(event); };

		for (int i = 0; i < 100; i++)
		{
			m_KeyStates[i] = InputState::Up;
		}

		for (int i = 0; i < 6; i++)
		{
			m_MouseStates[i] = InputState::Up;
		}
	}

	void Input::HandleEvent(Event &event)
	{
		switch (event.GetId())
		{
		case 7:
			m_MouseStates[event.OnMouseButtonEvent->MouseButton] = InputState::Pressed;
			break;
		case 8:
			m_MouseStates[event.OnMouseButtonEvent->MouseButton] = InputState::Released;
			break;
		case 9:
			m_MouseX = event.OnMouseMoveEvent->MouseX;
			m_MouseY = event.OnMouseMoveEvent->MouseY;
			break;
		case 10:
			m_OffsetX = event.OnMouseScrollEvent->OffsetX;
			m_OffsetY = event.OnMouseScrollEvent->OffsetY;
			break;
		case 11:
			m_KeyStates[event.OnKeyEvent->KeyCode] = InputState::Pressed;
			break;
		case 12:
			m_KeyStates[event.OnKeyEvent->KeyCode] = InputState::Released;
			break;
		}
	}

	void Input::Update()
	{

		for (int i = 0; i < 100; i++)
		{
			if (m_KeyStates[i] == InputState::Released)
				m_KeyStates[i] = InputState::Up;
		}

		for (int i = 0; i < 6; i++)
		{
			if (m_MouseStates[i] == InputState::Released)
				m_MouseStates[i] = InputState::Up;
		}
	}

	bool Input::IsKeyDown(Key key)
	{
		return (m_KeyStates[(int)key] == InputState::Pressed);
	}

	bool Input::IsKeyUpThisFrame(Key key)
	{
		return m_KeyStates[(int)key] == InputState::Released;
	}

	bool Input::IsKeyUp(Key key)
	{
		return m_KeyStates[(int)key] == InputState::Up;
	}

	bool Input::IsMouseDown(MouseButton button)
	{
		return m_MouseStates[(int)button] == InputState::Pressed;
	}

	bool Input::IsMouseUpThisFrame(MouseButton button)
	{
		return m_MouseStates[(int)button] == InputState::Released;
	}

	bool Input::IsMouseUp(MouseButton button)
	{
		return m_MouseStates[(int)button] == InputState::Up;
	}

	std::pair<int, int> Input::GetMousePosition()
	{
		return std::pair<int, int>(m_MouseX, m_MouseY);
	}

	std::pair<double, double> Input::GetMouseScrollOffset()
	{
		return std::pair<double, double>(m_OffsetX, m_OffsetY);
	}

}