#include "qaqpch.h"
#include "Entity.h"

namespace QAQ {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{
	}

}