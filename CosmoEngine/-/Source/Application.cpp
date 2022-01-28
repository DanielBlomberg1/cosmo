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

VOID Application::Initialize()
{
	MessageBox(0, L"Entry Initalized", 0, 0);
	return VOID();
}

VOID Application::Update()
{
	return VOID();
}
