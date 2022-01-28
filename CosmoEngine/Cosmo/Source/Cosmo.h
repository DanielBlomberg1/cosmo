#pragma once
#ifdef WIN32
#include <Windows.h>
#endif

#ifdef BUILD_DLL
#define COSMO_API __declspec(dllexport)
#else
#define COSMO_API __declspec(dllimport)
#endif