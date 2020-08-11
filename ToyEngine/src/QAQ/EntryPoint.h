#pragma once

#ifdef QAQ_PLATFORM_WINDOWS

extern QAQ::Application* QAQ::CreateApplication();

int main(int argc, char** argv) {
	QAQ::Log::Init();

	QAQ_CORE_WARN("fuck");

	int a = 5;
	QAQ_INFO("Hello! Var={0}",a);

	auto app = QAQ::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif