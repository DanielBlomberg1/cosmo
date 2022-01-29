#include "Cosmo.h"
#include <fstream>
#include <ShlObj.h>
#include <cstdio>
#include <tlhelp32.h>

Logger* Logger::inst;

Logger::Logger()
{
	inst = this;
}

Logger::~Logger()
{

}

std::wstring Logger::LogDir() {
	WCHAR path[1024];
	WCHAR* appData;
	SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &appData);
	wcscpy_s(path, appData);
	wcscat_s(path, L"\\");
	wcscat_s(path, PerGameSettings::GameName());
	//MessageBox(0, path, 0, 0);
	CreateDirectory(path, NULL);
	wcscat_s(path, L"\\Log");
	CreateDirectory(path, NULL);
	return path;
}

std::wstring Logger::LogFile() {
	WCHAR File[1024];
	wcscpy_s(File, PerGameSettings::GameName());
	wcscat_s(File, PerGameSettings::InitTime());
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
		OutputDebugString(s.c_str());
	}
	else {
		MessageBox(0, L"Unable to open log file", L"Log Error", MB_OK);
	}
}

VOID Logger::PrintDebugSeperator()
{
	std::wstring s = L"\n------------------------------------------------------------------------------------\n\n";

#ifdef _DEBUG
	std::wfstream outfile;
	outfile.open(std::wstring(LogDir() + L"/" + LogFile()), std::ios_base::app);

	if (outfile.is_open()) {
		outfile << s;
		outfile.close();
	}
	else {
		MessageBox(NULL, L"Unable to open log file...", L"Log Error", MB_OK);
	}
#endif
}
