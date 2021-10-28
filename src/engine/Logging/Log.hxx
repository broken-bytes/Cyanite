#pragma once


enum class LogLevel: uint8_t {
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