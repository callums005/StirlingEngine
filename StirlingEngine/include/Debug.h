#pragma once

#include <stdio.h>
#include <stdarg.h>
#include <fstream>
#include <iostream>

namespace StirlingEngine
{
	enum DebugLevel
	{
		Info = 0,
		Debug,
		Warning,
		Error,
		Critical
	};

	class Debug
	{
	public:
		/// @brief Logs text to the console
		/// @param debugLevel Sets the prefix text to display and colour
		/// @param fmt The text to display with format speecifiers
		/// @param ... variance args
		static void Log(const DebugLevel debugLevel, const char *fmt, ...);

		/// @brief Logs text to the console - defaults to DebugLevel::Info
		/// @param fmt The text to display with format speecifiers
		/// @param ... variance args
		static void Log(const char *fmt, ...);
	};
}