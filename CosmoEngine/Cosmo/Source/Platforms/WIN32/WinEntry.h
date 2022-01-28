#include "Cosmo.h"
#include "iApplication.h"

extern IApplication* EntryApplication();

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	auto EntryPoint = EntryApplication();
	EntryPoint->Initialize();


	return 0;
}