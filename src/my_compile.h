#ifndef MY_MY_COMPILE_H_
#define MY_MY_COMPILE_H_

//
// OS
//
#define OS_LINUX                    1
//#define OS_WINDOWS                  1
//#define OS_MAC                      1


//
// DEBUG ENABLE
//
#define DEBUG                       1

// #if DEBUG
// #define NUMERIC_DBG                  1
// #endif

//
// Platform Compile Options
//

#if defined(__GNUC__)
#define MY_DEPRECATED __attribute__((deprecated))
#define MY_FORCE_INLINE __attribute__((always_inline))
#elif defined(_MSC_VER)
#define MY_DEPRECATED
#define MY_FORCE_INLINE __forceinline
#else
#define MY_DEPRECATED
#define MY_FORCE_INLINE inline
#endif

#endif // MY_MY_COMPILE_H_