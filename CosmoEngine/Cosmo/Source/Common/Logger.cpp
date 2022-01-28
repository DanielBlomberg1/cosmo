#include "Cosmo.h"
#include <fstream>
#include <ShlObj.h>

Logger* Logger::inst;

Logger::~Logger()
{
	
}

Logger::Logger()
{
	inst = this;
}

std::wstring Logger::LogDir() {
	WCHAR path[1024];
	WCHAR* appData;
	SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &appData);
	wcscpy_s(path, appData);
	wcscpy_s(path, L"\\");
	wcscpy_s(path, PerGameSettings::GameName());
	CreateDirectory(path, NULL);
	wcscpy_s(path, L"\\Logs");
	CreateDirectory(path, NULL);
	return path;
}

std::wstring Logger::LogFile() {
	WCHAR File[1024];
	wcscpy_s(File, PerGameSettings::GameName());
	wcscpy_s(File, PerGameSettings::InitTime());
	wcscat_s(File, L".log");
	return File;
}

VOID Logger::Print(const WCHAR* fmt, ...)
{
	WCHAR buf[4096];
	va_list args;
	va_start(args, fmt);
	vswprintf_s(buf, fmt, args);
	va_end(args);

	OutputDebugString(buf);

	std::wfstream out;
	out.open(std::wstring(LogDir() + L"/" + LogFile()), std::ios_base::app);
	if (out.is_open()) 
	{
		std::wstring s = buf;
		out << L"[" << Time::GetDateTimeStr() << L"] " << s;
		out.close();
	}
	else {
		MessageBox(0, L"Unable to open log file", L"Log Error", MB_OK);
	}
}