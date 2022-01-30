#pragma once

#include "Platforms/WIN32/Window.h"

namespace SScreen {
	VOID COSMO_API Open();
	VOID COSMO_API Close();
	VOID COSMO_API AddMessage(const WCHAR* msg);
}

class COSMO_API SWindow : public Win32::Window {
public:
	SWindow();
	~SWindow();
	virtual	LRESULT	MessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) override;

private:
	WCHAR m_outputMessage[MX_STR];
};