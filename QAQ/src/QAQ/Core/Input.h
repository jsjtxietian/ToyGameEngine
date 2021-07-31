#pragma once

#include <glm/glm.hpp>

#include "QAQ/Core/KeyCodes.h"
#include "QAQ/Core/MouseCodes.h"

namespace QAQ {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
