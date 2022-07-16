#include "SimpleLog.h"
#include "windows.h"
#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>



namespace SimpleLog 
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	LoggingLevel defaultLevel = LoggingLevel::Info;

	Logger::Logger(LoggingLevel _minLogLevel = defaultLevel) 
	{
		minLogLevel = _minLogLevel;
	}

	void Logger::LogDebug(const char* message) 
	{
		std::time_t const now = std::time(nullptr);
		if ((int)minLogLevel == 0) {
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "[Debug]" << std::put_time(std::localtime(&now), "(%T):") << message << std::endl;
			SetConsoleTextAttribute(hConsole, 15);
			
		}
	}
	void Logger::LogInfo(const char* message) 
	{
		std::time_t const now = std::time(nullptr);
		if ((int)minLogLevel <= 1) {
			SetConsoleTextAttribute(hConsole, 15);
			std::cout << "[Info]" << std::put_time(std::localtime(&now), "(%T):") << message << std::endl;

		}
	};
	void Logger::LogWarning(const char* message)
	{
		std::time_t const now = std::time(nullptr);
		if ((int)minLogLevel <= 2) {
			SetConsoleTextAttribute(hConsole, 6);
			std::cout << "[Warning]" << std::put_time(std::localtime(&now), "(%T):") << message << std::endl;
			SetConsoleTextAttribute(hConsole, 15);

		}
	};
	void Logger::LogError(const char* message)
	{
		std::time_t const now = std::time(nullptr);
		if ((int)minLogLevel == 0) {
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "[Error]" << std::put_time(std::localtime(&now), "(%T):") << message << std::endl;
			SetConsoleTextAttribute(hConsole, 15);

		}
	};
	void Logger::LogCritical(const char* message)
	{
		std::time_t const now = std::time(nullptr);
		if ((int)minLogLevel == 0) {
			SetConsoleTextAttribute(hConsole, 4);
			std::cout << "[Critical]" << std::put_time(std::localtime(&now), "(%T):") << message << std::endl;
			SetConsoleTextAttribute(hConsole, 15);

		}
	};
}