#pragma once
class COSMO_API PerGameSettings {
private:
	static PerGameSettings* instance;
	static PerGameSettings* Instance() { return instance; }
public:
	PerGameSettings();
	~PerGameSettings();
private:
	//pg private vars
	WCHAR g_Name[MX_STR];
	WCHAR g_ShortName[MX_STR];
	HICON g_Icon;
	WCHAR g_InitTime[MX_STR];
public:
	static WCHAR* GameName() { return instance->g_Name; }
	static VOID SetGameName(UINT id) { LoadString(HInstance(), id, instance->g_Name, MX_STR); }

	static WCHAR* ShortGameName() { return instance->g_ShortName; }
	static VOID SetShortGameName(UINT id) { LoadString(HInstance(), id, instance->g_ShortName, MX_STR); }

	static HICON GameIcon() { return instance->g_Icon; }
	static VOID SetGameIcon(UINT id) { LoadIcon(HInstance(), MAKEINTRESOURCE(id)); }

	static WCHAR* InitTime() { return instance->g_InitTime; }
};