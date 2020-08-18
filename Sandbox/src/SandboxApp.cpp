#include <QAQ.h>
#include "imgui/imgui.h"

class ExampleLayer : public QAQ::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		/*if (QAQ::Input::IsKeyPressed(QAQ_KEY_TAB)) 
		{
			QAQ_TRACE("Tab is pressed(poll)");
		}*/
	}

	virtual void OnImGuiRender() override
	{
		/*ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();*/
	}

	void OnEvent(QAQ::Event& event) override
	{
		//QAQ_TRACE("{0}", event);
		/*if (event.GetEventType() == QAQ::EventType::KeyPressed) {
			QAQ::KeyPressedEvent& e = (QAQ::KeyPressedEvent&) event;
			if(e.GetKeyCode() == QAQ_KEY_TAB)
				QAQ_TRACE("Tab is pressed(event)");
			QAQ_TRACE("{0}",(char)e.GetKeyCode());
		}*/
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