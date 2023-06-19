#include <QAQ.h>
#include <QAQ/Core/EntryPoint.h>

#include <imgui/imgui.h>
#include <glm/gtc/matrix_transform.hpp>

#include <glm/gtc/type_ptr.hpp>

#include "EditorLayer.h"

namespace QAQ
{
	class QAQNut : public Application
	{
	public:
		QAQNut(const ApplicationSpecification& spec)
			: Application(spec)
		{
			PushLayer(new EditorLayer());
		}

		~QAQNut()
		{
		}
	};

	Application *CreateApplication(ApplicationCommandLineArgs args)
	{
		ApplicationSpecification spec;
		spec.Name = "QAQlnut";
		spec.CommandLineArgs = args;

		return new QAQNut(spec);
	}
}
