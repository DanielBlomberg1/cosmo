#include "Cosmo.h"
#include "SubObject.h"

namespace Win32 {
	SObject::SObject(std::wstring className, std::wstring titleName, HICON icon) 
		: m_Class(className), m_Title(titleName), m_Icon(icon)
	{
	}

	SObject::~SObject()
	{

	}

	VOID SObject::RegisterNewClass()
	{
		//make window 
		WNDCLASSEX wex;
		wex.cbSize = sizeof(WNDCLASSEX);
		wex.style = CS_HREDRAW | CS_VREDRAW;
		wex.cbClsExtra = 0;
		wex.cbWndExtra = 0;

		wex.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);

		wex.hIcon = m_Icon;
		wex.hIconSm = m_Icon;

		wex.lpszClassName = m_Class.c_str();
		wex.lpszMenuName = nullptr;

		wex.hInstance = HInstance();

		wex.lpfnWndProc = SetupMessageHandler;
		RegisterClassEx(&wex);
	}

	LRESULT SObject::SetupMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		if (msg == WM_NCCREATE)
		{
			const CREATESTRUCTW* const pCreate = reinterpret_cast<CREATESTRUCTW*>(lParam);
			Win32::SObject* const pWnd = static_cast<Win32::SObject*>(pCreate->lpCreateParams);
			SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWnd));
			SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&Win32::SObject::AssignMessageHandler));
			return pWnd->MessageHandler(hWnd, msg, wParam, lParam);
		}
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	LRESULT SObject::AssignMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		Win32::SObject* const pWnd = reinterpret_cast<Win32::SObject*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
		return pWnd->MessageHandler(hWnd, msg, wParam, lParam);
	}

	LRESULT SObject::CommonMessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
}

