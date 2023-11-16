#pragma once

#include <string>

#include "../SEDataHandler.h"

#include "Components/Transform.h"

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

		cTransform *Transform;

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

	private:
		unsigned int m_Id;
		std::string m_Name;
		std::string m_Tag;
	};
}