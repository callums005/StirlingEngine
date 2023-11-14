#include "Debug.h"

#include <typeinfo>

namespace StirlingEngine
{
	void Debug::Log(const char *fmt, ...)
	{
		va_list vargs;
		va_start(vargs, fmt);
		printf("\033[%s;m%s\t", "90", "[INFO] ");
		vprintf(fmt, vargs);
		printf("\033[0;m\n");
		va_end(vargs);
	}

	void Debug::Log(const DebugLevel debugLevel, const char *fmt, ...)
	{
		std::ofstream crashFile;

		const char *prefix = "";
		const char *colour = "";

		switch (debugLevel)
		{
		case DebugLevel::Info:
			prefix = "[INFO] ";
			colour = "90";
			break;
		case DebugLevel::Debug:
			prefix = "[DEBUG] ";
			colour = "32";
			break;
		case DebugLevel::Warning:
			prefix = "[WARNING] ";
			colour = "93";
			break;
		case DebugLevel::Error:
			prefix = "[ERROR] ";
			colour = "91";
			break;
		case DebugLevel::Critical:
			prefix = "[CRITICAL] ";
			colour = "91";

			crashFile.open("crash_report.txt", std::ios::app);
			crashFile << fmt << std::endl;
			crashFile.close();

			break;
		default:
			Log(DebugLevel::Critical, "Invalid DebugLevel {%i}", (int)debugLevel);
			return;
		}

		va_list vargs;
		va_start(vargs, fmt);
		printf("\033[%s;m%s", colour, prefix);
		vprintf(fmt, vargs);
		printf("\033[0;m\n");
		va_end(vargs);
	}
}