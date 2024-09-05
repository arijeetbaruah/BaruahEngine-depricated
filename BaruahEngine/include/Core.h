#pragma once

#ifdef BE_PLATFORM_WINDOW
	#if HZ_DYNAMIC_LINK
		#ifdef BE_BUILD_DLL
			#define BARUAH_API __declspec(dllexport)
		#else
			#define BARUAH_API __declspec(dllimport)
		#endif // BE_BUILD_DLL
	#else
		#define BARUAH_API
	#endif
#else
	#error Baruah Engine is only supported in Windows!
#endif

#ifdef BE_ENABLE_ASSERTS
#define BE_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define BE_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define BE_ASSERT(x, ...)
#define BE_CORE_ASSERT(x, ...)
#endif

#define BE_BIND(x) std::bind(&x, this, std::placeholders::_1)
