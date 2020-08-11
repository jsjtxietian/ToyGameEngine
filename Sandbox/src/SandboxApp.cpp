#include <QAQ.h>

class Sandbox : public QAQ::Application
{
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};


QAQ::Application* QAQ::CreateApplication()
{
	return new Sandbox();
}