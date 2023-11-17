#include "ECS/EntityManager.h"

namespace StirlingEngine
{
	EntityVector EntityManager::m_Entities;
	EntityMap EntityManager::m_EntityMap;

	EntityVector EntityManager::m_AddBuffer;
	EntityVector EntityManager::m_RemBuffer;
	EntityMap EntityManager::m_RemMap;

	unsigned int EntityManager::m_EntityCount;

	Entity *EntityManager::CreateEntity(const std::string resPath)
	{
		m_EntityCount++;
		Entity *e = new Entity(resPath, m_EntityCount);
		m_AddBuffer.push_back(e);
		return e;
	}

	void EntityManager::HandleAddEntity()
	{
		for (Entity *entity : m_AddBuffer)
		{
			m_Entities.push_back(entity);
			m_EntityMap[entity->GetTag()].push_back(entity);
		}

		m_AddBuffer.clear();
	}

	void EntityManager::HandleDeleteEntity()
	{
		for (Entity *entity : m_Entities)
		{
			if (!entity->GetDeleteFlag())
			{
				m_RemBuffer.push_back(entity);
				m_RemMap[entity->GetTag()].push_back(entity);
			}
		}

		m_Entities.clear();
		m_EntityMap.clear();
		m_Entities = m_RemBuffer;
		m_EntityMap = m_RemMap;
		m_RemBuffer.clear();
		m_RemMap.clear();
	}

	void EntityManager::Update()
	{
		HandleDeleteEntity();
		HandleAddEntity();

		for (Entity *entity : m_Entities)
		{
			if (!entity->IsEnabled())
				continue;

			if (entity->Transform)
				entity->Transform->System();
		}
	}

	EntityVector &EntityManager::GetEntities()
	{
		return m_Entities;
	}

	EntityVector &EntityManager::GetEntities(const std::string tag)
	{
		return m_EntityMap[tag];
	}

	Entity *EntityManager::GetEntityByID(unsigned int id)
	{
		for (Entity *entity : m_Entities)
		{
			if (entity->GetId() == id)
				return entity;
		}

		return nullptr;
	}

	Entity *EntityManager::GetEntityByName(std::string name)
	{
		for (Entity *entity : m_Entities)
		{
			if (entity->GetName() == name)
				return entity;
		}

		return nullptr;
	}
}