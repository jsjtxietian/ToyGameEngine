#pragma once

#include <memory>

#ifdef QAQ_PLATFORM_WINDOWS
#if QAQ_DYNAMIC_LINK
#ifdef QAQ_BUILD_DLL
	#define QAQ_API __declspec(dllexport)
#else
	#define QAQ_API __declspec(dllimport)
#endif
#else
	#define QAQ_API
#endif
#else
	#error Only Support Windows!
#endif

#ifdef QAQ_DEBUG
	#define QAQ_ENABLE_ASSERTS
#endif

#ifdef QAQ_ENABLE_ASSERTS
	#define QAQ_ASSERT(x, ...) { if(!(x)) { QAQ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define QAQ_CORE_ASSERT(x, ...) { if(!(x)) { QAQ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define QAQ_ASSERT(x, ...)
	#define QAQ_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x) 

#define QAQ_BIND_EVENT_FN(fn) std::bind(&fn,this,std::placeholders::_1)

#define HZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace QAQ {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;

}