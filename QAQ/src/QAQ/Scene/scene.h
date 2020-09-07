#pragma once

#include <entt.hpp>
#include "QAQ/Core/TimeStep.h"

namespace QAQ {

	class Entity;

	class Scene
	{
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string& name = std::string());

		//temp
		entt::registry& Reg() { return m_Registry; }

		void OnUpdate(TimeStep ts);

	private:
		entt::registry m_Registry;

		friend class Entity;
	};
}