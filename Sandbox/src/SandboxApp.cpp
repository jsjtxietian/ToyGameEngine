#include <QAQ.h>

class ExampleLayer : public QAQ::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		QAQ_INFO("ExampleLayer::Update");
	}

	void OnEvent(QAQ::Event& event) override
	{
		QAQ_TRACE("{0}", event);
	}

};

class Sandbox : public QAQ::Application
{
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}

	~Sandbox() {

	}
};


QAQ::Application* QAQ::CreateApplication()
{
	return new Sandbox();
}