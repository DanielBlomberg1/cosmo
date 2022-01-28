#pragma once
#ifdef WIN32
#include <Windows.h>
#endif

constexpr auto MX_STR = 256;
#define HInstance() GetModuleHandle(NULL)

#ifdef BUILD_DLL
#define COSMO_API __declspec(dllexport)
#else
#define COSMO_API __declspec(dllimport)
#endif

#include "Common/Logger.h"
#include "Common/Time.h"
#include "Core/PerGameSettings.h"