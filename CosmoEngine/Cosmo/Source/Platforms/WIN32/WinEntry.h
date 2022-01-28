#include "Cosmo.h"
#include "iApplication.h"

extern IApplication* EntryApplication();

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	auto EntryPoint = EntryApplication();

	PerGameSettings pgs;
	Logger logger;
	MSG msg{ 0 };

	EntryPoint->SetupSettingsForGame();

	if (logger.Instance) {
		MessageBox(0, L"logger online",0,0);
	}

	EntryPoint->Initialize();

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