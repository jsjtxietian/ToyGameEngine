#pragma once

#ifdef QAQ_PLATFORM_WINDOWS
	#ifdef QAQ_BUILD_DLL
		#define QAQ_API__ __declspec(dllexport)
	#else
		#define QAQ_API__ __declspec(dllimport)
	#endif 
#else
	#error Only Support Windows!
#endif
