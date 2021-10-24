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
		QAQNut(ApplicationCommandLineArgs args)
			: Application("QAQNut", args)
		{
			PushLayer(new EditorLayer());
		}

		~QAQNut()
		{
		}
	};

	Application *CreateApplication(ApplicationCommandLineArgs args)
	{
		return new QAQNut(args);
	}
}
