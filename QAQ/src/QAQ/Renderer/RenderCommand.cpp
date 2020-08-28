#include "qaqpch.h"
#include "QAQ/Renderer/RenderCommand.h"

namespace QAQ {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}