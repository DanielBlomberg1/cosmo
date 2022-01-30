#include "Cosmo.h"
#include "SScreen.h"

#include "Platforms/WIN32/Win32Utils.h"

namespace SScreen
{
#define WM_OUTPUTMESSAGE (WM_USER + 0x0001)

	SWindow* m_SWindow;
	VOID COSMO_API Open()
	{
		if (m_SWindow != nullptr) {
			return;
		}
		m_SWindow = new SWindow();
	}

	VOID COSMO_API Close()
	{
		return VOID COSMO_API();
	}

	VOID COSMO_API AddMessage(const WCHAR* msg)
	{
		PostMessage(m_SWindow->GetHandle(), WM_OUTPUTMESSAGE, (WPARAM)msg, 0);
	}
}


SWindow::SWindow() : Win32::Window(L"Kosmo Engine", L"Kosmo Engine", NULL, 600, 500)
{
	wcscpy_s(m_outputMessage, L"SScreen starting...");
	Win32::Window::RegisterNewClass();
	Win32::Window::Initialize();
}

SWindow::~SWindow()
{
}

LRESULT SWindow::MessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_PAINT: 
	{
		HBITMAP bitMap;
		HDC hdc, hmemdc;
		PAINTSTRUCT pS;

		hdc = BeginPaint(hwnd, &pS);

		Win32::Utils::AddBitmap(L"E:\\Coding\\Git\\cosmo\\CosmoEngine\\Cosmo\\Source\\Assets\\SScreen.bmp", hdc);

		SetBkMode(hdc, TRANSPARENT);
		SetTextColor(hdc, RGB(200, 200, 200));

		std::wstring eMText = EngineModeToString() + L" Mode";
		SetTextAlign(hdc, TA_RIGHT);
		TextOut(hdc, m_Width - 15, 15, eMText.c_str(), wcslen(eMText.c_str()));


		SetTextAlign(hdc, TA_CENTER);

		TextOut(hdc, m_Width / 2, m_Height / 2, m_outputMessage, wcslen(m_outputMessage));
		EndPaint(hwnd, &pS);
		return 0;
	}
	break;
	case WM_OUTPUTMESSAGE:
	{
		WCHAR* msg = (WCHAR*)wParam;
		wcscpy_s(m_outputMessage, msg);
		RedrawWindow(GetHandle(), NULL, NULL, RDW_INVALIDATE);
		return 0;
	}
	}
	return CommonMessageHandler(hwnd, message, wParam, lParam);
}
