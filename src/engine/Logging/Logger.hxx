#pragma once

#include <cstdint>
#include <memory>
#include "Log.hxx"
#include "../../Globals.hxx"
extern "C" {
	DLL_EXPORT auto CreateLogger() -> void;
	DLL_EXPORT auto Log(char* title, char* message, uint8_t level) -> void;
	DLL_EXPORT auto Test(int x, int y) -> void;
}