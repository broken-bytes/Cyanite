#pragma once

#include <stdint.h>
#include <Globals.hxx>
#include "Color.hxx"
#include <SDL.h>

enum RendererBackendType : uint8_t {
	OpenGL,
	Vulkan,
	Direct3D12,
	Metal
};

auto RendererInit(
	SDL_Window* window,
	uint16_t width,
	uint16_t height,
	RendererBackendType backend
) -> uint8_t;
auto RendererUpdate() -> void;
auto RendererDeinit() -> void;

