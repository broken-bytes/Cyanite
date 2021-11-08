#pragma once

#include <stdint.h>
#include <Globals.hxx>
#include "Color.hxx"

enum RendererBackendType : uint8_t {
	OpenGL,
	Vulkan,
	Direct3D12,
	Metal
};

auto RendererInit(
	Window window,
	uint16_t width,
	uint16_t height,
	RendererBackendType backend
) -> void;
auto RendererUpdate() -> void;
auto RendererDeinit() -> void;

