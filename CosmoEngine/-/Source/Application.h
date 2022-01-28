#pragma once
#include "pch.h"

#include "Platforms/WIN32/IApplication.h"

class Application : public IApplication {
public:
	Application();
	~Application();
public:
	VOID Initialize();
	VOID Update();
};