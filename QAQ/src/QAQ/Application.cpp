#include "Application.h"
#include "QAQ/Events/ApplicationEvent.h"
#include "QAQ/Log.h"

namespace QAQ
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			QAQ_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			QAQ_TRACE(e);
		}
		while (true);
	}

}

