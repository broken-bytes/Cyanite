#pragma once

#include <cstdint>
#include <Globals.hxx>
#include <memory>

namespace BrokenBytes::Cyanite::Engine::Rendering {
	class RenderBackend {
	public:
		RenderBackend(Window window, uint16_t width, uint16_t height) {
			this->_window = std::make_unique<Window>(window);
			this->_width = width;
			this->_height = height;
		}
		virtual auto Init() -> void = 0;
		virtual auto Update() -> void = 0;
		virtual auto Render() -> void = 0;
		virtual auto Deinit() -> void = 0;
		virtual ~RenderBackend() {
			auto* ptr = this->_window.release();
			delete ptr;
		}
		/// <summary>
		/// The VRAM in Bytes
		/// </summary>
		/// <returns></returns>
		virtual auto VRAM()->uint64_t = 0;
	protected:
		std::unique_ptr<Window> _window;
		uint16_t _width;
		uint16_t _height;
	};
}


