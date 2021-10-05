#pragma once


enum class LogLevel {
	Verbose,
	Info,
	Warn,
	Error,
	Critical
};

struct LogMessage {
	const char* title;
	const char* message;
	LogLevel level;
	const char* file;
	const char* location;
};