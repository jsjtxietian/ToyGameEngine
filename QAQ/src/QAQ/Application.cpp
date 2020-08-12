#include "qaqpch.h"
#include "Application.h"
#include "QAQ/Events/ApplicationEvent.h"
#include "QAQ/Log.h"
#include <GLFW/glfw3.h>

namespace QAQ
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (true)
		{
			while (m_Running)
			{
				glClearColor(1, 0, 1, 1);
				glClear(GL_COLOR_BUFFER_BIT);
				m_Window->OnUpdate();
			}
		}
	}

}

