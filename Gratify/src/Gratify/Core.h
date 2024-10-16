#pragma once

#ifdef PLATFORM_WINDOWS
	#ifdef BUILD_DLL
		#define GFAPI __declspec(dllexport) 
	#else
		#define GFAPI __declspec(dllimport) 
	#endif // GF_BUILD_DLL
#else
	#error GRATIFY IS ONLY FOR WINDOWS PLATFORM!

#endif // GF_PLATFORM_WINDOWS

#define BIT(x) (1 << x)
