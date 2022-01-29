#pragma once
#include "pch.h"

#include "Engine/Simulation.h"

class Application : public Cosmo::Simulation {
public:
	Application();
	~Application();
public:
	VOID SetupSettingsForGame();
	VOID Initialize();
	VOID Update();
};