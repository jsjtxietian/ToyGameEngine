#include "qaqpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace QAQ {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}