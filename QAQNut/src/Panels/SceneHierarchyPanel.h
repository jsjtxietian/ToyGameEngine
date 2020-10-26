#pragma once
#pragma once

#include "QAQ/Core/Base.h"
#include "QAQ/Scene/Scene.h"
#include "QAQ/Scene/Entity.h"

namespace QAQ {

	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& scene);

		void SetContext(const Ref<Scene>& scene);

		void OnImGuiRender();

	private:
		void DrawEntityNode(Entity entity);
		void DrawComponents(Entity entity);
		
		Ref<Scene> m_Context;
		Entity m_SelectionContext;
	};

}
