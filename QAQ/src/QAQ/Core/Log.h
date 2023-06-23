#pragma once

#include "QAQ/Core/Base.h"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)


namespace QAQ {

	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define QAQ_CORE_TRACE(...)    ::QAQ::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define QAQ_CORE_INFO(...)     ::QAQ::Log::GetCoreLogger()->info(__VA_ARGS__)
#define QAQ_CORE_WARN(...)     ::QAQ::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define QAQ_CORE_ERROR(...)    ::QAQ::Log::GetCoreLogger()->error(__VA_ARGS__)
#define QAQ_CORE_CRITICAL(...) ::QAQ::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define QAQ_TRACE(...)         ::QAQ::Log::GetClientLogger()->trace(__VA_ARGS__)
#define QAQ_INFO(...)          ::QAQ::Log::GetClientLogger()->info(__VA_ARGS__)
#define QAQ_WARN(...)          ::QAQ::Log::GetClientLogger()->warn(__VA_ARGS__)
#define QAQ_ERROR(...)         ::QAQ::Log::GetClientLogger()->error(__VA_ARGS__)
#define QAQ_CRITICAL(...)      ::QAQ::Log::GetClientLogger()->critical(__VA_ARGS__)


#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

template<typename OStream, glm::length_t L, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::vec<L, T, Q>& vector)
{
	return os << glm::to_string(vector);
}

template<typename OStream, glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::mat<C, R, T, Q>& matrix)
{
	return os << glm::to_string(matrix);
}

template<typename OStream, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, glm::qua<T, Q> quaternio)
{
	return os << glm::to_string(quaternio);
}
