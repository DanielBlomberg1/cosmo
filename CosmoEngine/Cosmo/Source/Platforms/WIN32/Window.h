#pragma once

#include "SubObject.h"

namespace Win32 {
	class COSMO_API Window : public Win32::SObject {
	public:
		Window(std::wstring className, std::wstring title, HICON icon, INT width, INT height);
		~Window();

		virtual VOID Initialize() override;
	protected:
		INT m_Width;
		INT m_Height;
	};
}