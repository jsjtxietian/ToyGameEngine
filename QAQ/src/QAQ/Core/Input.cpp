#include "qaqpch.h"
#include "QAQ/Core/Input.h"

#ifdef QAQ_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsInput.h"
#endif

namespace QAQ {

	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
#ifdef QAQ_PLATFORM_WINDOWS
		return CreateScope<WindowsInput>();
#else
		QAQ_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}
}