#include "qaqpch.h"

#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace QAQ {

	OpenGLContext::OpenGLContext(GLFWwindow * windowHandle)
		:m_WindowHandle(windowHandle)
	{
		QAQ_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		QAQ_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		QAQ_CORE_ASSERT(status, "Failed to init Glad!");

		QAQ_CORE_INFO("OpenGL Info:");
		QAQ_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		QAQ_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		QAQ_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

		QAQ_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Hazel requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		QAQ_PROFILE_FUNCTION();

		glfwPollEvents();
		glfwSwapBuffers(m_WindowHandle);
	}
}
