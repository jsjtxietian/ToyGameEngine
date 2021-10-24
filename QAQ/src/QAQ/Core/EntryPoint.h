#pragma once
#include "QAQ/Core/Base.h"
#include "QAQ/Core/Application.h"

#ifdef QAQ_PLATFORM_WINDOWS

extern QAQ::Application* QAQ::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	QAQ::Log::Init();

	QAQ_PROFILE_BEGIN_SESSION("Startup", "QAQProfile-Startup.json");
	auto app = QAQ::CreateApplication({ argc, argv });
	QAQ_PROFILE_END_SESSION();

	QAQ_PROFILE_BEGIN_SESSION("Runtime", "QAQProfile-Runtime.json");
	app->Run();
	QAQ_PROFILE_END_SESSION();

	QAQ_PROFILE_BEGIN_SESSION("Shutdown", "QAQProfile-Shutdown.json");
	delete app;
	QAQ_PROFILE_END_SESSION();
}

#endif
