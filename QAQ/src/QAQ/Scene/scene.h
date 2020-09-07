#pragma once

#include <entt.hpp>
#include "QAQ/Core/TimeStep.h"

namespace QAQ {
	class Scene
	{
	public:
		Scene();
		~Scene();

		entt::entity CreateEntity();

		//temp
		entt::registry& Reg() { return m_Registry; }

		void OnUpdate(TimeStep ts);

	private:
		entt::registry m_Registry;
	};
}