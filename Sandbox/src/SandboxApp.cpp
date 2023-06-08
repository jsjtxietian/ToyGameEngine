#include <QAQ.h>
#include <QAQ/Core/EntryPoint.h>

#include "Sandbox2D.h"
//#include "TestingLayer.h"
//#include "ExampleLayer.h"

class Sandbox : public QAQ::Application
{
public:
	Sandbox(QAQ::ApplicationCommandLineArgs args)
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
	return new Sandbox(args);
}
