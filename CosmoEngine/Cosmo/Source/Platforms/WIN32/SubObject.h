#pragma once
namespace Win32 {
	class COSMO_API SObject {
	public:
		SObject(std::wstring className, std::wstring title, HICON icon);
		~SObject();
		virtual VOID RegisterNewClass();
		virtual VOID Initialize() = 0;

	protected:
		static			LRESULT CALLBACK	SetupMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
		static			LRESULT				AssignMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
		virtual			LRESULT				CommonMessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

		virtual			LRESULT				MessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) = 0;


	protected:
		std::wstring m_Class;
		std::wstring m_Title;

		HICON m_Icon;

		HWND m_Handle;
	};

}