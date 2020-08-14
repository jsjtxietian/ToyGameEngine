#pragma once

#include "QAQ/Layer.h"

namespace QAQ
{
	class QAQ_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnUpdate();
		void OnEvent(Event &event);

		void OnAttach();
		void OnDetach();

	private:
		float m_Time = 0.0f;
	};
} // namespace QAQ
