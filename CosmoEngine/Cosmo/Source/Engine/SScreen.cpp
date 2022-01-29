#include "Cosmo.h"
#include "SScreen.h"

namespace SScreen
{
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

	VOID COSMO_API AddMessage()
	{
		return VOID COSMO_API();
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
	return CommonMessageHandler(hwnd, message, wParam, lParam);
}
