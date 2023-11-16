#pragma once

#include "Debug.h"
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

#include "Utils.hpp"

enum LineTypes
{
	Unknown = -1,
	ScopeStart = 0, // Has tag { in line (x1)
	ScopeEnd = 1,	// Has } in line (x1)
	Assignment = 2, // Has = in line (x1)
};

namespace StirlingEngine
{
	struct Scope
	{
		Scope();
		Scope(int line, std::string s, std::string id);
		int lineNumber = 0;
		std::string identifer;
		std::string scope = "";

		std::string GetScopePath();
	};

	struct Variable
	{
		Variable();
		Variable(int line, Scope s, std::string id, std::string val);

		int lineNumber = 0;
		std::string identifer;
		std::string value;
		Scope scope;
	};

	class SEDataHandler
	{
	public:
		SEDataHandler(std::string resPath);

		std::map<std::string, std::vector<Variable>> Variables;
		std::vector<Scope> Scopes;

		std::string GetValueFromScope(std::string scope, std::string identifier);
	};
}