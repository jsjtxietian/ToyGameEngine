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

		void BlockEvents(bool block) { m_BlockEvents = block; }

	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};
} 
