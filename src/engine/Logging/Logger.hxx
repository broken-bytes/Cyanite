#pragma once

#include <cstdint>
#include <memory>
#include <vector>

#include "Log.hxx"
#include "../../Globals.hxx"
extern "C" {
	DLL_EXPORT auto CreateLogger() -> void;
	DLL_EXPORT auto Log(const char* message, size_t len, uint8_t level) -> void;
	DLL_EXPORT auto Test(int x, int y) -> int;
}