#include <windows.h>

#define MAX_NAME_SZ 256
#define HInstance() GetModuleHandle(NULL)

WCHAR WindowClass[MAX_NAME_SZ];
WCHAR WindowTitle[MAX_NAME_SZ];

INT WinWidth;
INT WinHeight;

int CALLBACK WinMain(HINSTANCE, LPSTR, INT ) 
{
	// globals
	wcscpy_s(WindowClass, TEXT("a Name"));
	wcscpy_s(WindowTitle, TEXT("Titteli"));
	WinWidth = 1920;
	WinHeight = 1080;

	// window class
	WNDCLASSEX wex;
	wex.cbSize = sizeof(WNDCLASSEX);
	wex.style = CS_HREDRAW | CS_VREDRAW;
	wex.cbClsExtra = 0;
	wex.cbWndExtra = 0;

	wex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);

	wex.hIcon = LoadIcon(0, IDI_APPLICATION);
	wex.hIconSm = LoadIcon(0, IDI_APPLICATION);

	wex.lpszClassName = WindowClass;
	wex.lpszMenuName = nullptr;
	
	wex.hInstance = HInstance();

	wex.lpfnWndProc = DefWindowProc;
	RegisterClassEx(&wex);

	// Window

	HWND hWnd = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, WinWidth, WinHeight, nullptr, nullptr, HInstance(), nullptr);
	ShowWindow(hWnd, SW_SHOW);

	return 0;
}