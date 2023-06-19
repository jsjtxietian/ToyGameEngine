#include <QAQ.h>
#include <QAQ/Core/EntryPoint.h>

#include "Sandbox2D.h"
//#include "TestingLayer.h"
//#include "ExampleLayer.h"

class Sandbox : public QAQ::Application
{
public:
	Sandbox(const QAQ::ApplicationSpecification& specification)
		: QAQ::Application(specification)
	{
		PushLayer(new Sandbox2D());
		//PushLayer(new TestingLayer());
	}

	~Sandbox()
	{
	}
};

QAQ::Application* QAQ::CreateApplication(ApplicationCommandLineArgs args)
{
	ApplicationSpecification spec;
	spec.Name = "Sandbox";
	spec.WorkingDirectory = "../QAQNut";
	spec.CommandLineArgs = args;

	return new Sandbox(spec);
}
