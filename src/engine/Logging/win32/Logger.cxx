#include <Globals.hxx>
#include "../Logger.hxx"
#include <sstream>
#include <string>
#include <chrono>
#include <ctime>    
#include <Globals.hxx>
#include <iostream>

#ifdef _WIN32
typedef HANDLE Console;
#endif

Console console;

auto Init(uint64_t pid) -> void;

auto Log(LogMessage message) -> void {
	LPDWORD written = {};

	std::stringstream str;
	
	switch (message.level) {
	case LogLevel::Verbose:
		SetConsoleTextAttribute(
			console,
			0x0F);
		break;
	case LogLevel::Info:
		SetConsoleTextAttribute(
			console,
			0x07);
		break;
	case LogLevel::Warn:
		SetConsoleTextAttribute(
			console,
			0x06);
		break;
	case LogLevel::Error:
		SetConsoleTextAttribute(
			console,
			0x04);
		break;
	case LogLevel::Critical:
		SetConsoleTextAttribute(
			console,
			0x0D);
		break;
	}

	char buf[128];
	char* data = nullptr;

	time_t rawtime;
	time(&rawtime);
	auto timeStr = ctime_s(buf, 128, &rawtime);

	for (int x = 0; x < 128; x++) {
		if (buf[x] == '\n') {
			data = new char[1 + x];
			std::memcpy(data, buf, x);
			data[x] = '\0';

			break;
		}
	}

	str << data;
	str << " | ";
	str << message.title;
	str << " ";
	str << message.message;
	if (message.file || message.location) {
		str << " | ";
		if (message.file) {
			str << message.file << " ";
		}
		if (message.location) {
			str << message.location << " ";
		}
	}
	str << "\n";

	auto result = WriteConsoleA(
		console,
		str.str().c_str(),
		strlen(str.str().c_str()),
		written,
		nullptr
	);
	delete[] data;
}

auto CreateLogger() -> void {
	Init(ATTACH_PARENT_PROCESS);
}

auto Log(const char* message, size_t len, uint8_t level) -> void {
	LPDWORD written = {};
	std::stringstream str;

	auto addr = reinterpret_cast<int32_t*>(message[24]);

	char* printStr = new char[len + 1];

	for(int x = 0; x < len; x++) {		
		printStr[x] = static_cast<char>(message[x]);
	}


	
	printStr[len] = '\0';
	auto l = strlen(printStr);
	
	switch (LogLevel(level)) {
	case LogLevel::Verbose:
		SetConsoleTextAttribute(
			console,
			0x0F);
		break;
	case LogLevel::Info:
		SetConsoleTextAttribute(
			console,
			0x07);
		break;
	case LogLevel::Warn:
		SetConsoleTextAttribute(
			console,
			0x06);
		break;
	case LogLevel::Error:
		SetConsoleTextAttribute(
			console,
			0x04);
		break;
	case LogLevel::Critical:
		SetConsoleTextAttribute(
			console,
			0x0D);
		break;
	}

	char buf[128];
	char* data = nullptr;

	time_t rawtime;
	time(&rawtime);
	auto timeStr = ctime_s(buf, 128, &rawtime);

	for (int x = 0; x < 128; x++) {
		if (buf[x] == '\n') {
			data = new char[1 + x];
			std::memcpy(data, buf, x);
			data[x] = '\0';

			break;
		}
	}

	str << data;
	str << " | ";
	str << " ";
	str << message;
	str << "\n";

	auto result = WriteConsoleA(
		console,
		str.str().c_str(),
		strlen(str.str().c_str()),
		written,
		nullptr
	);
	delete[] data;
}

auto Test(int x, int y) -> int {
	return  x + y;
}



auto Init(uint64_t pid) -> void {
	if (AllocConsole()) {
		AttachConsole(pid);
		console = GetStdHandle(STD_OUTPUT_HANDLE);
	}
	else {
		throw "Could not create output console";
	}

  }
