#include "Log.h"

#include <Windows.h>



namespace toxic
{
	void Log::Debug(const IPrintable& printable)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 0x0B);
		std::cout << "[DEBUG] " << printable.ToString() << std::endl;
	}

	void Log::Info(const String msg)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 0x0F);
		std::cout << "[INFO] " << msg << std::endl;
	}

	void Log::Error(const String msg)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 0x0C);
		std::cout << "[ERROR] " << msg << std::endl;
	}

	void Log::Warning(const String msg)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 0x0E);
		std::cout << "[WARNING] " << msg << std::endl;
	}
}