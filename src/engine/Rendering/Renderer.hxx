#pragma once

#include <stdint.h>
#include "Color.hxx"
#include <SDL.h>

#ifdef _WIN32 
#define DLL_EXPORT __declspec( dllexport )
#else 
#define DLL_EXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif
	DLL_EXPORT enum RendererBackendType : uint8_t {
		OpenGL,
		Vulkan,
		Direct3D12,
		Metal
	} typedef RendererBackendType;

	DLL_EXPORT auto RendererInit(
		SDL_Window* window,
		uint32_t width,
		uint32_t height,
		RendererBackendType backend
	)->uint8_t;
	DLL_EXPORT auto RendererUpdate() -> void;
	DLL_EXPORT auto RendererDeinit() -> void;

#ifdef __cplusplus
}
#endif