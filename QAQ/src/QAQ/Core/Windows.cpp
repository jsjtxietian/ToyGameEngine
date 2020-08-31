#include "qaqpch.h"
#include "QAQ/Core/Window.h"

#ifdef QAQ_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif

namespace QAQ
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef QAQ_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		QAQ_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}

}