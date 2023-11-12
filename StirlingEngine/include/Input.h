#pragma once

#include "Events/EventDispatcher.h"

namespace StirlingEngine
{
	enum class InputState
	{
		Pressed,
		Released,
		Up
	};

	enum class Key
	{
		KEY_UNKNOWN = -1,
		KEY_A = 0,
		KEY_B,
		KEY_C,
		KEY_D,
		KEY_E,
		KEY_F,
		KEY_G,
		KEY_H,
		KEY_I,
		KEY_J,
		KEY_K,
		KEY_L,
		KEY_M,
		KEY_N,
		KEY_O,
		KEY_P,
		KEY_Q,
		KEY_R,
		KEY_S,
		KEY_T,
		KEY_U,
		KEY_V,
		KEY_W,
		KEY_X,
		KEY_Y,
		KEY_Z,
		KEY_NUM0,
		KEY_NUM1,
		KEY_NUM2,
		KEY_NUM3,
		KEY_NUM4,
		KEY_NUM5,
		KEY_NUM6,
		KEY_NUM7,
		KEY_NUM8,
		KEY_NUM9,
		KEY_ESCAPE,
		KEY_LCONTROL,
		KEY_LSHIFT,
		KEY_LALT,
		KEY_LSYSTEM, // Left "Super" key
		KEY_RCONTROL,
		KEY_RSHIFT,
		KEY_RALT,
		KEY_RSYSTEM, // Right "Super" key
		KEY_MENU,
		KEY_LBRACKET,
		KEY_RBRACKET,
		KEY_SEMICOLON,
		KEY_COMMA,
		KEY_PERIOD,
		KEY_QUOTE,
		KEY_SLASH,
		KEY_BACKSLASH,
		KEY_TILDE,
		KEY_EQUAL,
		KEY_HYPHEN,
		KEY_SPACE,
		KEY_ENTER,
		KEY_BACKSPACE,
		KEY_TAB,
		KEY_PAGEUP,
		KEY_PAGEDOWN,
		KEY_END,
		KEY_HOME,
		KEY_INSERT,
		KEY_DELETE,
		KEY_ADD,
		KEY_SUBTRACT,
		KEY_MULTIPLY,
		KEY_DIVIDE,
		KEY_LEFT,
		KEY_RIGHT,
		KEY_UP,
		KEY_DOWN,
		KEY_NUMPAD0,
		KEY_NUMPAD1,
		KEY_NUMPAD2,
		KEY_NUMPAD3,
		KEY_NUMPAD4,
		KEY_NUMPAD5,
		KEY_NUMPAD6,
		KEY_NUMPAD7,
		KEY_NUMPAD8,
		KEY_NUMPAD9,
		KEY_F1,
		KEY_F2,
		KEY_F3,
		KEY_F4,
		KEY_F5,
		KEY_F6,
		KEY_F7,
		KEY_F8,
		KEY_F9,
		KEY_F10,
		KEY_F11,
		KEY_F12,
		KEY_F13,
		KEY_F14,
		KEY_F15,
		KEY_PAUSE,
		KEY_KEYCOUNT,
	};

	enum class MouseButton
	{
		MOUSE_BUTTON_UNKNOWN = -1,
		MOUSE_BUTTON_LEFT = 0,
		MOUSE_BUTTON_RIGHT,
		MOUSE_BUTTON_MIDDLE,
		MOUSE_BUTTON_XBUTTON1, // Extra Mouse Button, usually button3
		MOUSE_BUTTON_XBUTTON2, // Extra Mouse Button, usually button4
		MOUSE_BUTTON_BUTTONCOUNT
	};

	class Input
	{
	public:
		static void Init();

		/// @brief Callback function to be called when the event is triggered
		/// @param event The event that is dispatched
		static void HandleEvent(Event &event);

		/// @brief Called each frame of the game
		static void Update();

		/*
		******************* Keyboard *******************
		*/

		/// @brief Checks if a key is pressed down
		/// @param key The key to check
		/// @return If the key is down
		static bool IsKeyDown(Key key);

		/// @brief Checks if the key is released this frame
		/// @param key The key to check
		/// @return If the key was released this frame
		static bool IsKeyUpThisFrame(Key key);

		/// @brief Checks if the key is released
		/// @param key The key to check
		/// @return If the key is released
		static bool IsKeyUp(Key key);

		/*
		******************* Mouse *******************
		*/

		/// @brief Checks if a mouse button is pressed down
		/// @param button The button to check
		/// @return If the mouse button is down
		static bool IsMouseDown(MouseButton button);

		/// @brief Checks if a mouse button is released this frame
		/// @param button The button to check
		/// @return If the mouse button is released this frame
		static bool IsMouseUpThisFrame(MouseButton button);

		/// @brief Checks if a mouse button is released
		/// @param button The button to check
		/// @return If the mouse button is released
		static bool IsMouseUp(MouseButton button);

		/// @brief Gets the mouse X and Y position
		/// @return The mouse X and Y position
		static std::pair<int, int> GetMousePosition();
		static std::pair<double, double> GetMouseScrollOffset();

	private:
		static InputState m_KeyStates[100];
		static InputState m_MouseStates[6];
		static int m_MouseX;
		static int m_MouseY;
		static double m_OffsetX;
		static double m_OffsetY;
		static bool m_IsInit;
	};

}