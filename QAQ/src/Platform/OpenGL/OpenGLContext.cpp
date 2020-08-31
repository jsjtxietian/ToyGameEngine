#include "qaqpch.h"

#include "Platform/OpenGL/OpenGLContext.h"

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
		QAQ_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		QAQ_CORE_ASSERT(status, "Failed to init Glad!");

		QAQ_CORE_INFO("OpenGL Info:");
		QAQ_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		QAQ_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		QAQ_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

#ifdef QAQ_ENABLE_ASSERTS
		int versionMajor;
		int versionMinor;
		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

		QAQ_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "QAQ requires at least OpenGL version 4.5!");
#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		QAQ_PROFILE_FUNCTION();

		glfwPollEvents();
		glfwSwapBuffers(m_WindowHandle);
	}
}