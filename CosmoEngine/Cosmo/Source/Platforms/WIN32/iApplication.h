#pragma once
#include "Cosmo.h"
#define ENTRYAPP(x) Win32::IApplication* EntryApplication(){ return new x; }

namespace Win32 {
	class COSMO_API IApplication {
	public:
		IApplication();
		virtual ~IApplication() {};
	public:
		virtual VOID SetupSettingsForGame() = 0;
		virtual VOID PreInitialization() = 0;
		virtual VOID Initialize() = 0;
		virtual VOID Update() = 0;
	};

	IApplication* EntryApplication();
}
