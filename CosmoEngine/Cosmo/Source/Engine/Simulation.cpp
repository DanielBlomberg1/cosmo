#include "Cosmo.h"
#include "Simulation.h"
#include "Engine/SScreen.h"

Cosmo::Simulation::Simulation()
{
}

Cosmo::Simulation::~Simulation()
{
}

VOID Cosmo::Simulation::PreInitialization()
{
    SScreen::Open();
	Logger::PrintDebugSeperator();
	Logger::Print(L"Initialized \n");
	Logger::Print(L"Game name : %s\n", PerGameSettings::GameName());
	Logger::Print(L"Engine mode is set to : %s \n", Engine::EngineModeToString().c_str());
	Logger::PrintDebugSeperator();

}
