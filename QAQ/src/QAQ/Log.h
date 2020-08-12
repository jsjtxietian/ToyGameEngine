#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace QAQ {
	class QAQ_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	
	private:

		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


//core log macros
#define QAQ_CORE_TRACE(...)		::QAQ::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define QAQ_CORE_INFO(...)		::QAQ::Log::GetCoreLogger()->info(__VA_ARGS__)
#define QAQ_CORE_WARN(...)		::QAQ::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define QAQ_CORE_ERROR(...)		::QAQ::Log::GetCoreLogger()->error(__VA_ARGS__)
#define QAQ_CORE_FATAL(...)		::QAQ::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//client log macros
#define QAQ_TRACE(...)		::QAQ::Log::GetClientLogger()->trace(__VA_ARGS__)
#define QAQ_INFO(...)		::QAQ::Log::GetClientLogger()->info(__VA_ARGS__)
#define QAQ_WARN(...)		::QAQ::Log::GetClientLogger()->warn(__VA_ARGS__)
#define QAQ_ERROR(...)		::QAQ::Log::GetClientLogger()->error(__VA_ARGS__)
#define QAQ_FATAL(...)		::QAQ::Log::GetClientLogger()->fatal(__VA_ARGS__)

