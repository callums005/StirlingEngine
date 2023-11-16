#pragma once

#include <string>

#include "../SEDataHandler.h"

#include "Components/cTransform.h"

namespace StirlingEngine
{
	class Entity
	{
	public:
		Entity() {}
		Entity(std::string entityFilePath)
		{
			m_DataHandler = new SEDataHandler(entityFilePath);

			SetName(m_DataHandler->GetValueFromScope("Entity", "name"));
			SetTag(m_DataHandler->GetValueFromScope("Entity", "tag"));

			Transform = new cTransform(m_DataHandler);
		}

		~Entity()
		{
			delete Transform;
			delete m_DataHandler;
		}

		cTransform *Transform = nullptr;

		void SetId(unsigned int id)
		{
			m_Id = id;
		}

		void SetName(std::string name)
		{
			m_Name = name;
		}

		void SetTag(std::string tag)
		{
			m_Tag = tag;
		}

		unsigned int GetId()
		{
			return m_Id;
		}

		std::string GetName()
		{
			return m_Name;
		}

		std::string GetTag()
		{
			return m_Tag;
		}

		SEDataHandler *m_DataHandler;

		std::string ToString()
		{
			std::string result;

			std::string id = std::to_string(m_Id);

			result += "Entity: ";
			result += id + "\n";
			result += "Name: ";
			result += m_Name + "\t";
			result += "Tag: ";
			result += m_Tag + "\t";

			if (Transform != nullptr)
			{
				result += "\n\t{\t";
				result += Transform->ToString() + "}";
			}

			return result;
		}

	private:
		unsigned int m_Id = 0;
		std::string m_Name = "";
		std::string m_Tag = "";
	};
}