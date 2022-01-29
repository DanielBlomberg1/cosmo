#pragma once

#include "Platforms/WIN32/iApplication.h"

namespace Cosmo {
	class COSMO_API Simulation : public Win32::IApplication {
	public:
		Simulation();
		~Simulation();
	};
}