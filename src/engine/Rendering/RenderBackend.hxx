#pragma once

#include <cstdint>
#include <Globals.hxx>
#include <memory>
#include <SDL.h>

namespace BrokenBytes::Cyanite::Engine::Rendering {
	class RenderBackend {
	public:
		RenderBackend(SDL_Window* window, uint16_t width, uint16_t height) {
			this->_window = window;
			this->_width = width;
			this->_height = height;
		}
		virtual auto Init() -> uint8_t = 0;
		virtual auto Update() -> void = 0;
		virtual auto Render() -> void = 0;
		virtual auto Deinit() -> void = 0;
		virtual ~RenderBackend() {
			
		}
		/// <summary>
		/// The VRAM in Bytes
		/// </summary>
		/// <returns></returns>
		virtual auto VRAM()->uint64_t = 0;
	protected:
		SDL_Window* _window;
		uint16_t _width;
		uint16_t _height;
	};
}


