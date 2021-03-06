#pragma once

#include "QAQ/Core/Base.h"
#include "QAQ/Core/Window.h"
#include "QAQ/Core/LayerStack.h"
#include "QAQ/Events/Event.h"
#include "QAQ/Events/ApplicationEvent.h"
#include "QAQ/ImGui/ImGuiLayer.h"
#include "QAQ/Core/Timestep.h"

int main(int argc, char** argv);

namespace QAQ
{
	class Application
	{
	public:
		Application(const std::string& name = "QAQ Engine");
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverLay(Layer* layer);

		inline  Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }

		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
		void Run();

		static Application* s_Instance;

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0;

		friend int ::main(int argc, char** argv);
	};

	//to be defined in client
	Application* CreateApplication();

}

