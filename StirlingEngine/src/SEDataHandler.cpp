#include "SEDataHandler.h"

namespace StirlingEngine
{
	Variable::Variable() {}
	Variable::Variable(int line, Scope s, std::string id, std::string val)
		: lineNumber(line), scope(s), identifer(id), value(val)
	{
	}

	Scope::Scope() {}
	Scope::Scope(int line, std::string s, std::string id)
		: lineNumber(line), scope(s), identifer(id)
	{
	}

	std::string Scope::GetScopePath()
	{
		std::stringstream ss;

		if (scope == "")
		{
			ss << identifer;
		}
		else
		{
			ss << scope << "/" << identifer;
		}

		return ss.str();
	}

	SEDataHandler::SEDataHandler(std::string resPath)
	{
		std::string lineText;
		std::stringstream stringStream;
		std::string seg;
		std::vector<std::string> segList;
		Scope *currentScope = nullptr;

		std::ifstream resFile(resPath);

		int lineCount = 0;

		LineTypes lineType;
		LineTypes lastLineType;

		while (std::getline(resFile, lineText))
		{
			seg = "";
			segList = std::vector<std::string>();

			stringStream = std::stringstream(lineText);
			lineCount++;

			lineType = LineTypes::Unknown;
			int errCount = 0;

			if (lineText.find("{") != std::string::npos)
				lineType = LineTypes::ScopeStart;
			else
				errCount++;

			if (lineText.find("}") != std::string::npos)
				lineType = LineTypes::ScopeEnd;
			else
				errCount++;

			if (lineText.find("=") != std::string::npos)
				lineType = LineTypes::Assignment;
			else
				errCount++;

			if (errCount == 3)
			{
				Debug::Log(DebugLevel::Error, "Entity (\"%s\") has an unrecognised instruction at Line: %i", resPath.c_str(), lineCount);
				continue;
			}

			switch (lineType)
			{
			case LineTypes::ScopeStart:
				while (std::getline(stringStream, seg, ' '))
				{
					seg.erase(std::remove_if(
								  seg.begin(), seg.end(),
								  [l = std::locale{}](auto ch)
								  { return std::isspace(ch, l); }),
							  seg.end());
					segList.push_back(seg);
				}

				if (segList.size() > 2 || segList.size() < 2)
				{
					Debug::Log(DebugLevel::Error, "Entity (\"%s\") has invalid scope syntax at Line: %i. Follow the syntax <identifier> {.", resPath.c_str(), lineCount);
					break;
				}

				Scopes.push_back(Scope(lineCount, currentScope == nullptr ? "" : currentScope->identifer, segList[0]));
				currentScope = &Scopes.back();

				break;
			case LineTypes::ScopeEnd:
				break;
			case LineTypes::Assignment:
				while (std::getline(stringStream, seg, ' '))
				{
					seg.erase(std::remove_if(
								  seg.begin(), seg.end(),
								  [l = std::locale{}](auto ch)
								  { return std::isspace(ch, l); }),
							  seg.end());
					segList.push_back(seg);
				}

				if (segList.size() > 3 || segList.size() < 3)
				{
					Debug::Log(DebugLevel::Error, "Entity (\"%s\") has invalid assignment syntax at Line: %i. Follow the syntax <identifier> = <value>.", resPath.c_str(), lineCount);
					break;
				}

				if (currentScope == nullptr)
				{
					Debug::Log(DebugLevel::Error, "Entity (\"%s\") you must define a scope before assigning a variable at Line: %i.", resPath.c_str(), lineCount);
					break;
				}

				for (auto var : Variables[currentScope->identifer])
				{
					if (var.identifer == segList[0])
					{
						Debug::Log(DebugLevel::Warning, "Entity (\"%s\") variable \"%s\" is already assigned, this will override the last value at Line: %i.", resPath.c_str(), segList[0].c_str(), lineCount);
						break;
					}
				}

				Variables[currentScope->GetScopePath()].push_back(Variable(lineCount, *currentScope, segList[0], segList[2]));

				break;
			default:
				break;
			}

			lastLineType = lineType;
		}
	}

	std::string SEDataHandler::GetValueFromScope(std::string scope, std::string identifer)
	{
		for (Variable var : Variables[scope])
		{
			if (var.identifer == identifer)
				return var.value;
		}

		return "NULL";
	}
}