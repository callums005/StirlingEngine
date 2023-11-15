#pragma once

#include "Debug.h"
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>

#include "Utils.hpp"

enum LineTypes
{
	Unknown = -1,
	BlockStart = 0, // Has tag { in line (x1)
	BlockEnd = 1,	// Has } in line (x1)
	Assignment = 2, // Has = in line (x1)
};

namespace StirlingEngine
{
	class SEDataHandler
	{
	public:
		SEDataHandler(std::string resPath);

		std::map<std::string, std::string> Variables;

	private:
	};
}