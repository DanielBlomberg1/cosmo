#include "Cosmo.h"

namespace Engine {
	OEngine gKosmoEngine;

	VOID SetMode(EngineMode mode)
	{
		gKosmoEngine.SetEngineMode(mode);
	}

	EngineMode GetEngineMode() {
		return gKosmoEngine.GetEngineMode();
	}

	std::wstring COSMO_API EngineModeToString()
	{
		switch (Engine::GetEngineMode())
		{
		case EngineMode::DEBUG:		return L"Debug";
		case EngineMode::RELEASE:	return L"Release";
		case EngineMode::SERVER:	return L"Server";
		case EngineMode::EDITOR:	return L"Editor";
		default:     return L"None";
		}
	}
}

OEngine::OEngine()
{
#ifdef _DEBUG
	EM = EngineMode::DEBUG;
#else
	EM = EngineMode::RELEASE;
#endif
}

OEngine::~OEngine()
{
}

EngineMode OEngine::GetEngineMode()
{
	return EM;
}

VOID OEngine::SetEngineMode(EngineMode mode)
{
	EM = mode;
}
