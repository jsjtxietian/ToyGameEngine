#include "qaqpch.h"

#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace QAQ {

	OpenGLContext::OpenGLContext(GLFWwindow * windowHandle)
		:m_WindowHandle(windowHandle)
	{
		QAQ_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		QAQ_CORE_ASSERT(status, "Failed to init Glad!");

		QAQ_CORE_INFO("OpenGL Info:");
		QAQ_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		QAQ_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		QAQ_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_WindowHandle);
	}
}