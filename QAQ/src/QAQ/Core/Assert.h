#pragma once

#include "QAQ/Core/Base.h"
#include "QAQ/Core/Log.h"
#include <filesystem>

#ifdef QAQ_ENABLE_ASSERTS

	// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
	// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
	#define QAQ_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { QAQ##type##ERROR(msg, __VA_ARGS__); QAQ_DEBUGBREAK(); } }
	#define QAQ_INTERNAL_ASSERT_WITH_MSG(type, check, ...) QAQ_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define QAQ_INTERNAL_ASSERT_NO_MSG(type, check) QAQ_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", QAQ_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define QAQ_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define QAQ_INTERNAL_ASSERT_GET_MACRO(...) QAQ_EXPAND_MACRO( QAQ_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, QAQ_INTERNAL_ASSERT_WITH_MSG, QAQ_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define QAQ_ASSERT(...) QAQ_EXPAND_MACRO( QAQ_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define QAQ_CORE_ASSERT(...) QAQ_EXPAND_MACRO( QAQ_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define QAQ_ASSERT(...)
#define QAQ_CORE_ASSERT(...)
#endif
