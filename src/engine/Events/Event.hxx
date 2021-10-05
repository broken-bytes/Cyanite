#pragma once

#include <vector>
#include <typeinfo>
#include <sstream>
#include "../Logging/Logger.hxx"

namespace BrokenBytes::Cyanite::Engine::Events {
    struct Event {
        bool consumed = false;

        Event() {
            consumed = false;
        }
    	
        virtual ~Event() {
	        
        }
    };
}
