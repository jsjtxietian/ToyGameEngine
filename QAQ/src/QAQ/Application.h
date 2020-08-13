#pragma once

#include "Core.h"
#include "Window.h"
#include "QAQ/LayerStack.h"
#include "QAQ/Events/Event.h"
#include "QAQ/Events/ApplicationEvent.h"


namespace QAQ
{
	class QAQ_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverLay(Layer* layer);

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	//to be defined in client
	Application* CreateApplication();

}

