#pragma once

#ifdef BE_PLATFORM_WINDOW
	#ifdef BE_BUILD_DLL
		#define BARUAH_API __declspec(dllexport)
	#else
		#define BARUAH_API __declspec(dllimport)
	#endif // BE_BUILD_DLL
#else
	#error Baruah Engine is only supported in Windows!
#endif
