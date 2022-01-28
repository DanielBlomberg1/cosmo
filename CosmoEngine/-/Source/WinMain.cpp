#include "pch.h"

#define MAX_NAME_SZ 256
#define HInstance() GetModuleHandle(NULL)

WCHAR WindowClass[MAX_NAME_SZ];
WCHAR WindowTitle[MAX_NAME_SZ];

INT WinWidth;
INT WinHeight;

HICON hIcon;

LRESULT CALLBACK WProcess(HWND hWnd, UINT msg, WPARAM wparam, LPARAM lparam) 
{
	switch (msg) {
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}

	return DefWindowProc(hWnd, msg, wparam, lparam);
}


int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT )
{
	// globals
	LoadString(HInstance(), IDS_PERGAMENAME, WindowClass, MAX_NAME_SZ);
	LoadString(HInstance(), IDS_WINDOWTITLE, WindowTitle, MAX_NAME_SZ);
	WinWidth = 1920;
	WinHeight = 1080;

	hIcon = LoadIcon(HInstance(), MAKEINTRESOURCE(IDI_MAINICON));

	// window class
	WNDCLASSEX wex;
	wex.cbSize = sizeof(WNDCLASSEX);
	wex.style = CS_HREDRAW | CS_VREDRAW;
	wex.cbClsExtra = 0;
	wex.cbWndExtra = 0;

	wex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);

	wex.hIcon = hIcon;
	wex.hIconSm = hIcon;

	wex.lpszClassName = WindowClass;
	wex.lpszMenuName = nullptr;
	
	wex.hInstance = HInstance();

	wex.lpfnWndProc = WProcess;
	RegisterClassEx(&wex);

	// Window

	HWND hWnd = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, WinWidth, WinHeight, nullptr, nullptr, HInstance(), nullptr);
	if (!hWnd) {
		MessageBeep(0);
		MessageBox(0, L"Window Creation Failed", 0, 0);
		return 0;
	}

	ShowWindow(hWnd, SW_SHOW);

	// Looping Function

	MSG msg{ 0 };
	while (msg.message != WM_QUIT) 
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return 0;
}