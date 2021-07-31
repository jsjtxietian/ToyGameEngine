#include "qaqpch.h"
#include "QAQ/Renderer/GraphicsContext.h"

#include "QAQ/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace QAQ {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    QAQ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		QAQ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}