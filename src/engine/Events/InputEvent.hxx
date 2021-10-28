#pragma once

#include <cstdint>

#include "Event.hxx"
#include "Input.hxx"

namespace BrokenBytes::Cyanite::Engine::Events {
	struct InputEvent : Event {
		InputEvent(KeyCode code, bool value) {
			this->code = code;
			this->value = value;
		}

		~InputEvent() {
			
		}
		
		KeyCode code;
		bool value;
	};
}
