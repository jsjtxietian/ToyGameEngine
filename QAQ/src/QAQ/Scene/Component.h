#pragma once

#include <glm/glm.hpp>

namespace QAQ {

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


}