#include "SEDataHandler.h"

namespace StirlingEngine
{
	SEDataHandler::SEDataHandler(std::string resPath)
	{
		std::string textLine;

		std::ifstream resFile(resPath);

		int lineCount = 0;

		LineTypes lineType;

		while (std::getline(resFile, textLine))
		{
			lineCount++;

			lineType = LineTypes::Unknown;
			int errCount = 0;

			if (textLine.find("{") != std::string::npos)
				lineType = LineTypes::BlockStart;
			else
				errCount++;

			if (textLine.find("}") != std::string::npos)
				lineType = LineTypes::BlockEnd;
			else
				errCount++;

			if (textLine.find("=") != std::string::npos)
				lineType = LineTypes::Assignment;
			else
				errCount++;

			if (errCount == 3)
			{
				Debug::Log(DebugLevel::Error, "Entity (\"%s\")  line at Line: %i", resPath.c_str(), lineCount);
				continue;
			}

			switch (lineType)
			{
			case LineTypes::BlockStart:

				break;
			case LineTypes::BlockEnd:
				break;
			case LineTypes::Assignment:
				int seperator = textLine.find(" ");
				while (seperator != std::string::npos)
				{
					textLine.substr();
					seperator = textLine.find(" ");
				}
				break;
			default:
				break;
			}
		}
	}
}