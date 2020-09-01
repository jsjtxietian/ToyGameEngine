#pragma once

#include "QAQ/Core/Layer.h"
#include "QAQ/Events/MouseEvent.h"
#include "QAQ/Events/KeyEvent.h"
#include "QAQ/Events/ApplicationEvent.h"

namespace QAQ
{
	class  ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach();
		virtual void OnDetach();
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
} 
