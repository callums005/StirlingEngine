#pragma once

#include <vector>
#include <map>

#include "Entity.hpp"

namespace StirlingEngine
{
	typedef std::vector<Entity *> EntityVector;
	typedef std::map<std::string, EntityVector> EntityMap;

	class EntityManager
	{
	public:
		static void Update();
		static unsigned int CreateEntity(const std::string resourcePath);
		static EntityVector &GetEntities();
		static EntityVector &GetEntities(const std::string tag);
		static Entity *GetEntityByID(unsigned int);

	private:
		static void HandleDeleteEntity();
		static void HandleAddEntity();

		static EntityVector m_Entities;
		static EntityMap m_EntityMap;

		static EntityVector m_AddBuffer;
		static EntityVector m_RemBuffer;
		static EntityMap m_RemMap;

		static unsigned int m_EntityCount;
	};
}