#include "Cosmo.h"

namespace Engine {
	OEngine gKosmoEngine;
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
