#include "Cosmo.h"
#include "CmdArgs.h"
#include <algorithm>

VOID CmdArgs::ReadArgs()
{
	int argSz = 0;
	LPWSTR* argData = CommandLineToArgvW(GetCommandLineW(), &argSz);
	for (int i = 1; i < argSz; i++) {
		std::wstring cmd = argData[i];
		if (cmd[0] == '-') {
			cmd.erase(0,1);
			std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
			TestArgs(cmd.c_str());
		}
	}
	return;
}

VOID CmdArgs::TestArgs(const WCHAR* cmd)
{
	if (wcscmp(cmd, L"editor") == 0) {
		Logger::Print(L"started app in editor mode\n");
	}
	else if (wcscmp(cmd, L"server") == 0) {
		Logger::Print(L"started in servermode");
	}
	else {
		Logger::Print(cmd, L"is not a valid argument\n");
	}
}