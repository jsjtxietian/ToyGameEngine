#pragma once

#include "QAQ/Layer.h"
#include "QAQ/Events/MouseEvent.h"
#include "QAQ/Events/KeyEvent.h"
#include "QAQ/Events/ApplicationEvent.h"

namespace QAQ
{
	class QAQ_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach();
		virtual void OnDetach();
		virtual void OnImGuiRender();
		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
} 
