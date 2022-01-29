#include "Cosmo.h"
#include "iApplication.h"
#include "Common/CmdArgs.h"

extern Win32::IApplication* EntryApplication();

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	auto EntryPoint = EntryApplication();

	PerGameSettings pgs;

	EntryPoint->SetupSettingsForGame();

	Logger logger;
	if (logger.Instance) {
		MessageBox(0, L"logger online",0,0);
	}

	CmdArgs::ReadArgs();

	EntryPoint->Initialize();

	MSG msg{ 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			EntryPoint->Update();
		}
	}

	return 0;
}