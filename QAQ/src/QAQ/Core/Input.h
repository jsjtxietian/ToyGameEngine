#pragma once

#include "QAQ/Core/Base.h"
#include "QAQ/Core/KeyCodes.h"
#include "QAQ/Core/MouseCodes.h"

namespace QAQ {
	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);
		static bool IsMouseButtonPressed(MouseCode button);
		static float GetMouseX();
		static float GetMouseY();
		static std::pair<float, float> GetMousePosition();
	};
}