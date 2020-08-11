#pragma once

#include "Core.h"

namespace QAQ
{
	class QAQ_API__ Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//to be defined in client
	Application* CreateApplication();

}

