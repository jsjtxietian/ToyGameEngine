#pragma once

#include "Core.h"
#include "Window.h"
#include "QAQ/LayerStack.h"
#include "QAQ/Events/Event.h"
#include "QAQ/Events/ApplicationEvent.h"
#include "QAQ/ImGui/ImGuiLayer.h"

#include "QAQ/Renderer/Shader.h"
#include "QAQ/Renderer/Buffer.h"

namespace QAQ
{
	class QAQ_API Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverLay(Layer* layer);

		inline  Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		static Application* s_Instance;
		
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
		
		unsigned int m_VertexArray;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
	};

	//to be defined in client
	Application* CreateApplication();

}

