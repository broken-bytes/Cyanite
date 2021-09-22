#pragma once

#include <cstdint>

namespace BrokenBytes::Cyanite::Engine::Rendering {
	class RenderBackend {
	public:
		RenderBackend(uint16_t width, uint16_t height);
		virtual auto Init() -> void;
		virtual auto Update() -> void;
		virtual auto Render() -> void;
		virtual auto Deinit() -> void;
		virtual ~RenderBackend() = 0;
		/// <summary>
		/// The VRAM in Bytes
		/// </summary>
		/// <returns></returns>
		virtual auto VRAM()->uint64_t = 0;
	protected:
		uint16_t _width;
		uint16_t height;
	};
}


