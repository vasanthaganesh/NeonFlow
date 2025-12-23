#pragma once

#if defined(_WIN32)
    #if defined(NEON_EXPORTS)
        #define NEON_API __declspec(dllexport)
    #else
        #define NEON_API __declspec(dllimport)
    #endif
#else
    #define NEON_API
#endif
