#pragma once

#include "QAQ/Core/Core.h"

#ifdef QAQ_PLATFORM_WINDOWS

extern QAQ::Application* QAQ::CreateApplication();

int main(int argc, char** argv) {

	QAQ::Log::Init();

	auto app = QAQ::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif