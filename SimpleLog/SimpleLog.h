#pragma once

namespace SimpleLog 
{
	enum class LoggingLevel{
		Debug = 0,
		Info = 1,
		Warning = 2,
		Error = 3,
		Critical = 4
	};
	class Logger 
	{
	public:
		Logger(LoggingLevel minLogLevel);

		void LogDebug(const char* message);
		void LogInfo(const char* message);
		void LogWarning(const char* message);
		void LogError(const char* message);
		void LogCritical(const char* message);
	private:
		LoggingLevel minLogLevel;
	};
}