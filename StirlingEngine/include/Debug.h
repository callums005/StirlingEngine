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
		static void Log(const DebugLevel debugLevel, const char* fmt, ...);
		static void Log(const char* fmt, ...);
	};
}