#include "SEDataHandler.h"

namespace StirlingEngine
{
	// ********************************************** //
	// *				Variable					* //
	// ********************************************** //
	/// @brief Default constructor
	Variable::Variable() {}

	/// @brief Constructor
	/// @param line Line the code is on
	/// @param s // The scope the code is inside
	/// @param id // The identifier of the variable
	/// @param val // The value of the variable
	Variable::Variable(int line, Scope s, std::string id, std::string val)
		: lineNumber(line), scope(s), identifer(id), value(val)
	{
	}

	// ********************************************** //
	// *					Scope					* //
	// ********************************************** //

	/// @brief Default Constructor
	Scope::Scope() {}

	/// @brief Constructor
	/// @param line Line the code is on
	/// @param s Scope the code is inside
	/// @param id The identifier of the scope
	Scope::Scope(int line, std::string s, std::string id)
		: lineNumber(line), scope(s), identifer(id)
	{
	}

	/// @brief Get the path of the scope (The scope above and the current scope seperated by a slash "/")
	/// @return The scopes path
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

	// ********************************************** //
	// *				SEDataHandler				* //
	// ********************************************** //

	/// @brief Split the line into segments
	/// @param seg
	void SEDataHandler::SplitIntoSegments(std::stringstream &ss, std::string &segment, std::vector<std::string> &segmentList, char character)
	{
		while (std::getline(ss, segment, character))
		{
			segment.erase(std::remove_if(
							  segment.begin(), segment.end(),
							  [l = std::locale{}](auto ch)
							  { return std::isspace(ch, l); }),
						  segment.end());
			segmentList.push_back(segment);
		}
	}

	/// @brief Constructor
	/// @param resPath Path of the file to load, typically inside the /res/ folder.
	SEDataHandler::SEDataHandler(std::string resPath)
	{

		// File to load
		std::ifstream resFile(resPath);

		// Checks if the data handler has failed to load the file, if so, display an error and return
		if (resFile.fail())
		{
			Debug::Log(DebugLevel::Critical, "SEDataHandler failed to load file \"%s\"", resPath.c_str());
			return;
		}

		// The line number the parser is on
		int lineCount = 0;
		// Current line the parser is on
		std::string lineText;
		// lineText string stream, allowing the parser to split up the text
		std::stringstream ltStream;
		// The segment to work on when parsing a line
		std::string seg;
		// List of all the segments on the current line
		std::vector<std::string> segList;
		// The type of line the parser is on
		LineTypes lineType;

		// The current scope the parser is using
		Scope *currentScope = nullptr;

		// Check the file extension is .see, if not then display an error and return
		ltStream = std::stringstream(resPath);
		SplitIntoSegments(ltStream, seg, segList, '.');
		if (segList.back() != "see")
		{
			Debug::Log(DebugLevel::Error, "Entity (\"%s\"), Stirling Engine entity files must have the \".see\" file extension.", resPath.c_str());
			return;
		}

		// Loop through all lines in the file
		while (std::getline(resFile, lineText))
		{
			// Reset variables
			seg = "";
			segList.clear();
			ltStream = std::stringstream(lineText);
			lineType = LineTypes::Unknown;
			int errCount = 0;

			// Increase line count
			lineCount++;

			// Find unique tokens in a line to decide what kind of line it is parsing
			// Start of Scope, syntax <identifier> {
			if (lineText.find("{") != std::string::npos)
				lineType = LineTypes::ScopeStart;
			else
				errCount++;

			// End of Scope, syntax }
			if (lineText.find("}") != std::string::npos)
				lineType = LineTypes::ScopeEnd;
			else
				errCount++;

			// Assignment, syntax <identifier> = <value>
			if (lineText.find("=") != std::string::npos)
				lineType = LineTypes::Assignment;
			else
				errCount++;

			// If none of the tokens are in a line, print an error
			if (errCount == 3)
			{
				Debug::Log(DebugLevel::Error, "Entity (\"%s\") has an unrecognised instruction at Line: %i", resPath.c_str(), lineCount);
				continue;
			}

			// Execute code depending on the line type
			switch (lineType)
			{
			case LineTypes::ScopeStart:
				SplitIntoSegments(ltStream, seg, segList);

				// If the segment list size is not 2, display an error and stop executing line
				if (segList.size() != 2)
				{
					Debug::Log(DebugLevel::Error, "Entity (\"%s\") has invalid scope syntax at Line: %i. Follow the syntax <identifier> {.", resPath.c_str(), lineCount);
					break;
				}

				if (DoesScopeExist(segList[0]))
				{
					Debug::Log(DebugLevel::Error, "Entity (\"%s\") scopes must have unique identifiers at Line: %i.", resPath.c_str(), lineCount);
					break;
				}

				Scopes.push_back(Scope(lineCount, currentScope == nullptr ? "" : currentScope->identifer, segList[0]));
				currentScope = &Scopes.back();

				break;
			case LineTypes::ScopeEnd:
				break;
			case LineTypes::Assignment:
				SplitIntoSegments(ltStream, seg, segList);

				// If the segment list size is not 3, display an error and stop executing line
				if (segList.size() != 3)
				{
					Debug::Log(DebugLevel::Error, "Entity (\"%s\") has invalid assignment syntax at Line: %i. Follow the syntax <identifier> = <value>.", resPath.c_str(), lineCount);
					break;
				}

				// If the current scope is not set (E.G variables in no scope), display an error and stop executing line
				if (currentScope == nullptr)
				{
					Debug::Log(DebugLevel::Error, "Entity (\"%s\") you must define a scope before assigning a variable at Line: %i.", resPath.c_str(), lineCount);
					break;
				}

				// Display warning if a variable with the same name is already defined in the scope
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
		}
	}

	/// @brief Get the value of a variable inside a specific scope
	/// @param scope Typlically the scope paired with the component, E.G "transform/position"
	/// @param identifer The variable identifier/name, E.G "x"
	/// @return The value of the variable
	std::string SEDataHandler::GetValueFromScope(std::string scope, std::string identifer)
	{
		for (Variable var : Variables[scope])
		{
			if (var.identifer == identifer)
				return var.value;
		}

		return "NULL";
	}

	bool SEDataHandler::DoesScopeExist(std::string scope)
	{
		bool result = false;

		for (Scope sc : Scopes)
		{
			if (sc.identifer == scope)
				return true;
		}

		return false;
	}
}