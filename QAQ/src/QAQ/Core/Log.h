#pragma once

#include "QAQ/Core/Base.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace QAQ {
	class  Log
	{
	public:
		static void Init();

		inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	
	private:

		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};
}


//core log macros
#define QAQ_CORE_TRACE(...)		::QAQ::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define QAQ_CORE_INFO(...)		::QAQ::Log::GetCoreLogger()->info(__VA_ARGS__)
#define QAQ_CORE_WARN(...)		::QAQ::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define QAQ_CORE_ERROR(...)		::QAQ::Log::GetCoreLogger()->error(__VA_ARGS__)
#define QAQ_CORE_CRITICAL(...)		::QAQ::Log::GetCoreLogger()->critical(__VA_ARGS__)

//client log macros
#define QAQ_TRACE(...)		::QAQ::Log::GetClientLogger()->trace(__VA_ARGS__)
#define QAQ_INFO(...)		::QAQ::Log::GetClientLogger()->info(__VA_ARGS__)
#define QAQ_WARN(...)		::QAQ::Log::GetClientLogger()->warn(__VA_ARGS__)
#define QAQ_ERROR(...)		::QAQ::Log::GetClientLogger()->error(__VA_ARGS__)
#define QAQ_CRITICAL(...)		::QAQ::Log::GetClientLogger()->critical(__VA_ARGS__)

