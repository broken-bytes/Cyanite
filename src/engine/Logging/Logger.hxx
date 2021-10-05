#pragma once

#include <cstdint>
#include <memory>
#include "Log.hxx"

namespace BrokenBytes::Cyanite::Engine::Logging {
	auto Create() -> void;
	auto Log(LogMessage message) -> void;
}
