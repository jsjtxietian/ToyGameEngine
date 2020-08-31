#include "qaqpch.h"

#include "QAQ/Core/Application.h"
#include "QAQ/Core/Log.h"
#include "QAQ/Core/Input.h"
#include "QAQ/Renderer/Renderer.h"

#include <glfw/glfw3.h>

namespace QAQ
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		QAQ_PROFILE_FUNCTION();

		QAQ_CORE_ASSERT(!s_Instance, "App already exists");
		s_Instance = this;
		m_Window = Window::Create();
		m_Window->SetEventCallback(QAQ_BIND_EVENT_FN(Application::OnEvent));

		Renderer::Init();

		m_ImGuiLayer = new ImGuiLayer();
		PushOverLay(m_ImGuiLayer);
	}

	Application::~Application()
	{
		QAQ_PROFILE_FUNCTION();

		Renderer::Shutdown();
	}


	void Application::Run()
	{
		QAQ_PROFILE_FUNCTION();

		while (m_Running)
		{
			QAQ_PROFILE_SCOPE("RunLoop");

			float time = (float)glfwGetTime();
			TimeStep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;


			if (!m_Minimized)
			{
				QAQ_PROFILE_SCOPE("LayerStack OnUpdate");

				for (Layer* layer : m_LayerStack)
					layer->OnUpdate(timestep);
			}

			m_ImGuiLayer->Begin();
			{
				QAQ_PROFILE_SCOPE("ImGui OnUpdate");
				for (Layer* layer : m_LayerStack)
					layer->OnImGuiRender();
			}
			m_ImGuiLayer->End();

			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event & e)
	{
		QAQ_PROFILE_FUNCTION();

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(QAQ_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(QAQ_BIND_EVENT_FN(Application::OnWindowResize));

		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
		{
			(*it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	void Application::PushLayer(Layer * layer)
	{
		QAQ_PROFILE_FUNCTION();

		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverLay(Layer * layer)
	{
		QAQ_PROFILE_FUNCTION();

		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	bool Application::OnWindowClose(WindowCloseEvent & e)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		QAQ_PROFILE_FUNCTION();

		if (e.GetWidth() == 0 || e.GetHeight() == 0)
		{
			m_Minimized = true;
			return false;
		}

		m_Minimized = false;
		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

		return false;
	}

}

