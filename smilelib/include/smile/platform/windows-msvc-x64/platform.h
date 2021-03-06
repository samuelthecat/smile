
#ifndef __SMILE_PLATFORM_WINDOWS_MSVC_X64_PLATFORM_H__
#define __SMILE_PLATFORM_WINDOWS_MSVC_X64_PLATFORM_H__

//------------------------------------------------------------------------------------------------
//  OS: Microsoft Windows.  Compiler: Microsoft Visual C++.  Architecture: Intel x64.

#ifdef SMILE_PLATFORM_IS_DEFINED
#error Only one platform can be selected at a time!
#endif
#define SMILE_PLATFORM_IS_DEFINED

#define SMILE_OS	SMILE_OS_WINDOWS
#define SMILE_CPU	SMILE_CPU_X64
#define SMILE_COMPILER	SMILE_COMPILER_MSVC
#define SMILE_ENDIAN	SMILE_ENDIAN_LITTLE

//------------------------------------------------------------------------------------------------
//  Portable type definitions.

// Portable fixed-size and fixed-sign types.
typedef char SByte;
typedef unsigned char Byte;
typedef char Int8;
typedef unsigned char UInt8;
typedef short Int16;
typedef unsigned short UInt16;
typedef int Int32;
typedef unsigned int UInt32;
typedef __int64 Int64;
typedef unsigned __int64 UInt64;

typedef struct {
	unsigned __int64 hi;
	unsigned __int64 lo;
} UInt128;

typedef struct {
	__int64 hi;
	unsigned __int64 lo;
} Int128;

// Portable pointer-casting types.
typedef UInt64 PtrInt;		// An unsigned integer type that is the same size as a pointer.
typedef Int64 Int;			// A signed integer type that matches the native platform's "best" register size.
typedef UInt64 UInt;		// An unsigned integer type that matches the native platform's "best" register size.

#define SizeofPtrInt 8
#define SizeofInt 8

// Portable binary floating-point types.
typedef float Float32;
typedef double Float64;
typedef struct __declspec(align(16)) { UInt64 value[2]; } Float128;

// Portable decimal floating-point types.
typedef struct { UInt32 value; } Real32;
typedef struct { UInt64 value; } Real64;
typedef struct __declspec(align(16)) { UInt64 value[2]; } Real128;

//------------------------------------------------------------------------------------------------
//  Declaration prefixes.

// How to make functions behave as 'inline' in this compiler.
#undef Inline
#define Inline static __inline

// How to declare thread-local data.
#define SMILE_HAS_THREAD_LOCAL True
#define SMILE_THREAD_LOCAL __declspec(thread)

// How to export public functions outside SmileLib.
#undef SMILE_API_FUNC
#undef SMILE_API_DATA
#ifdef SMILELIB_BUILD
	#define SMILE_API_FUNC extern __declspec(dllexport)
	#define SMILE_API_DATA extern __declspec(dllexport)
#else
	#define SMILE_API_FUNC extern __declspec(dllimport)
	#define SMILE_API_DATA extern __declspec(dllimport)
#endif

// How to align data structures in memory.
#undef SMILE_ALIGN
#define SMILE_ALIGN(__n__) __declspec(align(__n__))

// Compatibility macros.
#undef SMILE_DECLARATION_STATIC_PROTOTYPE
#define SMILE_DECLARATION_STATIC_PROTOTYPE extern
#undef SMILE_DECLARATION_EXTERN_OF_UNKNOWN_SIZE
#define SMILE_DECLARATION_EXTERN_OF_UNKNOWN_SIZE
#undef SMILE_NO_RETURN
#define SMILE_NO_RETURN __declspec(noreturn)

// Pragma warning macros.
#define SMILE_IGNORE_UNUSED_VARIABLES __pragma(warning(disable:4100))

// Declare these here to avoid having to include all of <windows.h> in every file.
extern __declspec(dllimport) int __stdcall IsDebuggerPresent(void);

extern void __debugbreak(void);
#pragma intrinsic(__debugbreak)

// Determine whether a system-level debugger is attached to this process.
#undef SMILE_IS_DEBUGGER_ATTACHED
#define SMILE_IS_DEBUGGER_ATTACHED \
	(IsDebuggerPresent())

// Stop this process at a breakpoint.
#undef SMILE_DEBUGGER_BREAK
#define SMILE_DEBUGGER_BREAK \
	do { __debugbreak(); } while (0)

// Ask the debugger to breakpoint this process.
#undef SMILE_DEBUGGER_BREAK_IF_ATTACHED
#define SMILE_DEBUGGER_BREAK_IF_ATTACHED \
	do { if (IsDebuggerPresent()) { __debugbreak(); } } while (0)

//------------------------------------------------------------------------------------------------
//  Entropy.

extern UInt64 __rdtsc(void);
#pragma intrinsic(__rdtsc)

// Get a reasonable degree of entropy from wherever this platform keeps it, as quickly as possible.
// This doesn't need to be crypto-secure; it just needs to be suitably semi-random.
Inline UInt64 GetBaselineEntropy(void)
{
    return __rdtsc();
}

#endif
