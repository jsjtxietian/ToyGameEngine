#include "qaqpch.h"
#include "QAQ/Renderer/VertexArray.h"

#include "QAQ/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace QAQ {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    QAQ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
		}

		QAQ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}