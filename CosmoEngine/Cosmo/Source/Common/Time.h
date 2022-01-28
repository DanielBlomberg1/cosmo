#pragma once
#include <string>

namespace Time {
	std::wstring COSMO_API GetTime(BOOL stripped = FALSE);
	std::wstring COSMO_API GetDate(BOOL stripped = FALSE);
	std::wstring COSMO_API GetDateTimeStr(BOOL stripped = FALSE);
}