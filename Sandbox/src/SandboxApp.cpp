#include <QAQ.h>
#include <QAQ/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class Sandbox : public QAQ::Application
{
public:
	Sandbox()
	{
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{
	}
};

QAQ::Application* QAQ::CreateApplication()
{
	return new Sandbox();
}
