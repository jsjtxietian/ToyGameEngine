#include <QAQ.h>
#include <QAQ/Core/EntryPoint.h>

#include <imgui/imgui.h>
#include <glm/gtc/matrix_transform.hpp>

#include <glm/gtc/type_ptr.hpp>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class Sandbox : public QAQ::Application
{
public:
	Sandbox() 
	{
		PushLayer(new Sandbox2D());
	}

	~Sandbox() {
	}
};


QAQ::Application* QAQ::CreateApplication()
{
	return new Sandbox();
}