#include "Cosmo.h"
#include "Window.h"

namespace Win32 {
	Window::Window(std::wstring className, std::wstring title, HICON icon, INT width, INT height) 
	: Win32::SObject(className, title, icon), m_Width(width), m_Height(height)
	{

	}

	Window::~Window()
	{

	}
	VOID Window::Initialize()
	{
		HWND hWnd = CreateWindow(m_Class.c_str(), m_Title.c_str(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, m_Width, m_Height, nullptr, nullptr, HInstance(), (void*)this);
		if (!hWnd) {
			MessageBeep(0);
			Logger::Print(L"Window creation failed");
			return;
		}
		ShowWindow(hWnd, SW_SHOW);
	}
}
