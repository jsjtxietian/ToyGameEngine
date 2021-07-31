#pragma once

#include <memory>

#include "QAQ/Core/PlatformDetection.h"

#ifdef QAQ_DEBUG
	#if defined(QAQ_PLATFORM_WINDOWS)
		#define QAQ_DEBUGBREAK() __debugbreak()
	#elif defined(QAQ_PLATFORM_LINUX)
		#include <signal.h>
		#define QAQ_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define QAQ_ENABLE_ASSERTS
#else
	#define QAQ_DEBUGBREAK()
#endif

#define QAQ_EXPAND_MACRO(x) x
#define QAQ_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define QAQ_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace QAQ {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}

#include "QAQ/Core/Log.h"
#include "QAQ/Core/Assert.h"
