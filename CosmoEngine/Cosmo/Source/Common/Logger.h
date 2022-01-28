#pragma once
#include <string>

class COSMO_API Logger 
{
private:
	static Logger* inst;
public:
	static Logger* Instance() { return inst; }
public:
	~Logger();
	Logger();

	static VOID Print(const WCHAR* fmt, ...);
	static std::wstring LogDir();
	static std::wstring LogFile();
};