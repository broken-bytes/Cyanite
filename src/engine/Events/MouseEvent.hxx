#pragma once

#include <cstdint>

#include "Event.hxx"

namespace BrokenBytes::Cyanite::Engine::Events {
	struct MouseEvent : Event {
		MouseEvent(uint16_t x, uint16_t y) {
			this->x = x;
			this->y = y;
		}

		~MouseEvent() {
			
		}
		
		uint16_t x;
		uint16_t y;
	};
}
