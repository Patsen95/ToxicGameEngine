#pragma once

#define TOXIC_VERSION 100


#if defined(_WIN32)
#define _CRT_SECURE_NO_WARNINGS
#endif

#if !defined(_WIN32)
#error This operating system is not suported by that shit :/
#endif

#ifdef TOXIC_EXPORTS
#define TOXIC_API __declspec(dllexport)
#else
#define TOXIC_API __declspec(dllimport)
#endif

#ifdef _MSC_VER
#pragma warning(disable: 4251)
#endif

//#ifdef __GNUC__
//#define DEPRECATED(func) func __attribute__ ((deprecated))
//#elif defined(_MSC_VER)
//#define DEPRECATED(func) __declspec(deprecated) func
//#else
//#pragma message("WARNING: You need to implement DEPRECATED for this compiler")
//#define DEPRECATED(func) func
//#endif

namespace toxic
{
	typedef signed char int8;
	typedef unsigned char uint8;
	typedef signed short int16;
	typedef unsigned short uint16;
	typedef signed int int32;
	typedef unsigned int uint32;
	typedef signed long long int64;
	typedef unsigned long long uint64;

	typedef uint32 uint;
}
