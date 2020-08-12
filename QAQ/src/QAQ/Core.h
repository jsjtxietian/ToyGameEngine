#pragma once

#ifdef QAQ_PLATFORM_WINDOWS
	#ifdef QAQ_BUILD_DLL
		#define QAQ_API __declspec(dllexport)
	#else
		#define QAQ_API __declspec(dllimport)
	#endif 
#else
	#error Only Support Windows!
#endif

#define BIT(x) (1 << x) 