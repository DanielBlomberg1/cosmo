#pragma once

class COSMO_API OEngine;
namespace Engine {
	enum class EngineMode : INT {
		NONE,
		DEBUG,
		RELEASE,
		EDITOR,
		SERVER
	};

	extern OEngine gKosmoEngine;
}


using namespace Engine;
class COSMO_API OEngine {
public:
	OEngine();
	~OEngine();
private:
	EngineMode EM;
};