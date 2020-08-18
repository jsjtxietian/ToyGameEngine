#pragma once

#include "Core.h"
#include "Window.h"
#include "QAQ/LayerStack.h"
#include "QAQ/Events/Event.h"
#include "QAQ/Events/ApplicationEvent.h"
#include "QAQ/ImGui/ImGuiLayer.h"

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

		inline  Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
		static Application* s_Instance;
	};

	//to be defined in client
	Application* CreateApplication();

}

