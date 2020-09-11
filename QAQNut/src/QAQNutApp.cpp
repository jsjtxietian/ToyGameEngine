#include <QAQ.h>
#include <QAQ/Core/EntryPoint.h>

#include <imgui/imgui.h>
#include <glm/gtc/matrix_transform.hpp>

#include <glm/gtc/type_ptr.hpp>

#include "EditorLayer.h"
#include "LuaTestLayer.h"

namespace QAQ {
	class QAQNut : public Application
	{
	public:
		QAQNut()
			:Application("QAQ Nut")
		{
			// PushLayer(new EditorLayer());
			PushLayer(new LuaTestLayer());
		}

		~QAQNut() {
		}
	};


	Application* CreateApplication()
	{
		return new QAQNut();
	}
}

