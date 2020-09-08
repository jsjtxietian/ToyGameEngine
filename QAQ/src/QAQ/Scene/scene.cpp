#include "qaqpch.h"

#include <glm/glm.hpp>
#include "QAQ/Scene/Scene.h"
#include "QAQ/Scene/Component.h"
#include "QAQ/Renderer/Renderer2D.h"
#include "QAQ/Scene/Entity.h"

namespace QAQ {

	static void DoMath(const glm::mat4& transform)
	{

	}

	static void OnTransformConstruct(entt::registry& r, entt::entity e)
	{

	}

	Scene::Scene()
	{
#if 0 // example
		struct MeshComponent
		{
			float value;
			MeshComponent() = default;
		};

		struct TranformComponent
		{
			glm::mat4 Tranform;
			TranformComponent() = default;
			TranformComponent(const glm::mat4& transform)
				: Tranform(transform) {}

			operator const glm::mat4& () const { return Tranform; }
			operator glm::mat4& () { return Tranform; }
		};

		entt::entity entity = m_Registry.create();
		m_Registry.emplace<TranformComponent>(entity, glm::mat4(1.0f));

		m_Registry.on_construct<TranformComponent>().connect<&OnTransformConstruct>();

		if (m_Registry.has<TranformComponent>(entity))
			auto& transform = m_Registry.get<TranformComponent>(entity);

		auto view = m_Registry.view<TranformComponent>();
		for (auto e : view)
		{
			auto& t = view.get<TranformComponent>(e);
		}
#endif
	}

	Scene::~Scene()
	{

	}

	Entity Scene::CreateEntity(const std::string& name)
	{
		Entity entity = { m_Registry.create(),this };
		entity.AddComponent<TransformComponent>();

		auto& tag = entity.AddComponent<TagComponent>();
		tag.Tag = name.empty() ? "Entity" : name;

		return entity;
	}

	void Scene::OnUpdate(Timestep ts)
	{
		//Update scripts
		{
			m_Registry.view<NativeScriptComponent>().each([=](auto entity, auto& nsc)
			{
				if (!nsc.Instance)
				{
					nsc.InstantiateFunction();
					nsc.Instance->m_Entity = Entity{ entity, this };
					if (nsc.OnCreateFunction)
						nsc.OnCreateFunction(nsc.Instance);
				}
				if (nsc.OnUpdateFunction)
					nsc.OnUpdateFunction(nsc.Instance, ts);
			});
		}

		//render 2D
		SceneCamera* mainCamera = nullptr;
		glm::mat4* cameraTransform = nullptr;

		auto view = m_Registry.view<TransformComponent, CameraComponent >();
		for (auto entity : view)
		{
			auto& [transform, camera] = view.get<TransformComponent, CameraComponent>(entity);
			if (camera.Primary)
			{
				mainCamera = &camera.Camera;
				cameraTransform = &transform.Transform;
				break;
			}
		}

		if (mainCamera)
		{
			Renderer2D::BeginScene(mainCamera->GetProjection(),*cameraTransform);


			auto group = m_Registry.group<TransformComponent>(entt::get<SpriteRendererComponent>);
			for (auto entity : group)
			{
				auto& [transform, sprite] = group.get<TransformComponent, SpriteRendererComponent>(entity);
				Renderer2D::DrawQuad(transform, sprite.Color);
			}

			Renderer2D::EndScene();
		}


	}

	void Scene::OnViewportResize(uint32_t width, uint32_t height)
	{
		m_ViewportWidth = width;
		m_ViewportHeight = height;

		//resize non-FixedAspectRatio Camera

		auto view = m_Registry.view<CameraComponent >();
		for (auto entity : view)
		{
			auto& camera = view.get<CameraComponent>(entity);
			if (!camera.FixAspectRatio)
			{
				camera.Camera.SetViewportSize(width, height);
			}
		}
	}
}