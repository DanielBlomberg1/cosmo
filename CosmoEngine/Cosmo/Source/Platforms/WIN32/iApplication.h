#pragma once
#include "Cosmo.h"
#define ENTRYAPP(x) IApplication* EntryApplication(){ return new x; }

class COSMO_API IApplication {
public:
	IApplication();
	virtual ~IApplication() {};
public:
	virtual VOID Initialize() = 0;
	virtual VOID Update() = 0;
};

IApplication* EntryApplication();