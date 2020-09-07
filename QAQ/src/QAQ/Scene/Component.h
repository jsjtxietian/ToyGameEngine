#pragma once

#include <glm/glm.hpp>
#include "QAQ/Renderer/Camera.h"

namespace QAQ {

	struct TagComponent
	{
		std::string Tag;
		TagComponent() = default;
		TagComponent(const TagComponent&) = default;
		TagComponent(const std::string& tag)
			: Tag(tag) {}
	};

	struct TranformComponent
	{
		glm::mat4 Tranform{ 1.0f };
		TranformComponent() = default;
		TranformComponent(const glm::mat4& transform)
			: Tranform(transform) {}

		operator const glm::mat4& () const { return Tranform; }
		operator glm::mat4& () { return Tranform; }
	};

	struct SpriteRendererComponent
	{
		glm::vec4 Color{ 1.0f,1.0f ,1.0f ,1.0f };

		SpriteRendererComponent() = default;
		SpriteRendererComponent(const SpriteRendererComponent&) = default;
		SpriteRendererComponent(const glm::vec4& color)
			: Color(color) {}
	};

	struct CameraComponent
	{
		Camera Camera;
		bool Primary = true; //todo move to scene

		CameraComponent() = default;
		CameraComponent(const CameraComponent&) = default;
		CameraComponent(const glm::mat4 & projection)
			: Camera(projection) {}
	};
}