#include "Application.h"
#include "pch.h"
#include "Platforms/WIN32/WinEntry.h"

ENTRYAPP(Application);

Application::Application()
{
}

Application::~Application()
{
}

VOID Application::SetupSettingsForGame()
{
	PerGameSettings::SetGameName(IDS_PERGAMENAME);
	PerGameSettings::SetShortGameName(IDS_SHORTNAME);
	PerGameSettings::SetGameIcon(IDI_MAINICON);
	return VOID();
}

VOID Application::Initialize()
{
	Logger::Print(L"I Have loaded up");
	return VOID();
}

VOID Application::Update()
{
	//MessageBox(0, L"Looping", 0, 0);
	//OutputDebugString(L"");
	return VOID();
}
