#include "Cosmo.h"

PerGameSettings* PerGameSettings::instance;

PerGameSettings::PerGameSettings()
{
	instance = this;

	wcscpy_s(instance->g_Name, L"undefined");
	wcscpy_s(instance->g_ShortName, L"undefined");
	wcscpy_s(instance->g_InitTime, Time::GetDateTimeStr(TRUE).c_str());
	//wcscpy_s(instance->g_Name, L"undefined");
}

PerGameSettings::~PerGameSettings()
{
}
