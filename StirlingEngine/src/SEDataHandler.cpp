#include "SEDataHandler.h"

namespace StirlingEngine
{
	SEDataHandler::SEDataHandler(std::string resPath)
	{
		std::string lineText;
		std::stringstream stringStream;
		std::string seg;
		std::vector<std::string> segList;

		std::ifstream resFile(resPath);

		int lineCount = 0;

		LineTypes lineType;

		while (std::getline(resFile, lineText))
		{
			stringStream = std::stringstream(lineText);
			lineCount++;

			lineType = LineTypes::Unknown;
			int errCount = 0;

			if (lineText.find("{") != std::string::npos)
				lineType = LineTypes::BlockStart;
			else
				errCount++;

			if (lineText.find("}") != std::string::npos)
				lineType = LineTypes::BlockEnd;
			else
				errCount++;

			if (lineText.find("=") != std::string::npos)
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
				if (lineCount != 2)
					break;
					
				while(std::getline(stringStream, seg, ' '))
				{
					seg.erase(std::remove_if(seg.begin(), seg.end(), std::isspace), seg.end());
					segList.push_back(seg);
					Debug::Log("%s", seg.c_str());
				}

				break;
			default:
				break;
			}
		}
	}
}